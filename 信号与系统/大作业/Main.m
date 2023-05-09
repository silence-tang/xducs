% 读取数据
% 输入的音频要对齐
% 对语言信号做原始的时域波形分析和频谱分析
% [y,fs]=audioread('C:\Users\HP\Desktop\LetHerGo.mp3');
% %sound(y,fs)                 %测试播放原声音信号
% n=length(y);                 %选取变换的点数 
% y_p=fft(y,n);                %对n个点进行傅里叶变换到频域
% f=fs*(0:n/2-1)/n;            %对应点的频率
% 
% %对音频信号产生噪声
% L=length(y);                 %计算音频信号的长度
% noise=0.1*randn(L,2);        %产生等长度的随机噪声信号(这里的噪声的大小取决于随机函数的幅度倍数）
% y_z=y+noise;                 %加噪声处理   
% %sound(y_z,fs)               %测试播放加噪后的声音信号
% %audiowrite('noiseadded.wav',y_z,fs);   %在当前文件夹中写入.wav文件（加噪声的声音）
% 
% %对加噪后的语音信号进行分析
% n=length(y);                 %选取变换的点数 
% y_zp=fft(y_z,n);             %对n点进行傅里叶变换到频域
% f=fs*(0:n/2-1)/n;            %对应点的频率
% % sound(y_z,fs)
% 
% %下面开始对加噪的语音信号进行去噪
% fp=1500;fc=1700;As=100;Ap=1;%低通滤波器的性能指标
% %设计一个带Kaiser窗的低通滤波器
% wc=2*pi*fc/fs; wp=2*pi*fp/fs;
% wdel=wc-wp;
% beta=0.112*(As-8.7);%计算beta
% N=ceil((As-8)/2.285/wdel);%确定滤波器阶数N
% wn= kaiser(N+1,beta);%计算Kaiser窗
% ws=(wp+wc)/2/pi;
% b=fir1(N,ws,wn);
% figure(1);
% freqz(b,1);%计算有限长单位脉冲响应的频率响应
% %开始去噪
% x=fftfilt(b,y_z);
% X=fft(x,n);
% 
% figure(2);
% subplot(2,3,1);
% plot(y);                     %绘制原始信号时域波形图
% title('原始信号时域波形图');ylabel('幅值');
% subplot(2,3,2);
% plot(y_z);                   %绘制加噪信号时域波形图
% title('加噪信号时域波形图');ylabel('幅值');
% subplot(2,3,3);
% plot(x);                     %绘制滤波后信号时域波形图
% set(gca,'YLim',[-1,1]);      %设置X轴的数据显示范围
% title('滤波后信号时域波形图');ylabel('幅值');
% subplot(2,3,4);
% plot(f,abs(y_p(1:n/2)));     %绘制原始信号的频谱图
% title('原始信号振幅频谱图');xlabel('频率/Hz');ylabel('幅值');
% subplot(2,3,5);
% plot(f,abs(y_zp(1:n/2)));    %绘制加噪语音信号的频谱图
% title('加噪信号振幅频谱图');xlabel('频率/Hz');ylabel('幅值');
% subplot(2,3,6);              %绘制滤波后语音信号的频谱图
% plot(f,abs(X(1:n/2)));
% title('滤波后信号频谱');xlabel('频率/Hz');ylabel('幅值');
% 
% %sound(x,fs)            %测试播放滤波后的声音信号
% %audiowrite('filtered.wav',x,fs);     %在当前文件夹中写入滤波后的声音

music1 = 'C:\Users\HP\Desktop\LetHerGo.mp3';
music2 = 'C:\Users\HP\Desktop\LetHerGo_NoiseAdded.wav';
music3 = 'C:\Users\HP\Desktop\LetHerGo_Filtered.wav';
[e1,Fs1] = audioread(music1);  %读取原音频信息
[e2,Fs2] = audioread(music2);  %读取加噪音频信息
[e3,Fs3] = audioread(music3);  %读取滤波后音频信息
f1 = Solve(e1, Fs1);           %调用Solve函数求原音频基音
f2 = Solve(e2, Fs2);           %调用Solve函数求加噪音频基音
f3 = Solve(e3, Fs3);           %调用Solve函数求滤波后音频基音

figure(1);
subplot(311);plot(f1);title('原音频基音频率');xlabel('帧数');ylabel('幅度');
subplot(312);plot(f2);title('加噪音频基音频率');xlabel('帧数');ylabel('幅度');
subplot(313);plot(f3);title('滤波后音频基音频率');xlabel('帧数');ylabel('幅度');

% 按帧分段(加噪音频)
D = 100;
pl_1 = 0;
pl_2 = 0;
for i=1:D:min(length(f1), length(f2))-D
    pl_1 = pl_1 + DTW(f1(:,i:i+D),f2(:,i:i+D));
end

% 按帧分段(滤波后音频)
for i=1:D:min(length(f1), length(f3))-D
    pl_2 = pl_2 + DTW(f1(:,i:i+D),f3(:,i:i+D));
end

%设置对照组
tpl = 0;
zf = zeros(1,length(f2));
for i=1:D:min(length(f1), length(zf))-D
    tpl = tpl + DTW(f1(:,i:i+D), zf(:,i:i+D));
end

if(tpl<pl_1)
    disp('音频2与原音频相关性太低，无法评分！');
else
    score_1 = (cos((pl_1/tpl)*pi)+1)*50;  %计算滤波后音频得分
end

if(tpl<pl_2)
    disp('音频3与原音频相关性太低，无法评分！');
else
    score_2 = (cos((pl_2/tpl)*pi)+1)*50;  %计算加噪音频得分
end

disp('加噪音频得分:');
disp(score_2);  %输出加噪音频得分
disp('滤波后音频得分:');
disp(score_1);  %输出滤波后音频得分