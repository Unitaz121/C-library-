// Aleksandrs Kucinskis, Student number- F020717, Module details: Digital Application Development. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library
{
	char vl_model[30];
	char manufacturer[30];
	float price;
};

int main()
{
	struct library l[100];
	char mn_nm[30], vl_md[30];
	int i, j, keepcount;
	i = j = keepcount = 0; // for the lib not to skip

	int ss = sizeof(struct library);
	printf("ss = %d\n", ss);

	//  you can uncomment this to start with vehicles in the array. Helps testing
	/*strcpy(l[0].vl_model, "model1");
	strcpy(l[0].manufacturer, "manuf1");
	l[0].price = 10;
	strcpy(l[1].vl_model, "model2");
	strcpy(l[1].manufacturer, "manuf2");
	l[1].price = 20;
	strcpy(l[2].vl_model, "model3");
	strcpy(l[2].manufacturer, "manuf3");
	l[2].price = 30;
	strcpy(l[3].vl_model, "model4");
	strcpy(l[3].manufacturer, "manuf4");
	l[3].price = 40;
	keepcount = 4;*/

	printf("\n\n Vehicle data library \n");
	while (j != 6)
	{
		printf("\n1. Add vehicle information\n");
		printf("2. Remove a vehicle from the list\n");
		printf("3. Display all available vehicles\n");
		printf("4. Display a highest price vehicle\n");
		printf("5. Display a list of manufacturers\n");
		printf("6. Exit");

		printf("\n\nEnter one of the above : ");
		scanf("%d", &j);

		switch (j)
		{

		case 1: // each vehicle must have a position in an array

			printf("Enter vehicle model = ");
			scanf("%s", l[i].vl_model);

			printf("Enter manufacturer name = ");
			scanf("%s", l[i].manufacturer);

			printf("Enter price = ");
			scanf("%f", &l[i].price);
			keepcount++;
			break;

		case 2:
			printf("Model of vehicle to remove = ");
			char model[30];
			scanf("%s", model);
			int indexToRemove = -1;
			for (i = 0; i < keepcount; i++)
			{
				if (strcmp(l[i].vl_model, model) == 0)
				{
					indexToRemove = i;
					break;
				}
			}
			if (indexToRemove == -1)
			{
				printf("Could not find model: %s\n", model);
			}
			else
			{
				
				// As the array "l" is all layed out contiguously in memory,
				// I can use memmove to copy the rest of the array to fill the gap
				// using pointer arithmetic (& operator)
				// sizeof(struct library) gives the size of a vehicle in memory in bytes: 30 (model) + 30 (manufacturer) + 4 (price) = 64
				// [0] [1] [2] [3]		keepcount=4
				//      x				indexToRemove=1
				// => moveCount = 2 (moving [2] and [3])
				printf("Deleting vehicle at index: %d", indexToRemove);
				int moveCount = keepcount - indexToRemove - 1;
				memmove(&l[indexToRemove], &l[indexToRemove + 1], moveCount * sizeof(struct library));
				keepcount--;
			}
			break;

		case 3:

			printf("Display all available vehicles\n");
			for (i = 0; i < keepcount; i++)
			{
				printf("\n vehicle model = %s", l[i].vl_model);

				printf("\t manufacturer name = %s", l[i].manufacturer);

				printf("\t  price = %f", l[i].price);
			}
			break;

		case 4:
			printf("Highest vehicle price : ");
			float temp = 0;
			for (i = 0; i < keepcount; i++)
			{
				if (temp < l[i].price)
					temp = l[i].price;
			}
			printf("%f", temp);
			break;

		case 5:
			printf("List of manufacturers : ");
			for (i = 0; i < keepcount; i++)
			{
				printf("\n %s ", l[i].manufacturer);
			}
			break;

		case 6:
			exit(0);
		}
	}
	return 0;
}
