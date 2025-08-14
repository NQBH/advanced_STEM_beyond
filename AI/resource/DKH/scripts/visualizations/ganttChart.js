// scripts/visualizations/ganttChart.js

/**
 * @namespace GanttChart
 * @description Các chức năng để vẽ biểu đồ Gantt sử dụng Google Charts.
 */
const GanttChart = {
    /**
     * Tải gói Google Charts Gantt.
     * Cần gọi hàm này trước khi cố gắng vẽ biểu đồ.
     * @returns {Promise<void>} Một Promise sẽ được giải quyết khi gói đã được tải.
     */
    loadGoogleCharts: () => {
        return new Promise((resolve) => {
            google.charts.load('current', {'packages':['gantt']});
            google.charts.setOnLoadCallback(resolve);
        });
    },

    /**
     * Vẽ biểu đồ Gantt.
     * @param {Task[]} scheduledTasks - Mảng các đối tượng Task đã được lên lịch.
     * @param {string} containerId - ID của phần tử DOM để vẽ biểu đồ.
     */
    drawChart: (scheduledTasks, containerId) => {
        if (!google.visualization) {
            console.error("Google Charts API chưa được tải. Vui lòng gọi GanttChart.loadGoogleCharts() trước.");
            return;
        }

        const data = new google.visualization.DataTable();
        data.addColumn('string', 'Task ID');
        data.addColumn('string', 'Task Name');
        data.addColumn('string', 'Resource'); // Dùng cho Priority để tô màu
        data.addColumn('date', 'Start Date');
        data.addColumn('date', 'End Date');
        data.addColumn('number', 'Duration');
        data.addColumn('number', 'Percent Complete');
        data.addColumn('string', 'Dependencies');

        const rows = scheduledTasks.map(task => {
            const startDate = task.actualStartTime instanceof Date && !isNaN(task.actualStartTime.getTime())
                ? task.actualStartTime
                : new Date();
            const endDate = task.actualEndTime instanceof Date && !isNaN(task.actualEndTime.getTime())
                ? task.actualEndTime
                : DateUtils.addMinutes(startDate, task.duration);

            const percentComplete = task.status === 'scheduled' ? 100 : 0;
            const resource = `Priority ${task.priority}`;

            return [
                task.id,
                task.name,
                resource,
                startDate,
                endDate,
                task.duration * 60 * 1000, // Duration in milliseconds
                percentComplete,
                task.dependencies.length > 0 ? task.dependencies.join(',') : null
            ];
        });

        data.addRows(rows);

        const options = {
            height: scheduledTasks.length * 45 + 100,
            width: '100%',
            gantt: {
                trackHeight: 40,
                barHeight: 25,
                labelStyle: {
                    fontName: 'Segoe UI',
                    fontSize: 14,
                    color: '#1565c0', // Xanh dương đậm
                    bold: true,
                },
                innerGridTrack: { fill: '#fff' },
                innerGridDarkTrack: { fill: '#f0f0f0' },
                barLabelStyle: {
                    fontName: 'Segoe UI',
                    fontSize: 12,
                    color: '#1565c0', // Xanh dương đậm cho text trên bar
                    bold: true,
                },
                percentEnabled: false,
                criticalPathEnabled: false,
                arrow: {
                    angle: 100,
                    width: 1,
                    color: '#FF0000',
                    length: 10,
                },
                timelineVAlign: 'bottom',
                gridLabelStyle: {
                    fontName: 'Segoe UI',
                    fontSize: 13,
                    color: '#1565c0', // Xanh dương đậm cho timeline
                    bold: true,
                },
                gridLine: {
                    color: '#bbb',
                },
                viewType: 'day',
                days: 30,
                scale: [
                    { unit: 'hour', format: 'HH:mm' },
                    { unit: 'day', format: 'dd MMM HH:mm' },
                    { unit: 'day', format: 'dd MMM' },
                    { unit: 'week', format: 'WW - dd MMM' },
                    { unit: 'month', format: 'MMMM yyyy' }
                ],
                cellFormat: {
                    'day': 'EEE dd',
                    'month': 'MMM yyyy'
                },
                palette: [
                    { "color": "#e0f2f7", "dark": "#b3e5fc", "light": "#e0f2f7" },
                    { "color": "#c8e6c9", "dark": "#a5d6a7", "light": "#e8f5e9" },
                    { "color": "#fff9c4", "dark": "#fff59d", "light": "#fffde7" },
                    { "color": "#ffccbc", "dark": "#ffab91", "light": "#fbe9e7" },
                    { "color": "#ffcdd2", "dark": "#ef9a9a", "light": "#ffebee" }
                ]
            }
        };

        const chartContainer = document.getElementById(containerId);
        if (!chartContainer) {
            console.error(`Không tìm thấy phần tử DOM với ID: ${containerId}`);
            return;
        }
        const chart = new google.visualization.Gantt(chartContainer);
        chart.draw(data, options);
    }
};