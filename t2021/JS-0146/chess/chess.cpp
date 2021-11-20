#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(0);
	int t,n,m,q;cin>>t;
	while(t--){
		cin>>n>>m>>q;
		int a[n+1][m+1],b[n+1][m+1],c,d,x,y;
		string c1[n+1],c2[n+1];bool f[n+1][m+1];
		for(int i=1;i<=n;++i){cin>>c1[i];c1[i]=' '+c1[i];}
		for(int i=1;i<n;++i){cin>>c2[i];c2[i]=' '+c2[i];}
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){a[i][j]=-1;b[i][j]=0;}
		while(q--){
			for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)f[i][j]=0;
			cin>>c>>d>>x>>y;f[x][y]=1;
			int cnt=-1,xx,yy;queue<int>xt,yt;
			xt.push(x);yt.push(y);
			while(xt.size()){
				int nx=xt.front();xt.pop();
				int ny=yt.front();yt.pop();
				xx=nx-1;yy=ny;
				if(xx>=1&&!f[xx][yy]&&c2[xx][yy]=='3'){
					if(a[xx][yy]<0){f[xx][yy]=1;xt.push(xx);yt.push(yy);}
					else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
				}
				xx=nx+1;yy=ny;
				if(xx<=n&&!f[xx][yy]&&c2[nx][ny]=='3'){
					if(a[xx][yy]<0){f[xx][yy]=1;xt.push(xx);yt.push(yy);}
					else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
				}
				xx=nx;yy=ny-1;
				if(yy>=1&&!f[xx][yy]&&c1[xx][yy]=='3'){
					if(a[xx][yy]<0){f[xx][yy]=1;xt.push(xx);yt.push(yy);}
					else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
				}
				xx=nx;yy=ny+1;
				if(yy<=m&&!f[xx][yy]&&c1[nx][ny]=='3'){
					if(a[xx][yy]<0){f[xx][yy]=1;xt.push(xx);yt.push(yy);}
					else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
				}
			}
			xx=x-1;yy=y;
			if(xx>=1&&c2[xx][yy]=='1'){
				if(a[xx][yy]<0)f[xx][yy]=1;
				else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
			}
			xx=x+1;yy=y;
			if(xx<=n&&c2[x][y]=='1'){
				if(a[xx][yy]<0)f[xx][yy]=1;
				else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
			}
			xx=x;yy=y-1;
			if(yy>=1&&c1[xx][yy]=='1'){
				if(a[xx][yy]<0)f[xx][yy]=1;
				else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
			}
			xx=x;yy=y+1;
			if(yy<=m&&c1[x][y]=='1'){
				if(a[xx][yy]<0)f[xx][yy]=1;
				else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
			}
			xx=x-1;yy=y;
			if(xx>=1&&c2[xx][yy]=='2'){
				if(a[xx][yy]<0){
					f[xx][yy]=1;
					for(--xx;xx>=1&&c2[xx][yy]=='2';--xx){
						if(a[xx][yy]<0)f[xx][yy]=1;
						else{
							if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
							break;
						}
					}
				}
				else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
			}
			xx=x+1;yy=y;
			if(xx<=n&&c2[x][y]=='2'){
				if(a[xx][yy]<0){
					f[xx][yy]=1;
					for(++xx;xx<=n&&c2[xx-1][yy]=='2';++xx){
						if(a[xx][yy]<0)f[xx][yy]=1;
						else{
							if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
							break;
						}
					}
				}
				else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
			}
			xx=x;yy=y-1;
			if(yy>=1&&c1[xx][yy]=='2'){
				if(a[xx][yy]<0){
					f[xx][yy]=1;
					for(--yy;yy>=1&&c1[xx][yy]=='2';--yy){
						if(a[xx][yy]<0)f[xx][yy]=1;
						else{
							if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
							break;
						}
					}
				}
				else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
			}
			xx=x;yy=y+1;
			if(xx<=n&&c1[x][y]=='2'){
				if(a[xx][yy]<0){
					f[xx][yy]=1;
					for(++yy;yy<=m&&c1[xx][yy-1]=='2';++yy){
						if(a[xx][yy]<0)f[xx][yy]=1;
						else{
							if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
							break;
						}
					}
				}
				else if(a[xx][yy]!=c&&b[xx][yy]<=d)f[xx][yy]=1;
			}
			for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(f[i][j])++cnt;
			cout<<cnt<<endl;a[x][y]=c;b[x][y]=d;
		}
	}
	return 0;
}
