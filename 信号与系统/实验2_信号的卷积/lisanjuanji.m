clear all;
close all;
y_1=[1,2,3,4,5,6,7,8,9];               %�趨��1����ֵ��������
y_2=[0,0,4,7,5,3,0,0];                 %�趨��2����ֵ��������
k_1=-2:-2+(length(y_1)-1);             %����1��Ӧ��ʱ������
k_2=-2:-2+(length(y_2)-1);             %����2��Ӧ��ʱ������
k_3=-2:-2+(length(y_1)+length(y_2)-2); %�����õ������е�ʱ������
y=conv(y_1,y_2);                       %����Matlab�⺯��conv()����
subplot(131);                      %������ͼ1
stem(k_1,y_1);                     %����y_1(k)ͼ��
xlabel('k');
ylabel('y_1(k)');
title('y_1(k)');
subplot(132);                      %������ͼ2
stem(k_2,y_2);                     %����y_1(k)ͼ��
xlabel('k');
ylabel('y_2(k)');
title('y_2(k)');
subplot(133);                      %������ͼ3
stem(k_3,y);                       %����y_1(k)ͼ��
xlabel('k');
ylabel('y(k)');
title('y(k)=y_1(k)*y_2(k)');