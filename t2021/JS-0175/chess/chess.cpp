#include<bits/stdc++.h>
#define N 300010
using namespace std;
inline int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int n,m,q,t,a[N][4],c[N],l[N],ans,dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();while(t--){
		n=read();m=read();q=read();
		for(int i=1;i<=n;++i){
			string s;cin>>s;
			for(int j=1;j<m;++j){
				a[i*m+j][0]=a[i+m+j+1][1]=s[j-1]-'0';
			}
		}for(int i=1;i<n;++i){
			string s;cin>>s;
			for(int j=1;j<=m;++j){
				a[i*m+j][2]=a[(i+1)*m+j][3]=s[j-1]-'0';
			}
		}while(q--){
			int k=read(),h=read(),x=read(),y=read();
			c[x*m+y]=k;l[x*m+y]=h;
			for(int i=0;i<4;++i){
				if(a[x*m+y][i]==0)continue;
			    int xx=x+dx[i],yy=dy[i]+y;
			    if(xx<1||xx>n||yy<1||yy>m)continue;
			    if(k!=c[xx*m+yy]&&h>=l[xx*m+yy])ans++;
			}printf("%d\n",ans);ans=0;
		}
	}return 0;
}
