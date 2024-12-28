#include <iostream>

using namespace std;

int v[100002];
int p[100002];
int inv[1002][1002];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			inv[i * j % m][i] = j;
		
		inv[0][i] = 0;
		inv[i][0] = 0;
	}
	
	for (int i = 2; i <= n; i++)
		if (v[i] == -1 && p[i] != -1 && p[i - 1] != -1)
			v[i] = inv[p[i]][p[i - 1]];
		else if (v[i] != -1 && p[i] == -1 && p[i - 1] != -1)
			p[i] = p[i - 1] * v[i] % m;
		else if (v[i] != -1 && p[i] != -1)
		{
			int j = i - 1;
			while (j > 1 && (v[j] == -1 || p[j] == -1))
			{
				if (p[j] == -1)
					p[j] = inv[p[j + 1]][v[j + 1]];
				if (v[j] == -1)
				{
					if (p[j - 1] == -1)
						break;
					
					v[j] = inv[p[j]][p[j - 1]];
				}
				
				j--;
			}
		}
	
	if (v[1] == -1 && p[1] != -1)
		v[1] = p[1];
	if (v[1] != -1 && p[1] == -1)
		p[1] = v[1];
	if (v[1] == -1 && p[1] == -1)
		if (v[2] == -1 || p[2] == -1)
		{
			v[1] = 1;
			p[1] = 1;
		}
		else
		{
			p[1] = inv[p[2]][v[2]];
			v[1] = p[1];
		}
	
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == -1 && p[i] == -1)
		{
			v[i] = 1;
			p[i] = p[i - 1];
		}
		if (v[i] != -1 && p[i] == -1)
			p[i] = p[i - 1] * v[i] % m;
		if (v[i] == -1 && p[i] != -1)
			v[i] = inv[p[i]][p[i - 1]];
	}
	
	for (int i = 1; i <= n; i++)
		cout << v[i] << ' ';
	cout << '\n';
	for (int i = 1; i <= n; i++)
		cout << p[i] << ' ';
	cout << '\n';
	
	return 0;
}
