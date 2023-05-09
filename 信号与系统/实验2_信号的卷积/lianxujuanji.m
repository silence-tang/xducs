p = 0.01; %设置采样间隔
k1 = 0 : p : 4;
f1 = 2 .* exp(-0.5*k1) .* sin(2*pi*k1);
k2 = k1;
f2 = 2 * exp(-1*k2);
sconv(f1,f2,k1,k2,p);

