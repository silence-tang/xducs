import numpy as np
from matplotlib import pyplot as plt

lr = 0.1 #学习率

class MLP():

    def __init__(self, inputNum, hiddenNum, outputNum):

        # 初始化权重及偏置参数
        self.W_1 = np.random.randn(hiddenNum, inputNum)
        self.W_2 = np.random.randn(outputNum, hiddenNum)
        self.b_1 = np.random.randn(hiddenNum, 1)
        self.b_2 = np.random.randn(outputNum, 1)

    def sigmoid(x):
        return 1 / (1 + np.exp(-x))

    # sigmoid的导数
    def d_s(x):
        return x * (1 - x)

    # 前向计算
    def forward(self, input):
        h_out = MLP.sigmoid(np.dot(self.W_1, input) + self.b_1)
        out = MLP.sigmoid(np.dot(self.W_2, h_out) + self.b_2)
        return h_out, out

    # 反向传播
    def backpropagation(self, input, h_out, out, y_true, lr = lr):
        # d_2是误差对输出层输出的偏导乘上输出层输出对输出层输入的偏导，尺寸为1x4
        d_2=(y_true - out) * MLP.d_s(out)
        # d_1是误差对隐层输入的偏导，尺寸为2x4
        d_1 = np.dot(self.W_2.T, d_2) * MLP.d_s(h_out)
        # d_W2是误差对W2矩阵的偏导，尺寸为1x2
        d_W2 = np.dot(d_2, h_out.T)
        # d_W1是误差对W1矩阵的偏导，尺寸为2x2
        d_W1 = np.dot(input, d_1.T)
        # 更新矩阵参数
        self.W_2 += lr * d_W2
        self.W_1 += lr * d_W1
        # 误差对偏置的偏导（4个输入的累加影响）
        d_b2 = float(sum(sum(d_2)))
        d_b1 = np.sum(d_1, axis=1).reshape(2,1)
        # 更新偏置参数
        self.b_2 += lr * d_b2
        self.b_1 += lr * d_b1


if __name__ == '__main__':

    # 实例化一个mlp
    mlp = MLP(2, 2, 1)
    # 给出输入及真实标签
    x_data = np.array([[0, 0, 1, 1],
                       [0, 1, 0, 1]])
    y_true = np.array([[0, 1, 1, 0]])
    # 不断迭代，当误差小于0.2时退出循环
    loss = 1.0
    i = 0
    losses = []
    while(loss > 0.20):
        i += 1
        # 前向传播，计算输出
        h_out, out = mlp.forward(x_data)
        # 反向传播，更新参数
        mlp.backpropagation(x_data, h_out, out, y_true)
        # 保存当前loss
        loss = np.mean(np.abs(out - y_true ))
        losses.append(loss)
    # 可视化loss下降曲线
    for i in range(len(losses)):
        if i % 100 == 0:
            plt.scatter(i, losses[i], linewidths = 0.5, color = 'blue')
    plt.xlabel('epoch')
    plt.ylabel('loss')
    plt.show()
    print('输入层-隐层权值:\n',mlp.W_1)
    print('隐层-输出层权值：\n',mlp.W_2)
    print('隐层偏置：\n',mlp.b_1)
    print('输出层偏置：\n',mlp.b_2)
    print('预测结果:\n',out)
    print('阈值过滤后的最终输出:')
    for i in out[0]:
        if i < 0.5:
            print(0)
        else:
            print(1)