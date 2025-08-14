// scripts/ui/taskFormHandler.js

/**
 * @class TaskFormHandler
 * @description Xử lý tương tác với form nhập công việc và hiển thị danh sách công việc.
 */
class TaskFormHandler {
    constructor() {
        this.tasks = []; // Mảng để lưu trữ tất cả các đối tượng Task
        this.taskIdCounter = 1; // Counter để tạo ID duy nhất cho công việc
        this.editingTaskId = null; // Biến lưu ID công việc đang được chỉnh sửa

        // Lấy tham chiếu đến các phần tử DOM
        this.form = document.getElementById('task-form');
        this.taskNameInput = document.getElementById('task-name');
        this.taskDurationInput = document.getElementById('task-duration');
        this.taskPriorityInput = document.getElementById('task-priority');
        this.taskDependenciesInput = document.getElementById('task-dependencies');
        this.taskEarliestStartInput = document.getElementById('task-earliest-start');
        this.taskLatestFinishInput = document.getElementById('task-latest-finish');
        this.addTaskBtn = document.getElementById('add-task-btn'); // Nút "Thêm công việc"
        this.formMessages = document.getElementById('form-messages');
        this.tasksTableBody = document.querySelector('#tasks-table tbody');
        this.totalTasksCountSpan = document.getElementById('total-tasks-count');

        // Gán sự kiện cho form
        this.form.addEventListener('submit', this.handleFormSubmit.bind(this));

        // Note: this.renderTasks() sẽ được gọi từ main.js sau khi tải tasks từ Local Storage
    }

    /**
     * Xử lý sự kiện submit của form (thêm hoặc cập nhật công việc).
     * @param {Event} event - Đối tượng sự kiện.
     */
    handleFormSubmit(event) {
        event.preventDefault(); // Ngăn chặn form submit mặc định

        const name = this.taskNameInput.value;
        const duration = parseInt(this.taskDurationInput.value);
        const priority = parseInt(this.taskPriorityInput.value);
        const dependenciesRaw = this.taskDependenciesInput.value;
        const earliestStart = this.taskEarliestStartInput.value;
        const latestFinish = this.taskLatestFinishInput.value;

        // --- Validate dữ liệu đầu vào ---
        this.clearMessages();
        if (!Validation.isNonEmptyString(name)) {
            this.displayMessage('Tên công việc không được để trống.', 'error');
            return;
        }
        if (!Validation.isValidDuration(duration)) {
            this.displayMessage('Thời lượng phải là số dương.', 'error');
            return;
        }
        if (!Validation.isValidPriority(priority)) {
            this.displayMessage('Mức độ ưu tiên phải từ 1 đến 5.', 'error');
            return;
        }

        let dependencies = [];
        if (Validation.isNonEmptyString(dependenciesRaw)) {
            dependencies = dependenciesRaw.split(',').map(dep => dep.trim()).filter(dep => dep !== '');
            for (const depId of dependencies) {
                // Kiểm tra xem công việc phụ thuộc có tồn tại và không phải là chính nó không
                if (!Validation.isValidDependency(this.tasks, depId, this.editingTaskId)) {
                    this.displayMessage(`ID công việc phụ thuộc "${depId}" không tồn tại hoặc là chính công việc này.`, 'error');
                    return;
                }
                // Kiểm tra vòng lặp phụ thuộc (dependency cycle) - Mức nâng cao
                // Có thể thêm logic kiểm tra vòng lặp phụ thuộc ở đây nếu cần (ví dụ: dùng DFS trên đồ thị phụ thuộc)
            }
        }

        let parsedEarliestStart = null;
        if (earliestStart) {
            parsedEarliestStart = new Date(earliestStart);
            if (!Validation.isValidDate(parsedEarliestStart)) {
                this.displayMessage('Định dạng thời gian bắt đầu sớm nhất không hợp lệ.', 'error');
                return;
            }
        }

        let parsedLatestFinish = null;
        if (latestFinish) {
            parsedLatestFinish = new Date(latestFinish);
            if (!Validation.isValidDate(parsedLatestFinish)) {
                this.displayMessage('Định dạng thời gian kết thúc muộn nhất không hợp lệ.', 'error');
                return;
            }
        }
        
        if (parsedEarliestStart && parsedLatestFinish && parsedEarliestStart.getTime() >= parsedLatestFinish.getTime()) {
            this.displayMessage('Thời gian bắt đầu sớm nhất phải trước hoặc bằng thời gian kết thúc muộn nhất.', 'error');
            return;
        }

        // --- Thêm hoặc cập nhật công việc ---
        if (this.editingTaskId) {
            // Cập nhật công việc hiện có
            const taskToUpdate = this.tasks.find(task => task.id === this.editingTaskId);
            if (taskToUpdate) {
                taskToUpdate.name = name;
                taskToUpdate.duration = duration;
                taskToUpdate.priority = priority;
                taskToUpdate.dependencies = dependencies;
                taskToUpdate.earliestStartTime = parsedEarliestStart;
                taskToUpdate.latestFinishTime = parsedLatestFinish;
                // Đặt lại trạng thái pending khi cập nhật
                taskToUpdate.actualStartTime = null;
                taskToUpdate.actualEndTime = null;
                taskToUpdate.status = "pending";

                this.displayMessage(`Đã cập nhật công việc "${name}" (ID: ${this.editingTaskId}).`, 'success');
            }
            this.editingTaskId = null; // Xóa trạng thái chỉnh sửa
            this.addTaskBtn.textContent = 'Thêm công việc'; // Đổi lại text nút
        } else {
            // Thêm công việc mới
            const id = `T${this.taskIdCounter++}`;
            try {
                const newTask = new Task(id, name, duration, priority, dependencies, parsedEarliestStart, parsedLatestFinish);
                this.tasks.push(newTask);
                this.displayMessage(`Đã thêm công việc "${name}" (ID: ${id}).`, 'success');
            } catch (e) {
                this.displayMessage(`Lỗi khi tạo công việc: ${e.message}`, 'error');
                return; // Ngừng nếu có lỗi tạo Task
            }
        }
        
        this.renderTasks(); // Cập nhật lại danh sách hiển thị
        this.form.reset(); // Xóa dữ liệu trong form
        // Trigger save to local storage after adding/updating
        if (typeof DataLoader !== 'undefined') {
            DataLoader.saveTasks(this.tasks);
        }
    }

    /**
     * Hiển thị thông báo trên form.
     * @param {string} message - Nội dung thông báo.
     * @param {string} type - Loại thông báo ('success' hoặc 'error').
     */
    displayMessage(message, type) {
        this.formMessages.textContent = message;
        this.formMessages.className = `messages ${type}`;
    }

    /**
     * Xóa thông báo trên form.
     */
    clearMessages() {
        this.formMessages.textContent = '';
        this.formMessages.className = 'messages';
    }

    /**
     * Hiển thị danh sách các công việc trong bảng.
     */
    renderTasks() {
        this.tasksTableBody.innerHTML = ''; // Xóa nội dung bảng hiện tại
        this.totalTasksCountSpan.textContent = this.tasks.length;

        if (this.tasks.length === 0) {
            const noTaskRow = this.tasksTableBody.insertRow();
            const cell = noTaskRow.insertCell(0);
            cell.colSpan = 9; // Spans all columns
            cell.textContent = "Chưa có công việc nào.";
            cell.style.textAlign = "center";
            return;
        }

        this.tasks.forEach(task => {
            const row = this.tasksTableBody.insertRow();
            row.id = `task-row-${task.id}`; // Gán ID cho hàng để dễ dàng thao tác

            row.insertCell(0).textContent = task.id;
            row.insertCell(1).textContent = task.name;
            row.insertCell(2).textContent = task.duration + ' phút';
            row.insertCell(3).textContent = task.priority;
            row.insertCell(4).textContent = task.dependencies.join(', ') || 'Không';
            row.insertCell(5).textContent = task.earliestStartTime ? DateUtils.formatDateTime(task.earliestStartTime) : 'Không';
            row.insertCell(6).textContent = task.latestFinishTime ? DateUtils.formatDateTime(task.latestFinishTime) : 'Không';
            
            const statusCell = row.insertCell(7);
            statusCell.textContent = task.status === 'scheduled' ? 'Đã lên lịch' : 'Chưa lên lịch';
            statusCell.className = `status-${task.status}`;

            const actionsCell = row.insertCell(8);
            actionsCell.className = 'action-buttons';
            
            // Nút Edit
            const editBtn = document.createElement('button');
            editBtn.textContent = 'Sửa';
            editBtn.className = 'edit-btn';
            editBtn.addEventListener('click', () => this.editTask(task.id));
            actionsCell.appendChild(editBtn);

            // Nút Delete
            const deleteBtn = document.createElement('button');
            deleteBtn.textContent = 'Xóa';
            deleteBtn.className = 'delete-btn';
            deleteBtn.addEventListener('click', () => this.deleteTask(task.id));
            actionsCell.appendChild(deleteBtn);
        });
    }

    /**
     * Xóa một công việc khỏi danh sách.
     * @param {string} taskId - ID của công việc cần xóa.
     */
    deleteTask(taskId) {
        // Kiểm tra xem có công việc nào khác phụ thuộc vào công việc này không
        const dependents = this.tasks.filter(task => task.dependencies.includes(taskId));
        if (dependents.length > 0) {
            const dependentNames = dependents.map(dep => dep.name).join(', ');
            this.displayMessage(`Không thể xóa công việc ${taskId} vì có các công việc khác phụ thuộc vào nó: ${dependentNames}.`, 'error');
            return;
        }

        // Lọc ra công việc cần xóa
        this.tasks = this.tasks.filter(task => task.id !== taskId);
        this.displayMessage(`Đã xóa công việc ${taskId}.`, 'success');
        this.renderTasks(); // Cập nhật lại giao diện
        // Trigger save to local storage after deleting
        if (typeof DataLoader !== 'undefined') {
            DataLoader.saveTasks(this.tasks);
        }
    }

    /**
     * Tải thông tin công việc vào form để chỉnh sửa.
     * @param {string} taskId - ID của công việc cần chỉnh sửa.
     */
    editTask(taskId) {
        const taskToEdit = this.tasks.find(task => task.id === taskId);
        if (taskToEdit) {
            this.taskNameInput.value = taskToEdit.name;
            this.taskDurationInput.value = taskToEdit.duration;
            this.taskPriorityInput.value = taskToEdit.priority;
            this.taskDependenciesInput.value = taskToEdit.dependencies.join(', ');
            
            // Format Date objects to datetime-local string (YYYY-MM-DDThh:mm)
            if (taskToEdit.earliestStartTime) {
                this.taskEarliestStartInput.value = taskToEdit.earliestStartTime.toISOString().substring(0, 16);
            } else {
                this.taskEarliestStartInput.value = '';
            }
            if (taskToEdit.latestFinishTime) {
                this.taskLatestFinishInput.value = taskToEdit.latestFinishTime.toISOString().substring(0, 16);
            } else {
                this.taskLatestFinishInput.value = '';
            }

            this.editingTaskId = taskId; // Đặt trạng thái đang chỉnh sửa
            this.addTaskBtn.textContent = 'Cập nhật công việc'; // Đổi text nút để người dùng biết đang cập nhật
            this.displayMessage(`Đang chỉnh sửa công việc: ${taskToEdit.name} (ID: ${taskToEdit.id})`, 'warning');
        }
    }

    /**
     * Trả về danh sách các công việc hiện tại.
     * @returns {Task[]} Mảng các đối tượng Task.
     */
    getTasks() {
        return this.tasks;
    }

    // --- Các phương thức mới cho Module 5 ---

    /**
     * Xóa tất cả công việc khỏi danh sách và reset form/counter.
     * Được gọi khi người dùng muốn xóa toàn bộ lịch trình.
     */
    clearAllTasks() {
        this.tasks = [];
        this.taskIdCounter = 1; // Reset counter về 1
        this.editingTaskId = null; // Đảm bảo không còn ở chế độ chỉnh sửa
        this.renderTasks();
        this.form.reset();
        this.clearMessages();
        this.addTaskBtn.textContent = 'Thêm công việc'; // Đảm bảo nút trở về trạng thái thêm
    }

    /**
     * Gán danh sách công việc mới (ví dụ: khi tải từ Local Storage hoặc import file).
     * @param {Task[]} newTasks - Mảng các đối tượng Task mới.
     */
    setTasks(newTasks) {
        this.tasks = newTasks;
        // Sau khi set tasks, bạn cần đảm bảo render lại
        // và cập nhật taskIdCounter nếu cần (sẽ làm trong main.js)
    }

    /**
     * Gán giá trị cho taskIdCounter (ví dụ: khi tải từ Local Storage để tránh trùng ID).
     * @param {number} counter - Giá trị mới cho taskIdCounter.
     */
    setTaskIdCounter(counter) {
        this.taskIdCounter = counter;
    }
}