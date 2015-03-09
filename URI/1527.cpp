#include <cstdio>

#define MAXN 100005

int n, m;
int pai[MAXN];
int forca[MAXN];
int rank[MAXN];

int find(int x)
{
	return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join(int x, int y)
{
	int pai_x = find(x);
	int pai_y = find(y);

	if(rank[pai_x] > rank[pai_y])
	{
		pai[pai_y] = pai_x;
		forca[pai_x] += forca[pai_y];
	}
	else
	{
		pai[pai_x] = pai_y;
		forca[pai_y] += forca[pai_x];

		if(rank[pai_x] == rank[pai_y])
			rank[pai_y]++;
	}
}

int main()
{
	while(scanf("%d %d", &n, &m) && n && m)
	{
		for(int i = 1; i <= n; i++)
		{
			int pt;	scanf("%d", &pt);

			pai[i] = i;
			forca[i] = pt;
			rank[i] = 0;
		}

		int n_victory = 0;
		for(int i = 1; i <= m; i++)
		{
			int q, a, b;	scanf("%d %d %d", &q, &a, &b);

			if(q == 1)
				join(a, b);
			if(q == 2)
			{
				int pai_a = find(a);
				int pai_b = find(b);
				int pai_raf = find(1);

				if(pai_raf == pai_a || pai_raf == pai_b)
				{
					int force_raf = pai_raf == pai_a ? forca[pai_a] : forca[pai_b];
					int force_enemy = pai_raf == pai_a ? forca[pai_b] : forca[pai_a];

					if(force_raf > force_enemy)
						n_victory++;
				}
			}
		}

		printf("%d\n", n_victory);
	}

	return 0;
}