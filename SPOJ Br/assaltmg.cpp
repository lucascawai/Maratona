#include <cstdio>
#include <cstring>

#include <bitset>

#define min(a, b)	((a)<(b)?(a):(b))

#define MAXN 32
#define INF 0x3f

using namespace std;

int main()
{
	int n_casos; 	scanf("%d", &n_casos);
	while(n_casos--)
	{
		int m, d;	scanf("%d %d", &m, &d);

		bitset<MAXN> chaves[MAXN];
		for(int i = 0; i < MAXN; i++)
			chaves[i].reset();

		for(int i = 0; i < d; i++)
		{
			int c;	scanf("%d", &c);
			for(int j = 0; j < c; j++)
			{
				int x;	scanf("%d", &x);
				chaves[i][x-1] = 1; 
			}
		}

		int num_subsets = 1 << d;
		int resp = INF, num;
		for(int i = 0; i < num_subsets; i++)
		{
			int pos = d - 1;
			int bitmask = i;

			bitset<MAXN> teste;	teste.reset();
			num = 0;
			while(bitmask > 0)
			{
				if((bitmask & 1) == 1)
					teste |= chaves[pos], num++;
				bitmask >>= 1;
				pos--;
			}

			if(teste.count() >= m)
				resp = min(resp, num);
		}

		if(resp == INF)	printf("Desastre!\n");
		else						printf("%d\n", resp);
	}

	return 0;
}