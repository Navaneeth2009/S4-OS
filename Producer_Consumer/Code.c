#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int signal(int s){
	return(++s);
}
int wait(int s){
	return(--s);
}
void producer(){
	empty=wait(empty);
	mutex=wait(mutex);
	x++;
	printf("Producer produces the item %d\n",x);
	full=signal(full);
	mutex=signal(mutex);
}
void consumer(){
	full=wait(full);
	mutex=wait(mutex);
	printf("Consumer consumes the item %d\n",x);
	x--;
	empty=signal(empty);
	mutex=signal(mutex);
}
void main(){
	int n;
	while(1)
	{
		printf("\nOPTIONS\n1.Producer\n2.Consumer\n3.Exit");
		printf("\nEnter your option : ");
		scanf("%d",&n);
		switch(n){
			case 1 :
				if((mutex==1) && (empty!=0))
					producer();
				else
					printf("\nBUFFER IS FULL");
				break;
			case 2 :
				if((mutex==1)&&(full!=0))
					consumer();
				else
					printf("\nBUFFER IS EMPTY");
				break;
			case 3 :
				exit(0);
				break;
		}
					
	}
}
