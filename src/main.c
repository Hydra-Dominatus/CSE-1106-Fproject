#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#include <time.h>

#define PIN 17 

void get_timestamp(char *buffer, size_t max_size)
{
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer, max_size, "%Y-%m-%d %H:%M", timeinfo);
}

void turnOnLed(int occupancyCounter, int max)
{
  gpioInitialise();
  gpioSetMode(PIN,PI_OUTPUT);
	if (occupancyCounter == max)
	{
		printf("Room at max capacity\n\n");
		gpioWrite(PIN, 1); // LED ON
         }
	 else
	 {
		gpioWrite(PIN, 0); // LED OFF
		
		printf("Current Occupancy: %d/%d\n\n", occupancyCounter, max);
	 }
	  gpioTerminate();
	  
	  return;
		
}

void  enterRoom(int *occupancyCounter, int max)
{

        char timestamp[30];
	get_timestamp(timestamp,sizeof(timestamp));  
	
        if (*occupancyCounter < max)
        {
              ++(*occupancyCounter);


              FILE * FH = fopen("change_log.txt", "a");

              if (FH == NULL)
              {
                      printf("File did not open...\n");
                      return;
              }

              fprintf(FH, "%s Occupancy increased ,Current occupancy: %d/%d\n", timestamp, *occupancyCounter, max);

              fclose(FH);
			
        }else{
           return;
        }
        
}

void  exitRoom(int *occupancyCounter, int max)
{
  
	
        char timestamp[30];
	get_timestamp(timestamp,sizeof(timestamp));  
        
	if (*occupancyCounter > 0)
	{

              --(*occupancyCounter);
           

              FILE * FH = fopen("change_log.txt", "a");

              if (FH == NULL)
              {
                      printf("File did not open...\n");
                      return;
              }

              fprintf(FH, "%s Occupancy decreased, Current Occupancy: %d/%d\n", timestamp, *occupancyCounter, max);

              fclose(FH);
	}else{
	   printf("Room already empty\n\n");
	   return;
	}
    
}


int main()
{
	int occupancyCounter  = 0;
    int maxOccupancy = 5;
	int choice = 0;
	char buffer[50] = {};

	printf("Hello, welcome to the Megamind study room!\n");
	printf("Please select an option from the menu:\n\n");

	while(1){
		printf("1: Student enters room\n");
		printf("2: Student exits room\n");
		printf("3: Change max occupancy\n");
		printf("4: exit menu\n");
		
		printf("Enter choice: ");
		
	      fgets(buffer, sizeof(buffer), stdin);
	      sscanf(buffer, "%d", &choice);
	      
	      printf("\n");

		switch(choice) {
    case 1:
	   enterRoom(&occupancyCounter, maxOccupancy);
	   turnOnLed(occupancyCounter, maxOccupancy);
	   break;

   case 2:
	   exitRoom(&occupancyCounter, maxOccupancy);
	   turnOnLed(occupancyCounter, maxOccupancy);
	   break;

   case 3:
	   printf("Enter new max occupancy value: ");
	   fgets(buffer, sizeof(buffer), stdin);
	   sscanf(buffer, "%d", &maxOccupancy);
	   printf("\nNew max occupancy: %d\n", maxOccupancy);
	   if (occupancyCounter > maxOccupancy)
	   {
	     occupancyCounter = maxOccupancy;
	    }
	    
	   turnOnLed(occupancyCounter, maxOccupancy);
	   break;

   case 4:
      gpioInitialise();
      gpioSetMode(PIN,PI_OUTPUT);
      printf("Exiting program\n");
      gpioWrite(PIN, 0); // trun LED OFF
      gpioTerminate();
      return 0;

   default:
	   printf("invalid choice\n");
	 }
	 
	}



}
