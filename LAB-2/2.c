#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortByArrival(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}

void sortByBurst(struct Process p[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && p[j].burst < p[j - 1].burst; j--) {
            swap(&p[j], &p[j - 1]);
        }
    }
}

void calculateTimes(struct Process p[], int n) {
    int completionTime[n];
    completionTime[0] = p[0].arrival + p[0].burst;
    p[0].turnaround = completionTime[0] - p[0].arrival;
    p[0].waiting = p[0].turnaround - p[0].burst;

    for (int i = 1; i < n; i++) {
        if (p[i].arrival > completionTime[i - 1]) {
            completionTime[i] = p[i].arrival + p[i].burst;
        } else {
            completionTime[i] = completionTime[i - 1] + p[i].burst;
        }
        p[i].turnaround = completionTime[i] - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }
}

void displayProcesses(struct Process p[], int n, char algo[]) {
    printf("\n--- %s Scheduling ---\n", algo);
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].waiting, p[i].turnaround);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n], fcfs[n], sjf[n];

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);
    }

    for (int i = 0; i < n; i++) {
        fcfs[i] = p[i];
        sjf[i] = p[i];
    }

    sortByArrival(fcfs, n);
    calculateTimes(fcfs, n);
    displayProcesses(fcfs, n, "FCFS");

    sortByArrival(sjf, n);
    sortByBurst(sjf, n);
    calculateTimes(sjf, n);
    displayProcesses(sjf, n, "SJF");

    printf("\nTANMAY - 1BM23CS360\n");

    return 0;
}
