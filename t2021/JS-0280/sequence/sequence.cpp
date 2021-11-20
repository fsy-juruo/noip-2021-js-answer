#include<bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int read(){
	 int r=0,f=1;char ch=getchar();
	 while (!isdigit(ch)&&ch!='-') ch=getchar();
	 if (ch=='-') f=-1,ch=getchar();
	 while (isdigit(ch)) r=(r<<3)+(r<<1)+ch-'0',ch=getchar();
	 return r*f;
}
int ksm(int a,int b){
	int ans=1;
	for (int i=1;i<=b;i++) ans*=a,ans%=mod;
	return ans;
}
int n,m,k;
int v[500005],d[500005],c[500005],Ans,b[500005],cnt;
int C[505][505];
void dfs(int dep,int now,int sum){//dep:the number not picked; now:what the current number is
	if (sum==dep){
//		cout<<dep<<' ';
//		for (int i=1;i<=m;i++) cout<<d[i]<<' ';
//		cout<<endl;
		long long ans1=1;
		for (int j=1;j<=m;j++) ans1*=ksm(v[j],d[j]),ans1%=mod;
		ans1*=ksm(v[0],dep),ans1%=mod;
		int ans2=1,now1=n;
		for (int i=1;i<=m;i++) ans2*=C[now1][d[i]],now1-=d[i],ans2%=mod;
//		cout<<ans1<<' '<<ans2<<endl;
		Ans+=ans1*ans2%mod,Ans%=mod;
		return ;
	}
	if (sum<dep) return ;
	if (dep*c[now]<sum) return ;
	if (dep==0) return ;
	if (now==0) return ;
	for (int i=0;i<=dep;i++) if (i*c[now]<=sum) d[now]=i,dfs(dep-i,now-1,sum-i*c[now]),d[now]=0;else break;
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for (int i=0;i<=500;i++) C[i][0]=1;
	for (int i=1;i<=500;i++)
	for (int j=1;j<=i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1],C[i][j]%=mod;
	cin>>n>>m>>k;
	if (m<=9&&n<=8){
		for (int i=0;i<=m;i++) v[i]=read();
//		int sta=clock();
		int M=ksm(2,m);c[0]=1;
		for (int i=1;i<=m;i++) c[i]=c[i-1]*2;
		for (int i=n;i<=n*M;i++){
			int x=i,r=0;
			while (x){
				if (x%2==1) r++;
				x/=2;
			}
			if (r<=k) b[++cnt]=i;
		}
//		cout<<cnt<<endl;
//		for (int i=1;i<=cnt;i++) cout<<b[i]<<' ';
//		cout<<endl;
		for (int i=1;i<=cnt;i++){
//			cout<<i<<endl;
			dfs(n,m,b[i]);
		}
		cout<<Ans<<endl;
//		cout<<clock()-sta<<endl;
		return 0;
	}
	
	return 0;
}
/*
5 2 1
2 3 5

8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
*/
