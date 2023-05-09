function f = Solve(e, Fs)
%函数Solve返回基音频率列向量

%预加重
ek = -0.98; %[-1,0]
e = filter([1,ek],1,e);
un = e;
figure(1);
plot(e);
title('Origin Acoustic Signal');xlabel('Samples');ylabel('Amplitude');
figure(2);
plot(un);
title('Acoustic Signal after Pre-emphasis');xlabel('Samples');ylabel('Amplitude');

L = 20;                  %帧长
RL = 15;                 %帧移
t = length(e)*1000/Fs;   %时长
N = floor((t-L)/RL);     %帧数
ns = floor(Fs*L/1000);   %帧采样点数
rnl = floor(Fs*RL/1000); %帧移点数

un(length(un)+1:ceil(t/L)*ns, :) = 0; %0扩充
su = size(un);
if su(2) == 2
    un = (un(:, 1) + un(:, 2))/2;
end

%分帧
e1 = zeros(N, ns);
for i = 1:1:N
    e1(i, :) = un((i-1)*rnl+1:(i-1)*rnl+ns, 1)';
end
figure(3);
plot(e1(100, :));
title('The 100th Frame Signal after Framing');xlabel('Samples');ylabel('Amplitude');

%加窗
e2 = zeros(N, ns);
for i = 1:1:N
    e2(i, :) = e1(i, :).*(hamming(ns))';
end
figure(4);
plot(e2(100, :));
title('The 100th Frame Signal after Windowing');xlabel('Samples');ylabel('Amplitude');

%短时平均能量
ee = sum(e1.^2, 2)';
ne = sum(ee)/N;

figure(5);
plot(ee);
title('Short Term Average Energy after Windowing');xlabel('Frames');ylabel('Energy');

disp('正在求解基音特征');
%求自相关
LE = ns;
re = e2;
tR = zeros(1, N);
kee = 1.0;%阈值
for i = 1:1:N
    if ee(:, i) < kee*ne
        continue
    end
    R = zeros(1, LE);
    for k = 1:1:LE
        for t = 1:1:LE-k
            R(1, t) = R(1, t) + re(i, t)*re(i, t + k);
        end
    end
    [~ ,tR(1, i)] = max(R);
end

figure(6);
plot(tR);
title('Pitch Frequency');xlabel('Frames');ylabel('Amplitude');
f = tR;
disp('基音特征提取完毕');