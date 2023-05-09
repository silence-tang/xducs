close all;
clear;
[X,Y,~]=xlsread('data.xlsx');	% 读取文件
net = selforgmap([2 2]);    	% 设置输出层神经元结构
net.trainparam.epochs = 10000; 	% 设置迭代次数

net = train(net,X');    % 训练SOM网络
plotsompos(net,X')		% 绘制hit图
y = net(X');            % 输出y
classes = vec2ind(y);   % 将0 1向量转为索引
z=Y(2:end,1)';			% 将样本名称转为一行向量
d={classes,z};			% 将样本名称与索引对应

% 进行排序输出
k=unique(classes);		% k是类别个数
i=1;					% 初始化i
while (i <= size(k,2))
    [~,n] = find(classes == k(i));
    fprintf('Class %d:',k(i));
    disp(z(n));			% 输出每个类别有哪些样本
    i = i+1;			% i自增1
end