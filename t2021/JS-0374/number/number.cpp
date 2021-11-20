#include<bits/stdc++.h>
using namespace std;
bool v[11000000];
int jd(long long x)
{
	while(x!=0&&x%10!=7)
	x/=10;
	if(x==0)
	return 1;
	else
	return 0;
}
void mar(long long x)
{
	for(long long i=x;i<=11000000;i+=x)
	v[i]=1;
}
void op()
{
	for(long long i=7;i<=11000000;i++)
	{
		if(v[i]==0&&jd(i)==0)
		mar(i);
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long t;
	cin>>t;
	op();
	for(long long i=1;i<=t;i++)
	{
		long long x;
		cin>>x;
		if(v[x]==1)
		cout<<-1<<endl;
		else
		{
			x+=1;
			while(v[x]==1)
			x++;
			cout<<x<<endl;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
