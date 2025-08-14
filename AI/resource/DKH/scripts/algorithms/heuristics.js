// scripts/algorithms/heuristics.js

/**
 * @namespace Heuristics
 * @description Tập hợp các hàm heuristic để đánh giá công việc trong quá trình lập lịch.
 */
const Heuristics = {
    /**
     * Heuristic dựa trên mức độ ưu tiên. Ưu tiên cao hơn sẽ có giá trị "tốt" hơn.
     * Khi sắp xếp, chúng ta muốn giá trị heuristic cao hơn được chọn trước.
     * @param {Task} task - Đối tượng công việc.
     * @returns {number} Giá trị heuristic (cao hơn là tốt hơn).
     */
    byPriority: (task) => {
        return task.priority; // Ưu tiên 5 là cao nhất, 1 là thấp nhất
    },

    /**
     * Heuristic dựa trên thời lượng công việc (Shortest Job First - SJF).
     * Công việc có thời lượng ngắn hơn sẽ có giá trị "tốt" hơn (hoặc chi phí thấp hơn).
     * Khi sắp xếp, chúng ta muốn giá trị heuristic thấp hơn được chọn trước.
     * @param {Task} task - Đối tượng công việc.
     * @returns {number} Giá trị heuristic (thấp hơn là tốt hơn).
     */
    byDuration: (task) => {
        return task.duration;
    },

    /**
     * Heuristic kết hợp ưu tiên và thời lượng.
     * Có thể điều chỉnh trọng số để ưu tiên yếu tố nào hơn.
     * Ví dụ: priorityFactor càng cao, càng ưu tiên công việc quan trọng.
     * durationFactor càng cao, càng ưu tiên công việc ngắn.
     * Đối với thuật toán Greedy (tìm giá trị tốt nhất), giá trị cao hơn là tốt hơn.
     * Để ưu tiên công việc ngắn, chúng ta cần nhân với -1 hoặc trừ đi giá trị nào đó.
     * Công thức: (priority * priorityFactor) - (duration * durationFactor)
     * @param {Task} task - Đối tượng công việc.
     * @param {object} [factors={priority: 1, duration: 0.1}] - Các trọng số cho heuristic.
     * @returns {number} Giá trị heuristic kết hợp (cao hơn là tốt hơn).
     */
    combined: (task, factors = { priority: 1, duration: 0.1 }) => {
        // Mức độ ưu tiên cao sẽ tăng điểm.
        // Thời lượng ngắn sẽ tăng điểm (bằng cách trừ đi một giá trị nhỏ hơn).
        return (task.priority * factors.priority) - (task.duration * factors.duration);
    },

    /**
     * Heuristic để ưu tiên các công việc có ràng buộc bắt đầu sớm nhất.
     * Công việc có earliestStartTime sớm hơn sẽ được ưu tiên hơn.
     * Nếu không có earliestStartTime, giá trị sẽ là một số rất lớn (ít ưu tiên).
     * @param {Task} task - Đối tượng công việc.
     * @returns {number} Timestamp của earliestStartTime hoặc Number.MAX_SAFE_INTEGER nếu không có.
     */
    byEarliestStartTime: (task) => {
        return task.earliestStartTime ? task.earliestStartTime.getTime() : Number.MAX_SAFE_INTEGER;
    },
};