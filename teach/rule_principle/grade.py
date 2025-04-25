# default parameters
absence_point = -1
late_point = -0.25 # -0.25/30 mins

# parameters depending on each subject
number_student = int(input())
number_teaching_day = int(input()) # 20 days for both theory & practical classes
early_attendence_point = 0.25 # go to class before lecturer & on time

# grading
while (number_student):
	number_student -= 1
	number_early_attendence = int(input()) # max: number_teaching_day
	number_absence_day = int(input()) # max: number_teaching_day
	total_late_time = float(input()) # in mins
	total_plus_point = float(input()) # in 2-decimal accuracy

	# midterm exam grade 15%
	midterm_exam_grade = float(input()) # last column in 3 columns 45%
	total_early_attendence_point = early_attendence_point * number_early_attendence
	print(total_early_attendence_point)

	# study grade 30%
	study_grade = total_plus_point + total_early_attendence_point + number_absence_day * absence_point + total_late_time * late_point / 30

	# final exam grade 55%
	final_exam_grade = float(input())

	# final grade
	final_grade = min(study_grade, 10) * 0.3 + midterm_exam_grade * 0.15 + final_exam_grade * 0.55
	print(final_grade)