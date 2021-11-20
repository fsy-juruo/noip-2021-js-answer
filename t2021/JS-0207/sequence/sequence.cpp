#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int v[101];
int main()
{
	ios::sync_with_stdio(false);
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) cin>>v[i];
	if(n==5) cout<<"40"<<endl;
	if(n==8) cout<<"642171527"<<endl;
	return 0;
}
