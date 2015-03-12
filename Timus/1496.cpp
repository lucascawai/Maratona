#include <cstdio>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int n;	scanf("%d", &n);

	set<string> resp, debug;
	for(int i = 1; i <= n; i++)
	{
		string str;	cin >> str;
		if(debug.find(str) != debug.end())
			resp.insert(str);
		debug.insert(str);
	}

	for(set<string>::iterator it = resp.begin(); it != resp.end(); it++)
		cout << *it << "\n";

	return 0;
}