#include <stdio.h>
#include<conio.h>
int bt[20],at[10],n,st[10],ft[10],wt[10],ta[10],ct[10];
void sjf()
{
    int i,j,temp;
    int totwt=0,totta=0;
    double awt,ata;
    printf("Enter the number of process:  ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter arrival time & burst time:\n");
        scanf("%d%d",&at[i],&bt[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(bt[i]<bt[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
            st[i]=at[i];
        else
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+bt[i];
            ta[i]=ft[i]-at[i];
            totwt+=wt[i];
            totta+=ta[i];
    }
    awt=(double)totwt/n;
    ata=(double)totta/n;
    printf("\nAverage waiting time: %f",awt);
    printf("\nAverage turnaroundtime: %f",ata);
}
void srtf() 
{
      int arrival_time[10], burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &limit); 
      printf("\nEnter Details of %d Processes\n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      average_waiting_time = wait_time / limit; 
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
    
}

int main()
{
    int i,ch,j,s=0,sw=0;
    float avgs,avgw;
    printf("Enter number of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for process %d:  ",i+1);
        scanf("%d",&at[i]);
        printf("Enter processing time for process %d:  ",i+1);
        scanf("%d",&bt[i]);
    }
    printf("Enter type of scheduling 1-FCFS 2-SJF 3-SRTF: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            ct[i]=ct[i]+bt[j];
        }
        for(i=0;i<n;i++)
        {
            ta[i]=ct[i]-at[i];
            wt[i]=ta[i]-bt[i];
            s=s+ta[i];
            sw=sw+wt[i];
        }
        avgs=(float)s/n;
        avgw=(float)sw/n;
        printf("Process\t| AT\t| PT\t| CT\t| TAT\t| WT\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t| %d\t| %d\t| %d\t| %d\t| %d\n",i+1,at[i],bt[i],ct[i],ta[i],wt[i]);
        }
        printf("Average waiting time is %f\n",avgw);
        printf("Average turn around time is %f\n",avgs);
        break;
        case 2:
        sjf();
        break;
        case 3:
        srtf();
        default:
        printf("Wrong choice");
       
    }
    printf("Code by Uditi");
    return 0;
}
