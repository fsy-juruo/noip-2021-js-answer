#include<bits/stdc++.h> 
using namespace std;
const int maxn=10000+5;
int v[maxn],tot;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int T,n;
	cin>>T;
	for(int i=1;i<=10000;i++)
	{
		n=i;
		while(n!=0)
		{
			if(n%10==7)
			{
				v[i]=1;
				break;
			}
			n/=10;
		}
	}
	for(int i=1;i<=10000;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(v[j]==1)
			{
				if(i%j==0)
				v[i]=1;
			}
		}
	}
	while(T--)
	{
		int x;  
		cin>>x;
		if(v[x]==1)
		{
			cout<<-1<<endl;
			continue;
		}  
		for(int i=x+1;i<=10000;i++)
		if(v[i]==0)
		{
		cout<<i<<endl;
		break;
      	}
	}
	return 0;
}
