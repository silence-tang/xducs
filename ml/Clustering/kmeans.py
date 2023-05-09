import math
import random
import time
import numpy as np
from matplotlib import pyplot as plt

def readTxt(path):
    x = []
    y = []
    with open(path, "r", encoding='utf8') as f:
        i = 0
        for line in f.readlines():
            i += 1
            if i >= 2:
                line = line.split()  # 以空格分隔内容，每行存入一个列表
                x.append(float(line[0]))
                y.append(float(line[1]))
    return x, y


def calcDist(x, y):
    d = math.sqrt( ((x[0] - y[0]) ** 2) + ((x[1] - y[1]) ** 2) )
    return d

def calcNewCentroid(cls_pos):
    x_centroids_new = []
    y_centroids_new = []
    for centroid in cls_pos.keys():
        # 初始化新聚类中心坐标
        x_new = 0.0
        y_new = 0.0
        for pos in cls_pos[centroid]:
            x_new += pos[0]
            y_new += pos[1]
        # 以各类中点坐标的均值作为新的聚类中心点坐标
        x_new /= len(cls_pos[centroid])
        y_new /= len(cls_pos[centroid])
        # 将新中心坐标添加到列表中
        x_centroids_new.append(x_new)
        y_centroids_new.append(y_new)
    return x_centroids_new, y_centroids_new


def kmeans(x, y, num_centroids, x_centroids, y_centroids):
    n = len(x)
    epoch = 0  # 迭代次数
    while(1):
        epoch += 1
        dist = {}
        cls_pos = {}
        cls = {}
        for i in range(n):
            d_list = []
            for j in range(num_centroids):
                d = calcDist([x[i], y[i]], [x_centroids[j], y_centroids[j]])
                d_list.append(d)
            dist[i] = d_list
            # 找到距离当前点最近的中心点作为该点的聚类中心
            c = dist[i].index(min(dist[i]))
            # 在聚类字典中以c为键的值列表中添加该点
            cls.setdefault(c,[]).append(i)
            # 在聚类坐标字典中以c为键的值列表中添加该点坐标
            cls_pos.setdefault(c,[]).append([x[i], y[i]])
        # 所有点均已分到相应的类中。下求新的聚类中心坐标
        x_centroids_new, y_centroids_new = calcNewCentroid(cls_pos)
        # 当聚类中心不再变化时，停止迭代
        if (x_centroids_new == x_centroids) & (y_centroids_new == y_centroids):
            break
        # 更新聚类中心为新的聚类中心
        x_centroids, y_centroids = x_centroids_new, y_centroids_new
    # 返回聚类的最终结果、聚类中心坐标及迭代次数
    return epoch, x_centroids_new, y_centroids_new, cls


def createColor():
    colorArr = ['1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
    color = ""
    for _ in range(6):
        color += colorArr[random.randint(0, 14)]
    return "#" + color


def drawCluster(cls, x_centroids_new, y_centroids_new, x, y):
    # 遍历每个类
    for i in range(len(cls.keys())):
        temp_x = []
        temp_y = []
        # 求出当前类的所有点坐标，放入temp_x和temp_y
        for idx in cls[i]:
            temp_x.append(x[idx])
            temp_y.append(y[idx])
        # 绘制当前类的散点，不同类使用不同的颜色
        plt.scatter(temp_x, temp_y, color = createColor())
        # 绘制聚类中心，以红色标出
        plt.scatter(x_centroids_new, y_centroids_new, marker = 'h', linewidths = 5, color = 'blue')
    plt.show()


if __name__ == '__main__':
    path = r'C:\Users\HP\Desktop\data.txt'
    x, y = readTxt(path)
    # 绘制数据点分布情况散点图
    plt.scatter(x, y)
    plt.show()
    num_centroids = 4
    x_centroids = [0.25, 0.45, 0.65, 0.78]
    y_centroids = [0.10, 0.50, 0.10, 0.50]
    print('processing...')
    tic = time.clock()
    epoch, x_centroids_new, y_centroids_new, cls = kmeans(x, y, num_centroids, x_centroids, y_centroids)
    toc = time.clock()
    print('done! 迭代次数：{}， 耗时{}秒'.format(epoch, toc - tic))
    print('共{}类，聚类结果如下：\n{}'.format(num_centroids, cls))
    print('最终的聚类中心坐标：\n横坐标列表：{}，纵坐标列表：{}'.format(x_centroids_new, y_centroids_new))
    # 可视化聚类结果
    drawCluster(cls, x_centroids_new, y_centroids_new, x, y)
