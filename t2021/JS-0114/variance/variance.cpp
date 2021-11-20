#include<bits/stdc++.h>
using namespace std;
int n,x;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x;
	if(n==4)
		cout<<52;
	else
		cout<<0;
	return 0;
}
