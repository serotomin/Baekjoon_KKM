#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
#define MAX 50000
void insertion_sort(int arr[], int num)
{
	int i, j;
	int value;

	for (i = 1; i < num; i++)
	{
		value = arr[i];
		j = i;
		while (arr[j - 1] > value)
		{
			arr[j] = arr[j - 1];
			j--;
		}
	
		arr[j] = value;
	}

}
int main()
{
	//int arr[MAX];
	int arr[] = { 55, 44, 33, 22, 11 };
	int num = sizeof(arr) / sizeof(int);

	insertion_sort(arr, num);

	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}