t = int(input())
for _ in range(t):
    n = int(input())

    array = list(map(int, input().split()))
    dem_1 = array.count(1)
    dem_2 = array.count(2)

    if (dem_1 % 2 == 0):
        if dem_1 == 0:
            if (dem_2 % 2 == 0):
                print('Yes')
            else: 
                print('No')
        elif (dem_1 != 0): 
            print('Yes')
        else:
            print('No')
    else:
      print('No')