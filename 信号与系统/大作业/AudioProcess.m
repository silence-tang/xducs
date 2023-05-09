%对语言信号做原始的时域波形分析和频谱分析
[y,fs]=audioread('C:\Users\HP\Desktop\LetHerGo.mp3');
%sound(y,fs)                 %测试播放原声音信号
n=length(y);                 %选取变换的点数 
y_p=fft(y,n);                %对n点进行傅里叶变换到频域
f=fs*(0:n/2-1)/n;            %对应点的频率
figure(1)
subplot(2,2,1);
plot(y);                     %绘制时域波形图
title('原始信号时域波形图');
ylabel('幅值')
subplot(2,2,3);
plot(f,abs(y_p(1:n/2)));     %绘制语音信号的频谱图
title('原始信号振幅频谱图');
xlabel('频率/Hz');
ylabel('幅值');
%对音频信号产生噪声
L=length(y);                 %计算音频信号的长度
noise=0.1*randn(L,2);        %产生等长度的随机噪声信号(这里的噪声的大小取决于随机函数的幅度倍数）
y_z=y+noise;                 %加噪声处理   
%sound(y_z,fs)               %测试播放加噪后的声音信号
audiowrite('noiseadded.wav',y_z,fs);   %在当前文件夹中写入.wav文件（加噪声的声音）
%对加噪后的语音信号进行分析
n=length(y);                 %选取变换的点数 
y_zp=fft(y_z,n);             %对n点进行傅里叶变换到频域
f=fs*(0:n/2-1)/n;            %对应点的频率
subplot(2,2,2);
plot(y_z);                   %绘制加噪语音信号的时域波形图
title('加噪信号时域波形图');
ylabel('幅值')
subplot(2,2,4);
plot(f,abs(y_zp(1:n/2)));    %绘制加噪语音信号的频谱图
title('加噪信号振幅频谱图');
xlabel('频率/Hz');
ylabel('幅值');
% sound(y_z,fs)
%下面开始对加噪的语音信号进行去噪
fp=1500;fc=1700;As=100;Ap=1;%低通滤波器的性能指标
%设计低通滤波器
wc=2*pi*fc/fs; wp=2*pi*fp/fs;
wdel=wc-wp;
beta=0.112*(As-8.7);
N=ceil((As-8)/2.285/wdel);
wn= kaiser(N+1,beta);
ws=(wp+wc)/2/pi;
b=fir1(N,ws,wn);
figure(2);
freqz(b,1);
%开始去噪
x=fftfilt(b,y_z);
X=fft(x,n);
figure(3);
subplot(2,2,1);plot(f,abs(y_zp(1:n/2)));
title('滤波前信号频谱');
subplot(2,2,2);plot(f,abs(X(1:n/2)));
title('滤波后信号频谱');
subplot(2,2,3);plot(y_z);
title('滤波前信号波形');
subplot(2,2,4);plot(x);
title('滤波后信号波形');
%sound(x,fs)            %测试播放滤波后的声音信号
%audiowrite('filtered.wav',x,fs);     %在当前文件夹中写入滤波后的声音