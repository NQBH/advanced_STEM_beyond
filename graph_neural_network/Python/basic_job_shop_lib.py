from job_shop_lib import JobShopInstance, Operation

# represent an Instance in JobShopLib
## each machine is represented with an ID (starting from 0)
CUTTING_MACHINE_ID = 0
SANDING_MACHINE_ID = 1
ASSEMBLY_MACHINE_ID = 2
table = [
	Operation(CUTTING_MACHINE_ID, duration = 2),
	Operation(SANDING_MACHINE_ID, duration = 2),
	Operation(ASSEMBLY_STATION_ID, duration = 2),
]
chair = [
	Operation(CUTTING_MACHINE_ID, duration = 1),
	Operation(SANDING_MACHINE_ID, duration = 1),
	Operation(ASSEMBLY_STATION_ID, duration = 1),
]
cabinet = [
	Operation(CUTTING_MACHINE_ID, duration = 2),
	Operation(ASSEMBLY_STATION_ID, duration = 3),
	Operation(SANDING_MACHINE_ID, duration = 3),
]
jobs = [table, chair, cabinet]
instance = JobShopInstance(jobs)

# represent schedules in JobShopLib
from job_shop_lib import Schedule

## the id of each job is the index in the jobs list
TABLE_ID = 0
CHAIR_ID = 1
CABINET_ID = 2

cutting_machine_order = [CABINET_ID, TABLE_ID, CHAIR_ID]
sanding_machine_order = [TABLE_ID, CHAIR_ID, CABINET_ID]
assembly_station_order = [CABINET_ID, TABLE_ID, CHAIR_ID]
y = [cutting_machine_order, sanding_machine_order, assembly_station_order, ]
schedule = Schedule.from_job_sequences(instance, y)