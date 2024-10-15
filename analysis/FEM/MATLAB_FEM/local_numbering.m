function a = local_numbering(b)
% Define the local numbering of the reference triangles P_1 & P_2
% Author: Nguyen Quan Ba Hong
% Date: 16/10/2018
% Last Update: 16/10/2018
% Input:
% + b: a 1x1 or 1x2 matrix
% Output:
% + a: If b is 1x1: b = 1 (edge 1) return a = [1,2], b = 2 (edge 2) return 
% a = [2,3], b = 3 (edge 3) return a = [1,3]. If b is 1x2: b = [1,2] return
% a = 1, b = [2,3] return a = 2, b = [1,3] return a = 3

if (b == 1)
    a = [1,2];
elseif (b == 2)
    a = [2,3];
elseif (b == 3)
    a = [1,3];
elseif (b == [1,2])
    a = 1;
elseif (b == [2,3])
    a = 2;
elseif (b == [1,3])
        a = 3;
else
    error('Invalid input');
end
