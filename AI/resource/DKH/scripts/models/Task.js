// scripts/models/Task.js

/**
 * @class Task
 * @description Định nghĩa cấu trúc dữ liệu cho một công việc cá nhân.
 */
class Task {
    /**
     * @param {string} id - ID duy nhất của công việc.
     * @param {string} name - Tên của công việc.
     * @param {number} duration - Thời gian dự kiến để hoàn thành công việc (đơn vị: phút).
     * @param {number} priority - Mức độ ưu tiên của công việc (ví dụ: 1-5, 5 là cao nhất).
     * @param {string[]} dependencies - Mảng các ID công việc mà công việc này phụ thuộc vào.
     * @param {Date | null} [earliestStartTime=null] - Thời gian bắt đầu sớm nhất có thể của công việc (Optional).
     * @param {Date | null} [latestFinishTime=null] - Thời gian kết thúc muộn nhất có thể của công việc (Optional).
     */
    constructor(id, name, duration, priority, dependencies = [], earliestStartTime = null, latestFinishTime = null) {
        if (!id) throw new Error("Task ID cannot be empty.");
        if (typeof name !== 'string' || name.trim() === '') throw new Error("Task name cannot be empty.");
        if (typeof duration !== 'number' || duration <= 0) throw new Error("Task duration must be a positive number.");
        if (typeof priority !== 'number' || priority < 1 || priority > 5) throw new Error("Task priority must be between 1 and 5.");
        if (!Array.isArray(dependencies)) throw new Error("Task dependencies must be an array of strings.");

        this.id = id;
        this.name = name;
        this.duration = duration; // In minutes
        this.priority = priority; // 1 (low) to 5 (high)
        this.dependencies = dependencies; // Array of task IDs

        // Thời gian thực tế được gán sau khi lập lịch
        this.actualStartTime = null;
        this.actualEndTime = null;

        // Ràng buộc thời gian (nâng cao)
        this.earliestStartTime = earliestStartTime instanceof Date ? earliestStartTime : null;
        this.latestFinishTime = latestFinishTime instanceof Date ? latestFinishTime : null;

        // Trạng thái của công việc (ví dụ: "pending", "scheduled", "completed")
        this.status = "pending";
    }

    /**
     * Kiểm tra xem công việc đã được lập lịch chưa.
     * @returns {boolean} True nếu công việc đã có thời gian bắt đầu/kết thúc.
     */
    isScheduled() {
        return this.actualStartTime !== null && this.actualEndTime !== null;
    }

    /**
     * Gán thời gian bắt đầu và kết thúc cho công việc.
     * @param {Date} startTime - Thời gian bắt đầu thực tế.
     */
    setSchedule(startTime) {
        if (!(startTime instanceof Date) || isNaN(startTime.getTime())) { 
            throw new Error("Start time must be a valid Date object."); 
        }
        this.actualStartTime = startTime;
        this.actualEndTime = new Date(startTime.getTime() + this.duration * 60 * 1000); // Thêm thời lượng (phút) vào startTime
        this.status = "scheduled";
    }

    /**
     * Trả về thông tin công việc dưới dạng đối tượng đơn giản.
     * @returns {object} Đối tượng chứa các thuộc tính của công việc.
     */
    toObject() {
        return {
            id: this.id,
            name: this.name,
            duration: this.duration,
            priority: this.priority,
            dependencies: this.dependencies,
            actualStartTime: this.actualStartTime ? this.actualStartTime.toISOString() : null,
            actualEndTime: this.actualEndTime ? this.actualEndTime.toISOString() : null,
            earliestStartTime: this.earliestStartTime ? this.earliestStartTime.toISOString() : null,
            latestFinishTime: this.latestFinishTime ? this.latestFinishTime.toISOString() : null,
            status: this.status
        };
    }

    /**
     * Tạo một đối tượng Task từ một đối tượng dữ liệu đơn giản.
     * @param {object} data - Đối tượng dữ liệu công việc.
     * @returns {Task} Đối tượng Task mới.
     */
    static fromObject(data) {
        const earliestStartTime = data.earliestStartTime ? new Date(data.earliestStartTime) : null;
        const latestFinishTime = data.latestFinishTime ? new Date(data.latestFinishTime) : null;
        const task = new Task(data.id, data.name, data.duration, data.priority, data.dependencies, earliestStartTime, latestFinishTime);
        
        if (data.actualStartTime && data.actualEndTime) { // Đảm bảo cả hai đều tồn tại
            const parsedActualStartTime = new Date(data.actualStartTime);
            const parsedActualEndTime = new Date(data.actualEndTime);
            
            // THÊM KIỂM TRA ĐỊNH DẠNG DATE HỢP LỆ KHI TẠO TỪ OBJECT
            if (Validation.isValidDate(parsedActualStartTime) && Validation.isValidDate(parsedActualEndTime)) {
                task.actualStartTime = parsedActualStartTime;
                task.actualEndTime = parsedActualEndTime;
                task.status = data.status || "scheduled"; // Đảm bảo status được set đúng
            } else {
                // Nếu không hợp lệ, set lại null để không gây lỗi hiển thị
                task.actualStartTime = null;
                task.actualEndTime = null;
                task.status = "pending"; 
            }
        }
        return task;
    }
}