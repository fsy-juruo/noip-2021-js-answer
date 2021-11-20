#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
char rdi[1010][1010];//i->i+1
char rdj[1010][1010];//j->j+1
int mp[1010][1010];
int dir[10][3]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};
bool vis[1010][1010];
map<int,int>p;
int n,m,q,ans,col,lv,nxtx,nxty;
bool inside(int x,int y){return x>0&&y>0&&x<=n&&y<=m;}
int has(int x,int y){return x*10000+y;}
void dfs(int x,int y){
	if(mp[x][y]!=0){
		if(col*mp[x][y]<0){
			if(abs(mp[x][y])<=lv){
				if(p[has(x,y)]==0){
					ans++;
					p[has(x,y)]=1;
				}
			}
		}
		return;
	}else{
		if(p[has(x,y)]==0){
			ans++;
			p[has(x,y)]=1;
		}
		for(int i=1;i<=4;i++){
			int tx=x+dir[i][0];
			int ty=y+dir[i][1];
			if(!vis[tx][ty]&&inside(tx,ty)){
				bool flg=0;
				int fx=dir[i][0];
				int fy=dir[i][1];
				if(fx==0){
					if(fy==1){
						if(rdj[x][y]-'0'==3)flg=1;
					}else{
						if(rdj[x][y-1]-'0'==3)flg=1;
					}
				}else{
					if(fx==1){
						if(rdi[x][y]-'0'==3)flg=1;
					}else{
						if(rdi[x-1][y]-'0'==3)flg=1;
					}
				}
//				cout<<"!!"<<endl;
				if(flg==0)continue;
//				cout<<"!"<<endl;
				vis[tx][ty]=1;
				dfs(tx,ty);
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	cin>>T;
	
	while(T--){
		memset(mp,0,sizeof(mp));
		n=read(),m=read(),q=read();
		
		for(int i=1;i<=n;i++)for(int j=1;j<=m-1;j++)cin>>rdj[i][j];
		for(int i=1;i<=n-1;i++)for(int j=1;j<=m;j++)cin>>rdi[i][j];
		for(int qwe=1;qwe<=q;qwe++){
			memset(vis,0,sizeof(vis));
			col=read(),lv=read(),nxtx=read(),nxty=read();
			if(col==0)col=-1;
			p.clear();
			p[has(nxtx,nxty)]=1;
			ans=0;
			//(i,j)->(i+1,j)
			if(rdi[nxtx][nxty]!='0'){
				int rd=rdi[nxtx][nxty]-'0';
				if(rd==1){
					if(mp[nxtx+1][nxty]!=0){
						if(mp[nxtx+1][nxty]*col<0){
							if(abs(mp[nxtx+1][nxty]<=lv)){
								if(p[has(nxtx+1,nxty)]==0){
									p[has(nxtx+1,nxty)]=1;
									ans++;
								}
							} 
						}
					}else{
						if(p[has(nxtx+1,nxty)]==0){
							p[has(nxtx+1,nxty)]=1;
							ans++;
						}
					}
				}
				if(rd==2){
					int i=nxtx;
					while(rdi[i][nxty]-'0'==2&&inside(i+1,nxty)){
						if(mp[i+1][nxty]!=0){
							if(mp[i+1][nxty]*col<0){
								if(abs(mp[i+1][nxty])<=lv){
									if(p[has(i+1,nxty)]==0){
										ans++;
										p[has(i+1,nxty)]=1;
									}
								}
							}
							break;
						}else{
							if(p[has(i+1,nxty)]==0){
								ans++;
								p[has(i+1,nxty)]=1;
							}
							i++;
						}
					}
				}
				if(rd==3)dfs(nxtx,nxty);
			}
			//(i,j)->(i-1,j)
			if(rdi[nxtx-1][nxty]!='0'){
				int rd=rdi[nxtx-1][nxty]-'0';
				if(rd==1){
					if(mp[nxtx-1][nxty]!=0){
						if(mp[nxtx-1][nxty]*col<0){
							if(abs(mp[nxtx-1][nxty])<=lv){
								if(p[has(nxtx-1,nxty)]==0){
									ans++;
									p[has(nxtx-1,nxty)]=1;
								}
							}
						}
					}else{
						if(p[has(nxtx-1,nxty)]==0){
							ans++;
							p[has(nxtx-1,nxty)]=1;
						}
					}
				}
				if(rd==2){
					int i=nxtx;
					while(rdi[i-1][nxty]-'0'==2&&inside(i-1,nxty)){
						if(mp[i-1][nxty]!=0){
							if(mp[i-1][nxty]*col<0){
								if(abs(mp[i-1][nxty])<=lv){
									if(p[has(i-1,nxty)]==0){
										ans++;
										p[has(i-1,nxty)]=1;
									}
								}
							}
							break;
						}else{
							if(p[has(i-1,nxty)]==0){
								ans++;
								p[has(i-1,nxty)]=1;
							}
							i--;
						}
					}
				}
				if(rd==3)dfs(nxtx,nxty);
			}
			//(i,j)->(i,j+1)
			if(rdj[nxtx][nxty]!='0'){
				int rd=rdj[nxtx][nxty]-'0';
				if(rd==1){
					if(mp[nxtx][nxty+1]!=0){
						if(mp[nxtx][nxty+1]*col<0){
							if(abs(mp[nxtx][nxty+1])<=lv){
								if(p[has(nxtx,nxty+1)]==0){
									ans++;
									p[has(nxtx,nxty+1)]=1;
								}
							}
						}
					}else{
						if(p[has(nxtx,nxty+1)]==0){
							ans++;
							p[has(nxtx,nxty+1)]=1;
						}
					}
				}
				
				if(rd==2){
					int j=nxty;
					while(rdj[nxtx][j]-'0'==2&&inside(nxtx,j+1)){
						if(mp[nxtx][j+1]!=0){
							if(mp[nxtx][j+1]*col<0){
								if(abs(mp[nxtx][j+1])<=lv){
									if(p[has(nxtx,j+1)]==0){
										ans++;
										p[has(nxtx,j+1)]=1;
									}
								}
							}
							break;
						}else{
							if(p[has(nxtx,j+1)]==0){
								ans++;
								p[has(nxtx,j+1)]=1;
							}
							j++;
						}
					}
				}
				if(rd==3)dfs(nxtx,nxty);
			}
			//(i,j)->(i,j-1)
			if(rdj[nxtx][nxty-1]!='0'){
				int rd=rdj[nxtx][nxty-1]-'0';
				if(rd==1){
					if(mp[nxtx][nxty-1]!=0){
						if(mp[nxtx][nxty-1]*col<0){
							if(abs(mp[nxtx][nxty-1])<=lv){
								if(p[has(nxtx,nxty-1)]==0){
									ans++;
									p[has(nxtx,nxty-1)]=1;
								}
							}
						}
					}else{
						if(p[has(nxtx,nxty-1)]==0){
							ans++;
							p[has(nxtx,nxty-1)]=1;
						}
					}
				}
				if(rd==2){
					int j=nxty;
					while(rdj[nxtx][j-1]-'0'==2&&inside(nxtx,j-1)){
						if(mp[nxtx][j-1]!=0){
							if(mp[nxtx][j-1]*col<0){
								if(abs(mp[nxtx][j-1])<=lv){
									if(p[has(nxtx,j-1)]==0){
										ans++;
										p[has(nxtx,j-1)]=1;
									}
								}
							}
							break;
						}else{
							if(p[has(nxtx,j-1)]==0){
								ans++;
								p[has(nxtx,j-1)]=1;
							}
							j--;
						}
					}
				}
				if(rd==3)dfs(nxtx,nxty);
			}
			mp[nxtx][nxty]=lv*col;
			cout<<ans<<endl;
		}
	}
	return 0;
}
