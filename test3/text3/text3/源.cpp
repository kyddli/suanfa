#include<iostream>
using namespace std;

int SequentialSearch(int a[], int n, int key)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 0;
}
int BinarySearch(int a[], int length, int key)
{
	int low = 1;
	int high = length;
	int middle;
	while (low <= high)
	{
		middle = (low + high) / 2;   //折半
		if (key < a[middle])
			high = middle - 1;     //最大下标变为对应数组下标的前一位
		else if (key > a[middle])
			low = middle + 1;     //最小下标变为对应数组下标的后一位，继续查找
		else
			return middle;      //相等返回对应的数组下标
	}
	return 0;
}

int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n;
	int length = sizeof(a);
	cin >> n;
	//顺序查找
	int j = SequentialSearch(a, length, n);
	//二分查找
	//int j = BinarySearch(a, length - 1, n);
	if (j >= 0)
	{
		cout << "j=" << j << endl;
	}
	else
	{
		cout << "j=0" << endl;
	}

	return 0;
}