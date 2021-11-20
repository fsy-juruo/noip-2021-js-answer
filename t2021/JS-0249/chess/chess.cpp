#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

string w[100010];
string h[100010];
pair<int,int>vis[100010];
queue<pair<pair<int,int>,int> >Q;
struct node
{
	int x,y,co,lv;
}E[100010];
bool check(int x,int y,int co,int lv,int z)
{
	for(int i=0;i<z;i++)
		if(x==E[i].x&&y==E[i].y)
			return co!=E[i].co&&lv>=E[i].lv;
	return 1;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read();
		int m=read();
		int q=read();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m-1;j++)
				w[i]+=getchar();
			getchar();
		}
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<m;j++)
				h[i]+=getchar();
			getchar();
		}
		for(int i=0;i<q;i++)
		{
			int co=read();
			int lv=read();
			int x=read();
			int y=read();
			int ans=-1;
			int cnt=0;
			while(!Q.empty())
				Q.pop();
			Q.push({{x,y},0});
			while(!Q.empty())
			{
				pair<pair<int,int>,int>tmp=Q.front();
				Q.pop();
				vis[cnt]=tmp.first;
				cnt++;
				ans++;
				if(tmp.second==0)
				{
					// x -> .
					if(tmp.first.first<n-1)
					{
						if(w[tmp.first.second][tmp.first.first]=='1')
							ans+=!!check(tmp.first.first+1,tmp.first.second,co,lv,i);
						if(w[tmp.first.second][tmp.first.first]=='2')
						{
							int tmp2=check(tmp.first.first+1,tmp.first.second,co,lv,i);
							if(tmp2)
							{
								ans++;
								Q.push({{tmp.first.first+1,tmp.first.second},1});
							}
						}
						if(w[tmp.first.second][tmp.first.first]=='3')
						{
							int tmp2=check(tmp.first.first+1,tmp.first.second,co,lv,i);
							bool fl=1;
							for(int i=0;i<cnt;i++)
								if(vis[i].first==tmp.first.first+1&&vis[i].second==tmp.first.second)
									fl=0;
							if(tmp2&&fl)
							{
								ans++;
								Q.push({{tmp.first.first+1,tmp.first.second},5});
							}
						}
					}
					//x v .
					if(tmp.first.second<m-1)
					{
						if(h[tmp.first.first][tmp.first.second]=='1')
							ans+=!!check(tmp.first.first,tmp.first.second+1,co,lv,i);
						if(h[tmp.first.first][tmp.first.second]=='2')
						{
							int tmp2=check(tmp.first.first,tmp.first.second+1,co,lv,i);
							if(tmp2)
							{
								ans++;
								Q.push({{tmp.first.first,tmp.first.second+1},2});
							}
						}
						if(h[tmp.first.first][tmp.first.second]=='3')
						{
							int tmp2=check(tmp.first.first,tmp.first.second+1,co,lv,i);
							bool fl=1;
							for(int i=0;i<cnt;i++)
								if(vis[i].first==tmp.first.first&&vis[i].second==tmp.first.second+1)
									fl=0;
							if(tmp2&&fl)
							{
								ans++;
								Q.push({{tmp.first.first,tmp.first.second+1},5});
							}
						}
					}
					// . <- x
					if(tmp.first.first>0)
					{
						if(w[tmp.first.second][tmp.first.first-1]=='1')
							ans+=!!check(tmp.first.first-1,tmp.first.second,co,lv,i);
						if(w[tmp.first.second][tmp.first.first-1]=='2')
						{
							int tmp2=check(tmp.first.first-1,tmp.first.second,co,lv,i);
							if(tmp2)
							{
								ans++;
								Q.push({{tmp.first.first-1,tmp.first.second},3});
							}
						}
						if(w[tmp.first.second][tmp.first.first-1]=='3')
						{
							int tmp2=check(tmp.first.first-1,tmp.first.second,co,lv,i);
							bool fl=1;
							for(int i=0;i<cnt;i++)
								if(vis[i].first==tmp.first.first-1&&vis[i].second==tmp.first.second)
									fl=0;
							if(tmp2&&fl)
							{
								ans++;
								Q.push({{tmp.first.first-1,tmp.first.second},5});
							}
						}
					}
					//x ^ .
					if(tmp.first.second>0)
					{
						if(h[tmp.first.first][tmp.first.second-1]=='1')
							ans+=!!check(tmp.first.first,tmp.first.second-1,co,lv,i);
						if(h[tmp.first.first][tmp.first.second-1]=='2')
						{
							int tmp2=check(tmp.first.first,tmp.first.second-1,co,lv,i);
							if(tmp2)
							{
								ans++;
								Q.push({{tmp.first.first,tmp.first.second-1},4});
							}
						}
						if(h[tmp.first.first][tmp.first.second-1]=='3')
						{
							int tmp2=check(tmp.first.first,tmp.first.second-1,co,lv,i);
							bool fl=1;
							for(int i=0;i<cnt;i++)
								if(vis[i].first==tmp.first.first+1&&vis[i].second==tmp.first.second-1)
									fl=0;
							if(tmp2&&fl)
							{
								ans++;
								Q.push({{tmp.first.first,tmp.first.second-1},5});
							}
						}
					}
				}
				if(tmp.second==1)
				{
					if(tmp.first.first<n-1)
					{
						if(w[tmp.first.second][tmp.first.first]=='2')
						{
							int tmp2=check(tmp.first.first+1,tmp.first.second,co,lv,i);
							if(tmp2)
							{
								ans++;
								Q.push({{tmp.first.first+1,tmp.first.second},1});
							}
						}
					}
				}
				if(tmp.second==2)
				{
					if(tmp.first.second<m-1)
					{
						if(h[tmp.first.first][tmp.first.second]=='2')
						{
							int tmp2=check(tmp.first.first,tmp.first.second+1,co,lv,i);
							if(tmp2)
							{
								ans++;
								Q.push({{tmp.first.first,tmp.first.second+1},2});
							}
						}
					}
				}
				if(tmp.second==3)
				{
					if(tmp.first.first>0)
					{
						if(w[tmp.first.second][tmp.first.first-1]=='2')
						{
							int tmp2=check(tmp.first.first-1,tmp.first.second,co,lv,i);
							if(tmp2)
							{
								ans++;
								Q.push({{tmp.first.first-1,tmp.first.second},3});
							}
						}
					}
				}
				if(tmp.second==4)
				{
					if(tmp.first.second>0)
					{
						if(h[tmp.first.first][tmp.first.second-1]=='2')
						{
							int tmp2=check(tmp.first.first,tmp.first.second-1,co,lv,i);
							if(tmp2)
							{
								ans++;
								Q.push({{tmp.first.first,tmp.first.second-1},4});
							}
						}
					}
				}
				if(tmp.second==5)
				{
					// x -> .
					if(tmp.first.first<n-1)
					{
						if(w[tmp.first.second][tmp.first.first]=='3')
						{
							int tmp2=check(tmp.first.first+1,tmp.first.second,co,lv,i);
							bool fl=1;
							for(int i=0;i<cnt;i++)
								if(vis[i].first==tmp.first.first+1&&vis[i].second==tmp.first.second)
									fl=0;
							if(tmp2&&fl)
							{
								ans++;
								Q.push({{tmp.first.first+1,tmp.first.second},5});
							}
						}
					}
					//x v .
					if(tmp.first.second<m-1)
					{
						if(h[tmp.first.first][tmp.first.second]=='3')
						{
							int tmp2=check(tmp.first.first,tmp.first.second+1,co,lv,i);
							bool fl=1;
							for(int i=0;i<cnt;i++)
								if(vis[i].first==tmp.first.first+1&&vis[i].second==tmp.first.second+1)
									fl=0;
							if(tmp2&&fl)
							{
								ans++;
								Q.push({{tmp.first.first,tmp.first.second+1},5});
							}
						}
					}
					// . <- x
					if(tmp.first.first>0)
					{
						if(w[tmp.first.second][tmp.first.first-1]=='3')
						{
							int tmp2=check(tmp.first.first-1,tmp.first.second,co,lv,i);
							bool fl=1;
							for(int i=0;i<cnt;i++)
								if(vis[i].first==tmp.first.first-1&&vis[i].second==tmp.first.second)
									fl=0;
							if(tmp2&&fl)
							{
								ans++;
								Q.push({{tmp.first.first-1,tmp.first.second},5});
							}
						}
					}
					//x ^ .
					if(tmp.first.second>0)
					{
						if(h[tmp.first.first][tmp.first.second-1]=='3')
						{
							int tmp2=check(tmp.first.first,tmp.first.second-1,co,lv,i);
							bool fl=1;
							for(int i=0;i<cnt;i++)
								if(vis[i].first==tmp.first.first+1&&vis[i].second==tmp.first.second-1)
									fl=0;
							if(tmp2&&fl)
							{
								ans++;
								Q.push({{tmp.first.first,tmp.first.second-1},5});
							}
						}
					}
				}
			}
			E[i].x=x;
			E[i].y=y;
			E[i].co=co;
			E[i].lv=lv;
			printf("%d\n",ans);
		}
	}
	return 0;
	//freopen
	//大小写
	//return
	//文件名
}

