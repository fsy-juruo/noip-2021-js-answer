#include<bits/stdc++.h>
#define SIZE 10000010
using namespace std;
int T,num;
bool v[SIZE];
vector<int> a;
int erfen(int x)
{
	int l=0,r=a.size()-1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>=x)
			r=mid;
		else
			l=mid+1;
	}
	return a[l];
}
bool break_down(int x)
{
	while(x)
	{
		if(x%10==7)	
			return true;
		x/=10;
	}
	return false;
}
void Pre()
{
	memset(v,0,sizeof(v));
	for(int i=7;i<SIZE;i++)
	{
		if(break_down(i)&&!v[i])
		{
			for(int j=1;j<=SIZE/i;j++)
				v[i*j]=1;
		}
	}
	for(int i=1;i<SIZE;i++)
		if(!v[i])
			a.push_back(i);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	Pre();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&num);
		v[num]?puts("-1"):printf("%d\n",erfen(num+1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
