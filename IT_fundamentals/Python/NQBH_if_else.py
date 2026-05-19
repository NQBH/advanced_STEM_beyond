# VD1: Phân loại học sinh
grade = float(input()) # Nhập điểm học sinh  vào

## Bắt đầu phân loại
if (grade >= 9):
	print("HS xuất sắc")
elif (8 <= grade <= 8.9):
	print("HS giỏi")
elif (6.5 <= grade <= 7.9):
	print("HS khá")
elif (5 <= grade <= 6.4):
	print("HS khá")
else:
	print("HS yếu")

# Phân loại số âm vs. số dương
a = float(input())
phan_loai_am_duong = "không âm" if a >= 0 else "số âm"
print(phan_loai_am_duong)