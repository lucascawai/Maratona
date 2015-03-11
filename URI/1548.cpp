#include <cstdio>
#include <queue>
#include <map>

#define rep(i,k)	for( (i) = 1; (i) <= (k); (i)++)

using namespace std;

typedef pair<int, int> pii;

int main()
{
	int n_casos;	scanf("%d", &n_casos);
	while(n_casos--)
	{
		int i, n;	scanf("%d", &n);
		
		priority_queue<pii>	fila;
		rep(i, n)
		{
			int x;	scanf("%d", &x);
			fila.push( make_pair(x, i) );
		}

		int cont = 0;
		rep(i, n)
		{
			pii davez = fila.top();	fila.pop();
			printf("%d %d\n", davez.first, davez.second);
			if(davez.second == i)
				cont++;
		}

		printf("%d\n", cont);
	}

	return 0;
}