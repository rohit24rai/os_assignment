#include<stdio.h>
#include<conio.h>
int main()
{
	// Global variables Declaration
	int i,No_of_Process,total=0,n,count=0,time_quantum;
	int wait_time=0,turnaround_time=0,arrival_time[10],burst_time[10],temp_burst[10];
	float average_wait_time,average_turnaround_time;
	// Asking the user total number of Process
	printf("\n Enter Total Number of Process:");
	scanf("%d",&No_of_Process);
	n=No_of_Process;
	// Taking different values of arrival_time and burst_time of the process from the user
	for(i=0;i<No_of_Process;i++)
	{
		printf("\n Enter Details of process[%d]\n",i+1);
		printf("Arrival time:\t");
		scanf("%d",&arrival_time[i]);
		printf("Burst_time:\t");
		scanf("%d",&burst_time[i]);
		// Storing burst_time array into temporary_burst_time array for computation
		temp_burst[i]=burst_time[i];
	}
	// Taking value of time_quantum from user
	printf("\n Enter Time quantum:");
	scanf("%d",&time_quantum);
	printf("\n Process ID\t\tBurst_time\t\tTurnaround_time\t\tWaiting_time\n");	
	// Necessary condition for the execution of all process
	for(i=0;total=0,n!=0;)
	{
		if(temp_burst[i]<=time_quantum && temp_burst[i]>0)
		{
			total=total+temp_burst[i];
			temp_burst[i]=0;
			count=1;
		}
		else if(temp_burst[i]>0)
		{
			temp_burst[i]=temp_burst[i]-time_quantum;
			total=total+time_quantum;
		}
		if (temp_burst[i]==0 && count==1)
		{
			n--;
			printf("\n Process[%d]\t\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d",i+1,burst_time[i],total-arrival_time[i],total-arrival_time[i]-burst_time[i]);
			wait_time=wait_time+total-arrival_time[i]-burst_time[i];
			turnaround_time=turnaround_time+total-arrival_time[i];
			count=0;
		}
	}
	// Computation of average_wait_time and average_turnaround_time
	average_wait_time=wait_time * 1.0 / No_of_Process;
	average_turnaround_time=turnaround_time * 1.0 / No_of_Process;
	printf("\n\nTotal waiting time:%d",wait_time);
	printf("\n\n average waiting time:%f",average_wait_time);
	printf("\nAvg turnaround time:%f",average_turnaround_time);
	return 0;
}

