#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
} Process;

void sort_by_arrival(Process queue[], int n) {
    Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (queue[j].arrival_time > queue[j + 1].arrival_time) {
                temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
}

void execute_round_robin(Process queue[], int n, int *current_time, int time_quantum) {
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\n");

    Process queue_copy[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        queue_copy[i] = queue[i];
        queue_copy[i].remaining_burst_time = queue[i].burst_time;
    }

    int processes_left = n;

    while (processes_left > 0) {
        int executed = 0;
        for (int i = 0; i < n; i++) {
            if (queue_copy[i].remaining_burst_time > 0) {
                executed = 1;
                int time_slice = (queue_copy[i].remaining_burst_time < time_quantum) ? queue_copy[i].remaining_burst_time : time_quantum;

                *current_time += time_slice;
                queue_copy[i].remaining_burst_time -= time_slice;

                if (queue_copy[i].remaining_burst_time == 0) {
                    printf("%d\t%d\t\t%d\t\t%d\n", queue_copy[i].pid, queue_copy[i].arrival_time, queue_copy[i].burst_time, *current_time);
                    processes_left--;
                }
            }
        }

        if (!executed) {
            (*current_time)++;
        }
    }
}

int main() {
    int n, system_count = 0, user_count = 0, time_quantum;
    Process system_queue[MAX_PROCESSES], user_queue[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int type;
        Process p;
        printf("Enter process ID, arrival time, burst time, and type (0=System, 1=User) for process %d: ", i + 1);
        scanf("%d %d %d %d", &p.pid, &p.arrival_time, &p.burst_time, &type);

        if (type == 0) {
            system_queue[system_count++] = p;
        } else {
            user_queue[user_count++] = p;
        }
    }

    sort_by_arrival(system_queue, system_count);
    sort_by_arrival(user_queue, user_count);

    printf("Enter the time quantum for Round Robin: ");
    scanf("%d", &time_quantum);

    int current_time = 0;
    printf("\nExecuting System Processes (Higher Priority - Round Robin):\n");
    execute_round_robin(system_queue, system_count, &current_time, time_quantum);

    printf("\nExecuting User Processes (Lower Priority - Round Robin):\n");
    execute_round_robin(user_queue, user_count, &current_time, time_quantum);

    return 0;
}
