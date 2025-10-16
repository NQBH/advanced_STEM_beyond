Python 3.13.7 (tags/v3.13.7:bcee1c3, Aug 14 2025, 14:15:11) [MSC v.1944 64 bit (AMD64)] on win32
Enter "help" below or click "Help" above for more information.
>>> x=float(input(" Nhập giá trị x: "))
 Nhập giá trị x: 2
>>> y=float(input(" Nhập giá trị y: "))
 Nhập giá trị y: 3
>>> z=float(input(" Nhập giá trị z: "))
 Nhập giá trị z: 5
>>> p= (x + 1 == 2)
>>> q= (x + y == z)
>>> menhdegoc=(not p) or q
>>> menhdedao=(not q) or p
>>> menhdephandao=p or (not q)
>>> menhdenghichdao=q or (not p)
>>> print(f" Mệnh đề gốc: {menhdegoc}")
 Mệnh đề gốc: True
>>> print(f" Mệnh đề đảo: {menhdedao}")
 Mệnh đề đảo: False
>>> print(f" Mệnh đề phản đảo: {menhdephandao}")
 Mệnh đề phản đảo: False
>>> print(f" Mệnh đề nghịch đảo: {menhdenghichdao}")
 Mệnh đề nghịch đảo: True
