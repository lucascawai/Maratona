#include <cstdio>
#include <string>

int main()
{
	int ev1, ev2, at, d;
	double prob[] = {0.0, 1.0/6, 2.0/6, 3.0/6, 4.0/6, 5.0/6, 1.0};
	while(scanf("%d %d %d %d", &ev1, &ev2, &at, &d)
			&& ev1 && ev2 && at && d)
	{
		double p = prob[at]; 

		int cont = 0, ind, vdd = 0;
		for(int i = -10; i <= 10; i++)
			if(ev1 + d*i > 0 && ev2 - d*i > 0)
				cont++, ind = i == 0 ? cont : ind;
		cont += 2;

		double result[cont--];
		for(int i = 0; i <= cont; i++)
			result[i] = 0.0;
		result[0] = 0.0, result[cont] = 1.0;

		int aux = 0;
		while(true)
		{
			double mem = result[ind];
			for(int i = 1; i < cont; i++)
				result[i] = result[i-1]*(1-p) + result[i+1]*p;
			if(result[ind] - mem < 0.000001 && ++aux >= 15)
				break;
		}

		printf("%.1lf\n", 100*result[ind]);
	}

	return 0;
}
