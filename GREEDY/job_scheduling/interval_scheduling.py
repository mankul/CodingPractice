# schedule the jobs with maximizing accepted requests



jobs = []

#input number of jobs
num = input()

for i in range(num):
    # input starting and ending point seperated with space 
    line = raw_input()
    s,f = line.split(" ")
    jobs.append((int(s), int(f)))

sorted_jobs  = sorted(jobs, key= lambda x: x[0])


allocated_jobs = []

temp_job_start = -1
temp_job_end = 10000000

for s,f in sorted_jobs:
    if f < temp_job_end and s < temp_job_end:
        temp_job_end = f
        temp_job_start = s

    elif s >= temp_job_end:
        allocated_jobs.append((temp_job_start, temp_job_end))
        temp_job_start = s
        temp_job_end = f


allocated_jobs.append((temp_job_start,temp_job_end))

print(allocated_jobs)