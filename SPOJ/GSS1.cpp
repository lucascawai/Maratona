/**
	Questao inacabada
	Solução por dp incorreta
	**/

#include <cstdio>

#define MAXN 50005
#define INF 0x3f3f3f

#define rep(i, b, e)	for((i) = (b); (i) <= (e); (i)++)

#define	max(a, b)	((a)>(b)?(a):(b))

using namespace std;

int kadane(int num[MAXN], int x, int y)
{
	int maxSum = -INF;
	int currentMaxSum = 0;

	int i;
	rep(i, x, y)
	{
		currentMaxSum += num[i];
		if(currentMaxSum > maxSum)
			maxSum = currentMaxSum;
		if(currentMaxSum < 0)
			currentMaxSum = 0;
	}

	return maxSum;
}  

int main()
{
	int n;	scanf("%d", &n);

	int i, j;
	int num[MAXN], soma[MAXN];
	rep(i, 1, n)
	{
		int x;	scanf("%d", &x);
		num[i] = x;
		soma[i] = kadane(num, 1, i);
	}

	int m;	scanf("%d", &m);

	rep(i, 1, m)
	{
		int x, y;	scanf("%d %d", &x, &y);

		printf("%d\n", kadane(num, x, y));
	}

	return 0;
}