#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>

using namespace std;

void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)    // 교차되지 않을 때까지 반복
	{
		while (pivot > arr[low])
			low++;
		while (pivot < arr[high])
			high--;
	
		if (low <= high)    // 교차되지 않은 상태라면 Swap 실행
			swap(arr, low, high);    // low와 high가 가리키는 대상 교환
	}
	swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환

	return high;    // 옮겨진 피벗의 위치 정보 반환
}
void quick_sort(int arr[], int left, int right)
{
	int pivot;
	if (right >= left)
	{
		pivot = partition(arr, left, right);
		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot + 1, right);
	}
}
int main()
{
	int arr[] = { 55, 44, 33, 22, 11 };
	int num = sizeof(arr) / sizeof(int);
	quick_sort(arr, 0, num-1); // 0 : left, 피벗의 가장 왼쪽  num-1 : right 피벗의 가장 오른쪽
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}