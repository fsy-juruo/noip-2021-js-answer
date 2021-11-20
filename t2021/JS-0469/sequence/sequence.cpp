#include<bits/stdc++.h>
#define M 998244353
using namespace std;

int read(){
	int f=1,ans=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<3)+(ans<<1)+c-'0';c=getchar();}
	return f*ans;
}
void print(int xx){
	if(xx<0){
		putchar('-');
		print(-xx);
		return;
	}
	if(xx>9)print(xx/10);
	putchar(xx%10+'0');
	return;
}
int C[50][50];
int c(int mm,int nn){
	return C[nn+1][mm-nn+1];
}
int n,m,k;
int v[110];
int sl[111],s[40],sll[111],t;
long long ans=0;
void dfs(int dep,int las){
	if(dep>n){
		long long jj=1;
		for(int i=0;i<m+10;i++){
			sll[i]=sl[i];
			for(int j=1;j<=sl[i];j++){
				jj*=v[i];
				jj%=M;
			}
		}
		int num=0;
		for(int i=0;i<m+10;i++){
			if(sll[i]%2){
				num++;
				if(num>k)return;
			}
			sll[i+1]+=sll[i]/2;
		}
		int tn=n;
		long long xl=1;
		for(int i=1;i<=t;i++){
			xl*=c(tn,sl[s[i]]);
			tn-=sl[s[i]];
			xl%=M;
		}
		ans+=jj*xl%M;
		ans%=M;
		return;
	}
	for(int i=las;i<=m;i++){
		sl[i]++;
		if(sl[i]==1)s[++t]=i;
		dfs(dep+1,i);
		sl[i]--;
		if(sl[i]==0)t--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			C[i][j]=0;
		}
	}
	for(int i=1;i<50;i++){
		for(int j=1;j<50;j++){
			if(i==1&&j==1)C[i][j]=1;
			else C[i][j]=C[i-1][j]+C[i][j-1];
			C[i][j]%=M;
		}
	}
	//C
	
	
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;i++){v[i]=read();sl[i]=0;}
	t=0;
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
