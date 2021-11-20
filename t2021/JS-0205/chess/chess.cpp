#include<bits/stdc++.h>
using namespace std;
int t,n,m,q,memory[5050][5050],level[5050][5050],col[5050][5050];
string sx[5050],sy[5050];
int a,b,c,d;
bool check1(int l,int ll)
{
	if(sx[l-1][ll]-'0'==1)return true;
	if(sx[l][ll-1]-'0'==1)return true;
	if(sy[l-1][ll]-'0'==1)return true;
	if(sy[l][ll-1]-'0'==1)return true;
	return false;
}
bool check2(int l,int ll)
{
	if(sx[l-1][ll]-'0'==2)return true;
	if(sx[l][ll-1]-'0'==2)return true;
	if(sy[l-1][ll]-'0'==2)return true;
	if(sy[l][ll-1]-'0'==2)return true;
	return false;
}
bool check3(int l,int ll)
{
	if(sx[l-1][ll]-'0'==3)return true;
	if(sx[l][ll-1]-'0'==3)return true;
	if(sy[l-1][ll]-'0'==3)return true;
	if(sy[l][ll-1]-'0'==3)return true;
	return false;
}
int dfs(int x,int y)
{
	if(check1(x,y))return 1;
	if(check2(x,y))
	{
		int tmp=0,tot=1,xx=x,yy=y;
		while(sx[xx-1][yy]-'0'==2)
		{
			xx-=1;
			tot+=1;
		}
		tmp=max(tot,tmp);
		tot=1,xx=x,yy=y;
		while(sx[xx][yy-1]-'0'==2)
		{
			xx-=1;
			tot+=1;
		}
		tmp=max(tot,tmp);
		tot=1,xx=x,yy=y;
		while(sy[xx][yy-1]-'0'==2)
		{
			xx-=1;
			tot+=1;
		}
		tmp=max(tot,tmp);
		tot=1,xx=x,yy=y;
		while(sy[xx-1][yy]-'0'==2)
		{
			xx-=1;
			tot+=1;
		}
		tmp=max(tot,tmp);
		return tmp;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>q;
		for(int j=1;j<=n;j++)
		{
			cin>>sx[j];
		}
		for(int j=1;j<n;j++)
		{
			cin>>sy[j];
		}
		for(int i=0;i<q;i++)
		{
			cin>>a>>b>>c>>d;
			cout<<dfs(c,d)<<endl;
		}
	}
	return 0;
}

