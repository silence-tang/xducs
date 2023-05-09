function dist = DTW(t,r)
n = length(t);
m = length(r);
d = zeros(n,m);
for i = 1:n
    for j = 1:m
        d(i,j) = (t(:,i)-r(:,j))^2;%¼ÆËãÖ¡Æ¥Åä¾àÀë¾ØÕó
    end
end
D = ones(n,m) * realmax;
D(1,1) = d(1,1);
disp('ÕıÔÚÖ´ĞĞ¶¯Ì¬¹æ»®...');
for i = 1:n
    for j = 1:m
        if i>1
            D1 = D(i-1,j);
            if j>1
                D2 = D(i-1,j-1);
                D3 = D(i,j-1);
            else
                D2 = realmax;
                D3 = realmax;
            end
        else
            D1 = realmax;
            D2 = realmax;
            if j>1
                D3 = D(i,j-1);
            else
                D(i, j) = d(i, j);
                continue
            end
        end
        D(i,j) = d(i,j) + min(min(D1,D2),D3);
    end
end
dist = D(n,m);