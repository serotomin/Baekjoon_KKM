#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void shell_sort(int arr[], int num)
{
	int h, i, j, value;
	h = 1;
	do h = 3 * h + 1;
	while (h < num);
	
	do {
		h = h / 3;
		for (i = h; i < num; i++)
		{
			value = arr[i];
			j = i;
		
			while (arr[j - h] > value)
			{
				arr[j] = arr[j - h];
				j -= h;
				if (j < h - 1)
					break;
			}
		arr[j] = value;
		}
	} while (h > 1);
}
int main()
{
	int arr[] = { 55, 44, 33, 22, 11 };
	int num = sizeof(arr) / sizeof(int);

	shell_sort(arr, num);

	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}