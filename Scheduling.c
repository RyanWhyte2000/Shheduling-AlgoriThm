#include <stdio.h>
/* Ryan Whyte
   1800715*/

   int main()
{
    roundRobin();


  return 0;
}

void roundRobin(){
    int i,count,n,time,temp, remain,flag=0,quantum, choice;
    int responseTIme[10],waitTime=0, turnTime=0, PID[10],arrivalTime[10],burstTime[10],rem_Time[10];
    float AverageTurnaround, averagWaitime;
  printf("How many process are in the system\n");
  scanf("%d",&n);
  remain=n;// intialize decrement counter


  for(i=0;i<n;i++)
  {
    printf("Process ID is ");
    scanf("%d", &PID[i]);
    printf("Enter Arrival Time   :");
    scanf("%d\n",&arrivalTime[i]);

    printf("Enter Burst Time :");
    scanf("%d\n",&burstTime[i]);

    rem_Time[i]=burstTime[i];
  }

/******************read from file*********************************/
  printf("Do you want to enter the quantum");
  scanf("%d", &choice);
  if( choice==1){
  printf("Enter Time Quantum:\t");
  scanf("%d",&quantum);
  }else{

  quantum=2;/*random number generation*/
  }

  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,count=0;remain!=0;)
  {
      /*The process is sent to the processor to check if its cable of
      execution within that time quantum */
    if(rem_Time[count]<=quantum && rem_Time[count]>0)
    {
      time+=rem_Time[count];
      rem_Time[count]=0;
      flag=1;
    }
    else if(rem_Time[count]>0)
    {
      rem_Time[count]-=quantum;
      time+=quantum;
    }
    if(rem_Time[count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-arrivalTime[count],time-arrivalTime[count]-burstTime[count]);

      waitTime+= time-arrivalTime[count]-burstTime[count];
      turnTime+=time-arrivalTime[count];
      //responseTIme+=time -arrivalTime[count];
       flag=0;
    }
    if(count==n-1)
      count=0;
    else if(arrivalTime[count+1]<=time)
      count++;
    else
      count=0;
  }
  AverageTurnaround= turnTime/n;
  averagWaitime=waitTime/n;


  printf("\nAverage Waiting Time is  %f\n",averagWaitime);
  printf("Avg Turnaround Time is %f",turnTime);

}

void npp(){


    int arrival_time[20], bursttime[20], priority[20], c, n=0,i;
    int end,temp, processnumber[20], pos;

        printf("How many process are in the system\n");
        scanf("%d", &end);

        while(n!= end){

            printf("\nprocess number is %d\n", n+1);

            printf("\nEnter the arrival time");
            scanf("%d", &arrival_time[n]);

            printf("\nEnter the burst time");
            scanf("%d", &bursttime[n]);

            printf("\nEnter the priority");
            scanf("%d", &priority[n]);



            processnumber[n]=n+1;
            n++;
        }

    for ( int i=0; i< end; i++){
        pos=i;
        for (int j= i+1; j<end; j++){

            if (arrival_time[j] <arrival_time[pos]){
                pos =j;
                    }else if(arrival_time[j]==arrival_time[pos]){
                        if(priority[j]< priority[pos]){
                        pos =j;
                        }
                    else if (priority[j]== priority[pos]){

                        //pos =j;
                    }

        }
    }

                    temp = processnumber[i];
                    processnumber[i]= processnumber[pos];
                    processnumber[pos]= temp;

                    temp = priority[i];
                    priority[i]= priority[pos];
                    priority[pos]= temp;

                    temp = arrival_time[i];
                    arrival_time[i]= arrival_time[pos];
                    arrival_time[pos]= temp;

                    temp = bursttime[i];
                    bursttime[i]= bursttime[pos];
                    bursttime[pos]=temp;
                }




        for (i=0; i<end; i++){
            printf("\nProcess number \t    Arrival Time \t    Priority  \t    Burst Time ");
            printf("\n%d\t\t  %d\t\t    %d\t\t\t%d",processnumber[i],arrival_time[i],priority[i],bursttime[i]);
    }



}

/*void SJf(){

    int pid;     // process ID
    int bt;      // burst Time
    int n, int wt[], int tat[], tat[n], total_wt = 0, total_tat = 0;

    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] = proc[i-1].bt + wt[i-1] ;
    }

    for (int i = 0; i < n ; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }

}*/

