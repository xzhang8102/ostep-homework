# Homework

1. Compute the response time and turnaround time when running three jobs of length 200 with the SJF and FIFO schedulers.  
**Answer:** FIFO: response time: (0 + 200 + 400) / 3 = 200; turnaround time: (200 + 400 + 600) / 3 = 400. SJF is the same as FIFO since all job lengths are the same.

2. Now do the same but with jobs of different lengths: 100, 200, and 300.  
**Answer:** FIFO: response time: (0 + 100 + 300) / 3 = 133.3; turnaround time: (100 + 300 + 600) / 3 = 333.3. SJF is the same as FIFO since the job processing layout is the same.

3. Now do the same, but also with the RR scheduler and a time-slice of 1.  
**Answer:** response time: (0 + 1 + 2) / 3 = 1; turnaround time: (199 * 3 + 1 + 199 * 3 + 2 + 199 * 3 + 3) / 3 = 599.

4. For what types of workloads does SJF deliver the same turnaround times as FIFO?  
**Answer:** The order of the incoming jobs is the same as the increasing order of the incoming job length.

5. For what types of workloads and quantum lengths does SJF deliver the same response times as RR?  
**Answer:** Every single job can be done with one quantum length.

6. What happens to response time with SJF as job lengths increase? Can you use the simulator to demonstrate the trend?  
**Answer:** Same as the 4th question. In this case, SJF will work like FIFO.

7. What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given N jobs?  
**Answer:** The worst case is when the quantum length is large enough to fit the longest job. The response time would be the total of job length divided by N.