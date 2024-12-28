#include<bits/stdc++.h>
using namespace std;
int k,x,y,s;
int main()
{
	cin>>k>>x>>y>>s;
	return cout<<(s%k==(x+y)%k&&s>=x+y?"DA":"NU"),0;
}
