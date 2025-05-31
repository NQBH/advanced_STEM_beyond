t = [] # 2D array of times t_{ij}
m, n = map(int, input().split())
for i in range(m):
	row = [int(x) for x in input().split()]
	t.append(row)

current_sum_working_time = [0] * m
roster = [0] * n # machine with roster[i] take ith work

for j in range(n):
	current_sum_working_time_min = current_sum_working_time[0] + t[0][j]
	for i in range(1, m):
		tmp = current_sum_working_time[i] + t[i][j]
		if tmp < current_sum_working_time_min:
			current_sum_working_time_min = tmp
			roster[j] = i
		print("roster[j] = ", roster[j])
	current_sum_working_time[roster[j]] += t[roster[j]][j]
	print(current_sum_working_time)
print(roster)