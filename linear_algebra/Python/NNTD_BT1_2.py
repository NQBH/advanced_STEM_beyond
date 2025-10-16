#!/usr/bin/env python3#BT1

"""Chương trình hoàn chỉnh cho BT1 và BT2def print_matrix(M):

	#!/usr/bin/env python3

BT1: Nhập ma trận A và vector b, kiểm tra kích thước, in ma trận bổ sung [A|b] hoặc in "Impossible".	"""Chương trình hoàn chỉnh cho BT1 và BT2

BT2: Thực hiện 3 phép biến đổi sơ cấp trên dòng (swap, scale, add multiple) trên một ma trận A bằng menu tương tác.

	BT1: Nhập ma trận A và vector b, kiểm tra kích thước, in ma trận bổ sung [A|b] hoặc in "Impossible".

Hướng dùng: Chạy script, chọn BT1 hoặc BT2 theo menu. Mã ngắn gọn, dễ hiểu, có giải thích chi tiết ở dưới.	BT2: Thực hiện 3 phép biến đổi sơ cấp trên dòng (swap, scale, add multiple) trên một ma trận A bằng menu tương tác.

"""	"""



from copy import deepcopy	from copy import deepcopy

from typing import List, Optional	from typing import List, Optional





def print_matrix(M: List[List[float]]) -> None:	def print_matrix(M: List[List[float]]) -> None:

    """In ma trận dạng hàng-ô, căn đều cột cho dễ đọc."""	    if not M:

    if not M:	        print('[]')

        print('[]')	        return

        return	    cols = max(len(r) for r in M)

    cols = max(len(r) for r in M)	    widths = [max(len(f"{row[c]}") if c < len(row) else 0 for row in M) for c in range(cols)]

    widths = [max(len(f"{row[c]}") if c < len(row) else 0 for row in M) for c in range(cols)]	    for row in M:

    for row in M:	        print('[' + '  '.join(f"{row[c]:>{widths[c]}}" if c < len(row) else ' ' * widths[c] for c in range(cols)) + ' ]')

        print('[' + '  '.join(f"{row[c]:>{widths[c]}}" if c < len(row) else ' ' * widths[c] for c in range(cols)) + ' ]')



	def input_matrix() -> Optional[List[List[float]]]:

def input_matrix() -> Optional[List[List[float]]]:	    """Nhập ma trận: nhập số hàng và số cột, sau đó từng hàng cách nhau bởi khoảng trắng."""

    """Nhập ma trận: hỏi m,n rồi nhập từng hàng (số cách nhau dấu cách).	    try:

	        m = int(input('Số hàng m = ').strip())

    Trả về None nếu nhập không hợp lệ.	        n = int(input('Số cột n = ').strip())

    """	    except ValueError:

    try:	        print('Lỗi: m,n phải là số nguyên.')

        m = int(input('Số hàng m = ').strip())	        return None

        n = int(input('Số cột n = ').strip())	    M = []

    except ValueError:	    for i in range(m):

        print('Lỗi: m,n phải là số nguyên.')	        while True:

        return None	            line = input(f'Hàng {i+1} ({n} số, cách nhau bằng dấu cách): ').strip()

    M: List[List[float]] = []	            parts = line.split()

    for i in range(m):	            if len(parts) != n:

        while True:	                print(f'Nhập sai: cần {n} phần tử, bạn đã nhập {len(parts)}.')

            line = input(f'Hàng {i+1} ({n} số, cách nhau bằng dấu cách): ').strip()	                continue

            parts = line.split()	            try:

            if len(parts) != n:	                row = [float(x) if ('.' in x or 'e' in x.lower()) else int(x) for x in parts]

                print(f'Nhập sai: cần {n} phần tử, bạn đã nhập {len(parts)}.')	            except ValueError:

                continue	                print('Các phần tử phải là số. Thử lại.')

            try:	                continue

                row = [float(x) if ('.' in x or 'e' in x.lower()) else int(x) for x in parts]	            M.append(row)

            except ValueError:	            break

                print('Các phần tử phải là số. Thử lại.')	    return M

                continue

            M.append(row)

            break	def input_vector(expected_len: Optional[int] = None) -> Optional[List[float]]:

    return M	    line = input(f'Nhập vector b (các phần tử cách nhau dấu cách){" (độ dài cần là " + str(expected_len) + ")" if expected_len else ""}: ').strip()

	    parts = line.split()

	    if expected_len is not None and len(parts) != expected_len:

def input_vector(expected_len: Optional[int] = None) -> Optional[List[float]]:	        print(f'Lỗi: vector cần có {expected_len} phần tử, bạn đã nhập {len(parts)}.')

    """Nhập vector b dưới dạng một dòng các số cách nhau bằng dấu cách.	        return None

	    try:

    Nếu expected_len khác None thì kiểm tra độ dài.	        return [float(x) if ('.' in x or 'e' in x.lower()) else int(x) for x in parts]

    Trả về None nếu nhập sai.	    except ValueError:

    """	        print('Các phần tử phải là số.')

    line = input(f'Nhập vector b (các phần tử cách nhau dấu cách){" (độ dài cần là " + str(expected_len) + ")" if expected_len else ""}: ').strip()	        return None

    parts = line.split()

    if expected_len is not None and len(parts) != expected_len:

        print(f'Lỗi: vector cần có {expected_len} phần tử, bạn đã nhập {len(parts)}.')	def augment_matrix(A: List[List[float]], b: List[float]) -> Optional[List[List[float]]]:

        return None	    """Trả về ma trận [A|b] nếu len(A) == len(b), ngược lại trả None."""

    try:	    if len(A) != len(b):

        return [float(x) if ('.' in x or 'e' in x.lower()) else int(x) for x in parts]	        return None

    except ValueError:	    return [row + [val] for row, val in zip(A, b)]

        print('Các phần tử phải là số.')

        return None

	# --- 3 phép biến đổi sơ cấp trên dòng ---

	def swap_rows(A: List[List[float]], i: int, j: int) -> None:

def augment_matrix(A: List[List[float]], b: List[float]) -> Optional[List[List[float]]]:	    A[i], A[j] = A[j], A[i]

    """Trả về ma trận [A|b] nếu len(A) == len(b), ngược lại trả None."""

    if len(A) != len(b):

        return None	def scale_row(A: List[List[float]], i: int, k: float) -> None:

    return [row + [val] for row, val in zip(A, b)]	    A[i] = [k * x for x in A[i]]





# --- 3 phép biến đổi sơ cấp trên dòng ---	def add_multiple_row(A: List[List[float]], src: int, dest: int, k: float) -> None:

def swap_rows(A: List[List[float]], i: int, j: int) -> None:	    A[dest] = [a + k * b for a, b in zip(A[dest], A[src])]

    """Đổi hàng i và j (chỉ số 0-based)."""

    A[i], A[j] = A[j], A[i]

	def bt1_interactive() -> None:

	    print('\n--- BT1: Tạo ma trận bổ sung [A|b] ---')

def scale_row(A: List[List[float]], i: int, k: float) -> None:	    A = input_matrix()

    """Nhân hàng i với hệ số k."""	    if A is None:

    A[i] = [k * x for x in A[i]]	        return

	    b = input_vector(expected_len=len(A))

	    if b is None:

def add_multiple_row(A: List[List[float]], src: int, dest: int, k: float) -> None:	        print('Impossible')

    """Cộng k lần hàng src vào hàng dest: R_dest <- R_dest + k*R_src."""	        return

    A[dest] = [a + k * b for a, b in zip(A[dest], A[src])]	    Ab = augment_matrix(A, b)

	    if Ab is None:

	        print('Impossible')

def bt1_interactive() -> None:	    else:

    """Thực hiện BT1: nhập A và b, kiểm tra và in [A|b] hoặc in 'Impossible'."""	        print('\nMa trận [A|b] =')

    print('\n--- BT1: Tạo ma trận bổ sung [A|b] ---')	        print_matrix(Ab)

    A = input_matrix()

    if A is None:

        return	def bt2_interactive() -> None:

    b = input_vector(expected_len=len(A))	    print('\n--- BT2: 3 phép biến đổi sơ cấp trên dòng ---')

    if b is None:	    A = input_matrix()

        print('Impossible')	    if A is None:

        return	        return

    Ab = augment_matrix(A, b)	    M = deepcopy(A)

    if Ab is None:	    while True:

        print('Impossible')	        print('\nMa trận hiện tại:')

    else:	        print_matrix(M)

        print('\nMa trận [A|b] =')	        print('\nChọn phép biến đổi:')

        print_matrix(Ab)	        print('1. Đổi hai hàng (swap)')

	        print('2. Nhân một hàng với hệ số (scale)')

	        print('3. Cộng k lần hàng này vào hàng khác (Rj <- Rj + k*Ri)')

def bt2_interactive() -> None:	        print('4. Kết thúc')

    """Thực hiện BT2: menu tương tác cho 3 phép biến đổi sơ cấp trên dòng."""	        choice = input('Lựa chọn (1-4): ').strip()

    print('\n--- BT2: 3 phép biến đổi sơ cấp trên dòng ---')	        if choice == '1':

    A = input_matrix()	            try:

    if A is None:	                i = int(input('Hàng i (1-based): ')) - 1

        return	                j = int(input('Hàng j (1-based): ')) - 1

    M = deepcopy(A)	                swap_rows(M, i, j)

    while True:	            except Exception:

        print('\nMa trận hiện tại:')	                print('Lỗi chỉ số. Thử lại.')

        print_matrix(M)	        elif choice == '2':

        print('\nChọn phép biến đổi:')	            try:

        print('1. Đổi hai hàng (swap)')	                i = int(input('Hàng i (1-based): ')) - 1

        print('2. Nhân một hàng với hệ số (scale)')	                k = float(input('Hệ số k: '))

        print('3. Cộng k lần hàng này vào hàng khác (Rj <- Rj + k*Ri)')	                scale_row(M, i, k)

        print('4. Kết thúc')	            except Exception:

        choice = input('Lựa chọn (1-4): ').strip()	                print('Lỗi nhập. Thử lại.')

        if choice == '1':	        elif choice == '3':

            try:	            try:

                i = int(input('Hàng i (1-based): ')) - 1	                src = int(input('Hàng nguồn i (1-based): ')) - 1

                j = int(input('Hàng j (1-based): ')) - 1	                dest = int(input('Hàng đích j (1-based): ')) - 1

                swap_rows(M, i, j)	                k = float(input('Hệ số k: '))

            except Exception:	                add_multiple_row(M, src, dest, k)

                print('Lỗi chỉ số. Thử lại.')	            except Exception:

        elif choice == '2':	                print('Lỗi nhập. Thử lại.')

            try:	        elif choice == '4':

                i = int(input('Hàng i (1-based): ')) - 1	            print('Kết thúc BT2.')

                k = float(input('Hệ số k: '))	            break

                scale_row(M, i, k)	        else:

            except Exception:	            print('Lựa chọn không hợp lệ.')

                print('Lỗi nhập. Thử lại.')

        elif choice == '3':

            try:	def main() -> None:

                src = int(input('Hàng nguồn i (1-based): ')) - 1	    print('Chọn bài (BT1 hoặc BT2):')

                dest = int(input('Hàng đích j (1-based): ')) - 1	    print('1. BT1 - Tạo ma trận [A|b]')

                k = float(input('Hệ số k: '))	    print('2. BT2 - Thực hiện 3 phép biến đổi sơ cấp trên dòng')

                add_multiple_row(M, src, dest, k)	    print('0. Thoát')

            except Exception:	    while True:

                print('Lỗi nhập. Thử lại.')	        cmd = input('Lựa chọn: ').strip()

        elif choice == '4':	        if cmd == '1':

            print('Kết thúc BT2.')	            bt1_interactive()

            break	        elif cmd == '2':

        else:	            bt2_interactive()

            print('Lựa chọn không hợp lệ.')	        elif cmd == '0' or cmd.lower() in ('q', 'quit', 'exit'):

	            print('Thoát chương trình.')

	            break

def main() -> None:	        else:

    print('Chọn bài (BT1 hoặc BT2):')	            print('Lựa chọn không đúng, thử lại.')

    print('1. BT1 - Tạo ma trận [A|b]')

    print('2. BT2 - Thực hiện 3 phép biến đổi sơ cấp trên dòng')

    print('0. Thoát')	if __name__ == '__main__':

    while True:	    main()

        cmd = input('Lựa chọn: ').strip()			elif cmd == '0' or cmd.lower() in ('q', 'quit', 'exit'):

        if cmd == '1':

            bt1_interactive()
        elif cmd == '2':
            bt2_interactive()
        elif cmd == '0' or cmd.lower() in ('q', 'quit', 'exit'):
            print('Thoát chương trình.')
            break
        else:
            print('Lựa chọn không đúng, thử lại.')


if __name__ == '__main__':
    main()
