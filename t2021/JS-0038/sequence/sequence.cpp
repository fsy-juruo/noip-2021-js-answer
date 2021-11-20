#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int n,m,lim,ans;
int fct[35],ict[35],bct[35];
int a[105];
int mt[105][35];
int dp[105][35][35][35];

int Pow(int x,int y){
	int mt=x,rt=1;
	while(y){
		if(y&1) rt=1ll*rt*mt%MOD;
		y>>=1;
		mt=1ll*mt*mt%MOD;
	}
	return rt;
}

void add(int &x,int y){
	x+=y;
	if(x>=MOD) x-=MOD;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	fct[0]=ict[0]=1;
	for(int i=1;i<=30;i++) fct[i]=1ll*fct[i-1]*i%MOD;
	for(int i=1;i<=30;i++) ict[i]=Pow(fct[i],MOD-2);
	for(int i=1;i<=30;i++) bct[i]=bct[i/2]+i%2;
	scanf("%d%d%d",&n,&m,&lim);
	for(int i=0;i<=m;i++){
		scanf("%d",a+i);
		mt[i][0]=1;
		for(int j=1;j<=30;j++) mt[i][j]=1ll*mt[i][j-1]*a[i]%MOD;
	}
	for(int i=0;i<=n;i++) add(dp[0][i][i%2][i/2],1ll*ict[i]*mt[0][i]%MOD);
	for(int i=1;i<=m;i++) for(int j=0;j<=n;j++) for(int k=0;k<=lim;k++) for(int l=0;l<=n;l++) for(int x=0;j+x<=n;x++){
		int tot=l+x;
		add(dp[i][j+x][k+tot%2][tot/2],1ll*dp[i-1][j][k][l]*ict[x]%MOD*mt[i][x]%MOD);
	}
	for(int i=0;i<=lim;i++) for(int j=0;j<=n;j++) if(i+bct[j]<=lim) add(ans,dp[m][n][i][j]);
	ans=1ll*ans*fct[n]%MOD;
	printf("%d\n",ans);
	return 0;
}
