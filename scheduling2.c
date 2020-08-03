#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Ryan Whyte
   1800715
   Daniel Wright

   Marvin Arnett


   */

   FILE *fptr;


   int main()
{
    storeRec();

    int i=0, n=5, r, value;
    int  PID[n], arrivalTime[n], burstTime[n];


     fptr=fopen("Schedule.text","r");

	if((fptr==NULL))
	{
		printf("The file is not opened.\n");
	}
	else
	{
		do
		{
				fscanf(fptr,"%d %d %d \n",&PID[i], &arrivalTime[i],&burstTime[i]);
				i++;

		}while(!feof(fptr));
		}
		fclose(fptr);

        //roundRobin(PID, arrivalTime, burstTime);
        //npp(PID, arrivalTime, burstTime);
        SJf(PID, arrivalTime, burstTime);

  return 0;
}

void roundRobin(  int PID[5], int arrivalTime[5], int burstTime[5]){
    int i,count,time,temp, remain,flag=0,quantum, end=5, choice;
    int responseTIme[10],waitTime=0, turnTime=0, rem_Time[5];
    float AverageTurnaround, averagWaitime;

    remain=end;
 for(i=0;i<end;i++)
  {
      printf(" Process %d\n", PID[i]);
      rem_Time[i]=burstTime[i];
  }





/******************read from file*********************************/
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
    system("pause");
      waitTime+= time-arrivalTime[count]-burstTime[count];
      turnTime+=time-arrivalTime[count];
      //responseTIme+=time -arrivalTime[count];
       flag=0;
    }
    if(count==end-1)
      count=0;
    else if(arrivalTime[count+1]<=time)
      count++;
    else
      count=0;
  }
  AverageTurnaround= turnTime/end;
  averagWaitime=waitTime/end;


  printf("\nAverage Waiting Time is  %f\n",averagWaitime);
  printf("Avg Turnaround Time is %f",turnTime);

}

void npp(int PID[5], int arrivalTime[5], int burstTime[5]){


    int  priority[5], c, n=0,i;
    int end,temp,time=0,  pos,rem_Time[5];
    int responseTIme[10],waitTime=0, turnTime=0;


        while(n!= 5){

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
                    else if (priority[j]== priority[pos]){

                        //pos =j;
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

                   //rem_Time[i]=burstTime[pos];
                   // time+=rem_Time[i];


                }




        for (i=0; i<5; i++){
            printf("\nProcess number \t    Arrival Time \t    Priority  \t    Burst Time ");
            printf("\n%d\t\t  %d\t\t    %d\t\t\t%d",PID[i],arrivalTime[i],priority[i],burstTime[i]);
            time = burstTime[i]-arrivalTime[i];
            turnTime+= time;
            waitTime+= time-  burstTime[i];


    }

        printf("\n Average Turnaround Time is %f",turnTime/n);
         printf("\n Average Wait Time is %f",waitTime/n);
}

void SJf( int PID[5], int arrivalTime[5], int burstTime[5]){


    int  temp[10];
      int i, shortest, count = 0, n=5,time;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;


      for(i = 0; i < n; i++)
      {

            temp[i] =burstTime[i];
      }
     burstTime[9] = 9999;
      for(time = 0; count != end; time++)
      {
            shortest= 9;
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
      average_waiting_time = wait_time / n;
      average_turnaround_time = turnaround_time / n;
      printf("Average Waiting Time:t%lfn", average_waiting_time);
      printf("Average Turnaround Time:t%lfn", average_turnaround_time);

}

void storeRec(){
    int i, n=5, r, value;
    int  PID[n], arrivalTime[n], burstTime[n];
     for (i=0; i<n; i++ )
		{
            r=rand();
          /*PID[i]= i+1;
            arrivalTime[i]= (r % 10) + 1;
		    burstTime[i]= (r % 10) + 1;*/

		    PID[i]= i+1;
            arrivalTime[i]= i+2;
		   burstTime[i]= i+3;
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
		        fprintf(fptr,"%d %d %d \n",PID[i],  arrivalTime[i], burstTime[i]);
        }
		}
		fclose(fptr);




}
