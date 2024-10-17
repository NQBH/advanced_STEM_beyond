function R = CF(A)
A = triu(A);
m = size(A,1);
R = A;
for k =1:m
   for j = k+1:m
      R(j,j:m) = R(j,j:m) - R(k,j:m).*R(k,j)./R(k,k); 
   end
   R(k,k:m) = R(k,k:m)/sqrt(R(k,k));
end
