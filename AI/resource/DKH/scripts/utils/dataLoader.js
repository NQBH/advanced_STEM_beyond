// scripts/utils/dataLoader.js

/**
 * @namespace DataLoader
 * @description Các chức năng để lưu và tải dữ liệu công việc từ Local Storage.
 */
const DataLoader = {
    /**
     * Tên key dùng để lưu trữ trong Local Storage.
     */
    STORAGE_KEY: 'personalTasks',

    /**
     * Lưu danh sách công việc vào Local Storage.
     * @param {Task[]} tasks - Mảng các đối tượng Task cần lưu.
     */
    saveTasks(tasks) {
        try {
            // Chuyển đổi mảng Task objects sang mảng plain objects
            const plainTasks = tasks.map(task => task.toObject());
            localStorage.setItem(DataLoader.STORAGE_KEY, JSON.stringify(plainTasks));
            console.log("Tasks saved to Local Storage.");
        } catch (e) {
            console.error("Error saving tasks to Local Storage:", e);
        }
    },

    /**
     * Tải danh sách công việc từ Local Storage.
     * @returns {Task[]} Mảng các đối tượng Task đã tải. Trả về mảng rỗng nếu không có dữ liệu.
     */
    loadTasks() {
        try {
            const data = localStorage.getItem(DataLoader.STORAGE_KEY);
            if (data) {
                const plainTasks = JSON.parse(data);
                // Chuyển đổi plain objects trở lại thành Task objects
                const tasks = plainTasks.map(plainTask => Task.fromObject(plainTask));
                console.log("Tasks loaded from Local Storage.");
                return tasks;
            }
        } catch (e) {
            console.error("Error loading tasks from Local Storage:", e);
            localStorage.removeItem(DataLoader.STORAGE_KEY); // Xóa dữ liệu lỗi
        }
        return [];
    },

    /**
     * Xóa tất cả công việc khỏi Local Storage.
     */
    clearTasks() {
        try {
            localStorage.removeItem(DataLoader.STORAGE_KEY);
            console.log("All tasks cleared from Local Storage.");
        } catch (e) {
            console.error("Error clearing tasks from Local Storage:", e);
        }
    }
};