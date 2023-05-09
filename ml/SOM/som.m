close all;
clear;
[X,Y,~]=xlsread('data.xlsx');	% ��ȡ�ļ�
net = selforgmap([2 2]);    	% �����������Ԫ�ṹ
net.trainparam.epochs = 10000; 	% ���õ�������

net = train(net,X');    % ѵ��SOM����
plotsompos(net,X')		% ����hitͼ
y = net(X');            % ���y
classes = vec2ind(y);   % ��0 1����תΪ����
z=Y(2:end,1)';			% ����������תΪһ������
d={classes,z};			% ������������������Ӧ

% �����������
k=unique(classes);		% k��������
i=1;					% ��ʼ��i
while (i <= size(k,2))
    [~,n] = find(classes == k(i));
    fprintf('Class %d:',k(i));
    disp(z(n));			% ���ÿ���������Щ����
    i = i+1;			% i����1
end