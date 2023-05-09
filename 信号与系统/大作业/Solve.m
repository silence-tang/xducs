function f = Solve(e, Fs)
%����Solve���ػ���Ƶ��������

%Ԥ����
ek = -0.98; %[-1,0]
e = filter([1,ek],1,e);
un = e;
figure(1);
plot(e);
title('Origin Acoustic Signal');xlabel('Samples');ylabel('Amplitude');
figure(2);
plot(un);
title('Acoustic Signal after Pre-emphasis');xlabel('Samples');ylabel('Amplitude');

L = 20;                  %֡��
RL = 15;                 %֡��
t = length(e)*1000/Fs;   %ʱ��
N = floor((t-L)/RL);     %֡��
ns = floor(Fs*L/1000);   %֡��������
rnl = floor(Fs*RL/1000); %֡�Ƶ���

un(length(un)+1:ceil(t/L)*ns, :) = 0; %0����
su = size(un);
if su(2) == 2
    un = (un(:, 1) + un(:, 2))/2;
end

%��֡
e1 = zeros(N, ns);
for i = 1:1:N
    e1(i, :) = un((i-1)*rnl+1:(i-1)*rnl+ns, 1)';
end
figure(3);
plot(e1(100, :));
title('The 100th Frame Signal after Framing');xlabel('Samples');ylabel('Amplitude');

%�Ӵ�
e2 = zeros(N, ns);
for i = 1:1:N
    e2(i, :) = e1(i, :).*(hamming(ns))';
end
figure(4);
plot(e2(100, :));
title('The 100th Frame Signal after Windowing');xlabel('Samples');ylabel('Amplitude');

%��ʱƽ������
ee = sum(e1.^2, 2)';
ne = sum(ee)/N;

figure(5);
plot(ee);
title('Short Term Average Energy after Windowing');xlabel('Frames');ylabel('Energy');

disp('��������������');
%�������
LE = ns;
re = e2;
tR = zeros(1, N);
kee = 1.0;%��ֵ
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
disp('����������ȡ���');