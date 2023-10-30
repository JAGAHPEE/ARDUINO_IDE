clear;
a = input('enter the sequence x(n) =');
b = input('enter the sequence h(n) =');
n1 = length(a);
n2 = length(b);
N = max(n1,n2);
x = [a zeros(1,(N-n1))];
for i = 1:N
 i;
 j =1:n2
,j) = x(k)*b(j);
 k-1;
k == 0)
 N;



y = zeros(1,N);
M = H';
for j = 1:N
 i = 1:n2
) = M(i,j)+y(j);


disp('The output sequence is y(n)=');
disp(y)  9     4     8
stem(y);
title('Circular Convolution');
xlabel('n');
ylabel('y(n)');
