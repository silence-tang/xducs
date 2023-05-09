clear;
close all;
% 读取评分文件
ratings = dlmread('C:\Users\HP\Desktop\数据挖掘上机作业\ml-1m\ratings.dat');
% 我们只需要提取用户、电影、评分这3列
ratings = ratings(:, [1,3,5]);
% 求用户数及总电影数
user_num = max(ratings(:,1));
movie_num = max(ratings(:,2));
% 初始化二部图邻接矩阵a
a = zeros(user_num,movie_num);
for i = 1 : user_num
    % 找到所有第一列值为i的行号
    temp_index = find(ratings(:,1)==i);
    % 取出第一列值为i的所有行放入temp矩阵
    temp = ratings(temp_index,:);
    for j = 1 : length(temp_index)
        % 若评分大于3，则在二部图中添加一条对应的边
        if temp(j,3) > 3
            a(i,temp(j,2)) = 1;
        end
    end
end

% 初始化用户k值和电影k值
k_user = zeros(user_num,1);
k_movie = zeros(movie_num,1);
% 计算用户k值
for i = 1 : user_num
    k_user(i) = length(find(ratings(:,1)==i));
end
% 计算电影k值
for i = 1 : movie_num
    k_movie(i) = length(find(ratings(:,2)==i));
end

% 先通过k_movie找出所有未被任何一个用户评价过的电影，清理噪声数据
bad_index = find(k_movie == 0);
a(:,bad_index) = [];
k_movie(bad_index) = [];
[~,movie_num] = size(a);

% 划分数据集：90%作为训练集，10%作为测试集
test_num = round(user_num * 0.1);
train_num = user_num - test_num;
% 随机抽取a矩阵中10%的行出来构成测试集
rand_idx = randperm(user_num);
test_index = rand_idx(1:test_num);
a_test = a(test_index,:);
a(test_index,:) = [];
% a中剩下的90%的行构成训练集
a_train = a;
% 计算训练集和测试集中的用户k值
k_user_test = k_user(test_index,:);
k_user(test_index,:) = [];
k_user_train = k_user;

% 利用训练集计算资源分配矩阵W
% 初始化计算需要用到的临时矩阵
temp1 = zeros(train_num,movie_num);
temp2 = zeros(train_num,movie_num);
% 先对a_train的列进行除操作
for i = 1 : movie_num
    temp1(:,i) = a_train(:,i) / k_movie(i);
end
% 再对a_train的行进行除操作
for i = 1 : train_num
    temp2(i,:) = temp1(i,:) / k_user_train(i);
end
% 由矩阵乘法得到W，加速计算过程
% W是n×n矩阵
W = a_train' * temp2;
% -------------下面是测试集运算---------------------%
% 用测试集计算推荐评分矩阵f，尺寸为test_num×movie_num
f = (W * a_test')';
% 初始化R矩阵，第i行存放对于用户i，这些电影中的每个电影在评分中的排名
R = zeros(test_num,movie_num);
% 初始化r矩阵
r = zeros(test_num,movie_num);
% 计算R矩阵
for i = 1 : test_num
    [~,R(i,:)] = sort(f(i,:), 'descend');
end

% 计算r矩阵
for i = 1 : test_num
    % r(i,:) = R(i,:) / (movie_num - k_user_test(i));
    r(i,:) = R(i,:) / (movie_num - sum(a_test(i)));
end
% 计算r值，衡量模型准确度
r_score = mean(r(:));

% 最后一步，绘制ROC曲线
% 设置阈值分别为0-1.4中间的若干个数
% 定义最大循环次数
max_epoch = 5000;
% 初始化x,y向量，存放每个阈值下对应的fpr和tpr
x = zeros(1,max_epoch);
y = zeros(1,max_epoch);
% count记录循环次数
count = 1;
for t = 0 : 0.001 : 1.4
    % 初始化pred矩阵，代表当前阈值下的推荐电影(预测)矩阵
    pred = double(f >=t);
    % fact矩阵是真实矩阵，代表用户真实喜欢的电影
    fact = a_test;
    % 下面计算TP TN FP FN矩阵(尺寸为600×1)
    TP = sum(double((pred == 1) & (fact== 1)),2);
    FP = sum(double((pred == 1) & (fact== 0)),2);
    TN = sum(double((pred == 0) & (fact== 0)),2);
    FN = sum(double((pred == 0) & (fact== 1)),2);
    % 计算FPR TPR矩阵
    FPR = FP ./ (FP + TN);
    TPR = TP ./ (TP + FN);
    % 对各用户的FPR TPR求均值，得到一个阈值下最终的FPR和TPR
    fpr = mean(FPR);
    tpr = mean(TPR);
    x(count) = fpr;
    y(count) = tpr;
    count = count + 1;
end

% 近似计算AUC值
AUC = 0;
for i = 2 : length(x)
    AUC = AUC + (x(i-1) - x(i)) * y(i-1);
end
disp(AUC);

% 绘制ROC曲线图
plot(x,y,'-bo','LineWidth',1,'MarkerSize',1);
xlabel('FPR');
ylabel('TPR');
title(sprintf("ROC曲线图(AUC=%.4f)", AUC));
hold on;
line([0,1],[0,1],'linestyle','-.','color','r');