#include <cstdio>
#include <cstring>

#define min(a, b)	((a)<(b)?(a):(b))

#define INF 999999999
#define MAXC 100005
#define MAXN 1005

int main()
{
	int n_casos;	scanf("%d", &n_casos);
	while(n_casos--)
	{
		int n;	scanf("%d", &n);
		
		int minimum = INF;
		char viz[MAXC];
		int fila[MAXN];
		for(int i = 1; i <= n; i++)
		{
			getchar();
			scanf("%[^\n]s", viz);

			int cont = 0;
			int tam = strlen(viz);
			for(int j = 0; j < tam; j++)
				if(viz[j] == ' ')
					cont++;
			fila[i] = cont;
			minimum = min(cont, minimum);
		}

		for(int i = 1; i <= n; i++)
			if(fila[i] == minimum)
				printf("%d ", i);
		printf("\n");
	}

	return 0;
}
/**
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f

int main()
{
	int Vizinhos2[1000];
	char Vizinhos[100000];
	int len, min, cont;
	int N, P;
	int i, j, k;
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		min = INF;
		scanf("%d", &P);
		for(j=0;j<P;j++)
		{
			cont = 0;
			getchar();
			scanf("%[^\n]s",Vizinhos);
			len = strlen(Vizinhos);
			for(k=0;k<len;k++)
			{
				if(Vizinhos[k] == ' ')
					cont++;
			}
			Vizinhos2[j] = cont+1;
			if(Vizinhos2[j] < min)
			{
				min = Vizinhos2[j];
			}
		}
		for(j=0;j<P;j++)
		{
			if(Vizinhos2[j] == min)
				printf("%d ", j+1);
		}
		printf("\n");
	}
	return 0;
}**/
