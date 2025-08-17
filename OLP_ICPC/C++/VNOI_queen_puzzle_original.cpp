#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;
//mảng đánh dấu cột, đường chéo phụ và đường chéo chính
bool isInCol[13], isInDiag1[26], isInDiag2[26];

//gọi 2 tập riêng chi hàng và cột
//tập X có thể bỏ qua do các quân Hậu được sinh lần lượt theo từng hàng
vector <int> curQueensSetX, curQueensSetY;

//In kết quả dạng (X, Y)
void printQueensSet()
{
    for (int i = 0; i < n; i ++)
    {
        cout << "(" << curQueensSetX[i] << ", " << curQueensSetY[i] << ")";
        if (i < n - 1) cout << ", ";
    }
    cout << "\n";
}

//Hàm đệ quy
void genQueensSet(int curRow)
{
    for (int curCol = 1; curCol <= n; curCol ++)
    {
        //Xác định đường chéo phụ và chính hiện tại
        int curDiag1 = curRow + curCol;
        int curDiag2 = curRow - curCol + 13;    //+13 để tránh chỉ số âm

        //Kiểm tra toạ độ mới xem có thoả mãn không
        if (isInCol[curCol] == true) continue;
        if (isInDiag1[curDiag1] == true) continue;
        if (isInDiag2[curDiag2] == true) continue;

        //Thêm nó vào tập hợp hiện tại nếu thoả mãn
        curQueensSetX.push_back(curRow);
        curQueensSetY.push_back(curCol);
        isInCol[curCol] = true;
        isInDiag1[curDiag1] = true;
        isInDiag2[curDiag2] = true;

        //Gọi đệ quy thêm quân tiếp theo hoặc in kết quả
        if (curQueensSetX.size() == n) printQueensSet();
        else genQueensSet(curRow + 1);

        //Xoá quân vừa thêm vào khỏi tập hợp
        curQueensSetX.pop_back();
        curQueensSetY.pop_back();
        isInCol[curCol] = false;
        isInDiag1[curDiag1] = false;
        isInDiag2[curDiag2] = false;
    }
}

int main()
{
    cin >> n;

    memset(isInCol, 0, sizeof(isInCol));
    memset(isInDiag1, 0, sizeof(isInDiag1));
    memset(isInDiag2, 0, sizeof(isInDiag2));

    genQueensSet(1);

    return 0;
}