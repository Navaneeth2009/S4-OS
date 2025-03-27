#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10 
#define MAX_RESOURCES 10  

bool isSafe(int processes[], int avail[], int max[][MAX_RESOURCES], int allot[][MAX_RESOURCES], int numProcesses, int numResources) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};
    int safeSeq[MAX_PROCESSES];
    int work[MAX_RESOURCES];
    int count = 0;
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
    for (int i = 0; i < numResources; i++) {
        work[i] = avail[i];
    }
    while (count < numProcesses) {
        bool found = false;
        for (int p = 0; p < numProcesses; p++) {
            if (!finish[p]) {
                bool canBeDone = true;
                for (int j = 0; j < numResources; j++) {
                    if (need[p][j] > work[j]) {
                        canBeDone = false;
                        break;
                    }
                }
                if (canBeDone) {
                    for (int j = 0; j < numResources; j++) {
                        work[j] += allot[p][j];
                    }
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            return false; 
        }
    }
    printf("Safe sequence: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return true;
}

bool requestResources(int processID, int request[], int avail[], int max[][MAX_RESOURCES], int allot[][MAX_RESOURCES], int numProcesses, int numResources) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
    for (int i = 0; i < numResources; i++) {
        if (request[i] > need[processID][i]) {
            printf("Error: Process P%d requested more than its declared need.\n", processID);
            return false;
        }
    }
    for (int i = 0; i < numResources; i++) {
        if (request[i] > avail[i]) {
            printf("Process P%d must wait. Not enough resources available.\n", processID);
            return false;
        }
    }
    for (int i = 0; i < numResources; i++) {
        avail[i] -= request[i];
        allot[processID][i] += request[i];
        need[processID][i] -= request[i];
    }

    if (isSafe((int[]){0, 1, 2, 3, 4}, avail, max, allot, numProcesses, numResources)) {
        printf("Request granted. System remains in a safe state.\n");
        return true;
    } else {
        printf("Request denied. System would become unsafe.\n");
        for (int i = 0; i < numResources; i++) {
            avail[i] += request[i];
            allot[processID][i] -= request[i];
            need[processID][i] += request[i];
        }
        return false;
    }
}
int main() {
    int processes[MAX_PROCESSES];
    int avail[MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allot[MAX_PROCESSES][MAX_RESOURCES];
    int numProcesses, numResources;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    printf("Enter the number of resource types: ");
    scanf("%d", &numResources);
    printf("Enter the available resources:\n");
    for (int i = 0; i < numResources; i++) {
        printf("Resource %d: ", i);
        scanf("%d", &avail[i]);
    }
    printf("Enter the maximum demand matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            printf("Max for process P%d, Resource %d: ", i, j);
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            printf("Allocated for process P%d, Resource %d: ", i, j);
            scanf("%d", &allot[i][j]);
        }
    }
    if (!isSafe(processes, avail, max, allot, numProcesses, numResources)) {
        printf("System is in an unsafe state!\n");
    } else {
        printf("System is in a safe state!\n");
        int processID;
        int request[MAX_RESOURCES];
        printf("\nDo you want to make a new resource request? (1 for Yes, 0 for No): ");
        int choice;
 	scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter the process ID making the request: ");
            scanf("%d", &processID);
            printf("Enter the request :\n");
            for (int i = 0; i < numResources; i++) {
                printf("Resource %d: ", i);
                scanf("%d", &request[i]);
            }
            requestResources(processID, request, avail, max, allot, numProcesses, numResources);
        }
    }
    return 0;
}
