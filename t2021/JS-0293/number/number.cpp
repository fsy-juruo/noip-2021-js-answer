#include <bits/stdc++.h>
using namespace std;
const int maxt=1e4+5;
const int maxn=2e5+5; 
int t;
int x[maxt];
int p[maxn],y[maxn],dp[maxn];
int pos=7;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++){
		x[i]=read();
	}
	p[1]=7;p[2]=17;p[3]=27;p[4]=37;p[5]=47;p[6]=57,p[7]=67;
	for(int i=70;i<=200000;i++){
		int a=i;
		while(a>0){
			if(a%10==7){
				p[++pos]=i;
				break;
			}
			a/=10;
		}
	}
	for(int i=1;i<=pos;i++){
		int j=1;
		while(p[i]*j<=200000){
			y[p[i]*j]=1;
			j++;
		}
	} 
	dp[200000]=200000;
	for(int i=200000-1;i>=1;i--){
		if(!y[i]) dp[i]=i;
		else dp[i]=dp[i+1];
	}
	for(int i=1;i<=t;i++){
		if(y[x[i]]==1){
			printf("-1\n");
			continue;
		}else{
			printf("%d\n",dp[x[i]+1]);
		}
	}
	return 0;
} 
