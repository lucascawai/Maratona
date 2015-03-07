#include <cstdio>
#include <cstring>

#include <iostream>
#include <map>
#include <string>

#define MAXC 100

using namespace std;

int main()
{
	int n_instancias;	scanf("%d", &n_instancias);

	int cont = 1;
	while(cont++<=n_instancias)
	{
		int n, m;	scanf("%d %d ", &n, &m);
		
		char str1[MAXC], str2[MAXC];	
		map<string, string> dic;
		for(int i=1; i<=n; i++)
		{
			/*fflush(stdin);*/	fgets(str1, 100, stdin);	str1[strlen(str1)-1] = '\0';
			/*fflush(stdin);*/	fgets(str2, 100, stdin);	str2[strlen(str2)-1] = '\0';
			string s1 = str1, s2 = str2;

			dic[s1] = s2;
		}

		for(int i=1; i<=m; i++)
		{
			fgets(str1, 100, stdin);
			
			int tam = strlen(str1), cont = 0;	str1[tam-1] = ' ';
			for(int i=0; i<tam; i++)
			{
				if(str1[i]==' ' || str1[i]=='\0')
				{
					str2[cont] = '\0';
					cont = 0;
					
					string s = str2;
					
					map<string, string>::iterator it = dic.find(s);
					if(it!=dic.end())	cout << dic[s] << " ";
					else				printf("%s ", str2);
				}
				else
					str2[cont++] = str1[i];
			}
			printf("\n");
		}

	}

	return 0;
}
