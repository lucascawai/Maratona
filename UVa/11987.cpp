#include <cstdio>
#include <vector>
#include <map>

#define MAXN 100005

#define pair<int, int> pii;

using namespace std;

vector<pii> dados;
int pai[MAXN];
int rank[MAXN];

int find(int x)
{
	return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join(int x, int y)
{
	int
}

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		dados.clear();
		for(int i = 1; i <= n; i++)
			pai[i] = i, rank[i] = 0;

		int op;	scanf("%d", &op);
		if(op == 1)
		{
			int x, y;	scanf("%d %d", &x, &y);
			join(x, y);
		}
		else if(op == 2)
		{
			int x, y;	scanf("%d %d", &x, &y);
			move(x, y);
		}
		else if(op == 3)
		{
			int x;	scanf("%d", &x);
			printf("%d %d\n", )
		}
	}

	return 0;
}