from collections import deque

def is_prime(n):
    if n < 2: return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def generate_primes():
    return {i for i in range(1000, 10000) if is_prime(i)}

def neighbors(num, primes):
    result = []
    num = str(num)
    for i in range(4):
        for d in '0123456789':
            if d != num[i]:
                new_num = num[:i] + d + num[i+1:]
                if new_num[0] != '0' and int(new_num) in primes:
                    result.append(int(new_num))
    return result

def prime_path(start, end, primes):
    visited = set()
    queue = deque([(start, 0)])
    visited.add(start)

    while queue:
        current, steps = queue.popleft()
        if current == end:
            return steps
        for neighbor in neighbors(current, primes):
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append((neighbor, steps + 1))
    return "impossible"

def main():
    try:
        start = int(input("Nhập số bắt đầu (4 chữ số, nguyên tố): "))
        end = int(input("Nhập số kết thúc (4 chữ số, nguyên tố): "))
    except ValueError:
        print("Bạn phải nhập số nguyên!")
        return

    primes = generate_primes()
    if start not in primes or end not in primes:
        print("Số bạn nhập không phải là số nguyên tố.")
        return

    result = prime_path(start, end, primes)
    print(f"Kết quả: {result}")

if __name__ == "__main__":
    main()