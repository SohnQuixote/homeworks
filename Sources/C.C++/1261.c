#include <math.h>
#include <stdio.h>
int *d; int *a;
int n, m;
int x = 1;
int dis(int a, int b)
{
	if (a == 1 && b == 1)
		return 1;
	else
		return abs(a - b);
}
void search(int i, int j, int *p)
{
	int min = 99999; int temp = 99999;
	int s = i * n + j;
	if (a[s] == 1 || s == (n - 1)*n + j) return;
	while (x)
	{
		x = 0;
		if (j + 1<n && a[s + 1] == 0 && d[s] + dis(p[s + 1], p[s]) < d[s + 1])
		{
			d[s + 1] = d[s] + dis(p[s + 1], p[s]); if (min > d[s + 1]) { min = d[s + 1]; temp = 1; }
		}
		if (i + 1<m &&a[s + n] == 0 && d[s] + dis(p[s + n], p[s])< d[s + n])
		{
			d[s + n] = d[s] + dis(p[s + n], p[s]); if (min > d[s + n]) { min = d[s + n]; temp = n; }
		}
		if (j - 1>0 && a[s - 1] == 0 && d[s] + dis(p[s - 1], p[s]) < d[s - 1])
		{
			d[s - 1] = d[s] + dis(p[s - 1], p[s]); if (min > d[s - 1]) { min = d[s - 1]; temp = -1; }
		}
		if (i - 1>0 && a[s - n] == 0 && d[s] + dis(p[s - n], p[s]) < d[s - n])
		{
			d[s - n] = d[s] + dis(p[s - n], p[s]); if (min > d[s - n]) { min = d[s - n]; temp = -n; }
		}
		a[s] = 1;
		if (temp == 99999)
		{
			x = 1;
			return;
		}
		else if (temp / n == 0)
		{
			x = 1; search(i, j + temp, p);
		}
		else if (temp / n == 1 || temp / n == -1)
		{
			x = 1; search(i + temp / n, j, p);
		}
	}
}

int main(void)
{
	/*scanf_s("%d %d", &n, &m);*/
	n = 3; m = 3;
	int *p = (int*)malloc(n*m * sizeof(int));
	d = (int*)malloc(n*m * sizeof(int));
	a = (int*)malloc(n*m * sizeof(int));
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			/*scanf_s("%d", &p[i*n + j]);*/ d[i*n + j] = 5000; a[i*n + j] = 0;
		}
	}
	p[0] = 0; p[1] = 1; p[2] = 1; p[3] = 1; p[4] = 1; p[5] = 1; p[6] = 1; p[7] = 1; p[8] = 0;
	d[0] = 0;
	for (int j = 0; j<n; j++)
	{
		if (p[j] == 0)
			search(0, j, p);
	}
	printf("%d", d[(n - 1)*n + m - 1]);
	return 0;
}