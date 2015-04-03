#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int n_casos;	scanf("%d", &n_casos);
	while(n_casos--)
	{
		map<char, double> cust;
		cust.clear();

		int k;	scanf("%d", &k);
		for(int i = 1; i <= k; i++)
		{
			char ch;	double x;	scanf(" %c %lf", &ch, &x);
			cust[ch] = x/100;
		}

		int c;	scanf("%d\n", &c);
		double resp = 0.0;
		for(int i = 1; i <= c; i++)
		{	
			char ch;
			do
			{
				scanf("%c", &ch);
				if(cust.find(ch) != cust.end())
					resp += cust[ch];
			}while(ch != '\n');
		}

		printf("%.2lf$\n", resp);
	}

	return 0;
}
