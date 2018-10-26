#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define n 4

void slash()
{
	printf("\n");
}


void clear()
{
	system("cls"); 
}


int enter_koef()
{
	int k = 0;
	printf("Enter your rate: ");
	scanf("%d", &k);
	slash();
	while (k > 10 || k < 0)
	{
		printf("Enter your rate againe: ");
		scanf("%d", &k);
		slash();
	}
	clear();
	printf("Your rate is: %d", k);
	return k;
}


void color_generation(int **mass)
{
	slash();
	srand(time(NULL) | clock());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mass[i][j] = 0 + rand() % 255;
		}
	}
}



void inverse(int **mass, int **mass1, int k)
{
	int hh, ww, x1, y1;
	for (int i = 0, x1 = 0; i < n*k; i+=k, x1++)
	{
		for (int j = 0, y1 = 0; j < n*k; j+=k, y1++)
		{
			for (int h = i, hh = 0; hh < k; hh++, h++)
			{
				for (int w = j, ww = 0; ww < k; ww++, w++)
				{
					mass1[h][w] = mass[x1][y1];
				}
			}
		}
	}

}
void print_mas(int **mass)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf(" %d ", mass[i][j]);
		}
		slash();
	}
}


void print_exit_mass(int **mass, int k)
{
	for(int i = 0; i < n*k; i++)
	{	
		for(int j = 0; j < n*k; j++)
		{
			printf(" %d ", mass[i][j]);
		}
		slash();
		slash();
	}
}

int main(void)
{
	int k = enter_koef();
	int **mass_first;
	mass_first = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		mass_first[i] = (int*)calloc(n, sizeof(int));
	}
	int **mass_second;
	mass_second = (int**)calloc(n*k, sizeof(int*));
	for (int i = 0; i < n*k; i++) {
		mass_second[i] = (int*)calloc(n*k, sizeof(int));
	}
	color_generation(mass_first);
	print_mas(mass_first);
	slash();
	inverse(mass_first, mass_second, k);
	print_exit_mass(mass_second, k);
	return 0;
}
