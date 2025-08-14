// scripts/utils/validation.js

/**
 * @namespace Validation
 * @description Tập hợp các hàm để kiểm tra tính hợp lệ của dữ liệu.
 */
const Validation = {
    /**
     * Kiểm tra xem giá trị có phải là số dương hợp lệ cho thời lượng không.
     * @param {any} value - Giá trị cần kiểm tra.
     * @returns {boolean} True nếu hợp lệ, ngược lại false.
     */
    isValidDuration(value) {
        return typeof value === 'number' && value > 0;
    },

    /**
     * Kiểm tra xem giá trị có phải là mức ưu tiên hợp lệ (1-5) không.
     * @param {any} value - Giá trị cần kiểm tra.
     * @returns {boolean} True nếu hợp lệ, ngược lại false.
     */
    isValidPriority(value) {
        return typeof value === 'number' && value >= 1 && value <= 5;
    },

    /**
     * Kiểm tra xem một ID công việc phụ thuộc có tồn tại trong danh sách các công việc đã có không.
     * @param {Task[]} tasks - Mảng các đối tượng Task hiện có.
     * @param {string} dependencyId - ID của công việc phụ thuộc cần kiểm tra.
     * @returns {boolean} True nếu hợp lệ (ID tồn tại và không phải là chính nó), ngược lại false.
     */
    isValidDependency(tasks, dependencyId, currentTaskId = null) {
        if (typeof dependencyId !== 'string' || dependencyId.trim() === '') {
            return false;
        }
        // Không thể phụ thuộc vào chính mình
        if (currentTaskId && dependencyId === currentTaskId) {
            return false;
        }
        // Kiểm tra xem ID phụ thuộc có tồn tại trong danh sách công việc không
        return tasks.some(task => task.id === dependencyId);
    },

    /**
     * Kiểm tra xem một chuỗi có rỗng hoặc chỉ chứa khoảng trắng không.
     * @param {string} value - Chuỗi cần kiểm tra.
     * @returns {boolean} True nếu không rỗng và có ký tự khác khoảng trắng, ngược lại false.
     */
    isNonEmptyString(value) {
        return typeof value === 'string' && value.trim() !== '';
    },

    /**
     * Kiểm tra xem một đối tượng Date có hợp lệ không.
     * @param {any} value - Giá trị cần kiểm tra.
     * @returns {boolean} True nếu là đối tượng Date hợp lệ, ngược lại false.
     */
    isValidDate(value) {
        return value instanceof Date && !isNaN(value);
    }
};