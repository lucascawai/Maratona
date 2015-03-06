#include <cstdio>
#include <cstring>

#define MAXN 1805

#define max(a,b)	((a)>(b)?(a):(b))

bool terreno[MAXN][MAXN];
int perimetro;

bool verifica(int x, int y)
{
	return x >= 0 && y >= 0;
}

void pinta(int x, int y, int l, int c)
{
	for(int i = x; i < x + l; i++)
	for(int j = y; j < y + c; j++)
			terreno[i][j] = true;
}

void peri(int x, int y)
{
	int xx[] = {0, 1,  0, -1};
	int yy[] = {1, 0, -1,  0};
	for(int i = 0; i < 4; i++)
	{
		int x_ = x + xx[i],
				y_ = y + yy[i];

		if(verifica(x_, y_) && terreno[x_][y_])
			perimetro++;
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) && n)
	{
		memset(terreno, 0, sizeof terreno);

		int m = -999999999;
		for(int i = 1; i <= n; i++)
		{
			int x, y, l, c;
			scanf("%d %d %d %d", &x, &y, &l, &c);
			pinta(++x, ++y, l, c);

			m = max(m, max(x + l, y + c));
		}

		int area = 0;
		perimetro = 0;
		for(int i = 0; i < m + 3; i++)
		for(int j = 0; j < m + 3; j++)
			if(terreno[i][j])
				area++;
			else
				peri(i, j);

		printf("%d %d\n", area, perimetro);
	}

	return 0;
}