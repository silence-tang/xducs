clear all;
close all;
y_1=[1,2,3,4,5,6,7,8,9];               %设定第1个样值序列向量
y_2=[0,0,4,7,5,3,0,0];                 %设定第2个样值序列向量
k_1=-2:-2+(length(y_1)-1);             %序列1对应的时间向量
k_2=-2:-2+(length(y_2)-1);             %序列2对应的时间向量
k_3=-2:-2+(length(y_1)+length(y_2)-2); %卷积后得到的序列的时间向量
y=conv(y_1,y_2);                       %调用Matlab库函数conv()求卷积
subplot(131);                      %绘制子图1
stem(k_1,y_1);                     %绘制y_1(k)图像
xlabel('k');
ylabel('y_1(k)');
title('y_1(k)');
subplot(132);                      %绘制子图2
stem(k_2,y_2);                     %绘制y_1(k)图像
xlabel('k');
ylabel('y_2(k)');
title('y_2(k)');
subplot(133);                      %绘制子图3
stem(k_3,y);                       %绘制y_1(k)图像
xlabel('k');
ylabel('y(k)');
title('y(k)=y_1(k)*y_2(k)');