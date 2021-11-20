#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define init(a,i) memset(a,i,sizeof(a))
int n,m,q,x[100005],y[100005],col[100005],lv[100005],xx,yy,ans=0;
char c;
vector<vector<int> >v1,v2,f,num; 
int aa,bb,cc;
bool check(int a,int b){
	if(num[a][b]==-1)return 1;
	if(col[num[a][b]]!=col[cc]&&lv[num[a][b]]<=lv[cc])return 1;
	return 0;
}
void dfs(int a,int b){
	if(!check(a,b))return;
	if(f[a][b])return;
	f[a][b]=1;
	if(num[a][b]!=-1&&col[num[a][b]]!=col[cc]&&lv[num[a][b]]<=lv[cc])return;
	if(b!=m-1&&v1[a][b]==3)dfs(a,b+1);
	if(a!=n-1&&v2[a][b]==3)dfs(a+1,b);
	if(b&&v1[a][b-1]==3)dfs(a,b-1);
	if(a&&v2[a-1][b]==3)dfs(a-1,b);
}
void solve(){
	cin>>n>>m>>q;
	v1.resize(n);
	v2.resize(n);
	f.resize(n);
	num.resize(n);
	rep(i,n){
		v1[i].resize(m);
		f[i].resize(m);
		num[i].resize(m);
		rep(j,m-1){
			cin>>c;
			v1[i][j]=c-'0';
		} 
	}
	rep(i,n-1){
		v2[i].resize(m);
		rep(j,m){
			cin>>c;
			v2[i][j]=c-'0';
		}
	}
	rep(i,n)rep(j,m)num[i][j]=-1;
	rep(i,q){
		cin>>col[i]>>lv[i]>>x[i]>>y[i];
		x[i]--,y[i]--;
		aa=x[i],bb=y[i],cc=i;
		rep(j,n)rep(k,m)f[j][k]=0; 
		//turnable road
		dfs(x[i],y[i]);
		//common road
		if(y[i]!=m-1&&v1[x[i]][y[i]]==1&&check(x[i],y[i]+1))f[x[i]][y[i]+1]=1;
		if(x[i]!=n-1&&v2[x[i]][y[i]]==1&&check(x[i]+1,y[i]))f[x[i]+1][y[i]]=1;
		if(y[i]&&v1[x[i]][y[i]-1]==1&&check(x[i],y[i]-1))f[x[i]][y[i]-1]=1;
		if(x[i]&&v2[x[i]-1][y[i]]==1&&check(x[i]-1,y[i]))f[x[i]-1][y[i]]=1;
		//straight road
		xx=x[i];yy=y[i];
		while(y[i]!=m-1&&v1[x[i]][y[i]]==2){ //right
			y[i]++;
			if(num[x[i]][y[i]]!=-1){
				if(col[num[x[i]][y[i]]]!=col[i]&&lv[num[x[i]][y[i]]]<=lv[i])f[x[i]][y[i]]=1;
				break;
			}
			f[x[i]][y[i]]=1;
		}
		x[i]=xx;y[i]=yy;
		while(x[i]!=n-1&&v2[x[i]][y[i]]==2){ //down
			x[i]++;
			if(num[x[i]][y[i]]!=-1){
				if(col[num[x[i]][y[i]]]!=col[i]&&lv[num[x[i]][y[i]]]<=lv[i])f[x[i]][y[i]]=1;
				break;
			}
			f[x[i]][y[i]]=1;
		}
		x[i]=xx;y[i]=yy;
		while(y[i]&&v1[x[i]][y[i]-1]==2){ //left
			y[i]--;
			if(num[x[i]][y[i]]!=-1){
				if(col[num[x[i]][y[i]]]!=col[i]&&lv[num[x[i]][y[i]]]<=lv[i])f[x[i]][y[i]]=1;
				break;
			}
			f[x[i]][y[i]]=1;
		}
		x[i]=xx;y[i]=yy;
		while(x[i]&&v2[x[i]-1][y[i]]==2){ //up
			x[i]--;
			if(num[x[i]][y[i]]!=-1){
				if(col[num[x[i]][y[i]]]!=col[i]&&lv[num[x[i]][y[i]]]<=lv[i])f[x[i]][y[i]]=1;
				break;
			}
			f[x[i]][y[i]]=1;
		}
		x[i]=xx;y[i]=yy;
		//count
		ans=0;
		rep(j,n)rep(k,m)ans+=f[j][k];
		cout<<ans-1<<endl;
		num[x[i]][y[i]]=i; 
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--){solve();}
	return 0;
}

