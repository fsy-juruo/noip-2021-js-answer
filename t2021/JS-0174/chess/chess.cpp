#include<bits/stdc++.h>
using namespace std;
int n,m,q,T,v[5005][5005],ans;
string h[5005],ll[5005];
struct Node2{
	int col,lv;
};
Node2 a[5005][5005];
void dfs(int x,int y,int con,int co,int l,int la )
{ 

	int go=(h[x][y-1]-'0'),x1=x,y1=y-1;
	if(go!=0&&(con==4||con==go))
	{
		if(v[x1][y1]==2&&a[x1][y1].col!=co&&a[x1][y1].lv<=l)
		{ans++;v[x1][y1]=3;
		}

			if(go==1) ans++;
			if(go==2){
				if(la==1){dfs(x1,y1,con,co,l,la);ans++;}
				if(la==0){dfs(x1,y1,con,co,l,1);ans++;}
			}
		if(v[x1][y1]==0)
		{	
		if(go==3){
				v[x1][y1]=1;dfs(x1,y1,con,co,l,la);ans++;
			}
		}
	}
//l
    go=int(h[x][y]-'0');x1=x;y1=y+1;
	if(go!=0&&(con==4||con==go))
	{
		if(v[x1][y1]==2&&a[x1][y1].col!=co&&a[x1][y1].lv<=l)
		{ans++;v[x1][y1]=3;
		}

			if(go==1) ans++;
			if(go==2){
				if(la==1){dfs(x1,y1,con,co,l,la);ans++;}
				if(la==0){dfs(x1,y1,con,co,l,1);ans++;}
			}
		if(v[x1][y1]==0)
		{	
		if(go==3){
				v[x1][y1]=1;dfs(x1,y1,con,co,l,la);ans++;
			}
		}
	}	

//s
    go=int(ll[x-1][y]-'0');x1=x-1;y1=y;
	if(go!=0&&(con==4||con==go))
	{
		if(v[x1][y1]==2&&a[x1][y1].col!=co&&a[x1][y1].lv<=l)
		{ans++;v[x1][y1]=3;
		}

			if(go==1) ans++;
			if(go==2){
				if(la==1){dfs(x1,y1,con,co,l,la);ans++;}
				if(la==0){dfs(x1,y1,con,co,l,1);ans++;}
			}
		if(v[x1][y1]==0)
		{	
		if(go==3){
				v[x1][y1]=1;dfs(x1,y1,con,co,l,la);ans++;
			}
		}
	}
	
//x
    go=int(ll[x][y]-'0');x1=x+1;y1=y;
	if(go!=0&&(con==4||con==go))
	{
		if(v[x1][y1]==2&&a[x1][y1].col!=co&&a[x1][y1].lv<=l)
		{ans++;v[x1][y1]=3;
		}

			if(go==1) ans++;
			if(go==2){
				if(la==1){dfs(x1,y1,con,co,l,la);ans++;}
				if(la==0){dfs(x1,y1,con,co,l,1);ans++;}
			}
		if(v[x1][y1]==0)
		{	
		if(go==3){
				v[x1][y1]=1;dfs(x1,y1,con,co,l,la);ans++;
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T>0)
	{
		T--;
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
			cin>>h[i];
		for(int i=1;i<n;i++)
		    cin>>ll[i];
		for(int i=1;i<=q;i++)
		  {
		  	int x,y,co,l;
		  	ans=0;
		  	cin>>co>>l>>x>>y;
		  	v[x][y]=2;
		  	a[x][y].col=co;
		  	a[x][y].lv=l;
		  	dfs(x,y,4,co,l,0);
		  	cout<<ans<<endl;
		  	for(int i=1;i<=n;i++)
		  	  for(int j=1;j<=m;j++)
		  	    {
		  	      if(v[i][j]==1)v[i][j]=0;
				  if(v[i][j]==3)v[i][j]=2;		
				  }
				  cout<<ans<<endl;
		  }
	}
	return 0;
}

