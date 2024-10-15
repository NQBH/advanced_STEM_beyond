function g = diff_op(type, u, Du)
% Differentiel operator
% Author: G.Vial
% Date: 16/09/2010
% Last update: 17/11/10
%
% usage: g = diff_op(type,u,Du)
%
% input:
% 	type : type of operator (string)
% 	u    : value of function (scalar)
% 	Du   : value of function derivative (1 by 2 array)
%
% output:
%	g : value of operator

switch (type)
   case 'Id'
      g=u;
   case 'D1'
      g=Du(1);
   case 'D2'
      g=Du(2);
   otherwise
      error(['Operator ',type,' not defined -- :-((( --'])
end