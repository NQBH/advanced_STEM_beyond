for _ in range(int(input())):
    l, r = map(int, input().split())
	
	def f(x):
        res = 0
        ps = [2, 3, 5, 7]
        for mask in range(16):
        	m = 1
        	sg = 1
        	for i in range(4):
        		if (mask >> i) & 1:
        			m *= ps[i]
        			sg = -sg
        	res += sg * (x // m)
        return res
    print(f(r) - f(l - 1))