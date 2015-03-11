#include <cstdio>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
	int n;
	bitset<3005> correct, teste;
	while(scanf("%d", &n) != EOF)
	{
		teste.reset();
		correct.set();	correct[0] = 0;
		int v[3005];

		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &v[i]);

			int opa = fabs(v[i] - v[i-1]);
			if(i >= 2 && opa > 0 && opa < n)
				teste[opa] = 1;
		}

		correct &= teste;
		if(correct.count() == n - 1)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}

	return 0;
}