t = int(input()) # number of test cases
for _ in range(t):
  m, r, n = map(float, input().split())
  n = int(n)
  tien = 0
  for i in range(1, n+1):
    tien = (tien + m) * (1+ r/100)
    print(f"Năm {i}: {tien:,.0f} đồng")
  print("--------------------------")
