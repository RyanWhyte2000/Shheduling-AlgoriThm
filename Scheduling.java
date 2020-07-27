import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import java.util.Scanner;
import java.util.Random;

public class Scheduling {
	
		
	public void roundrobin(){
		
		int[] rem_Burst;
		int[] Wait_Time= {0};
		int time=0;
		Scanner input = new Scanner(System.in);
		
		System.out.println(" Enter the Quantum");
		int quantum= input.nextInt();
		
		
		
	
	
		
		
	}
	
	public void SRTF() {
		
		
	}
	
	public void NPP() {
		
		
	}
	    
	public void SJF() {
		
		
	}
	
	public void FCFS() {
		
		
	}

	public void writetofile() {/* This method writes puzzle and category to file*/
			
	     	Random rand = new Random(); /*GENRATE RANDOM NUMBER*/

			int PID= rand.nextInt(10 - 1) + 1;
			int arrival= rand.nextInt(10 - 1) + 1;
			int burst= rand.nextInt(10 - 1) + 1;
			try { 
				Scanner in = new Scanner(System.in);
				File file = new File("Schedule.txt"); /*FILE DECLARATION*/
				
				
				
				file.createNewFile();
				if (file.exists()) {/*CHECK IF FILE EXISTS ON MACHINE*/

					FileWriter writer = new FileWriter(file, true);
					
					/* WRITES DATA TO FILE*/
					writer.write( PID);
					writer.write( arrival);
					writer.write(burst);

					writer.close();

				} else {

					System.out.println("File not Found");
					in.close();
				} 
			} catch (IOException e) {

				System.out.println("File Error");
				e.printStackTrace();
			}

			
		}






}

