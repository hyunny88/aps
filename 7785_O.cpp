#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;

int main() {
	string N, s;
	int n;
	map<string, int, greater<string>> m;
	map<string, int, greater<string>>::iterator iter;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> N >> s;
		if (s == "enter")
		{
			m[N] = 1;
		}
		else
		{
			m[N] = 0;
		}
	}

	for (iter = m.begin(); iter != m.end(); ++iter)
	{
		if (iter->second == 1)
			cout << iter->first << endl;
	}


	return 0;
}