function[f,k] = sconv(f1,f2,k1,k2,p)
f = conv(f1,f2);
f = f * p;        %p是取样间隔
k3 = length(f1) + length(f2) - 2;
k = 0 : p : k3 * p;
subplot(2,2,1);
plot(k1,f1);
title('f_1(t)');
xlabel('t');
ylabel('f_1(t)');
subplot(2,2,2)
plot(k2,f2);
title('f_2(t)');
xlabel('t');
ylabel('y_2(t)');
subplot(2,2,3);
plot(k,f);
h = get(gca,'position');
h(3) = 2.5 * h(3);
set(gca,'position',h);
title('f(t)=f_1(t)*f_2(t)');
xlabel('t');
ylabel('f(t)');
end

