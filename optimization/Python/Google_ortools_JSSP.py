import collections
from ortools.sat.python import cp_model

# define data
jobs_data = [  # task = (machine_id, processing_time).
    [(0, 3), (1, 2), (2, 2)],  # Job0
    [(0, 2), (2, 1), (1, 4)],  # Job1
    [(1, 4), (2, 3)],  # Job2
]
machines_count = 1 + max(task[0] for job in jobs_data for task in job)
all_machines = range(machines_count)
# compute horizon dynamically as sum of all durations
horizon = sum(task[1] for job in jobs_data for task in job)

# define model
model = cp_model.CpModel()

# define variables
# named tuple to store information about created variables
task_type = collections.namedtuple("task_type", "start end interval")
# named tuple to manipulate solution information
assigned_task_type = collections.namedtuple("assigned_task_type", "start job index duration")

# create job intervals & add to the corresponding machine lists
all_tasks = {}
machine_to_intervals = collections.defaultdict(list)

for job_id, job in enumerate(jobs_data):
	for task_id, task in enumerate(job):
		machine, duration = task
		suffix = f"_{job_id}_{task_id}"
		start_var = model.new_int_var(0, horizon, "start" + suffix)
		end_var = model.new_int_var(0, horizon, "end" + suffix)
		interval_var = model.new_interval_var(start_var, duration, end_var, "interval" + suffix)
		all_tasks[job_id, task_id] = task_type(start = start_var, end = end_var, interval = interval_var)
		machine_to_intervals[machine].append(interval_var)

# define constraints
# create & add disjunctive constraints
for machine in all_machines:
	model.add_no_overlap(machine_to_intervals[machine])

# precedences inside a job
for job_id, job in enumerate(jobs_data):
	for task_id in range(len(job) - 1):
		model.add(all_tasks[job_id, task_id + 1].start >= all_tasks[job_id, task_id].end)

# define objective
# makespan objective
obj_var = model.new_int_var(0, horizon, "makespan")
model.add_max_equality(obj_var, [all_tasks[job_id, len(job) - 1].end for job_id, job in enumerate(jobs_data)],)
model.minimize(obj_var)

# invoke solver
solver = cp_model.CpSolver()
status = solver.solve(model)

# display results
if status == cp_model.OPTIMAL or status == cp_model.FEASIBLE:
    print("Solution:")
    # Create one list of assigned tasks per machine.
    assigned_jobs = collections.defaultdict(list)
    for job_id, job in enumerate(jobs_data):
        for task_id, task in enumerate(job):
            machine = task[0]
            assigned_jobs[machine].append(
                assigned_task_type(
                    start=solver.value(all_tasks[job_id, task_id].start),
                    job=job_id,
                    index=task_id,
                    duration=task[1],
                )
            )

    # Create per machine output lines.
    output = ""
    for machine in all_machines:
        # Sort by starting time.
        assigned_jobs[machine].sort()
        sol_line_tasks = "Machine " + str(machine) + ": "
        sol_line = "           "

        for assigned_task in assigned_jobs[machine]:
            name = f"job_{assigned_task.job}_task_{assigned_task.index}"
            # add spaces to output to align columns.
            sol_line_tasks += f"{name:15}"

            start = assigned_task.start
            duration = assigned_task.duration
            sol_tmp = f"[{start},{start + duration}]"
            # add spaces to output to align columns.
            sol_line += f"{sol_tmp:15}"

        sol_line += "\n"
        sol_line_tasks += "\n"
        output += sol_line_tasks
        output += sol_line

    # Finally print the solution found.
    print(f"Optimal Schedule Length: {solver.objective_value}")
    print(output)
else:
    print("No solution found.")