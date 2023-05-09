%�������ź���ԭʼ��ʱ���η�����Ƶ�׷���
[y,fs]=audioread('C:\Users\HP\Desktop\LetHerGo.mp3');
%sound(y,fs)                 %���Բ���ԭ�����ź�
n=length(y);                 %ѡȡ�任�ĵ��� 
y_p=fft(y,n);                %��n����и���Ҷ�任��Ƶ��
f=fs*(0:n/2-1)/n;            %��Ӧ���Ƶ��
figure(1)
subplot(2,2,1);
plot(y);                     %����ʱ����ͼ
title('ԭʼ�ź�ʱ����ͼ');
ylabel('��ֵ')
subplot(2,2,3);
plot(f,abs(y_p(1:n/2)));     %���������źŵ�Ƶ��ͼ
title('ԭʼ�ź����Ƶ��ͼ');
xlabel('Ƶ��/Hz');
ylabel('��ֵ');
%����Ƶ�źŲ�������
L=length(y);                 %������Ƶ�źŵĳ���
noise=0.1*randn(L,2);        %�����ȳ��ȵ���������ź�(����������Ĵ�Сȡ������������ķ��ȱ�����
y_z=y+noise;                 %����������   
%sound(y_z,fs)               %���Բ��ż����������ź�
audiowrite('noiseadded.wav',y_z,fs);   %�ڵ�ǰ�ļ�����д��.wav�ļ�����������������
%�Լ����������źŽ��з���
n=length(y);                 %ѡȡ�任�ĵ��� 
y_zp=fft(y_z,n);             %��n����и���Ҷ�任��Ƶ��
f=fs*(0:n/2-1)/n;            %��Ӧ���Ƶ��
subplot(2,2,2);
plot(y_z);                   %���Ƽ��������źŵ�ʱ����ͼ
title('�����ź�ʱ����ͼ');
ylabel('��ֵ')
subplot(2,2,4);
plot(f,abs(y_zp(1:n/2)));    %���Ƽ��������źŵ�Ƶ��ͼ
title('�����ź����Ƶ��ͼ');
xlabel('Ƶ��/Hz');
ylabel('��ֵ');
% sound(y_z,fs)
%���濪ʼ�Լ���������źŽ���ȥ��
fp=1500;fc=1700;As=100;Ap=1;%��ͨ�˲���������ָ��
%��Ƶ�ͨ�˲���
wc=2*pi*fc/fs; wp=2*pi*fp/fs;
wdel=wc-wp;
beta=0.112*(As-8.7);
N=ceil((As-8)/2.285/wdel);
wn= kaiser(N+1,beta);
ws=(wp+wc)/2/pi;
b=fir1(N,ws,wn);
figure(2);
freqz(b,1);
%��ʼȥ��
x=fftfilt(b,y_z);
X=fft(x,n);
figure(3);
subplot(2,2,1);plot(f,abs(y_zp(1:n/2)));
title('�˲�ǰ�ź�Ƶ��');
subplot(2,2,2);plot(f,abs(X(1:n/2)));
title('�˲����ź�Ƶ��');
subplot(2,2,3);plot(y_z);
title('�˲�ǰ�źŲ���');
subplot(2,2,4);plot(x);
title('�˲����źŲ���');
%sound(x,fs)            %���Բ����˲���������ź�
%audiowrite('filtered.wav',x,fs);     %�ڵ�ǰ�ļ�����д���˲��������