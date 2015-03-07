#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>

#define MAXN 150
#define MAXM 10005

#define INF 0x3f

#define min(a, b)	((a)<(b)?(a):(b))

using namespace std;

typedef pair<int, int> pii;

int n, m;
int ruas[MAXN][MAXN];

int dijkstra(int s, int d)
{
	int dist[MAXN];
	for(int i = 1; i <= n; i++)
		dist[i] = i != s ? INF : 0;

	set<int> visited;
	priority_queue<pii, vector<pii>, greater<pii> > fila;
	for(int i = 1; i <= n; i++)
		fila.push( make_pair(i, ruas[s][i]) );

	while(!fila.empty())
	{
		int davez = fila.top().first;	fila.pop();
		
		set<int>::iterator it = visited.find(davez);
		if(it != visited.end())	
			continue;
		visited.insert(davez);

		for(int i = 1; i <= n; i++)
				dist[i] = min(dist[i], dist[davez] + ruas[davez][i]);
	}

	return dist[d];
}

int main()
{
	while(scanf("%d %d", &n, &m) && n && m)
	{
		memset(ruas, 0, sizeof ruas);
		for(int i = 1; i <= m; i++)
		{
			int x, y, t;	scanf("%d %d %d", &x, &y, &t);
			ruas[x][y] = t;
		}

		int s, d;	scanf("%d %d", &s, &d);
		int x = dijkstra(s, d);
		printf("%d\n", x == INF ? -1 : x);
	}
	
	return 0;
}