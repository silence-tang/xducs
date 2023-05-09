[y,fs]=audioread('C:\Users\HP\Desktop\LetHerGo.mp3');
%sound(y,fs)                 %���Բ���ԭ�����ź�
n=length(y);                 %ѡȡ�任�ĵ��� 
y_p=fft(y,n);                %��n������и���Ҷ�任��Ƶ��
f=fs*(0:n/2-1)/n;            %��Ӧ���Ƶ��

%����Ƶ�źŲ�������
L=length(y);                 %������Ƶ�źŵĳ���
noise=0.1*randn(L,2);        %�����ȳ��ȵ���������ź�(����������Ĵ�Сȡ������������ķ��ȱ�����
y_z=y+noise;                 %����������   
%sound(y_z,fs)               %���Բ��ż����������ź�
%audiowrite('noiseadded.wav',y_z,fs);   %�ڵ�ǰ�ļ�����д��.wav�ļ�����������������

%�Լ����������źŽ��з���
n=length(y);                 %ѡȡ�任�ĵ��� 
y_zp=fft(y_z,n);             %��n����и���Ҷ�任��Ƶ��
f=fs*(0:n/2-1)/n;            %��Ӧ���Ƶ��
% sound(y_z,fs)

%���濪ʼ�Լ���������źŽ���ȥ��
fp=1500;fc=1700;As=100;Ap=1;%��ͨ�˲���������ָ��
%���һ����Kaiser���ĵ�ͨ�˲���
wc=2*pi*fc/fs; wp=2*pi*fp/fs;
wdel=wc-wp;
beta=0.112*(As-8.7);%����beta
N=ceil((As-8)/2.285/wdel);%ȷ���˲�������N
wn= kaiser(N+1,beta);%����Kaiser��
ws=(wp+wc)/2/pi;
b=fir1(N,ws,wn);
figure(1);
freqz(b,1);%�������޳���λ������Ӧ��Ƶ����Ӧ
%��ʼȥ��
x=fftfilt(b,y_z);
X=fft(x,n);

figure(2);
subplot(2,3,1);
plot(y);                     %����ԭʼ�ź�ʱ����ͼ
title('ԭʼ�ź�ʱ����ͼ');ylabel('��ֵ');
subplot(2,3,2);
plot(y_z);                   %���Ƽ����ź�ʱ����ͼ
title('�����ź�ʱ����ͼ');ylabel('��ֵ');
subplot(2,3,3);
plot(x);                     %�����˲����ź�ʱ����ͼ
set(gca,'YLim',[-1,1]);      %����X���������ʾ��Χ
title('�˲����ź�ʱ����ͼ');ylabel('��ֵ');
subplot(2,3,4);
plot(f,abs(y_p(1:n/2)));     %����ԭʼ�źŵ�Ƶ��ͼ
title('ԭʼ�ź����Ƶ��ͼ');xlabel('Ƶ��/Hz');ylabel('��ֵ');
subplot(2,3,5);
plot(f,abs(y_zp(1:n/2)));    %���Ƽ��������źŵ�Ƶ��ͼ
title('�����ź����Ƶ��ͼ');xlabel('Ƶ��/Hz');ylabel('��ֵ');
subplot(2,3,6);              %�����˲��������źŵ�Ƶ��ͼ
plot(f,abs(X(1:n/2)));
title('�˲����ź�Ƶ��');xlabel('Ƶ��/Hz');ylabel('��ֵ');

%sound(x,fs)            %���Բ����˲���������ź�
%audiowrite('filtered.wav',x,fs);     %�ڵ�ǰ�ļ�����д���˲��������