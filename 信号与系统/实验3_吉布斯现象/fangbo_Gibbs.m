%验证吉布斯现象
clear;
close;
t = 0 : 0.001 : 5;       %定义时轴区间
f = 2*pi;                %定义频率f=2*pi
T = 2*pi/f;              %周期T=1
A = 1;                   %幅度
y = A*square(f*t);
figure(1);
subplot(3,2,1);
plot(t,y);
title('方波信号');
%f(t)的傅里叶级数展开式：f(t) = 4/pi[sin(ft) + 1/3sin(3ft) + 1/5sin(5ft) +...+ 1/nsin(nft) + ...]
y1 = 4/pi*sin(1*f*t);
y3 = 4/pi/3*sin(3*f*t);
y5 = 4/pi/5*sin(5*f*t);
y7 = 4/pi/7*sin(7*f*t);
y9 = 4/pi/9*sin(9*f*t);
y11 = 4/pi/11*sin(11*f*t);
y13 = 4/pi/13*sin(13*f*t);
subplot(3,2,2);
plot(t,y1);               %基波
title('基波');
subplot(3,2,3);
plot(t,y1+y3);            %基波+三次谐波
title('基波+三次谐波');
subplot(3,2,4);
plot(t,y1+y3+y5);         %基波+三次谐波+五次谐波
title('基波+三、五次谐波');
subplot(3,2,5);
plot(t,y1+y3+y5+y7);      %基波+三次谐波+五次谐波+七次谐波
title('基波+三、五、七次谐波');
subplot(3,2,6);
plot(t,y1+y3+y5+y7+y9);   %基波+三次谐波+五次谐波+七次谐波+九次谐波
title('基波+三、五、七、九次谐波');
figure(2);
Y = 0;                    %初值
for i = 1 : 340
    Y = Y + (1/(2*i-1))*sin((2*i-1)*f*t);
end
Y = 4/pi*Y;
plot(t,Y);
title('基波加至679次谐波');
Y_max = max(Y);
disp('Y的最大值：')
disp(Y_max);
disp('偏差：')
temp = (Y_max-1)*100;
disp(temp);
disp('单位：%')