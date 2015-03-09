#include <cstdio>

#define MAXN 10005

#define rep(i, b, e)	for((i) = (b); (i) <= (e); (i)++)

int main()
{
	int n, i;
	while(scanf("%d", &n) && n)
	{
		int v[MAXN];
		rep(i, 1, n)
			scanf("%d", &v[i]);
		v[n+1] = v[1];

		bool vdd = false;
		int resp = 0;
		vdd = v[i] < v[i-1] ? true : false;
		rep(i, 2, n + 1)
		{
			if(v[i] < v[i-1] && !vdd)
				resp++, vdd = true;
			if(v[i] > v[i-1] && vdd)
				resp++, vdd = false;
		}

		printf("%d\n", resp);
	}

	return 0;
}