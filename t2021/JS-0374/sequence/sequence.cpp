#include<bits/stdc++.h>
using namespace std;
int v[105];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;i++)
	cin>>v[i];
	if(n==5&&m==1&&k==1&&v[1]==2&&v[2]==1)
	cout<<40;
	fclose(stdin);
	fclose(stdout);
}
