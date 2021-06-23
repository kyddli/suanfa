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
		middle = (low + high) / 2;   //�۰�
		if (key < a[middle])
			high = middle - 1;     //����±��Ϊ��Ӧ�����±��ǰһλ
		else if (key > a[middle])
			low = middle + 1;     //��С�±��Ϊ��Ӧ�����±�ĺ�һλ����������
		else
			return middle;      //��ȷ��ض�Ӧ�������±�
	}
	return 0;
}

int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n;
	int length = sizeof(a);
	cin >> n;
	//˳�����
	int j = SequentialSearch(a, length, n);
	//���ֲ���
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