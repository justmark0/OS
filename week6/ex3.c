#include <stdio.h>
int num_of_proc;


void robin(int arrival_time[], int burst_time[], int quantum){
    int waiting_time[num_of_proc], turn_around_time[num_of_proc], completion_time[num_of_proc];
    int burst_time_cpy[num_of_proc], count = 0;
    double total_waiting = 0, total_TAT = 0;
    waiting_time[0] = 0;
    for(int i = 0 ; i < num_of_proc; i++) {
        burst_time_cpy[i] = burst_time[i];
    }
    int x = num_of_proc;
    double allWT = 0, allTAT = 0;
    for (int t = 0, i = 0; x != 0; ) {
        if (burst_time_cpy[i] <= quantum && burst_time_cpy[i] > 0) {
            t += burst_time_cpy[i];
            burst_time_cpy[i] = 0;
            count = 1;
        } else if (burst_time_cpy[i] > 0) {
            burst_time_cpy[i] = burst_time_cpy[i] - quantum;
            t += quantum;
        }
        if (burst_time_cpy[i] == 0 && count == 1) {
            waiting_time[i] = t - arrival_time[i] - burst_time[i];
            turn_around_time[i] = t - arrival_time[i];
            completion_time[i] = t;
            allWT = allWT + waiting_time[i];
            allTAT = allTAT + turn_around_time[i];
            count = 0;
            x--;
        }
        if (i == num_of_proc-1) i = 0;
        else if (arrival_time[i + 1] <= t) i++;
        else i = 0;
    }
    for(int i = 0 ; i < num_of_proc; i++){
        total_waiting += waiting_time[i];
        total_TAT += turn_around_time[i];
        printf("processes %d:\nBurst time: %d\nArrival time: %d\nWaiting time: %d\nTurnaround time: %d\n"
               "Completion time: %d\n\n", i + 1, burst_time[i], arrival_time[i], waiting_time[i],turn_around_time[i],
               completion_time[i]);
    }
    printf("Average Waiting time: %lf\n", (double)total_waiting/(double)num_of_proc);
    printf("Average Average Turnaround time: %lf", (double)total_TAT/(double)num_of_proc);
}


int main() {
    printf("Enter number of processes:\n");
    scanf("%d", &num_of_proc);
    int arrival_time[num_of_proc], burst_time[num_of_proc], quantum;
    printf("Enter arrival_time and burst_time for each process:\n");
    for(int i = 0; i < num_of_proc; i++){
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    printf("Time quantum: ");
    scanf("%d",&quantum);
    robin(arrival_time, burst_time, quantum);
    return 0;
}

/*
 *
 * Input:
 * 3 proc
 * First process:
 *  arrival_time = 0
 *  burst_time = 10
 *
 *  Second process:
 *  arrival_time = 7
 *  burst_time = 9
 *
 *  Third process:
 *  arrival_time = 4
 *  burst_time = 2
 *
 *  quantum = 1
 *
 * Output:
 *
 * process 1:
 * Burst time: 10
 * Arrival time: 0
 * Waiting time: 5
 * Turnaround time: 15
 * Completion time: 15
 *
 * process 2:
 * Burst time: 9
 * Arrival time: 7
 * Waiting time: 5
 * Turnaround time: 14
 * Completion time: 21
 *
 * process 3:
 * Burst time: 2
 * Arrival time: 4
 * Waiting time: 6
 * Turnaround time: 8
 * Completion time: 12
 *
 * Average Waiting time: 5.333333
 * Average Average Turnaround time: 12.333333
 *
 * So, it is debatable which algorithms for sceduler is the best, we can see that in some cases
 * second solution(SJN) works better, but if we have one prosess which has large Burst time it will need to wait for
 * a long period of time. On the one hand we have 3-rd algorithm to implement sceduler(robin) will process all
 * processes by small parts. But waiting time will increase.
 *
 * This questions is debateble, but in my opinion 3-rd algorithm to implement sceduler(robin) is most suitable for
 * most of cases. We just need to choose optimal quantum.
 *
 */


