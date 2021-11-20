#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
bool num[N];
int a[N],h[N],low[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0;
	for(int i=1;i<=7;i++)
	{
		int x=7*pow(10,i-1);
		while(x<1e7)
		{
			a[++k]=x;
			num[x]=true;
			for(int j=1;j<pow(10,i-1);j++)
			{
				int p=x+j;
				a[++k]=p;
				num[p]=true;
			}
			x+=pow(10,i);
		}
	}
	sort(a+1,a+k+1);
	for(int i=1;i<=k;i++)
	   for(int j=1;j<=N/a[i];j++) num[a[i]*j]=true;
	for(int i=1,j=0;i<=10000000;i++)
	{
		while(!num[i])
		{
			j++;
			low[i]=j;
			h[low[i]]=i;
			i++;
		}
	}
	int t;
	cin>>t;
	while(t--){
		int m;
		cin>>m;
		if(num[m]){
			cout<<-1<<endl;
			continue;
		}
		else cout<<h[low[m]+1]<<endl;
	}
	return 0;
}
