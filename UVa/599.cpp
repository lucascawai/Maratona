#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

bool grafo[60][60];
bool visited[60];
int n_tree, n_v;

void dfs(int x)
{
	visited[x] = 1;
	for(int i = 1; i <= n_v; i++)
		if(grafo[x][i] && !visited[i])
			dfs(i);
	return;
}

int main()
{
	int n_casos; scanf("%d", &n_casos);
	while(n_casos--)
	{
		char buffer[60];
		n_v = 0;
		memset(grafo, 0, sizeof grafo);
		map<char, int> v;

		while(scanf(" %s", buffer) && buffer[0] != '*')
		{
			if(v.find(buffer[1]) == v.end())
				v[ buffer[1] ] = ++n_v;
			if(v.find(buffer[3]) == v.end())
				v[ buffer[3] ] = ++n_v;

			grafo[ v[ buffer[1] ] ][ v[ buffer[3] ] ] = 1;
			grafo[ v[ buffer[3] ] ][ v[ buffer[1] ] ] = 1;
		}

		scanf(" %s", buffer);

		int sz = strlen(buffer);
		int n_acorns = 0;
		for(int i = 0; i < sz; i += 2)
			if(v.find(buffer[i]) == v.end())
				n_acorns++;

		n_tree = 0;
		memset(visited, 0, sizeof visited);
		for(int i = 1; i <= n_v; i++)
			if(!visited[i])
				dfs(i), n_tree++;

		printf("There are %d tree(s) and %d acorn(s).\n", n_tree, n_acorns);
	}

	return 0;
}