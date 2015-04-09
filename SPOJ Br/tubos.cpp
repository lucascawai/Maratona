#include <cstdio>
#include <cstring>

#include <stack>

#define MAXN 1005
#define INF 999999999

using namespace std;

int n, m;
bool graph[MAXN][MAXN];

bool visited[MAXN];
int time;
int components;

stack<int> pilha;
int lowlink[MAXN];

void dfs(int v)
{
	lowlink[v] = time++;
	visited[v] = true;
	bool isRoot = true;
	pilha.push(v);

	for(int i = 1; i <= n; i++)
		if(graph[v][i])
		{
			int at = i;

			if( !visited[at] )
				graph[i][v] = false, dfs(at);
			if( lowlink[v] > lowlink[at] )
			{
				lowlink[v] = lowlink[at];
				isRoot = false;
			}
		}

	if(isRoot)
	{
		int u;
		do
		{
			u = pilha.top(); pilha.pop();
			lowlink[u] = INF;
		}while(u != v);
	
		components++;	
	}
}

int tarjan()
{
	memset(visited, 0, sizeof visited);
	time = 0;
	components = 0;

	for(int i = 1; i <= n; i++)
		if(!visited[i])
			dfs(i);

	return components;
}

int main()
{
	while(scanf("%d %d", &n, &m) && n && m)
	{
		memset(graph, 0, sizeof graph);
		for(int i = 1; i <= m; i++)
		{
			int x, y;	scanf("%d %d", &x, &y);
			graph[x][y] = graph[y][x] = 1;
		}
		
		printf("%c\n", tarjan() == 1 ? 'S' : 'N');
	}
	
	return 0;
}
