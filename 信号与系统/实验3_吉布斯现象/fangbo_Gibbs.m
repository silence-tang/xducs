%��֤����˹����
clear;
close;
t = 0 : 0.001 : 5;       %����ʱ������
f = 2*pi;                %����Ƶ��f=2*pi
T = 2*pi/f;              %����T=1
A = 1;                   %����
y = A*square(f*t);
figure(1);
subplot(3,2,1);
plot(t,y);
title('�����ź�');
%f(t)�ĸ���Ҷ����չ��ʽ��f(t) = 4/pi[sin(ft) + 1/3sin(3ft) + 1/5sin(5ft) +...+ 1/nsin(nft) + ...]
y1 = 4/pi*sin(1*f*t);
y3 = 4/pi/3*sin(3*f*t);
y5 = 4/pi/5*sin(5*f*t);
y7 = 4/pi/7*sin(7*f*t);
y9 = 4/pi/9*sin(9*f*t);
y11 = 4/pi/11*sin(11*f*t);
y13 = 4/pi/13*sin(13*f*t);
subplot(3,2,2);
plot(t,y1);               %����
title('����');
subplot(3,2,3);
plot(t,y1+y3);            %����+����г��
title('����+����г��');
subplot(3,2,4);
plot(t,y1+y3+y5);         %����+����г��+���г��
title('����+�������г��');
subplot(3,2,5);
plot(t,y1+y3+y5+y7);      %����+����г��+���г��+�ߴ�г��
title('����+�����塢�ߴ�г��');
subplot(3,2,6);
plot(t,y1+y3+y5+y7+y9);   %����+����г��+���г��+�ߴ�г��+�Ŵ�г��
title('����+�����塢�ߡ��Ŵ�г��');
figure(2);
Y = 0;                    %��ֵ
for i = 1 : 340
    Y = Y + (1/(2*i-1))*sin((2*i-1)*f*t);
end
Y = 4/pi*Y;
plot(t,Y);
title('��������679��г��');
Y_max = max(Y);
disp('Y�����ֵ��')
disp(Y_max);
disp('ƫ�')
temp = (Y_max-1)*100;
disp(temp);
disp('��λ��%')