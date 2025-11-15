for _ in range(int(input())):
    s = input()
    for i in range(len(s) - 1):
        if s[i] != '<' and s[i + 1] != '>':
            print(-1)
            break
    else:
        print(len(s) - min(s.count('<'), s.count('>')))