def count_subsets(n):
    return 2 ** n

if __name__ == "__main__":
    n = int(input("Nhap n: "))
    print(f"So tap con cua tap [1..{n}] la: {count_subsets(n)}")
