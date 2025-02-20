#include<stdio.h>
int main() {
    int n,temp,at[20],bt[20], p[20], wt[20], tt[20], pr[20];
    float avg_wt = 0, avg_tt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter Arrival time,Burst Time and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d:\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("P%d:\n", i+1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i+1;
    }
    for(int i=0;i<n-1;i++)
    {
    	for(int j=0;j<n-i-1;j++)
    	{
    		if(at[j]>at[j+1])
    		{
    			temp=at[j];
    			at[j]=at[j+1];
    			at[j+1]=temp;
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (pr[i] > pr[j]) {
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        avg_wt += wt[i];
    }
    for (int i = 0; i < n; i++) {
        tt[i] = wt[i] + bt[i];
        avg_tt += tt[i];
    }
    avg_wt /= n;
    avg_tt /= n;
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pr[i], bt[i], wt[i], tt[i]);
    }
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tt);
    printf("\nGantt Chart:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", p[i]);
    }
    printf("|\n");
    printf("--------------------------------------------------\n");
    printf("0");
    for (int i = 0; i < n; i++) {
        printf("\t%d", wt[i] + bt[i]);
    }
    printf("\n");
    return 0;
}
 
