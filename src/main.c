#include <stdio.h>
#define MAX 5

void turnOnLed(int *occupancy)
{
	/*
	if (*occupancy == MAX)
	{
		//make the LED turn on i guess?
        }
	*/
}

void  enterRoom(int *occupancy)
{
	/*
        if (*occupancy < MAX)
        {
           if (enter condition)
           {
              ++(*occupancy);



              FILE * FH = fopen("change_log.md", "r+");

              if (FH == NULL)
              {
                      printf("File did not open...\n");
                      return NULL;
              }

              fprintf(FH, "Occupancy increased by one\n");

              fclose(FH);
           }
        }else{
           printf("Sorry, room is full\n");
           return;
        }
        */
}

void  exitRoom(int *occupancy)
{
        /*
	if (*occupancy > 0)
	{
           if (exit condition) 
           {
              --(*occupancy);
           
        

              FILE * FH = fopen("change_log.md", "r+");

              if (FH == NULL)
              {
                      printf("File did not open...\n");
                      return NULL;
              }

              fprintf(FH, "Occupancy decreased by one\n");

              fclose(FH);
           }
	}else{
	   printf("Room empty\n");
	   return;
	}
        */
}


int main()
{
	int occupancyCounter  = 0;
	int choice = 0;
	char buffer[50] = {};

	printf("Hello, welcome to the Megamind study room!\n");

	while (occupancyCounter != MAX)
	{
           printf("Please select an option (1 to enter the room, 2 to exit the room, 3 to exit): \n");
           fgets(buffer, sizeof(buffer), stdin);
	   sscanf(buffer, "%d", &choice);

	   if (choice == 1)
           {
		   enterRoom(&occupancyCounter);
           }
	   else if (choice == 2)
           {
		   exitRoom(&occupancyCounter);
	   }
	   else if (choice == 3)
	   {
		   exit(0);
	   }
	   else 
	   {
		   printf("Invalid choice.\n");
	   }

	}

        if (occupancyCounter == MAX)
        {
		turnOnLed(&occupancyCounter);
	}

}
