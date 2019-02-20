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

	while (low <= high)    // �������� ���� ������ �ݺ�
	{
		while (pivot > arr[low])
			low++;
		while (pivot < arr[high])
			high--;
	
		if (low <= high)    // �������� ���� ���¶�� Swap ����
			swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ
	}
	swap(arr, left, high);    // �ǹ��� high�� ����Ű�� ��� ��ȯ

	return high;    // �Ű��� �ǹ��� ��ġ ���� ��ȯ
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
	quick_sort(arr, 0, num-1); // 0 : left, �ǹ��� ���� ����  num-1 : right �ǹ��� ���� ������
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}