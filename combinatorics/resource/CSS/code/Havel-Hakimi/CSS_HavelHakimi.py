def is_graphical_sequence(n, sequence):
    if any(d < 0 for d in sequence):
        return "0"
    if sum(sequence) % 2 != 0:
        return "0"
    seq = sorted(sequence, reverse=True)
    
    while seq and seq[0] > 0:
        d = seq[0]  
        seq = seq[1:] 
        
        if d > len(seq):
            return "0"
        for i in range(d):
            seq[i] -= 1
        
        if any(x < 0 for x in seq):
            return "0"
        seq = sorted(seq, reverse=True)

    if all(x == 0 for x in seq):
        return "1"
    return " ".join(map(str, seq))

def main():
    t = int(input())  
    results = []
    
    for _ in range(t):
        n = int(input())  
        sequence = list(map(int, input().split()))  
        results.append(is_graphical_sequence(n, sequence))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()