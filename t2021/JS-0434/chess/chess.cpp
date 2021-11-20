#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
   ll x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
ll n,m,q,x,y;
ll rdx[7001][7001],rdy[7001][7001];
int a[7002][7002],bx[5]={0,-1,0,1,0},by[5]={0,0,-1,0,1};
void readroad(){
	char ch;
	memset(rdx,0,sizeof(rdx));
	memset(rdy,0,sizeof(rdy));
	ch=getchar();
	for (ll i=1;i<=n;++i){
		while(ch<'0'||ch>'9')ch=getchar();
		for (ll j=2;j<=m;++j){
			rdx[i][j-1]=ch-'0';ch=getchar();
		}
	}
	for (ll i=1;i<n;++i){
		while(ch<'0'||ch>'9')ch=getchar();
		for (ll j=2;j<=m+1;++j){
			rdy[i][j-1]=ch-'0';ch=getchar();
		}
	}
}
ll straight(ll i,ll j,ll p){
	ll res=0;
	while(1){
		if (a[i][j]>0){
			if (a[i][j]>q&&a[x][y]<=q&&a[i][j]-q<=a[x][y]){
				a[i][j]*=-1;a[i][j]-=3;++res;
			}
			else if (a[i][j]<=q&&a[x][y]>q&&a[i][j]<=a[x][y]-q){
				a[i][j]*=-1;a[i][j]-=3;++res;
			}
			break;
		}
		else if(a[i][j]<-2)break;
		else if (a[i][j]==0){
			a[i][j]=-1;++res;
		}
		if (bx[p]!=0){
			if (rdy[i+(bx[p]==-1?-1:0)][j]==2)i+=bx[p];
			else break;
		}
		else {
			if (rdx[i][j+(by[p]==-1?-1:0)]==2)j+=by[p];
			else break;
		}
	}
	return res;
}
ll all(ll i,ll j,ll p){
	if (a[i][j]>0){
		if (i==x&&j==y)return 0;
		if (a[i][j]>q&&a[x][y]<=q&&a[i][j]-q<=a[x][y]){
			a[i][j]*=-1;a[i][j]-=3;return 1;
		}
		else if (a[i][j]<=q&&a[x][y]>q&&a[i][j]<=a[x][y]-q){
			a[i][j]*=-1;a[i][j]-=3;return 1;
		}
		return 0;
	}
	ll res=0;
	if (a[i][j]<=-2)return 0;
	if (a[i][j]==0){
		a[i][j]=-2;++res;
	}
	if (p!=3&&rdy[i-1][j]==3)res+=all(i-1,j,1);
	if (p!=4&&rdx[i][j-1]==3)res+=all(i,j-1,2);
	if (p!=1&&rdy[i][j]==3)res+=all(i+1,j,3);
	if (p!=2&&rdx[i][j]==3)res+=all(i,j+1,4);
	return res;
}
void disstraight(ll i,ll j,ll p){
	while(1){
		if (a[i][j]>0){
			break;
		}
		if (a[i][j]<-2){
			a[i][j]+=3;a[i][j]*=-1;
			break;
		}
		a[i][j]=0;
		if (bx[p]!=0){
			if (rdy[i+(bx[p]==-1?-1:0)][j]==2)i+=bx[p];
			else break;
		}
		else {
			if (rdx[i][j+(by[p]==-1?-1:0)]==2)j+=by[p];
			else break;
		}
	}
}
void disall(ll i,ll j,ll p){
	if (a[i][j]>0){
		return;
	}
	if (a[i][j]<-2){
		a[i][j]+=3;a[i][j]*=-1;return;
	}
	a[i][j]=1145;
	if (p!=3&&rdy[i-1][j]==3)disall(i-1,j,1);
	if (p!=4&&rdx[i][j-1]==3)disall(i,j-1,2);
	if (p!=1&&rdy[i][j]==3)disall(i+1,j,3);
	if (p!=2&&rdx[i][j]==3)disall(i,j+1,4);
	a[i][j]=0;
}
ll ans=0;
bool check(ll i,ll j){
	if (a[i][j]==0)return true;
	if (a[i][j]>0){
		if (a[i][j]>q&&a[x][y]<=q&&a[i][j]-q<=a[x][y]){
			return true;
		}
		else if (a[i][j]<=q&&a[x][y]>q&&a[i][j]<=a[x][y]-q){
			return true;
		}
	}
	return false;
}
void move(){
	if (rdy[x-1][y]>0){//up
		if (rdy[x-1][y]==1){
			if (check(x-1,y))++ans;
		}
		else {
			if (rdy[x-1][y]==2){
				ans+=straight(x-1,y,1);
			}
			else {
				ans+=all(x-1,y,1);
			}
		}
	}
	if (rdx[x][y-1]>0){//left
		if (rdx[x][y-1]==1){
			if (check(x,y-1))++ans;
		}
		else {
			if (rdx[x][y-1]==2){
				ans+=straight(x,y-1,2);
			}
			else {
				ans+=all(x,y-1,2);
			}
		}
	}
	if (rdy[x][y]>0){//down
		if (rdy[x][y]==1){
			if (check(x+1,y))++ans;
		}
		else {
			if (rdy[x][y]==2){
				ans+=straight(x+1,y,3);
			}
			else {
				ans+=all(x+1,y,3);
			}
		}
	}
	if (rdx[x][y]>0){//right
		if (rdx[x][y]==1){
			if (check(x,y+1))++ans;
		}
		else {
			if (rdx[x][y]==2){
				ans+=straight(x,y+1,4);
			}
			else {
				ans+=all(x,y+1,4);
			}
		}
	}
}
void dismove(){
	if (rdy[x-1][y]>0){//up
		if (rdy[x-1][y]==1);
		else {
			if (rdy[x-1][y]==2){
				disstraight(x-1,y,1);
			}
			else {
				disall(x-1,y,1);
			}
		}
	}
	if (rdx[x][y-1]>0){//left
		if (rdx[x][y-1]==1);
		else {
			if (rdx[x][y-1]==2){
				disstraight(x,y-1,2);
			}
			else {
				disall(x,y-1,2);
			}
		}
	}
	if (rdy[x][y]>0){//down
		if (rdy[x][y]==1);
		else {
			if (rdy[x][y]==2){
				disstraight(x+1,y,3);
			}
			else {
				disall(x+1,y,3);
			}
		}
	}
	if (rdx[x][y]>0){//right
		if (rdx[x][y]==1);
		else {
			if (rdx[x][y]==2){
				disstraight(x,y+1,4);
			}
			else {
				disall(x,y+1,4);
			}
		}
	}
}
void solve(){
	memset(a,0,sizeof(a));
	n=read();m=read();q=read();
	readroad();
	for (ll i=1;i<=q;++i){
		ll col=read(),lv=read();
		x=read();y=read();
		a[x][y]=col*q+lv;
		ans=0;
		move();
/*		
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}*/
		printf("%lld\n",ans);
		dismove();
		return;
	}
//	cerr<<1<<endl;
}
int main(){
	freopen("chess.in","r",stdin);
//	freopen("chess.out","w",stdout);
	ll T=read();
	while(T--)solve();
	return 0;
}

