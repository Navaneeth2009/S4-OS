//SJF
#include<stdio.h>
void main(){
	int pid[25],bt[25],wt[25],tt[25],i,j,n,temp;
	float avg_wt=0,avg_tt=0;
	printf("Enter no. of processes : ");
	scanf("%d",&n);
	//printf("Enter process id and burst times of processes\n");
	for(i=0;i<n;i++){
		printf("%d. process id : ",i+1);
		scanf("%d",&pid[i]);
		printf("%d. process burst time : ",i+1);
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(bt[j+1]<bt[j]){
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				temp=pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=temp;
			}
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		avg_wt+=wt[i];
	}
	for(i=0;i<n;i++){
		tt[i]=wt[i]+bt[i];
		avg_tt+=tt[i];
	}
	
	printf("|\tProcess_id\t||\tburst time\t|\n");
	printf("------------------------------------------------\n");
	for(i=0;i<n;i++){
		printf(" \t%d         \t  \t%d\t \n",pid[i],bt[i]);
	}
	printf("------------------------------------------------\n");
	printf("Ghant Chart");
	printf("\n------------------------------------------------\n");
	for(i=0;i<n;i++){
		printf("|\tP%d\t|",pid[i]);
	}
	printf("\n------------------------------------------------\n");
	for(i=0;i<n;i++){
		printf("|\t%d\t|",wt[i]);
	}
	printf("\n------------------------------------------------\n");
	avg_wt/=n;
	avg_tt/=n;
	printf("Average waiting time :%2f\n",avg_wt);
	printf("Average turnaround time :%2f\n",avg_tt);
}
