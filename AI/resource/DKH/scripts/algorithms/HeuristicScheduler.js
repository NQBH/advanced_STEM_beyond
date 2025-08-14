// scripts/algorithms/HeuristicScheduler.js

// Import Heuristics từ scripts/algorithms/heuristics.js
// Import DateUtils từ scripts/utils/dateUtils.js
// Import Task từ scripts/models/Task.js (cần để thao tác trên các đối tượng Task)

/**
 * @class HeuristicScheduler
 * @description Triển khai thuật toán lập lịch heuristic (Greedy) cho các công việc cá nhân.
 */
class HeuristicScheduler {
    /**
     * Lập lịch các công việc dựa trên một heuristic đã chọn.
     * @param {Task[]} tasks - Mảng các đối tượng Task chưa được lên lịch.
     * @param {Function} heuristicFn - Hàm heuristic dùng để đánh giá và sắp xếp công việc.
     * Hàm này nhận một Task và trả về một số.
     * Giá trị trả về càng CAO thì công việc càng được ưu tiên.
     * @param {Date} [initialStartTime=new Date()] - Thời gian bắt đầu lịch trình.
     * @returns {Task[]} Mảng các đối tượng Task đã được lên lịch, sắp xếp theo thời gian bắt đầu.
     */
    scheduleTasks(tasks, heuristicFn, initialStartTime = new Date()) {
        // Tạo một bản sao sâu của mảng tasks để không làm thay đổi mảng gốc
        // Quan trọng: Phải sao chép đối tượng Task, không chỉ tham chiếu.
        const allTasks = tasks.map(task => Task.fromObject(task.toObject()));
        
        // Danh sách các công việc đã được lên lịch
        const scheduledTasks = [];
        // Danh sách các công việc chưa được lên lịch
        let pendingTasks = [...allTasks];
        
        // Map để dễ dàng tra cứu công việc theo ID
        const taskMap = new Map(allTasks.map(task => [task.id, task]));

        // Lập lịch cho đến khi không còn công việc nào hoặc không thể lập lịch được nữa
        while (pendingTasks.length > 0) {
            let bestTaskToSchedule = null;
            let bestHeuristicValue = -Infinity; // Tìm công việc có heuristic cao nhất
            let bestPossibleStartTime = null;

            // Lọc ra các công việc có thể được xem xét ở bước này
            // Một công việc có thể xem xét nếu:
            // 1. Tất cả các công việc phụ thuộc của nó đã được lên lịch.
            // 2. Chưa được lên lịch.
            const schedulableTasks = pendingTasks.filter(task => {
                const allDependenciesMet = task.dependencies.every(depId => {
                    const dependentTask = taskMap.get(depId);
                    return dependentTask && dependentTask.isScheduled();
                });
                return allDependenciesMet;
            });

            if (schedulableTasks.length === 0 && pendingTasks.length > 0) {
                // Không có công việc nào có thể lên lịch, nhưng vẫn còn công việc chờ => Bế tắc do phụ thuộc không thể giải quyết
                console.warn("Không thể lập lịch tất cả công việc do các ràng buộc phụ thuộc không thể giải quyết.");
                break;
            }

            // Tìm công việc tốt nhất trong số các công việc có thể lên lịch
            for (const task of schedulableTasks) {
                // Xác định thời gian sớm nhất mà công việc này có thể bắt đầu
                let potentialStartTime = initialStartTime;

                // 1. Phụ thuộc thời gian: sau khi tất cả các công việc phụ thuộc hoàn thành
                task.dependencies.forEach(depId => {
                    const dependentTask = taskMap.get(depId);
                    if (dependentTask && dependentTask.actualEndTime) {
                        if (dependentTask.actualEndTime.getTime() > potentialStartTime.getTime()) {
                            potentialStartTime = dependentTask.actualEndTime;
                        }
                    }
                });

                // 2. Ràng buộc earliestStartTime của chính công việc đó
                if (task.earliestStartTime && task.earliestStartTime.getTime() > potentialStartTime.getTime()) {
                    potentialStartTime = task.earliestStartTime;
                }

                // 3. Đảm bảo không trùng với các công việc đã lên lịch
                // Vòng lặp này sẽ tìm khoảng trống sau các công việc đã lên lịch
                let currentConsideredStartTime = potentialStartTime;
                let foundSlot = false;
                while(!foundSlot) {
                    foundSlot = true;
                    for (const sTask of scheduledTasks) {
                        const sTaskEnd = sTask.actualEndTime;
                        const sTaskStart = sTask.actualStartTime;

                        // Kiểm tra nếu có sự chồng chéo với công việc đã lên lịch sTask
                        // Công việc mới (task) sẽ kết thúc SAU khi sTask bắt đầu
                        // VÀ công việc mới (task) sẽ bắt đầu TRƯỚC khi sTask kết thúc
                        if (DateUtils.addMinutes(currentConsideredStartTime, task.duration).getTime() > sTaskStart.getTime() &&
                            currentConsideredStartTime.getTime() < sTaskEnd.getTime()) {
                            // Bị trùng lặp, đẩy thời gian bắt đầu lên sau khi sTask kết thúc
                            currentConsideredStartTime = sTaskEnd;
                            foundSlot = false; // Phải kiểm tra lại với tất cả các scheduledTasks
                            break; // Thoát vòng lặp for (sTask) để kiểm tra lại từ đầu
                        }
                    }
                    if (!foundSlot) {
                        // Nếu bị đẩy thời gian, cần đảm bảo không vượt quá latestFinishTime của task đang xét
                        if (task.latestFinishTime && currentConsideredStartTime.getTime() > task.latestFinishTime.getTime()) {
                            foundSlot = false; // Không thể xếp task này trong ràng buộc thời gian của nó
                            break; // Thoát vòng lặp while, không thể xếp task này
                        }
                        // Thêm một khoảng nhỏ để tránh vòng lặp vô hạn nếu có các công việc rất nhỏ
                        currentConsideredStartTime = DateUtils.addMinutes(currentConsideredStartTime, 1); // Đẩy thêm 1 phút để tránh lỗi
                    }
                }
                
                // Nếu không tìm được slot hợp lệ trong ràng buộc latestFinishTime, bỏ qua task này
                if (!foundSlot) {
                    continue; 
                }

                const currentHeuristicValue = heuristicFn(task);

                // Ưu tiên các công việc có heuristic cao hơn.
                // Nếu heuristic bằng nhau, ưu tiên công việc có thời gian bắt đầu sớm hơn (để tối ưu khoảng trống).
                if (currentHeuristicValue > bestHeuristicValue ||
                    (currentHeuristicValue === bestHeuristicValue && 
                     (bestPossibleStartTime === null || currentConsideredStartTime.getTime() < bestPossibleStartTime.getTime()))) {
                    bestHeuristicValue = currentHeuristicValue;
                    bestTaskToSchedule = task;
                    bestPossibleStartTime = currentConsideredStartTime;
                }
            }

            if (bestTaskToSchedule) {
                // Đảm bảo bestPossibleStartTime là Date object hợp lệ
                if (!Validation.isValidDate(bestPossibleStartTime)) {
                    console.error("Lỗi: bestPossibleStartTime không phải là Date hợp lệ cho task", bestTaskToSchedule.id, bestPossibleStartTime);
                    // Có thể skip task này hoặc xử lý lỗi khác
                    continue; // Bỏ qua công việc này nếu thời gian không hợp lệ
                }
                // Lên lịch cho công việc tốt nhất
                bestTaskToSchedule.setSchedule(bestPossibleStartTime);
                scheduledTasks.push(bestTaskToSchedule);
                pendingTasks = pendingTasks.filter(task => task.id !== bestTaskToSchedule.id);
            } else {
                // Không tìm thấy công việc nào có thể lên lịch ở bước này
                // Điều này có thể xảy ra nếu không có công việc nào thỏa mãn ràng buộc
                // hoặc vòng lặp `while(!foundSlot)` không tìm thấy vị trí.
                console.warn("Không thể tìm thấy công việc nào để lên lịch trong bước hiện tại.");
                break;
            }
        }

        // Sắp xếp các công việc đã lên lịch theo thời gian bắt đầu
        scheduledTasks.sort((a, b) => a.actualStartTime.getTime() - b.actualStartTime.getTime());

        // Kiểm tra các công việc còn lại chưa được lên lịch (nếu có)
        if (pendingTasks.length > 0) {
            console.warn(`Có ${pendingTasks.length} công việc chưa được lên lịch.`);
        }
        
        return scheduledTasks;
    }
}