// scripts/main.js

document.addEventListener('DOMContentLoaded', () => {
    // Khởi tạo TaskFormHandler
    const taskFormHandler = new TaskFormHandler();

    // Khởi tạo ScheduleRenderer
    const scheduleRenderer = new ScheduleRenderer();

    // Lấy tham chiếu đến các nút và phần tử UI khác
    const scheduleTasksBtn = document.getElementById('schedule-tasks-btn');
    const clearAllTasksBtn = document.getElementById('clear-all-tasks-btn'); // NEW BUTTON
    const exportTasksBtn = document.getElementById('export-tasks-btn');     // NEW BUTTON
    const importTasksBtn = document.getElementById('import-tasks-btn');
    const importTasksInput = document.getElementById('import-tasks-input'); // NEW INPUT FILE

    // --- Module 5: Tải công việc đã lưu khi ứng dụng khởi động ---
    const savedTasks = DataLoader.loadTasks();
    if (savedTasks.length > 0) {
        // Cập nhật TaskFormHandler với các công việc đã tải
        taskFormHandler.setTasks(savedTasks); // Thêm phương thức này vào TaskFormHandler
        // Cập nhật taskIdCounter để tránh trùng ID
        const maxIdNum = savedTasks.reduce((max, task) => {
            const idNum = parseInt(task.id.replace('T', ''));
            return isNaN(idNum) ? max : Math.max(max, idNum);
        }, 0);
        taskFormHandler.setTaskIdCounter(maxIdNum + 1); // Thêm phương thức này vào TaskFormHandler
        taskFormHandler.renderTasks(); // Render lại bảng với dữ liệu đã tải
        scheduleRenderer.displayNoScheduleMessage(); // Vẫn hiển thị thông báo "Chưa có lịch trình"
    }

    // --- Gán sự kiện cho nút "Sắp xếp lịch trình" ---
    scheduleTasksBtn.addEventListener('click', () => {
        const currentTasks = taskFormHandler.getTasks();
        if (currentTasks.length === 0) {
            alert('Vui lòng thêm công việc trước khi sắp xếp lịch trình.');
            return;
        }

        const scheduler = new HeuristicScheduler();
        // Chọn heuristic, ví dụ: ưu tiên cao hơn và thời lượng ngắn hơn được ưu tiên
        const selectedHeuristic = (task) => Heuristics.combined(task, { priority: 10, duration: 0.01 });

        const now = new Date();
        now.setSeconds(0);
        now.setMilliseconds(0);

        const scheduledTasksResult = scheduler.scheduleTasks(currentTasks, selectedHeuristic, now);

        // Cập nhật trạng thái của các công việc trong TaskFormHandler
        taskFormHandler.tasks.forEach(taskInHandler => {
            const foundScheduledTask = scheduledTasksResult.find(st => st.id === taskInHandler.id);
            if (foundScheduledTask) {
                // Update properties of the original task object in handler's tasks array
                taskInHandler.actualStartTime = foundScheduledTask.actualStartTime;
                taskInHandler.actualEndTime = foundScheduledTask.actualEndTime;
                taskInHandler.status = foundScheduledTask.status;
            } else {
                // Task was not scheduled, reset its status if needed
                taskInHandler.actualStartTime = null;
                taskInHandler.actualEndTime = null;
                taskInHandler.status = 'pending';
            }
        });

        // --- Module 5: Lưu công việc sau khi lập lịch (để lưu trạng thái đã lên lịch) ---
        DataLoader.saveTasks(taskFormHandler.getTasks());

        // --- Tích hợp Module 4: Hiển thị biểu đồ ---
        scheduleRenderer.renderSchedule(scheduledTasksResult);

        // Cập nhật bảng Task
        taskFormHandler.renderTasks();
    });

    // --- Module 5: Sự kiện cho nút "Xóa tất cả công việc" ---
    if (clearAllTasksBtn) {
        clearAllTasksBtn.addEventListener('click', () => {
            if (confirm('Bạn có chắc chắn muốn xóa tất cả công việc? Hành động này không thể hoàn tác.')) {
                taskFormHandler.clearAllTasks(); // Thêm phương thức này vào TaskFormHandler
                DataLoader.clearTasks(); // Xóa khỏi Local Storage
                scheduleRenderer.displayNoScheduleMessage(); // Xóa biểu đồ
                scheduleRenderer.makespanDisplay.textContent = 'N/A'; // Reset makespan
                alert('Tất cả công việc đã được xóa.');
            }
        });
    }

    // --- Module 5: Sự kiện cho nút "Xuất công việc" ---
    if (exportTasksBtn) {
        exportTasksBtn.addEventListener('click', () => {
            const tasksToExport = taskFormHandler.getTasks().map(task => task.toObject());
            const dataStr = JSON.stringify(tasksToExport, null, 2); // Định dạng JSON đẹp hơn
            const dataUri = 'data:application/json;charset=utf-8,' + encodeURIComponent(dataStr);

            const exportFileDefaultName = 'tasks.json';

            let linkElement = document.createElement('a');
            linkElement.setAttribute('href', dataUri);
            linkElement.setAttribute('download', exportFileDefaultName);
            linkElement.click(); // Kích hoạt click để tải file
            linkElement.remove();
        });
    }

    // --- Module 5: Sự kiện cho nhập file "Import công việc" ---
    if (importTasksBtn && importTasksInput) {
        // Khi nhấn nút "Nhập công việc", mở input file
        importTasksBtn.addEventListener('click', () => {
            importTasksInput.click();
        });

        // Khi chọn file, đọc và import
        importTasksInput.addEventListener('change', (event) => {
            const file = event.target.files[0];
            if (!file) return;
            const reader = new FileReader();
            reader.onload = function(e) {
                try {
                    const imported = JSON.parse(e.target.result);
                    // Chuyển plain object thành Task object
                    const importedTasks = imported.map(obj => Task.fromObject(obj));
                    taskFormHandler.setTasks(importedTasks);
                    // Cập nhật counter để tránh trùng ID
                    const maxIdNum = importedTasks.reduce((max, task) => {
                        const idNum = parseInt(task.id.replace('T', ''));
                        return isNaN(idNum) ? max : Math.max(max, idNum);
                    }, 0);
                    taskFormHandler.setTaskIdCounter(maxIdNum + 1);
                    taskFormHandler.renderTasks();
                    DataLoader.saveTasks(importedTasks);
                    alert('Nhập công việc thành công!');
                } catch (err) {
                    alert('File không hợp lệ hoặc lỗi dữ liệu!');
                }
            };
            reader.readAsText(file);
            // Reset input để lần sau chọn lại vẫn trigger
            event.target.value = '';
        });
    }

    console.log("Ứng dụng đã sẵn sàng!");
});