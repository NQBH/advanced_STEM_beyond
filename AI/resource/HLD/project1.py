import heapq
from collections import defaultdict
from datetime import datetime, timedelta

class Task:
    def __init__(self, name, duration, priority, deadline, dependencies=None):
        self.name = name
        self.duration = duration  # Giờ
        self.priority = priority
        self.deadline = deadline  # datetime
        self.dependencies = dependencies if dependencies else []

def parse_time(time_str):
    """Chuyển chuỗi thời gian định dạng HH:MM thành số giờ dạng float."""
    try:
        hours, minutes = map(int, time_str.split(':'))
        if not (0 <= hours <= 23 and 0 <= minutes <= 59):
            raise ValueError("Giờ hoặc phút không hợp lệ")
        return hours + minutes / 60.0
    except ValueError:
        raise ValueError("Giờ phải có định dạng HH:MM (ví dụ: 08:00)")

def parse_datetime(date_str):
    """Chuyển chuỗi ngày giờ định dạng YYYY-MM-DD HH:MM thành datetime."""
    try:
        return datetime.strptime(date_str, "%Y-%m-%d %H:%M")
    except ValueError:
        raise ValueError("Ngày giờ phải có định dạng YYYY-MM-DD HH:MM (ví dụ: 2025-07-13 23:59)")

def get_user_input():
    """Thu thập công việc, công việc cố định và ngày từ người dùng."""
    tasks = []
    fixed_tasks = defaultdict(list)
    print("Nhập khung giờ làm việc mỗi ngày (bắt đầu và kết thúc, ví dụ: 05:00 22:30):")
    while True:
        try:
            user_input = input("Khung giờ (hoặc nhấn Enter để dùng mặc định 05:00-22:30): ").strip()
            if not user_input:
                work_hours = (5.0, 22.5)
                break
            start_time, end_time = user_input.split()
            work_hours = (parse_time(start_time), parse_time(end_time))
            if work_hours[0] >= work_hours[1]:
                raise ValueError("Giờ kết thúc phải muộn hơn giờ bắt đầu")
            break
        except ValueError as e:
            print(f"Lỗi: {e}. Vui lòng nhập lại.")

    print("\nNhập các ngày cần lập lịch (định dạng YYYY-MM-DD, mỗi ngày một dòng, nhấn Enter để kết thúc):")
    days = []
    while True:
        day_str = input("Ngày: ").strip()
        if not day_str:
            break
        try:
            day = datetime.strptime(day_str, "%Y-%m-%d")
            days.append(day)
        except ValueError:
            print("Ngày không đúng định dạng YYYY-MM-DD (ví dụ: 2025-07-13). Vui lòng nhập lại.")

    if not days:
        print("Không nhập ngày nào. Sẽ dùng 3 ngày tiếp theo từ hôm nay.")
        today = datetime.now().replace(hour=0, minute=0, second=0, microsecond=0)
        days = [today + timedelta(days=i) for i in range(3)]

    for day in days:
        print(f"\nNhập các công việc cố định cho ngày {day.strftime('%Y-%m-%d')} (tên, giờ bắt đầu, giờ kết thúc; nhấn Enter để kết thúc):")
        print("Ví dụ: Đi làm 08:00 12:00")
        while True:
            task_input = input("Công việc cố định: ").strip()
            if not task_input:
                break
            try:
                parts = task_input.split()
                if len(parts) < 3:
                    raise ValueError("Phải nhập tên công việc, giờ bắt đầu và giờ kết thúc")
                name = ' '.join(parts[:-2])
                start, end = parse_time(parts[-2]), parse_time(parts[-1])
                if start >= end:
                    raise ValueError("Giờ kết thúc phải muộn hơn giờ bắt đầu")
                fixed_tasks[day].append((name, start, end))
            except ValueError as e:
                print(f"Lỗi: {e}. Vui lòng nhập lại.")

    print("\nNhập các công việc cần sắp xếp (tên, thời lượng (giờ), độ ưu tiên, thời hạn, công việc phụ thuộc; nhấn Enter để kết thúc):")
    print("Ví dụ: Đọc sách 0.5 3 2025-07-13 23:59")
    print("Hoặc với phụ thuộc: Học bài 2.0 4 2025-07-14 23:59 Đọc sách")
    task_names = set()
    while True:
        task_input = input("Công việc: ").strip()
        if not task_input:
            break
        try:
            parts = task_input.split()
            if len(parts) < 4:
                raise ValueError("Phải nhập tên, thời lượng (số thập phân), độ ưu tiên (số nguyên), thời hạn (YYYY-MM-DD HH:MM)")
            name = ' '.join(parts[:-4]) if len(parts) <= 4 else ' '.join(parts[:-4]).rsplit(',', 1)[0]
            if not name:
                raise ValueError("Tên công việc không được để trống")
            if name in task_names:
                raise ValueError("Tên công việc phải duy nhất")
            duration = float(parts[-4])
            if duration <= 0:
                raise ValueError("Thời lượng phải lớn hơn 0")
            priority = int(parts[-3])
            if priority < 0:
                raise ValueError("Độ ưu tiên phải là số không âm")
            deadline = parse_datetime(f"{parts[-2]} {parts[-1]}")
            dependencies = []
            if len(parts) > 4 and ',' in ' '.join(parts[:-4]):
                dependencies = ' '.join(parts[:-4]).rsplit(',', 1)[-1].split(',')
                dependencies = [dep.strip() for dep in dependencies if dep.strip()]
            tasks.append(Task(name, duration, priority, deadline, dependencies))
            task_names.add(name)
        except ValueError as e:
            print(f"Lỗi: {e}. Vui lòng nhập lại.")

    return tasks, fixed_tasks, days, work_hours

def adjust_priority(tasks, current_date):
    """Điều chỉnh độ ưu tiên dựa trên độ trễ."""
    for task in tasks:
        if current_date > task.deadline:
            days_late = (current_date - task.deadline).days
            task.priority += days_late

def schedule_tasks(tasks, fixed_tasks, days, work_hours):
    """Sắp xếp công việc qua nhiều ngày bằng thuật toán Greedy và Local Search."""
    task_map = {task.name: task for task in tasks}
    schedule = {day: [] for day in days}
    remaining_tasks = tasks.copy()
    
    gaps_per_day = {}
    for day in days:
        day_gaps = []
        fixed = [(start, end) for name, start, end in fixed_tasks[day]]
        fixed.sort()
        last_end = work_hours[0]
        for start, end in fixed + [(work_hours[1], work_hours[1])]:
            if start > last_end:
                day_gaps.append((last_end, start))
            last_end = max(last_end, end)
        gaps_per_day[day] = day_gaps
    
    for day in days:
        adjust_priority(remaining_tasks, day)
        graph = defaultdict(list)
        in_degree = defaultdict(int)
        for task in remaining_tasks:
            for dep in task.dependencies:
                if dep in task_map:
                    graph[dep].append(task.name)
                    in_degree[task.name] += 1
        
        available_tasks = [(-task.priority, task.name) for task in remaining_tasks if in_degree.get(task.name, 0) == 0]
        heapq.heapify(available_tasks)
        
        for gap_start, gap_end in gaps_per_day[day]:
            current_time = gap_start
            while available_tasks and current_time < gap_end:
                priority, task_name = heapq.heappop(available_tasks)
                task = task_map[task_name]
                
                duration = min(task.duration, gap_end - current_time)
                if duration > 0:
                    schedule[day].append((task_name, current_time, current_time + duration))
                    task.duration -= duration
                    current_time += duration
                    
                    if task.duration <= 0:
                        remaining_tasks.remove(task)
                        for next_task in graph[task_name]:
                            in_degree[next_task] -= 1
                            if in_degree[next_task] == 0 and task_map[next_task] in remaining_tasks:
                                heapq.heappush(available_tasks, (-task_map[next_task].priority, next_task))
                    else:
                        heapq.heappush(available_tasks, (-task.priority, task_name))
    
    for day in days:
        if len(schedule[day]) > 1:
            best_schedule = schedule[day].copy()
            best_score = sum(task_map[task].priority for task, _, _ in best_schedule)
            for i in range(len(schedule[day])):
                for j in range(i + 1, len(schedule[day])):
                    new_schedule = schedule[day].copy()
                    new_schedule[i], new_schedule[j] = new_schedule[j], new_schedule[i]
                    valid = True
                    last_end = gaps_per_day[day][0][0]
                    for task, start, end in sorted(new_schedule, key=lambda x: x[1]):
                        if start < last_end or task_map[task].duration > (end - start):
                            valid = False
                            break
                        last_end = end
                    if valid:
                        score = sum(task_map[task].priority for task, _, _ in new_schedule)
                        if score > best_score:
                            best_score = score
                            best_schedule = new_schedule
            schedule[day] = best_schedule
    
    return schedule, remaining_tasks

def print_schedule(schedule, fixed_tasks):
    """In lịch trình."""
    for day in schedule:
        print(f"\nNgày {day.strftime('%Y-%m-%d')}:")
        all_tasks = fixed_tasks[day] + schedule[day]
        for task_name, start, end in sorted(all_tasks, key=lambda x: x[1]):
            start_str = f"{int(start)}:{int((start % 1) * 60):02d}"
            end_str = f"{int(end)}:{int((end % 1) * 60):02d}"
            print(f"{task_name}: {start_str} - {end_str}")

if __name__ == "__main__":
    tasks, fixed_tasks, days, work_hours = get_user_input()
    schedule, remaining = schedule_tasks(tasks, fixed_tasks, days, work_hours)
    print_schedule(schedule, fixed_tasks)
    if remaining:
        print("\nCông việc chưa được xếp lịch:", [task.name for task in remaining])