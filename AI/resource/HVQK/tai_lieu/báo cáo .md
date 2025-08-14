# PHÂN TÍCH CHI TIẾT NỘI DUNG BÁO CÁO SUDOKU SOLVER

## LỜI MỞ ĐẦU
Sudoku là một trò chơi logic số học nổi tiếng trên toàn thế giới, không chỉ giúp rèn luyện tư duy mà còn là ví dụ điển hình cho các bài toán ràng buộc trong trí tuệ nhân tạo (AI). Đồ án này hướng tới việc xây dựng một chương trình giải Sudoku tự động bằng thuật toán heuristic, hỗ trợ nhiều biến thể Sudoku, đồng thời giúp sinh viên hiểu sâu về các kỹ thuật AI ứng dụng thực tiễn.

---

## CHƯƠNG I: GIỚI THIỆU VÀ ĐẶT VẤN ĐỀ
### 1.1 Tổng quan về Sudoku và bài toán giải Sudoku
- **Sudoku** là trò chơi logic, người chơi điền các số vào bảng 9x9 sao cho mỗi hàng, cột, vùng 3x3 đều chứa đủ các số từ 1-9, không trùng lặp.
- Có nhiều biến thể: Sudoku 9x9, 16x16 (dùng cả số và ký tự hex), X-Sudoku (thêm ràng buộc đường chéo).
- Bài toán giải Sudoku là một **Constraint Satisfaction Problem (CSP)** điển hình trong AI.

### 1.2 Mục tiêu của đồ án
- Xây dựng chương trình giải tự động các loại Sudoku bằng thuật toán backtracking kết hợp heuristic MRV.
- Hỗ trợ nhập liệu, tạo đề tự động, kiểm tra hợp lệ, đo hiệu suất giải.

### 1.3 Phạm vi, yêu cầu và các tính năng chính
- Giải Sudoku 9x9, 16x16, X-Sudoku.
- Tạo đề tự động đảm bảo có lời giải duy nhất.
- Hiển thị số lần thử, thời gian giải, xuất kết quả rõ ràng.
- Kiểm tra hợp lệ dữ liệu đầu vào, phát hiện trường hợp không có lời giải.

### 1.4 Ứng dụng thực tiễn và ý tưởng mở rộng
- Ứng dụng trong giáo dục, luyện tư duy logic, nghiên cứu AI.
- Có thể phát triển thành phần mềm học tập, giao diện đồ họa, phân tích độ khó, giải nhiều lời giải, v.v.

---

## CHƯƠNG II: CƠ SỞ LÝ THUYẾT
### 2.1 Tổng quan về Trí tuệ nhân tạo (AI) và bài toán ràng buộc (CSP)
- AI giải quyết các bài toán logic, tối ưu, tìm kiếm lời giải tự động.
- Sudoku là một CSP: các biến là ô số, miền giá trị là các số hợp lệ, ràng buộc là luật Sudoku (hàng, cột, vùng, đường chéo).

### 2.2 Bài toán Sudoku
- **Định nghĩa**: Sudoku là trò chơi logic số học, bảng 9x9 hoặc 16x16, điền số sao cho không trùng lặp theo hàng, cột, vùng.
- **Luật chơi**:
  1. Mỗi ô chỉ điền một số.
  2. Mỗi hàng, cột, vùng con (3x3 hoặc 4x4) không trùng số.
  3. X-Sudoku: hai đường chéo chính cũng không trùng số.
- **Biến thể**:
  - Sudoku 9x9: số 1-9, vùng 3x3.
  - Sudoku 16x16: số 1-9, A-F, vùng 4x4.
  - X-Sudoku: thêm ràng buộc đường chéo.

### 2.3 Thuật toán giải Sudoku
- **Backtracking**: Thử điền từng giá trị hợp lệ vào ô trống, nếu không hợp lệ thì quay lui thử giá trị khác.
- **Heuristic MRV (Minimum Remaining Values)**: Luôn chọn ô có ít khả năng điền nhất để thử trước, giúp giảm số nhánh duyệt.
- **Kỹ thuật tối ưu hóa**:
  - Constraint Propagation: loại bỏ giá trị không hợp lệ sớm.
  - Forward Checking: kiểm tra tác động trước khi điền.

**Ví dụ mã nguồn (trích từ PROJECT_STRUCTURE.md):**
```cpp
bool solveWithMRV() {
    pair<int, int> cell = findMRVCell();
    if (cell.first == -1) return true;
    for (int num : getPossibleValues(cell.first, cell.second)) {
        board[cell.first][cell.second] = num;
        if (solveWithMRV()) return true;
        board[cell.first][cell.second] = 0; // Backtrack
    }
    return false;
}
```

### 2.4 Đánh giá hiệu suất các phương pháp
| Loại Sudoku | Số lần thử | Thời gian (ms) | Độ phức tạp |
|-------------|------------|---------------|-------------|
| 9x9 thường  | 156        | 3             | O(9^n)      |
| 9x9 X-Sudoku| 245        | 5             | O(9^n)      |
| 16x16       | 1024       | 45            | O(16^n)     |

- MRV giúp giảm 90% số lần thử so với backtracking thuần.
- Backtracking + MRV: 50-200ms, 500-2000 lần thử (so với 1000-5000ms, 10000-50000 lần thử của backtracking thường).

---

## CHƯƠNG III: PHÂN TÍCH VÀ THIẾT KẾ HỆ THỐNG
### 3.1 Phân tích yêu cầu và các chức năng chính
- Nhập liệu: thủ công, dùng bảng mẫu, tạo đề tự động.
- Giải Sudoku, xuất kết quả, kiểm tra hợp lệ, đo hiệu suất.

### 3.2 Mô hình hóa dữ liệu
- **Lớp chính**:
  - `SudokuSolver`: giải Sudoku 9x9.
  - `AdvancedSudokuSolver`: giải 9x9, 16x16, X-Sudoku, tạo đề tự động.
- **Thuộc tính**:
  - `board`: ma trận lưu trạng thái Sudoku.
  - `size`, `subSize`: kích thước bảng, vùng con.
  - `attempts`: số lần thử.
  - `isXSudoku`: cờ xác định có phải X-Sudoku không.
- **Phương thức**:
  - `isValid(row, col, num)`: kiểm tra hợp lệ.
  - `getPossibleValues(row, col)`: trả về các giá trị có thể điền.
  - `findMRVCell()`: tìm ô có ít khả năng điền nhất.
  - `solveWithMRV()`: giải bằng backtracking + MRV.
  - `generateValidBoard()`, `createPuzzle()`, `generatePuzzle()`: tạo đề tự động.

### 3.3 Thiết kế thuật toán
- Luồng giải quyết:
  1. Nhập dữ liệu.
  2. Kiểm tra hợp lệ.
  3. Giải bằng backtracking + MRV.
  4. Xuất kết quả, đo hiệu suất.
- Sơ đồ thuật toán: (xem code mẫu ở trên).

### 3.4 Thiết kế giao diện nhập/xuất (console)
- Hướng dẫn nhập dữ liệu:
  - Chọn loại Sudoku (9x9, 16x16, X-Sudoku).
  - Chọn cách nhập: thủ công, bảng mẫu, tạo đề tự động.
- Xuất kết quả: in bảng đầu vào, lời giải, số lần thử, thời gian giải.
- Xử lý lỗi: thông báo khi không có lời giải hoặc dữ liệu không hợp lệ.

### 3.5 Cấu trúc thư mục và các file mã nguồn
- `sudoku_solver.cpp`: giải Sudoku 9x9, giao diện đơn giản.
- `sudoku_advanced_fixed.cpp`: giải nhiều loại Sudoku, tạo đề tự động, giao diện nâng cao.
- `README.md`: hướng dẫn sử dụng, biên dịch, giải thích thuật toán.
- `SUDOKU_GUIDE.md`: lý thuyết Sudoku, luật chơi, thuật toán, ứng dụng thực tiễn.
- `DEMO.md`: hướng dẫn demo, ví dụ chạy, kết quả mẫu, phân tích hiệu suất.
- `PROJECT_STRUCTURE.md`: mô tả cấu trúc dự án, vai trò từng file.

---

## CHƯƠNG IV: TRIỂN KHAI VÀ KẾT QUẢ
### 4.1 Môi trường phát triển, công nghệ sử dụng
- Ngôn ngữ: C++
- Biên dịch: g++
- Hệ điều hành: Windows, Linux

### 4.2 Hướng dẫn biên dịch và chạy chương trình
```bash
# Biên dịch phiên bản cơ bản
g++ -o sudoku_solver sudoku_solver.cpp
# Biên dịch phiên bản nâng cao
g++ -o sudoku_advanced sudoku_advanced_fixed.cpp
```
Chạy chương trình:
```bash
./sudoku_solver
./sudoku_advanced
```

### 4.3 Demo các chức năng
- **Giải Sudoku 9x9**:
  - Nhập thủ công hoặc dùng bảng mẫu.
  - Kết quả: số lần thử 156, thời gian 3ms.
- **Giải X-Sudoku**:
  - Thêm ràng buộc đường chéo.
  - Kết quả: số lần thử 245, thời gian 5ms.
- **Giải Sudoku 16x16**:
  - Sử dụng số và ký tự hex.
  - Kết quả: số lần thử 1024, thời gian 45ms.
- **Tạo đề tự động**:
  - Đảm bảo có lời giải duy nhất.
- **Kiểm tra hợp lệ, đo hiệu suất**:
  - Thông báo khi không có lời giải hoặc dữ liệu không hợp lệ.

### 4.4 Kết quả mẫu, phân tích hiệu suất, xử lý lỗi
- **Bảng kết quả mẫu**:
  - Đầu vào, lời giải, số lần thử, thời gian giải (xem DEMO.md).
- **Phân tích hiệu suất**:
  - MRV giúp giảm mạnh số lần thử, tăng tốc độ giải.
- **Xử lý lỗi**:
  - Thông báo rõ ràng khi không có lời giải hoặc nhập sai dữ liệu.

### 4.5 Đánh giá ưu/nhược điểm, hạn chế hiện tại
- **Ưu điểm**:
  - Giải nhanh, hỗ trợ nhiều biến thể, giao diện đơn giản, dễ sử dụng.
- **Nhược điểm**:
  - Chưa có giao diện đồ họa.
  - Chưa phân tích độ khó, chưa giải nhiều lời giải cùng lúc.

---

## CHƯƠNG V: KẾT LUẬN VÀ HƯỚNG PHÁT TRIỂN
### 5.1 Tổng kết những gì đã đạt được
- Hoàn thiện chương trình giải Sudoku bằng AI heuristic, hỗ trợ nhiều biến thể, đo hiệu suất, tạo đề tự động.

### 5.2 Kiến thức, kỹ năng học được
- Hiểu về CSP, heuristic, lập trình hướng đối tượng, tối ưu hóa thuật toán, kỹ năng phân tích và thiết kế hệ thống.

### 5.3 Định hướng phát triển
- Phát triển giao diện đồ họa (GUI) bằng Qt/wxWidgets.
- Hỗ trợ giải nhiều lời giải, phân tích độ khó, lưu/tải đề.
- Cải tiến thuật toán: Naked Pairs/Triples, Hidden Singles, X-Wing, Swordfish, Genetic Algorithm.

---

## PHỤ LỤC
- Hướng dẫn chi tiết sử dụng chương trình (xem DEMO.md, README.md).
- Mã nguồn chính (sudoku_solver.cpp, sudoku_advanced_fixed.cpp).
- Tài liệu tham khảo: SUDOKU_GUIDE.md, các nguồn về CSP, heuristic, AI. 