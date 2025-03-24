#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 50

struct process_info {
    char process_name;
    int arrival;
    int burst;
    int priority;
    int completion;
    int turnaround;
    int waiting;
};

struct process_queue {
    struct process_info queue[MAX];
    int head;
    int tail;
};

void initialize_queue(struct process_queue* pq) {
    pq->head = -1;
    pq->tail = -1;
}

int is_queue_empty(struct process_queue* pq) {
    return (pq->head == -1 && pq->tail == -1);
}

int is_queue_full(struct process_queue* pq) {
    if (pq->tail == MAX - 1) {
        printf("Process queue is full! No more processes can be added.\n");
        return 1;
    }
    return 0;
}

void enqueue(struct process_queue* pq, struct process_info new_process) {
    if (is_queue_full(pq)) {
        return;
    }
    if (pq->head == -1) {
        pq->head = 0;
    }
    pq->tail++;
    pq->queue[pq->tail] = new_process;
}

struct process_info dequeue(struct process_queue* pq) {
    if (is_queue_empty(pq)) {
        struct process_info invalid = {'X', -1, -1, -1, -1, -1, -1};
        return invalid;
    }
    struct process_info ret_process = pq->queue[pq->head];
    pq->head++;
    if (pq->head > pq->tail) {
        pq->head = -1;
        pq->tail = -1;
    }
    return ret_process;
}

void input_processes(int count, struct process_info processes[]) {
    for (int i = 0; i < count; i++) {
        printf("Enter name of process %d: ", i + 1);
        scanf(" %c", &processes[i].process_name);
        printf("Arrival time of process %c: ", processes[i].process_name);
        scanf("%d", &processes[i].arrival);
        printf("Burst time of process %c: ", processes[i].process_name);
        scanf("%d", &processes[i].burst);
        printf("Priority of process %c: ", processes[i].process_name);
        scanf("%d", &processes[i].priority);
        processes[i].completion = 0;
        processes[i].turnaround = 0;
        processes[i].waiting = 0;
    }
}

void sort_processes(int count, struct process_info processes[], int key) {
    struct process_info temp;
    for (int i = 1; i < count; i++) {
        temp = processes[i];
        int j = i - 1;
        while (j >= 0 && ((key == 1 && processes[j].arrival > temp.arrival) ||
                          (key == 2 && processes[j].completion > temp.completion))) {
            processes[j + 1] = processes[j];
            j--;
        }
        processes[j + 1] = temp;
    }
}

void show_gantt_chart(int count, struct process_info processes[]) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < count; i++) {
        printf("| %c ", processes[i].process_name);
    }
    printf("|\n0");
    for (int i = 0; i < count; i++) {
        printf("     %d", processes[i].completion);
    }
    printf("\n");
}

void calc_avg_turnaround(int count, struct process_info processes[]) {
    float total_tt = 0;
    for (int i = 0; i < count; i++) {
        total_tt += processes[i].turnaround;
    }
    printf("\nAverage Turnaround Time: %.2f", total_tt / count);
}

void calc_avg_waiting(int count, struct process_info processes[]) {
    float total_wt = 0;
    for (int i = 0; i < count; i++) {
        total_wt += processes[i].waiting;
    }
    printf("\nAverage Waiting Time: %.2f", total_wt / count);
}

void fcfs_scheduling(int count, struct process_info processes[], struct process_queue* pq) {
    int time = 0, index = 0;
    while (!is_queue_empty(pq) || index < count) {
        while (index < count && processes[index].arrival <= time) {
            enqueue(pq, processes[index]);
            index++;
        }
        if (is_queue_empty(pq) && index < count) {
            time = processes[index].arrival;
            continue;
        }
        struct process_info current = dequeue(pq);
        current.waiting = time - current.arrival;
        current.completion = time + current.burst;
        current.turnaround = current.completion - current.arrival;
        time = current.completion;
        for (int i = 0; i < count; i++) {
            if (processes[i].process_name == current.process_name) {
                processes[i] = current;
                break;
            }
        }
    }
}

int main() {
    struct process_queue pq;
    initialize_queue(&pq);
    int count;
    printf("Enter number of processes: ");
    scanf("%d", &count);
    struct process_info processes[count];
    input_processes(count, processes);
    sort_processes(count, processes, 1);
    fcfs_scheduling(count, processes, &pq);
    sort_processes(count, processes, 2);
    show_gantt_chart(count, processes);
    calc_avg_turnaround(count, processes);
    calc_avg_waiting(count, processes);
    return 0;
}
