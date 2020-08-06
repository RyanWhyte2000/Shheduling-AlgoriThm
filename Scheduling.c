#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <Windows.h>

/* Ryan Whyte (1800715)
   Daniel Wright (1806169)
   Marvin Arnett (1701403)
   Operating System  Group Programming Project

   */

   FILE *fptr;

   int main()
{
    storeRec();

    int i=0, n=5, r, value;
    int  PID[n], arrivalTime[n], burstTime[n];
    int  ProcessID[n], ArrivalTime[n], BurstTime[n], queue[n], counter=0;


     fptr=fopen("Schedule.text","r");

	if((fptr==NULL))
	{
		printf("The file is not opened.\n");
	}
	else
	{
		do
		{
				fscanf(fptr,"%d %d %d %d \n",&PID[i], &arrivalTime[i],&burstTime[i], &queue[i]);
				if (queue[i]== 1){/*Checks the priority of the process */
                ProcessID[i]= PID[i];
                ArrivalTime[i]= arrivalTime[i];
                BurstTime[i]= burstTime[i];
                counter++;
                roundRobin(ProcessID, ArrivalTime, BurstTime ,counter);/* Function Call */

                }else if(queue[i]== 2){/*Checks the priority of the process */
                Sleep(1000);
                system("cls");
                ProcessID[i]= PID[i];
                ArrivalTime[i]= arrivalTime[i];
                BurstTime[i]= burstTime[i];
                counter++;
                npp(ProcessID, ArrivalTime, BurstTime ,counter);/* Function Call */

                }else if(queue[i]== 3){/*Checks the priority of the process */

                Sleep(1000);
                system("cls");
                ProcessID[i]= PID[i];
                ArrivalTime[i]= arrivalTime[i];
                BurstTime[i]= burstTime[i];
                counter++;
                SJf(ProcessID, ArrivalTime, BurstTime ,counter);/* Function Call */

				i++;
        }

		}while(!feof(fptr));
		}
    fclose(fptr);

  return 0;
}

void roundRobin(  int PID[], int arrivalTime[], int burstTime[], int counter){
    /* Round Robin uses preemption based on a clock. The clock interrupt is generated at periodic intervals
    When an interrupt occurs, the currently running process is placed in the ready queue which is selected on a FCFS basis
    */

    /*Variable declaration*/
    int i,count,time,temp, remain,flag=0,quantum, end=counter, choice;
    int responseTIme[counter],waitTime=0, turnTime=0, rem_Time[counter];
    float AverageTurnaround, averagWaitime;

    remain=end;
    for(i=0;i<end;i++)
    {
      printf(" Process %d\n", PID[i]);
      rem_Time[i]=burstTime[i];
    }


    printf("Do you want to enter the quantum--- 1 for yes and 2 for no");
    scanf("%d", &choice);
    if( choice==1){
        printf("Enter Time Quantum:\t");
        scanf("%d",&quantum);
    }else{

        quantum=10;/*random number generation*/
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
      printf("P[%d]\t|\t%d\t|\t%d\n",PID[count], time-arrivalTime[count],time-burstTime[count]);
      printf("\n");
      system("\n pause");
      waitTime+= time-arrivalTime[count]-burstTime[count];
      turnTime+=time-arrivalTime[count];
       flag=0;
    }
    if(count==end-1)
      count=0;
    else if(arrivalTime[count+1]<=time)
      count++;
    else
      count=0;
    }
    /*Average turnaround time and waiting time is calculated and printed to the screen*/
    AverageTurnaround= turnTime/end;
    averagWaitime=waitTime/end;


    printf("\nAverage Waiting Time is  %f\n",averagWaitime);
    printf("Avg Turnaround Time is %f",turnTime);

}

void npp(int PID[], int arrivalTime[], int burstTime[], int counter){

/*The non Preemptive Priority runs until completion or until they yield control of the processor
 */
    int  priority[counter], c, n=0,i;
    int end,temp,time=0,  pos,rem_Time[counter];
    int responseTIme[10],waitTime=0, turnTime=0;


        while(n!= counter){

                priority[n]=PID[n];

                n++;
        }

        for ( int i=0; i< end; i++){

            pos=i;
            for (int j= i+1; j<end; j++){


            if (arrivalTime[j] <arrivalTime[pos]){
                pos =j;


            }else if(arrivalTime[j]==arrivalTime[pos]){

                        if(priority[j]< priority[pos]){
                        pos =j;
                        }
        }
    }

                    temp = PID[i];
                    PID[i]= PID[pos];
                    PID[pos]= temp;

                    temp = priority[i];
                    priority[i]= priority[pos];
                    priority[pos]= temp;

                    temp = arrivalTime[i];
                    arrivalTime[i]= arrivalTime[pos];
                    arrivalTime[pos]= temp;

                    temp = burstTime[i];
                    burstTime[i]= burstTime[pos];
                    burstTime[pos]=temp;
                }

        for (i=0; i<5; i++){
            printf("\nProcess number \t    Arrival Time \t    Priority  \t    Burst Time ");
            printf("\n%d\t\t  %d\t\t    %d\t\t\t%d",PID[i],arrivalTime[i],priority[i],burstTime[i]);
            time = burstTime[i]-arrivalTime[i];
            turnTime+= time;
            waitTime+= time-  burstTime[i];
            printf("\n");
            system("pause");
    }
        /*Average turnaround time and waiting time is calculated and printed to the screen*/


        printf("\n Average Turnaround Time is %f",turnTime/n);
        printf("\n Average Wait Time is %f",waitTime/n);
}

void SJf( int PID[], int arrivalTime[], int burstTime[], int counter){
    /*SJF is a non-preemptive scheduling algorithm that handles jobs based on the length of their CPU cycle time
*/

      int  temp[counter];
      int i, shortest, count = 0, n=counter,time;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;


      for(i = 0; i < n; i++)
      {
            temp[i] =burstTime[i];
      }
      burstTime[counter] = 999;
      for(time = 0; count != n; time++)
      {
            shortest= counter;

            for(i = 0; i < n; i++)
            {

                  if(arrivalTime[i] <= time && burstTime[i] <burstTime[shortest] && burstTime[i] > 0)
                  {
                        shortest= i;
                  }
            }
            burstTime[shortest]--;
            if(burstTime[shortest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrivalTime[shortest] - temp[shortest];
                  turnaround_time = turnaround_time + end - arrivalTime[shortest];
            }

      }
      for (i=0; i<counter; i++){
            printf("\nProcess number \t    Arrival Time \t      Burst Time ");
            printf("\n%d\t\t  %d\t\t    %d\t\t\t%d",PID[i],arrivalTime[i],burstTime[i]);
           printf("\n");
            system("pause");
    }

    /*Average turnaround time and waiting time is calculated and printed to the screen*/

      average_waiting_time = wait_time / n;
      average_turnaround_time = turnaround_time / n;

      printf("\nAverage Waiting Time:%.2f\n", average_waiting_time);
      printf("\nAverage Turnaround Time:%.2f", average_turnaround_time);

}

void storeRec(){
    /*File needed to store the processes to eliminate the need for user inputs*/
    int i, n=5, r, value;
    int  PID[n], arrivalTime[n], burstTime[n], queue[n];
     for (i=0; i<n; i++ )
		{
            r=rand();
          /* Tgis is needed if you want to generate random numbers
            PID[i]= i+1;
            arrivalTime[i]= (r % 10) + 1;
		    burstTime[i]= (r % 10) + 1;*/

		    PID[i]= i+1;
            arrivalTime[i]= i+2;
		    burstTime[i]= i+3;
		    queue[i]= (r % 3) + 1;/*Priority is chosen at random for testing purposes*/
		}

    fptr=fopen("Schedule.text","w");

	if((fptr==NULL))
	{
		printf("The file is not opened.\n");
	}
	else
	{
		for (i=0; i<n; i++ )
		{
                fprintf(fptr,"%d %d %d %d\n",PID[i],  arrivalTime[i], burstTime[i], queue[i]);

        }
		}
		fclose(fptr);

}
