import numpy as np
from matplotlib import pyplot as plt

lr = 0.1
epoch = 10000

class Perceptron():

    def __init__(self, inputNum, outputNum):

        # 初始化权重及偏置参数
        self.W = np.random.randn(outputNum, inputNum)
        self.b = np.random.randn(outputNum, 1)

    # sigmoid激活函数
    def sigmoid(x):
        return 1 / (1 + np.exp(-x))

    # sigmoid的导数
    def d_s(x):
        return x * (1 - x)

    # 前向计算
    def forward(self, input):
        out = Perceptron.sigmoid(np.dot(self.W, input) + self.b)
        return out

    # 反向传播
    def backpropagation(self, input, out, y_true, lr = lr):
        # d_W是误差对W矩阵的偏导，尺寸为1x2
        d_W = np.dot((y_true - out) * Perceptron.d_s(out), input.T) 
        # 更新矩阵参数
        self.W += lr * d_W
        # 误差对偏置的偏导（4个输入的累加影响）
        d_b = float(sum(sum((y_true - out) * Perceptron.d_s(out))))
        # 更新偏置参数
        self.b += lr * d_b


if __name__ == '__main__':

    # 实例化一个perceptron
    perceptron = Perceptron(3,1)
    # perceptron = Perceptron(2,1)
    # perceptron = Perceptron(1,1)
    # 给出输入及真实标签
    # x_data = np.array([[0, 0, 1, 1],
    #                    [0, 1, 0, 1]])
    x_data = np.array([[0, 0, 1, 1],
                       [0, 1, 0, 1],
                       [0, 0, 0, 1]])
    # x_data = np.array([[0, 1]])
    # 逻辑与
    # y_data = np.array([[0, 0, 0, 1]])
    # 逻辑或
    # y_data = np.array([[0, 1, 1, 1]])
    # 逻辑非
    # y_data = np.array([[1, 0]])
    # 异或
    y_data = np.array([[0, 1, 1, 0]])

    # 迭代
    losses = []
    for i in range(epoch):
        # 前向传播，计算输出
        out = perceptron.forward(x_data)
        # 反向传播，更新参数
        perceptron.backpropagation(x_data, out, y_data)
        loss = np.mean(np.abs(y_data - out))
        losses.append(loss)
    #绘制loss曲线图
    for i in range(epoch):
        if i % 100 == 0:
            plt.scatter(i, losses[i], color='blue')
    plt.xlabel('eopch')
    plt.ylabel('loss')
    plt.show()
    print('输入层到输出层权值:\n', perceptron.W)
    print('输出层偏置：\n', perceptron.b)
    print('最终结果:\n',out)
    print('忽略误差的近似输出:')
    # 设定sigmoid激活后的阈值为0.5
    for i in sum(out):
        if i < 0.5:
            print(0)
        else:
            print(1)