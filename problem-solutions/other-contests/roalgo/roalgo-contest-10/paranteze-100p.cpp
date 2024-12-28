#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	vector<long long> gauss(100002);
	for(int i = 1; i <= 100000; i++)
		gauss[i] = 1LL * i * (i+1) / 2;
	
	int t;
	cin >> t;
	
    int cntfin = 0;
	while(t--)
	{
		long long n, p;
		cin >> n >> p;
		
		if(p > 1LL * (n/2) * (n/2+1) / 2)
		{
			cout << "-1\n";
			continue;
		}
        
        cntfin = 0;
		int padded = 0;

		int pos = 0;
		
		int p2 = 16;
		while(p2 >= 0)
        {
            if(pos + (1<<p2) <= 100000 && gauss[pos + (1<<p2)] <= p)
                pos += (1<<p2);
            p2--;
        }
        
		string s;
		while(pos > 0 && p)
		{
			while(p < gauss[pos])
				pos--;

			if(pos == 1)
            {
                for(int i = 0; i < p; i++)
                    s += '(';
				cntfin += p, p = 0;
            }
			else
			{
				p -= gauss[pos];
				for(int i = 0; i < pos; i++)
					s += '(', s += ')';
				cntfin++;
				s.pop_back();
			}
		}

		if(s.size() + cntfin <= n)
		{
            for(int i = 0; i < cntfin; i++)
                s += ')';
			cout << s;
			while(s.size() < n)
				s += '(', cout << '(';
		}
		else
			cout << -1;
		cout << '\n';
	}
    return 0;
}
