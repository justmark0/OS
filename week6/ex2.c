#include <stdio.h>
int num_of_proc;

void SJN(int arrival_time[], int burst_time[]){
    int waiting_time[num_of_proc], turn_around_time[num_of_proc], buff[num_of_proc], completion_time[num_of_proc];
    int burst_time_cpy[num_of_proc];
    double total_waiting = 0, total_TAT = 0;
    buff[0] = 0;
    waiting_time[0] = 0;
    for(int i = 0; i < num_of_proc; i++)
        burst_time_cpy[i] = burst_time[i];
    int time = -1, proc_left = num_of_proc;
    while(proc_left > 0) {// Find the smallest
        time ++;
        // Take smallest, execute, go for next
        int smallest = 1e9, index = num_of_proc + 1;
        for (int j = 0; j < num_of_proc; j++) {
            if(smallest > burst_time_cpy[j] && time >= arrival_time[j] && burst_time_cpy[j] > 0){
                smallest = burst_time_cpy[j];
                index = j;
            }
        }
        if(index < num_of_proc) // It may happen that arrival time of each process is bigger than now
            burst_time_cpy[index] --; // We proceed one instruction
        if(burst_time_cpy[index] <= 0 && index < num_of_proc) { // If we finish with some process
            proc_left--;
            int end = time + 1;
            waiting_time[index] = time + 1 - arrival_time[index]-burst_time[index];
            turn_around_time[index] = end - arrival_time[index];
            completion_time[index] = end;
        }
    }
    for(int i = 0 ; i < num_of_proc; i++){
        total_waiting += waiting_time[i];
        total_TAT += turn_around_time[i];
        printf("process %d:\nBurst time: %d\nArrival time: %d\nWaiting time: %d\nTurnaround time: %d\n"
               "Completion time: %d\n\n", i + 1, burst_time[i], arrival_time[i], waiting_time[i],turn_around_time[i],
               completion_time[i]);
    }
    printf("Average Waiting time: %lf\n", (double)total_waiting/(double)num_of_proc);
    printf("Average Average Turnaround time: %lf", (double)total_TAT/(double)num_of_proc);
}


int main() {
    printf("Enter number of processes:\n");
    scanf("%d", &num_of_proc);
    int arrival_time[num_of_proc], burst_time[num_of_proc];
    printf("Enter arrival_time and burst_time for each process:\n");
    for(int i = 0; i < num_of_proc; i++){
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    SJN(arrival_time, burst_time);
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
 * Output:
 *
 * process 1:
 * Burst time: 10
 * Arrival time: 0
 * Waiting time: 2
 * Turnaround time: 12
 * Completion time: 12
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
 * Waiting time: 0
 * Turnaround time: 2
 * Completion time: 6
 *
 * Average Waiting time: 2.333333
 * Average Average Turnaround time: 9.333333
 *
 */

