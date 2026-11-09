#include <stdio.h>


void turnOnLed(int *occupancy)
{
	/*
	if (*occupancy == MAX)
	{
		//make the LED turn on i guess?
        }
	*/
}

void  enterRoom(int *occupancy, int max)
{
	
        if (*occupancy < max)
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
			
        }else{
           printf("Sorry, room is full\n");
           return;
        }
        
}

void  exitRoom(int *occupancy)
{
        
	if (*occupancy > 0)
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
	}else{
	   printf("Room already empty\n");
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

		switch(choice): 
    case 1:
	   enterRoom(&occupancyCounter, maxOccupancy);
	   break;

   case 2:
	   exitRoom(&occupancyCounter);
	   break;

   case 3:
	   printf("Enter new max occupancy value: ");
	   fgets(buffer, sizeof(buffer), stdin);
	   sscanf(buffer, "%d", &maxOccupancy);
	   printf("\nNew max occupancy: %d\n", maxOccupancy);
	   break;

   case 4:
      exit(0);
       break;

   default:
	   printf("invalid choice\n");
	}


	/*
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
	*/

}
