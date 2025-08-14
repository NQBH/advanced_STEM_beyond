// scripts/utils/dateUtils.js

/**
 * @namespace DateUtils
 * @description Tập hợp các hàm tiện ích để xử lý đối tượng Date.
 */
const DateUtils = {
    /**
     * Thêm một số phút vào một đối tượng Date.
     * @param {Date} date - Đối tượng Date gốc.
     * @param {number} minutes - Số phút cần thêm.
     * @returns {Date} Đối tượng Date mới sau khi thêm phút.
     */
    addMinutes(date, minutes) {
        if (!(date instanceof Date) || isNaN(date.getTime())) {
            throw new Error("Invalid date object provided to addMinutes.");
        }
        if (typeof minutes !== 'number') {
            throw new Error("Minutes must be a number.");
        }
        return new Date(date.getTime() + minutes * 60 * 1000);
    },

    /**
     * Thêm một số giờ vào một đối tượng Date.
     * @param {Date} date - Đối tượng Date gốc.
     * @param {number} hours - Số giờ cần thêm.
     * @returns {Date} Đối tượng Date mới sau khi thêm giờ.
     */
    addHours(date, hours) {
        return DateUtils.addMinutes(date, hours * 60);
    },

    /**
     * Tính toán khoảng thời gian giữa hai đối tượng Date theo phút.
     * @param {Date} startDate - Thời gian bắt đầu.
     * @param {Date} endDate - Thời gian kết thúc.
     * @returns {number} Khoảng thời gian theo phút.
     */
    diffInMinutes(startDate, endDate) {
        if (!(startDate instanceof Date) || isNaN(startDate.getTime()) ||
            !(endDate instanceof Date) || isNaN(endDate.getTime())) {
            throw new Error("Invalid date objects provided to diffInMinutes.");
        }
        return (endDate.getTime() - startDate.getTime()) / (1000 * 60);
    },

    /**
     * Format đối tượng Date thành chuỗi "YYYY-MM-DD HH:MM".
     * @param {Date} date - Đối tượng Date cần format.
     * @returns {string} Chuỗi thời gian đã format.
     */
    formatDateTime(date) {
        if (!(date instanceof Date) || isNaN(date.getTime())) {
            return "N/A";
        }
        const year = date.getFullYear();
        const month = String(date.getMonth() + 1).padStart(2, '0');
        const day = String(date.getDate()).padStart(2, '0');
        const hours = String(date.getHours()).padStart(2, '0');
        const minutes = String(date.getMinutes()).padStart(2, '0');
        return `${year}-${month}-${day} ${hours}:${minutes}`;
    }
};