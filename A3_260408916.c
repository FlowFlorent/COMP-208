/* 

Assignment 3
Author: Florent Lefebvre
McGill id: 260408916
Editor: Sublime Text 2
Compiler: gcc (XCode)

 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int * package() //function that will generate seven card package
{
	int i, j;

	int* pack = malloc(sizeof(int)*7);

		for (int i = 0; i < 7; ++i)
		{
			pack[i]= rand() % 500;

			for ( j = 0; j < i; ++j)
			{
				if (pack[i] == pack[j]) //takes next random value if there's a duplicate
				{
					i =  --i;
				}
			}
		}

		return pack;
}

int most_duplicate(int set[]) //checks the card with most duplicates
{
	int most_duplicate = set[0] , i;

 	for ( i = 0; i < 500; ++i)
 	{	
 		if (set[i] > most_duplicate)
 		{
 			most_duplicate = set[i] ;
 		}
 	}

 	return most_duplicate;
}

float pack_stats(int packarray[]) //gives pack stats
{
	float pack_avg, sum = 0.0; 
	int i, pack_max = packarray[0], pack_min = packarray[0];

	for (i = 0; i < 100; ++i)
	{
		sum += packarray[i];

		pack_avg = sum / 100;

		if (packarray[i] > pack_max)
 		{
 			pack_max = packarray[i];
 		}
	 	if (packarray[i] < pack_min)
 		{
 			pack_min = packarray[i];
 		}
	}

	printf("Average number of packs bought = %.2f \n", pack_avg);
	printf("Maximum number of packs bought = %d \n", pack_max);
	printf("Minimum number of packs bought = %d \n", pack_min);

	return 0;
}

int main()
{
	int set[500], packarray[100], i, j, k, pack_number;
	int * pack;

	srand(time(NULL));

	for ( k = 0; k < 100; ++k) //100 experiments
	{

		pack_number = 0; //reset pack number

		for (j = 0; j < 500; ++j) //
		{

			if (set[j] == 0) //Check if value in set[] is 0 meaning that the set is not yet full
			{
				pack=package();

		 		for (i = 0; i < 7; ++i) //adds 1 to set[] value at location pack[i]
				{
					set[pack[i]]++;
				} 

				pack_number = ++pack_number;//counts the number of packs bought

				packarray[k] = pack_number;//adds the number of packs bought to the array

				j = 0;//to check array from start again

			}

		}

	memset(set, 0, sizeof(set)); //resets set[] to 0, for a new experiment

	}

	pack_stats(packarray); //prints average of packs bought

	return 0;
}