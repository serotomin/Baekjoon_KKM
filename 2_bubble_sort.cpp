#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
#define MAX 50000

void bubble_sort(int arr[], int num)
{
	int i, j;
	int tmp;

	//bubble sort
	for (i = 0; i < num -1; i++)
	{
		for (j = 0; j < num -1; j++) // 원래의 조건은 MAX-(i+1)...같은 의미이다.
		{
			if (arr[j] > arr[j + 1]) // 자리교환
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr [j];
				arr[j] = tmp;
			}
		}
	}
}
int main()
{
	int arr[MAX];
	int num;

	cin >> num;

	srand((unsigned)time(NULL));

	for (int i = 0; i <= num; i++)
	{
		arr[i] = rand() % 101;
	}
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	bubble_sort(arr, num);

	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}