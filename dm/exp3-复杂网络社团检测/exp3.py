import random
import copy
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt


# 显示图G的相关信息
def show_info(G):
    # 输出所有节点和所有边
    print("nodes:", G.nodes(), '\n')
    print("edges:", G.edges(), '\n')
    # 输出节点总数和边总数
    nodes_num = G.number_of_nodes()
    edges_num = G.number_of_edges()
    print("number of nodes:", nodes_num)
    print("number of edges:", edges_num)

# 计算相似性矩阵
def calc_s(G):
    # 初始化s
    nodes_num = G.number_of_nodes()
    sim = np.zeros((nodes_num,nodes_num))
    # 开始计算s
    for i in range(1, nodes_num + 1):
        for j in range(1, nodes_num + 1):
            # 根据定义计算i,j的相似性
            sim[i-1][j-1] = len(G.adj[i].keys() & G.adj[j].keys()) / len(G.adj[i].keys() | G.adj[j].keys())
    print('图G的相似性矩阵为：')
    print(sim)
    return sim

# 计算社团密度（采用基于相似度度量的密度）
def calc_density(c, s):
    # 求出社团中的点数和边数
    v = c.number_of_nodes()
    e = c.number_of_edges()
    # 若社团中只有一个点，返回密度为2
    if len(c) == 1:
        return 2.0
    # 初始化总相似度
    sum_sim = 0.0
    for node_i in list(c.nodes()):
        for node_j in list(c.nodes()):
            # 不计算自身
            if (node_i != node_j) & (node_j.__index__() > node_i.__index__()):
                sum_sim = sum_sim + s[node_i-1][node_j-1]
    # 最后除以社团c中node_i,node_j的组合数再除以系数
    density_2 = sum_sim / ( ( v * (v - 1) ) / 4 )
    # 最后返回社团密度
    return density_2

# 求社团未聚类的邻居节点
def find_nbrs(G, G_copy, c):
    # 初始化
    nbrs = []
    for node in list(c.nodes()):
        # node的邻居应该在G中找
        node_nbrs = list(G.adj[node].keys())
        nbrs = list(set(nbrs) | (set(node_nbrs)))
    # 未聚类的邻居节点应该在G_copy中找，最后以数值形式存放在列表里
    final_nbrs = list(set(nbrs) & (set(list(G_copy.nodes()))))
    return final_nbrs

# 这里是初始化全局变量picked_node
picked_node = 0
# 利用贪心算法找到所有的社团——核心函数
def club_julei(G, s, t):
    # 初始化列表存放所有社团列表
    clubs = []
    # 深拷贝G，否则对G_copy操作也会同时影响G
    G_copy = copy.deepcopy(G)
    # 当G_copy的节点列表不为空时循环寻找社团，G_copy节点列表为空时说明所有的社团均已被找到
    while(G_copy.nodes()):
        # 注意列表下标从0开始
        c = nx.Graph()
        idx = random.randint(0, len(G_copy)-1)
        # 随机选择一个G_copy中的节点初始化社团c（G_copy中节点都是未被聚类的）
        randpick_node = list(G_copy.nodes())[idx]
        c.add_node(randpick_node)
        # 从G_copy中删去该节点
        G_copy.remove_node(randpick_node)
        # 死循环构造社团直到社团密度小于阈值
        while(1):
            # 计算原始社团密度
            density_old = calc_density(c, s)
            # 求当前社团未聚类的邻居节点
            candinodes = find_nbrs(G, G_copy, c)
            if len(candinodes) == 0:
                clubs.append(list(c.nodes()))
                break
            minval = 2.0
            global picked_node # 全局变量picked_node 
            # 寻找使社团密度降低最小的那个节点
            for node in candinodes:
                c.add_node(node)
                # 计算加入该节点后的社团密度
                density_new = calc_density(c, s)
                # 计算社团密度减小量
                dec = density_old - density_new
                # 若dec<minval，更新数据
                if dec < minval:
                    minval = dec
                    picked_node = node
                # 测试完当前结点后删除该节点，再循环测下一个
                c.remove_node(node)
            # 循环结束后picked_node已找到，将该节点加入社团c
            # 这里判断是否为0是为了应对picked_node未被赋值的情况
            if picked_node == 0:
                continue
            else:
                c.add_node(picked_node)
            # 同时在G中删除该点，因为该点已被分类
            if picked_node in list(G_copy.nodes()):
                G_copy.remove_node(picked_node)
            # 若当前社团的密度小于阈值，则将其加入到clubs列表中
            if calc_density(c, s) < t:
                #print(calc_density(c, s))
                clubs.append(list(c.nodes()))
                break
    # 返回所有社团
    return clubs


if __name__ == '__main__':
    # 读入karate数据
    G = nx.read_gml('C:\\Users\\HP\\Desktop\\数据挖掘上机作业\\karate\\karate.gml',label='id')
    nodes_num = G.number_of_nodes()
    edges_num = G.number_of_edges()
    # 显示图的基本信息
    show_info(G)
    # 调用nx.draw+plt.show可视化karate图
    #nx.draw(G, node_color = '#0099FF', edge_color = '#003366', with_labels = True)
    #plt.show()
    # 计算相似度矩阵
    s = calc_s(G)
    # 设定阈值t
    t = 0.4
    clubs = club_julei(G, s, t)
    # 打印所有社团
    print('t = %f时，社团聚类结果如下：' % t)
    print(clubs)