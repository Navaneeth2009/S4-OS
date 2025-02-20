#include<stdio.h>
int main()
{
	int i,n,at[50],bt[50],ct[50],tt[50],wt[50],comp=0,time=0;
	float avg_wt=0,avg_tt=0;
	printf("Enter no. of processes:  ");
	scanf("%d",&n);
	printf("--Enter process arrival times and burst times--\n");
	for(i=0;i<n;i++)
	{
		printf("P%d arrival time:  ",i+1);
		scanf("%d",&at[i]);
		printf("P%d burst time: ",i+1);
		scanf("%d",&bt[i]);
	}
	while(comp<n)
	{
		for(i=0;i<n;i++)
		{
			if(at[i]>=time)
			{
				time+=bt[i];
				ct[i]=time;
				comp++;
			}
			else
			{
				time=at[i];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
        	tt[i] = ct[i] - at[i];   
        	wt[i] = tt[i] - bt[i];  
        	avg_wt += wt[i];
       	 	avg_tt += tt[i];
    	}	
    	printf("\nProcess\tAT\tBT\tCT\tTT\tWT\n");
    	for (int i = 0; i < n; i++) 
    	{
        	printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tt[i], wt[i]);
   	}
   	printf("\nAverage Turnaround Time: %.2f", avg_tt / n);
    	printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);
		
}
