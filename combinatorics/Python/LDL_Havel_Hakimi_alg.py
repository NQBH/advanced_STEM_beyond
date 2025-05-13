def havel_hakimi(sequence):
    while True:
        sequence = [d for d in sequence if d != 0]

        if not sequence:
            return True

        # Sort in non-increasing order
        sequence.sort(reverse=True)
        d = sequence.pop(0)

        if d > len(sequence):
            return False

        # Subtract 1 from the next d elements
        for i in range(d):
            sequence[i] -= 1
            if sequence[i] < 0:
                return False
            
        print(f"After processing: {sequence}, removed: {d}")

def main():
    t = int(input("Enter number of test cases: "))
    for _ in range(t):
        n = int(input("Enter number of members: "))
        sequence = list(map(int, input(f"Enter {n} degree values: ").split()))
        if havel_hakimi(sequence):
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()