#B4
def decimal_to_roman(num):
    val = [
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4,
        1
    ]
    syb = [
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I"
    ]
    roman_num = ''
    i = 0
    while num > 0:
        while num >= val[i]:
            roman_num += syb[i]
            num -= val[i]
        i += 1
    return roman_num

n = int(input("Nhập số nguyên dương: "))
if n > 0:
    print("Số La Mã tương ứng là:", decimal_to_roman(n))
else:
    print("Vui lòng nhập số nguyên dương!")

#bai 4
number = int(input("Nhập số nguyên dương cần đổi sang La Mã: "))
roman = ""
values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
i = 0

while number > 0:
    if number >= values[i]:
        roman = roman + symbols[i]
        number = number - values[i]
    else:
        i = i + 1

print("Số La Mã tương ứng là:", roman)

#bai4
n=int(input())
def RNum(n):
    a = ""
    while n > 0:
        if n >= 1000: a += "M"; n -= 1000
        elif n >= 900: a += "CM"; n -= 900
        elif n >= 500: a += "D"; n -= 500
        elif n >= 400: a += "CD"; n -= 400
        elif n >= 100: a += "C"; n -= 100
        elif n >= 90: a += "XC"; n -= 90
        elif n >= 50: a += "L"; n -= 50
        elif n >= 40: a += "XL"; n -= 40
        elif n >= 10: a += "X"; n -= 10
        elif n >= 9: a += "IX"; n -= 9
        elif n >= 5: a += "V"; n -= 5
        elif n >= 4: a += "IV"; n -= 4
        else: a += "I"; n -= 1
    print(a)
RNum(n)

#bai4
def doi_sang_la_ma(so):
    bang = [
        (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
        (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
        (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")]
    ket_qua = ""
    while so > 0:
        for gia_tri, ky_hieu in bang:
            if so >= gia_tri:
                ket_qua += ky_hieu
                so -= gia_tri
                break
    return ket_qua
n = int(input("Nhập số nguyên dương: "))
chuoi_la_ma = doi_sang_la_ma(n)
print("Số La Mã tương ứng là:", chuoi_la_ma)

#Bai 4
num = int(input("Nhập số nguyên dương: "))
roman = ""
while num > 0:
    if num >= 1000:
        roman += "M"
        num -= 1000
    elif num >= 900:
        roman += "CM"
        num -= 900
    elif num >= 500:
        roman += "D"
        num -= 500
    elif num >= 400:
        roman += "CD"
        num -= 400
    elif num >= 100:
        roman += "C"
        num -= 100
    elif num >= 90:
        roman += "XC"
        num -= 90
    elif num >= 50:
        roman += "L"
        num -= 50
    elif num >= 40:
        roman += "XL"
        num -= 40
    elif num >= 10:
        roman += "X"
        num -= 10
    elif num == 9:
        roman += "IX"
        num -= 9
    elif num >= 5:
        roman += "V"
        num -= 5
    elif num == 4:
        roman += "IV"
        num -= 4
    else:
        roman += "I"
        num -= 1
print("Số La Mã tương ứng là:", roman)

num = int(input("Nhập số: "))
roman = ""

while num > 0:
    if num >= 1000: roman += "M"; num -= 1000
    elif num >= 900: roman += "CM"; num -= 900
    elif num >= 500: roman += "D"; num -= 500
    elif num >= 400: roman += "CD"; num -= 400
    elif num >= 100: roman += "C"; num -= 100
    elif num >= 90: roman += "XC"; num -= 90
    elif num >= 50: roman += "L"; num -= 50
    elif num >= 40: roman += "XL"; num -= 40
    elif num >= 10: roman += "X"; num -= 10
    elif num >= 9: roman += "IX"; num -= 9
    elif num >= 5: roman += "V"; num -= 5
    elif num >= 4: roman += "IV"; num -= 4
    else: roman += "I"; num -= 1

print("Số La Mã:", roman)

n = int(input("Nhập số: "))
roman = ""

while n > 0:
    if n >= 1000: roman += "M"; n -= 1000
    elif n >= 900: roman += "CM"; n -= 900
    elif n >= 500: roman += "D"; n -= 500
    elif n >= 400: roman += "CD"; n -= 400
    elif n >= 100: roman += "C"; n -= 100
    elif n >= 90: roman += "XC"; n -= 90
    elif n >= 50: roman += "L"; n -= 50
    elif n >= 40: roman += "XL"; n -= 40
    elif n >= 10: roman += "X"; n -= 10
    elif n >= 9: roman += "IX"; n -= 9
    elif n >= 5: roman += "V"; n -= 5
    elif n >= 4: roman += "IV"; n -= 4
    else: roman += "I"; n -= 1

print("La Mã:", roman)

#BAI4
def convert_to_roman_simple(num):
    roman_map = [
        (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
        (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
        (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')
    ]

    roman_numeral = "" 
    
    for value, symbol in roman_map:
        while num >= value:
            roman_numeral += symbol 
            num -= value          
    
    return roman_numeral

decimal_num_input = int(input("Nhập một số nguyên dương: "))

roman_result = convert_to_roman_simple(decimal_num_input)
print(f"Số La Mã tương ứng: {roman_result}")

num = int(input("Nhập số nguyên dương: "))

so_la_ma = [
    (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
    (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
    (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")
]

ket_qua = ""
i = 0

while num > 0:
    gia_tri, ky_hieu = so_la_ma[i]
    if num >= gia_tri:
        ket_qua += ky_hieu
        num -= gia_tri
    else:
        i += 1

print("Số La Mã là:", ket_qua)

#Bai4                                                                                                                                                                                                       n = int(input("Nhập số: "))
roman = ""

while n > 0:
    if n >= 1000: roman += "M"; n -= 1000
    elif n >= 900: roman += "CM"; n -= 900
    elif n >= 500: roman += "D"; n -= 500
    elif n >= 400: roman += "CD"; n -= 400
    elif n >= 100: roman += "C"; n -= 100
    elif n >= 90: roman += "XC"; n -= 90
    elif n >= 50: roman += "L"; n -= 50
    elif n >= 40: roman += "XL"; n -= 40
    elif n >= 10: roman += "X"; n -= 10
    elif n >= 9: roman += "IX"; n -= 9
    elif n >= 5: roman += "V"; n -= 5
    elif n >= 4: roman += "IV"; n -= 4
    else: roman += "I"; n -= 1

print("Số La Mã cần tìm:", roman)

num = int(input("Nhập số nguyên dương cần đổi sang số La Mã: "))
roman_numerals = [
    (1000, "M"),
    (900, "CM"),
    (500, "D"),
    (400, "CD"),
    (100, "C"),
    (90, "XC"),
    (50, "L"),
    (40, "XL"),
    (10, "X"),
    (9, "IX"),
    (5, "V"),
    (4, "IV"),
    (1, "I")
]

result = ""
i = 0  # Chỉ số để duyệt danh sách các cặp

while num > 0:
    if num >= roman_numerals[i][0]:
        num -= roman_numerals[i][0]
        result += roman_numerals[i][1]
    else:
        i += 1

print("Số La Mã tương ứng là:", result)

num = int(input("Nhập số nguyên dương: "))
roman = ""
val = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
sym = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
i = 0
while num > 0:
    if num >= val[i]:
        roman += sym[i]
        num -= val[i]
    else:
        i += 1
print("Số La Mã là:", roman)