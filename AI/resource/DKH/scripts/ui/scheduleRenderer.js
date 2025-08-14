// scripts/ui/scheduleRenderer.js

// Import GanttChart từ scripts/visualizations/ganttChart.js
// Import DateUtils từ scripts/utils/dateUtils.js

/**
 * @class ScheduleRenderer
 * @description Xử lý việc hiển thị lịch trình đã sắp xếp lên giao diện.
 */
class ScheduleRenderer {
    constructor() {
        this.ganttChartContainer = document.getElementById('gantt-chart-container');
        this.makespanDisplay = document.getElementById('makespan-display');
        this.isGoogleChartsLoaded = false;

        // Tải Google Charts khi ScheduleRenderer được khởi tạo
        GanttChart.loadGoogleCharts().then(() => {
            this.isGoogleChartsLoaded = true;
            console.log("Google Charts Gantt package loaded successfully.");
            this.displayNoScheduleMessage(); // Hiển thị thông báo ban đầu
        }).catch(error => {
            console.error("Lỗi khi tải Google Charts:", error);
            this.ganttChartContainer.innerHTML = '<p style="color: red;">Không thể tải biểu đồ. Vui lòng kiểm tra kết nối internet.</p>';
        });
    }

    /**
     * Hiển thị lịch trình đã sắp xếp.
     * @param {Task[]} scheduledTasks - Mảng các đối tượng Task đã được lên lịch.
     */
    renderSchedule(scheduledTasks) {
        if (!this.isGoogleChartsLoaded) {
            this.ganttChartContainer.innerHTML = '<p>Đang tải thư viện biểu đồ...</p>';
            // Thử lại sau một khoảng thời gian nếu chưa tải xong
            setTimeout(() => this.renderSchedule(scheduledTasks), 500);
            return;
        }

        // Lọc ra chỉ những công việc đã được lên lịch thành công và có thời gian hợp lệ
        const actualScheduledTasks = scheduledTasks.filter(task => 
            task.isScheduled() && 
            task.actualStartTime instanceof Date && !isNaN(task.actualStartTime.getTime()) &&
            task.actualEndTime instanceof Date && !isNaN(task.actualEndTime.getTime())
        );

        if (actualScheduledTasks.length === 0) {
            this.displayNoScheduleMessage();
            this.makespanDisplay.textContent = 'N/A';
            return;
        }

        // 1. Tính toán Makespan (Tổng thời gian hoàn thành)
        let earliestStartOverall = null;
        let latestEndOverall = null;

        actualScheduledTasks.forEach(task => { // Dùng actualScheduledTasks đã lọc
            if (earliestStartOverall === null || task.actualStartTime.getTime() < earliestStartOverall.getTime()) {
                earliestStartOverall = task.actualStartTime;
            }
            if (latestEndOverall === null || task.actualEndTime.getTime() > latestEndOverall.getTime()) {
                latestEndOverall = task.actualEndTime;
            }
        });

        if (earliestStartOverall && latestEndOverall) {
            const makespanMinutes = DateUtils.diffInMinutes(earliestStartOverall, latestEndOverall);
            const makespanHours = Math.floor(makespanMinutes / 60);
            const remainingMinutes = Math.round(makespanMinutes % 60); // Làm tròn phút
            this.makespanDisplay.textContent = `${makespanHours} giờ ${remainingMinutes} phút`;
        } else {
            this.makespanDisplay.textContent = 'Chưa xác định';
        }

        // 2. Vẽ biểu đồ Gantt
        GanttChart.drawChart(actualScheduledTasks, 'gantt-chart-container');
    }

    /**
     * Hiển thị thông báo khi không có lịch trình nào được tạo.
     */
    displayNoScheduleMessage() {
        this.ganttChartContainer.innerHTML = '<p style="text-align: center; color: #666;">Chưa có lịch trình nào được tạo. Vui lòng thêm công việc và nhấn "Sắp xếp lịch trình".</p>';
    }
}