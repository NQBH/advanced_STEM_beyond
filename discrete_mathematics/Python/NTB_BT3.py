x = int(input("Nhap x: "))
y = int(input("Nhap y: "))
z = int(input("Nhap z: "))

# P: x + 1 = 2
P = (x + 1 == 2)
# Q: x + y = z
Q = (x + y == z)

#gia tri logic
Q_and_P = P and Q
P_or_Q = P or Q
not_P = not P
not_Q = not Q
P_xor_Q = (P != Q)

#xuat
print (f"P (x + 1 = 2) : {P}")
print (f"Q (x + y = z) : {Q}")
print (f"P and Q: {P_and_Q}")
print (f"P or Q: {P_or_Q}")
print (f"negative Q: {not_P}")
print (f"negative Q: {not_Q}")
print (f"exclusive or của P và Q: {(P_xor_Q)}")