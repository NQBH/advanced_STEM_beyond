import re

def calculate_score(input_text):
    total_score = 0
    breakdown = {}
    sections = re.split(r'\\item\s+', input_text)
    sections = [s.strip() for s in sections if s.strip()]

    for section in sections:
        section_lower = section.lower()
        numbers = re.findall(r'[+-]?\d+(?:\.\d+)?', section)

        if section_lower.startswith('absence'):
            score = -sum(abs(float(num)) for num in numbers)
            total_score += score
            breakdown['Absence'] = f"{numbers} => {score}"

        elif section_lower.startswith('early attendance'):
            score = sum(float(num) for num in numbers)
            total_score += score
            breakdown['Early Attendance'] = f"{numbers} => +{score}"

        elif section_lower.startswith('bonus'):
            score = sum(float(num) for num in numbers)
            total_score += score
            breakdown['Bonus'] = f"{numbers} => +{score}"

        elif section_lower.startswith('late'):
            total_minutes = sum(int(num) for num in numbers)
            if total_minutes < 30:
                late_penalty = 0
            else:
                late_penalty = -((total_minutes // 30) * 0.25)
            total_score += late_penalty
            breakdown['Late'] = f"{numbers} => {total_minutes} mins => {late_penalty}"

    return total_score, breakdown

def process_input():
    print("\n" + "=" * 50)
    print("NHẬP ĐIỂM (\\begin{itemize} ... \end{itemize}):")
    #Bonus xóa hết những số không phải điểm
    #Ex9.cpp -> Ex.cpp / xóa, Prob. 1 -> Prob. / xóa
    #(Pascal, làm được cho ($sum_{i=1}^m a_i)^n$ nhiều điểm hơn) -> xóa
    lines = []
    while True:
        line = input()
        if line.strip() == '\end{itemize}':
            break
        lines.append(line)
    input_text = '\n'.join(lines)
    score, breakdown = calculate_score(input_text)
    print("\n=== KẾT QUẢ ===")
    print(f"Tổng điểm: {score}")
    print("\n=== CHI TIẾT ===")
    for category, detail in breakdown.items():
        print(f"{category}: {detail}")

process_input()