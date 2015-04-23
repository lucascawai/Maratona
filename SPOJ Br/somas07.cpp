#include <cstdio>

#include <vector>
#include <algorithm>

#define MAXN 100010

using namespace std;

vector<int> adj[MAXN], conj[2];
int par[MAXN], vis[MAXN], v[MAXN];

int dfs(int u, int pi, int p)
{
	vis[u] = 1;
	par[u] = p;
	conj[p].push_back(v[u]);
	for(int i = 0 ; i < (int)adj[u].size(); i++)
	{
		int q = adj[u][i];
		if(q == pi)	continue;
		if(vis[q] && par[u] == par[q])		return 0;
		if(!vis[q] && !dfs(q, u, 1 - p))	return 0;
	}

	return 1;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
		vis[i] = 0;
		par[i] = -1;
	}
	for(int i = 0; i < m; i++)
	{
		int s;	scanf("%d", &s);
		int	fi = n - 1;
		int in = 0;
		while(fi > in)
		{
			if(v[in] + v[fi] > s)				fi--;
			else if(v[in] + v[fi] < s)	in++;
			else
			{
				adj[in].push_back(fi);
				adj[fi].push_back(in);
				in++;
			}
		}
	}
	int ret = 1;
	for(int i = 0; i < n; i++)
	{
		int p = 0;
		if(vis[i])	continue;
		if( !(ret = dfs(i, i, p)) )	break;
	}
	if(!ret)	printf("-1\n-1\n");
	else
	{
		sort(conj[0].begin(), conj[0].end());
		sort(conj[1].begin(), conj[1].end());
		printf("%d", (int)conj[0].size());
		for(int i = 0; i < (int)conj[0].size(); i++)
			printf(" %d", conj[0][i]);
		printf("\n%d", (int)conj[1].size());
		for(int i = 0; i < (int)conj[1].size(); i++)
			printf(" %d", conj[1][i]);
		printf("\n");
	}		

	return 0;
}
