#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll s[101],v[31][101],n,c[101][101],m,k,ans,t[101];
int check(int x){
	int ans=0;
	while(x){
		ans+=x%2;
		x/=2;
	}
	if(ans>k) return 1;
	else return 0;
}
void solve(){
	ll tmp=1,temp=n;
	for(int i=0;i<m;i++)
		tmp=(tmp*c[temp][t[i]]*v[t[i]][i])%mod,temp-=t[i];
	tmp=(tmp*v[t[m]][m])%mod;ans=(ans+tmp)%mod;
	for(int i=1;i<m;i++){
		while(t[i]>=3){
			t[i]-=3;t[i-1]+=2;t[i+1]++;
			tmp=1,temp=n;
			for(int i=0;i<m;i++)
				tmp=(tmp*c[temp][t[i]]*v[t[i]][i])%mod,temp-=t[i];
			tmp=(tmp*v[t[m]][m])%mod;ans=(ans+tmp)%mod;
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) v[0][i]=1;
	for(int i=0;i<=m;i++) cin>>v[1][i];
	for(int i=2;i<=30;i++)
		for(int j=0;j<=m;j++)
			v[i][j]=v[i-1][j]*v[1][j]%mod;
	for(int i=0;i<=100;i++)
		c[0][i]=1;
	c[1][0]=1;c[1][1]=1;
	for(int i=2;i<=100;i++){
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		c[i][0]=1;
	}
	for(int i=n;i<=n*pow(2,m);i++){
		if(i==n){s[0]=n;}
		else{
			s[0]++;int tmp=0,k=0;
			for(int i=0;i<=m;i++) k+=s[i];
			while(k!=n){
				if(s[tmp]>=2&&tmp+1<=m){s[tmp]-=2;s[tmp+1]++;k--;}
				else tmp++;
				if(tmp==m) break;
			}
		}
		if(check(i)) continue;
		memcpy(t,s,sizeof(s));
		solve();
	}
	cout<<ans%mod<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
