#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+7;
bool c[maxn];
bool check(int n)
{
	if(n%7==0) return true;
	while(n!=0)
	{
		int nn;
		nn=n%10;
		if(nn==7) return true;
		n/=10;
	}
	return false;
}
void ch(int n)
{
	if(check(n)&&n%7!=0)
	{
		for(int i=2;i<=588235;i++)
	    {
	    	if(i*n<maxn-7) c[i*n]=true;
	    	else return;
		}
	} 
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//先对全体数进行check并存入数组	
	int T,x;
	cin>>T;
	/*for(int i=1;i<=maxn-7;i++)
	{
		if(i%7==0) c[i]=true;
		if(check(i)==true)
		{
			c[i]=true;
			int m=i,cnt=2;
			while(m<=maxn-7)
			{
				m=m/(cnt-1)*cnt;
				c[m]=true;
				cnt++;
			}
		}
	}*/
	for(int k=1;k<=10000000;k++)
	{
		if(check(k)==true)
		{
			c[k]=true;
			ch(k);
		}
	}
	for(int i=1;i<=T;i++)
	{
		cin>>x;
		if(c[x]==true)
		{
			cout<<-1<<endl;
			//continue;
		}
		if(c[x]==false)
		{
			for(int j=x+1;j<=maxn-7;j++)
			if(c[j]==false){
				cout<<j<<endl;
				break;
			} 
		}
	}
	return 0;
}
