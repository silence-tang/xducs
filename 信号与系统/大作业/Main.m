% ��ȡ����
% �������ƵҪ����
% �������ź���ԭʼ��ʱ���η�����Ƶ�׷���
% [y,fs]=audioread('C:\Users\HP\Desktop\LetHerGo.mp3');
% %sound(y,fs)                 %���Բ���ԭ�����ź�
% n=length(y);                 %ѡȡ�任�ĵ��� 
% y_p=fft(y,n);                %��n������и���Ҷ�任��Ƶ��
% f=fs*(0:n/2-1)/n;            %��Ӧ���Ƶ��
% 
% %����Ƶ�źŲ�������
% L=length(y);                 %������Ƶ�źŵĳ���
% noise=0.1*randn(L,2);        %�����ȳ��ȵ���������ź�(����������Ĵ�Сȡ������������ķ��ȱ�����
% y_z=y+noise;                 %����������   
% %sound(y_z,fs)               %���Բ��ż����������ź�
% %audiowrite('noiseadded.wav',y_z,fs);   %�ڵ�ǰ�ļ�����д��.wav�ļ�����������������
% 
% %�Լ����������źŽ��з���
% n=length(y);                 %ѡȡ�任�ĵ��� 
% y_zp=fft(y_z,n);             %��n����и���Ҷ�任��Ƶ��
% f=fs*(0:n/2-1)/n;            %��Ӧ���Ƶ��
% % sound(y_z,fs)
% 
% %���濪ʼ�Լ���������źŽ���ȥ��
% fp=1500;fc=1700;As=100;Ap=1;%��ͨ�˲���������ָ��
% %���һ����Kaiser���ĵ�ͨ�˲���
% wc=2*pi*fc/fs; wp=2*pi*fp/fs;
% wdel=wc-wp;
% beta=0.112*(As-8.7);%����beta
% N=ceil((As-8)/2.285/wdel);%ȷ���˲�������N
% wn= kaiser(N+1,beta);%����Kaiser��
% ws=(wp+wc)/2/pi;
% b=fir1(N,ws,wn);
% figure(1);
% freqz(b,1);%�������޳���λ������Ӧ��Ƶ����Ӧ
% %��ʼȥ��
% x=fftfilt(b,y_z);
% X=fft(x,n);
% 
% figure(2);
% subplot(2,3,1);
% plot(y);                     %����ԭʼ�ź�ʱ����ͼ
% title('ԭʼ�ź�ʱ����ͼ');ylabel('��ֵ');
% subplot(2,3,2);
% plot(y_z);                   %���Ƽ����ź�ʱ����ͼ
% title('�����ź�ʱ����ͼ');ylabel('��ֵ');
% subplot(2,3,3);
% plot(x);                     %�����˲����ź�ʱ����ͼ
% set(gca,'YLim',[-1,1]);      %����X���������ʾ��Χ
% title('�˲����ź�ʱ����ͼ');ylabel('��ֵ');
% subplot(2,3,4);
% plot(f,abs(y_p(1:n/2)));     %����ԭʼ�źŵ�Ƶ��ͼ
% title('ԭʼ�ź����Ƶ��ͼ');xlabel('Ƶ��/Hz');ylabel('��ֵ');
% subplot(2,3,5);
% plot(f,abs(y_zp(1:n/2)));    %���Ƽ��������źŵ�Ƶ��ͼ
% title('�����ź����Ƶ��ͼ');xlabel('Ƶ��/Hz');ylabel('��ֵ');
% subplot(2,3,6);              %�����˲��������źŵ�Ƶ��ͼ
% plot(f,abs(X(1:n/2)));
% title('�˲����ź�Ƶ��');xlabel('Ƶ��/Hz');ylabel('��ֵ');
% 
% %sound(x,fs)            %���Բ����˲���������ź�
% %audiowrite('filtered.wav',x,fs);     %�ڵ�ǰ�ļ�����д���˲��������

music1 = 'C:\Users\HP\Desktop\LetHerGo.mp3';
music2 = 'C:\Users\HP\Desktop\LetHerGo_NoiseAdded.wav';
music3 = 'C:\Users\HP\Desktop\LetHerGo_Filtered.wav';
[e1,Fs1] = audioread(music1);  %��ȡԭ��Ƶ��Ϣ
[e2,Fs2] = audioread(music2);  %��ȡ������Ƶ��Ϣ
[e3,Fs3] = audioread(music3);  %��ȡ�˲�����Ƶ��Ϣ
f1 = Solve(e1, Fs1);           %����Solve������ԭ��Ƶ����
f2 = Solve(e2, Fs2);           %����Solve�����������Ƶ����
f3 = Solve(e3, Fs3);           %����Solve�������˲�����Ƶ����

figure(1);
subplot(311);plot(f1);title('ԭ��Ƶ����Ƶ��');xlabel('֡��');ylabel('����');
subplot(312);plot(f2);title('������Ƶ����Ƶ��');xlabel('֡��');ylabel('����');
subplot(313);plot(f3);title('�˲�����Ƶ����Ƶ��');xlabel('֡��');ylabel('����');

% ��֡�ֶ�(������Ƶ)
D = 100;
pl_1 = 0;
pl_2 = 0;
for i=1:D:min(length(f1), length(f2))-D
    pl_1 = pl_1 + DTW(f1(:,i:i+D),f2(:,i:i+D));
end

% ��֡�ֶ�(�˲�����Ƶ)
for i=1:D:min(length(f1), length(f3))-D
    pl_2 = pl_2 + DTW(f1(:,i:i+D),f3(:,i:i+D));
end

%���ö�����
tpl = 0;
zf = zeros(1,length(f2));
for i=1:D:min(length(f1), length(zf))-D
    tpl = tpl + DTW(f1(:,i:i+D), zf(:,i:i+D));
end

if(tpl<pl_1)
    disp('��Ƶ2��ԭ��Ƶ�����̫�ͣ��޷����֣�');
else
    score_1 = (cos((pl_1/tpl)*pi)+1)*50;  %�����˲�����Ƶ�÷�
end

if(tpl<pl_2)
    disp('��Ƶ3��ԭ��Ƶ�����̫�ͣ��޷����֣�');
else
    score_2 = (cos((pl_2/tpl)*pi)+1)*50;  %���������Ƶ�÷�
end

disp('������Ƶ�÷�:');
disp(score_2);  %���������Ƶ�÷�
disp('�˲�����Ƶ�÷�:');
disp(score_1);  %����˲�����Ƶ�÷�