#include <stdio.h>
#include<math.h>
char X[130], Y[130];
int A[130][130] = { 0 }, B[130][130] = { 0 };
int m, n;
void print(int B[][130], int i, int j) {
	if (i == 0 || j == 0)
	{
		return;
	}
	if (B[i][j] == 2) 
	{
		print(B, i - 1, j - 1);
		printf("%c ", X[i]);
	}
	else if (B[i][j] == 1)
	{
		print(B, i - 1, j);
	}
	else 
	{
		print(B, i, j - 1);
	}
}
void LCS(char X[], int m, char Y[], int n, int A[][130], int B[][130]) {
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; ++j) 
		{
			if (X[i] == Y[j]) {
				A[i][j] = A[i - 1][j - 1] + 1;
				B[i][j] = 2;
			}
			else
			{
				if (A[i - 1][j] > A[i][j - 1])
				{
					A[i][j] = A[i - 1][j];
					B[i][j] = 1;
				}
				else {
					A[i][j] = A[i][j - 1];
					B[i][j] = 0;
				}
			}
		}
	}
	print(B, m, n);
}
int main() 
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c", &X[i]);
	}
	for (int i = 1; i <= n; i++) 
	{
		scanf(" %c", &Y[i]);
	}
	LCS(X, m, Y, n, A, B);
}