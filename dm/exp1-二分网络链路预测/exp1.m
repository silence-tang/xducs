clear;
close all;
% ��ȡ�����ļ�
ratings = dlmread('C:\Users\HP\Desktop\�����ھ��ϻ���ҵ\ml-1m\ratings.dat');
% ����ֻ��Ҫ��ȡ�û�����Ӱ��������3��
ratings = ratings(:, [1,3,5]);
% ���û������ܵ�Ӱ��
user_num = max(ratings(:,1));
movie_num = max(ratings(:,2));
% ��ʼ������ͼ�ڽӾ���a
a = zeros(user_num,movie_num);
for i = 1 : user_num
    % �ҵ����е�һ��ֵΪi���к�
    temp_index = find(ratings(:,1)==i);
    % ȡ����һ��ֵΪi�������з���temp����
    temp = ratings(temp_index,:);
    for j = 1 : length(temp_index)
        % �����ִ���3�����ڶ���ͼ�����һ����Ӧ�ı�
        if temp(j,3) > 3
            a(i,temp(j,2)) = 1;
        end
    end
end

% ��ʼ���û�kֵ�͵�Ӱkֵ
k_user = zeros(user_num,1);
k_movie = zeros(movie_num,1);
% �����û�kֵ
for i = 1 : user_num
    k_user(i) = length(find(ratings(:,1)==i));
end
% �����Ӱkֵ
for i = 1 : movie_num
    k_movie(i) = length(find(ratings(:,2)==i));
end

% ��ͨ��k_movie�ҳ�����δ���κ�һ���û����۹��ĵ�Ӱ��������������
bad_index = find(k_movie == 0);
a(:,bad_index) = [];
k_movie(bad_index) = [];
[~,movie_num] = size(a);

% �������ݼ���90%��Ϊѵ������10%��Ϊ���Լ�
test_num = round(user_num * 0.1);
train_num = user_num - test_num;
% �����ȡa������10%���г������ɲ��Լ�
rand_idx = randperm(user_num);
test_index = rand_idx(1:test_num);
a_test = a(test_index,:);
a(test_index,:) = [];
% a��ʣ�µ�90%���й���ѵ����
a_train = a;
% ����ѵ�����Ͳ��Լ��е��û�kֵ
k_user_test = k_user(test_index,:);
k_user(test_index,:) = [];
k_user_train = k_user;

% ����ѵ����������Դ�������W
% ��ʼ��������Ҫ�õ�����ʱ����
temp1 = zeros(train_num,movie_num);
temp2 = zeros(train_num,movie_num);
% �ȶ�a_train���н��г�����
for i = 1 : movie_num
    temp1(:,i) = a_train(:,i) / k_movie(i);
end
% �ٶ�a_train���н��г�����
for i = 1 : train_num
    temp2(i,:) = temp1(i,:) / k_user_train(i);
end
% �ɾ���˷��õ�W�����ټ������
% W��n��n����
W = a_train' * temp2;
% -------------�����ǲ��Լ�����---------------------%
% �ò��Լ������Ƽ����־���f���ߴ�Ϊtest_num��movie_num
f = (W * a_test')';
% ��ʼ��R���󣬵�i�д�Ŷ����û�i����Щ��Ӱ�е�ÿ����Ӱ�������е�����
R = zeros(test_num,movie_num);
% ��ʼ��r����
r = zeros(test_num,movie_num);
% ����R����
for i = 1 : test_num
    [~,R(i,:)] = sort(f(i,:), 'descend');
end

% ����r����
for i = 1 : test_num
    % r(i,:) = R(i,:) / (movie_num - k_user_test(i));
    r(i,:) = R(i,:) / (movie_num - sum(a_test(i)));
end
% ����rֵ������ģ��׼ȷ��
r_score = mean(r(:));

% ���һ��������ROC����
% ������ֵ�ֱ�Ϊ0-1.4�м�����ɸ���
% �������ѭ������
max_epoch = 5000;
% ��ʼ��x,y���������ÿ����ֵ�¶�Ӧ��fpr��tpr
x = zeros(1,max_epoch);
y = zeros(1,max_epoch);
% count��¼ѭ������
count = 1;
for t = 0 : 0.001 : 1.4
    % ��ʼ��pred���󣬴���ǰ��ֵ�µ��Ƽ���Ӱ(Ԥ��)����
    pred = double(f >=t);
    % fact��������ʵ���󣬴����û���ʵϲ���ĵ�Ӱ
    fact = a_test;
    % �������TP TN FP FN����(�ߴ�Ϊ600��1)
    TP = sum(double((pred == 1) & (fact== 1)),2);
    FP = sum(double((pred == 1) & (fact== 0)),2);
    TN = sum(double((pred == 0) & (fact== 0)),2);
    FN = sum(double((pred == 0) & (fact== 1)),2);
    % ����FPR TPR����
    FPR = FP ./ (FP + TN);
    TPR = TP ./ (TP + FN);
    % �Ը��û���FPR TPR���ֵ���õ�һ����ֵ�����յ�FPR��TPR
    fpr = mean(FPR);
    tpr = mean(TPR);
    x(count) = fpr;
    y(count) = tpr;
    count = count + 1;
end

% ���Ƽ���AUCֵ
AUC = 0;
for i = 2 : length(x)
    AUC = AUC + (x(i-1) - x(i)) * y(i-1);
end
disp(AUC);

% ����ROC����ͼ
plot(x,y,'-bo','LineWidth',1,'MarkerSize',1);
xlabel('FPR');
ylabel('TPR');
title(sprintf("ROC����ͼ(AUC=%.4f)", AUC));
hold on;
line([0,1],[0,1],'linestyle','-.','color','r');