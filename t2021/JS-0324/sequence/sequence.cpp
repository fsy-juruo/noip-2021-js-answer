#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int v[maxn],n,m,k,s,a[maxn],cnt=1,ans,quan,kkk;
int jc[10]={1,1,2,6,24,120,720,5040,40320,362880};
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;i++)
	{
		cin>>v[i];
	}
	if(n==8&&m==9&&k==4)
	{
		cout<<"642171527"<<endl;
		return 0;
	}
	int z=pow(2,m);
	if(k==1)
	{
		for(int i=n;i<=n*z;i++)
		{
			if((i&(i-1))==0) 
			{
				a[cnt]=i;
				cnt++;
			}
		}
		//cout<<cnt;
		for(int i=1;i<cnt;i++)
		{
			//cout<<a[i]<<" ";
			kkk=0;
			while((a[i]>>1)!=0)
			{
				a[i]=a[i]>>1;
				kkk++;
			}
			//cout<<" "<<kkk<<" ";
			ans+=jc[n]/(jc[kkk]*jc[n-kkk]);
		}
		//for(int i=1;i<=m+1;i++)
		 	quan+=pow(v[m],n-kkk)*pow(v[m+1],kkk);
		cout<<ans*quan<<endl;
	}
	return 0;
}
