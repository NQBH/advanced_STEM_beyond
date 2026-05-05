# dấu này để chú thích code: tự do gõ theo ý cá nhân
print("I love UMT") # chuỗi được in ra phải nằm trong dấu " " hoặc ' '

# cách 2
slogan = "I love UMT" # slogan là 1 biến dạng chuỗi ký tự (string)
print(slogan) # in ra giá trị của biến chuỗi slogan

# xử lý tuổi
age = 18 # SV Khoa Kinh Doanh đang 18 tuổi, age là biến số (variable)
print("I am ", age, "years old this year")

# Mẫu: Bài toán mô phỏng nhân viên Business Analytics deal hợp đồng với khách hàng
print("Nhập tuổi của bạn")
age = input() # Nhập tuổi ở đây. Hàm input là hàm nhập tuổi

print("Giới tính của Khách hàng?")
gender = input() # Nhập giới tính vào: là 1 chuỗi ký tự, e.g., "Male"

print("Khách hàng chịu chi bao nhiêu?")
money_client = int(input()) # Nhập tiền mà khách hàng muốn trả, int() để ép kiểu chuỗi thành số nguyên

# Cấu trúc rẽ nhánh: Bài toán đưa ra quyết định
if (money_client >= 100):
	print("OK em sẽ làm. Em sẽ báo cáo với sếp em.")
else: # Khách hàng quá keo kiệt
	print("Số tiền không phù hợp với lượng công việc. Nên em xin từ chối")