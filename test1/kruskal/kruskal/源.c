#include <stdio.h>
#define MAXE 100
#define MAXV 100
typedef struct {
	int v1;                     //边的起始顶点
	int v2;                     //边的终止顶点
	int weight;                 //边的权值
}Edge;
void kruskal(Edge E[], int n, int e)
{
	int i, j, m1, m2, s1, s2, k, sum = 0;
	int vset[MAXV];
	for (i = 1;i <= n;i++)        //初始化数组
		vset[i] = i;
	k = 1;//表示当前构造最小生成树的第k条边，初值为1
	j = 0;//E中边的下标，初值为0
	while (k < e)//生成的边数小于e时继续循环
	{
		m1 = E[j].v1;
		m2 = E[j].v2;//取一条边的两个邻接点
		s1 = vset[m1];
		s2 = vset[m2];
		if (s1 != s2)//两顶点分属于不同的集合，该边是最小生成树的一条边
		{
			printf("V%d-V%d=%d\n", m1, m2, E[j].weight);
			sum += E[j].weight;
			k++;                //生成边数增加 
			if (k >= n)
				break;
			for (i = 1;i <= n;i++)    //两个集合统一编号
				if (vset[i] == s2)  //集合编号为s2的改为s1
					vset[i] = s1;
		}
		j++;                  //扫描下一条边
	}
	printf("total:%d\n", sum);
}
int fun(Edge arr[], int low, int high)
{
	int key;
	Edge lowx;
	lowx = arr[low];
	key = arr[low].weight;
	while (low < high)
	{
		while (low < high && arr[high].weight >= key)
			high--;
		if (low < high)
			arr[low++] = arr[high];

		while (low < high && arr[low].weight <= key)
			low++;
		if (low < high)
			arr[high--] = arr[low];
	}
	arr[low] = lowx;
	return low;
}
void quick_sort(Edge arr[], int start, int end)
{
	int pos;
	if (start < end)
	{
		pos = fun(arr, start, end);
		quick_sort(arr, start, pos - 1);
		quick_sort(arr, pos + 1, end);
	}
}
int main()
{
	Edge E[MAXE];
	int nume, numn;
	scanf("%d%d", &numn, &nume);
	for (int i = 0;i < nume;i++)
		scanf("%d%d%d", &E[i].vex1, &E[i].vex2, &E[i].weight);
	quick_sort(E, 0, nume - 1);
	kruskal(E, numn, nume);
}
