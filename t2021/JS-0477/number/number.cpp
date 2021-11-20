#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;bool f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=0;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?x:-x;
}
void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int t,n,f[10000010];
bool b[10000010]; 
bool ck(int x){
	for(;x;x/=10)
		if(x%10==7)return 1;
	return 0;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	for(int i=7;i<10000007;++i){
		if(!b[i]&&ck(i)){
			for(int j=i;j<10000007;j+=i)b[j]=1;
		}
	}
	for(int s=-1,i=10000005;i;--i){
		f[i]=s;
		if(!b[i])s=i;
	}
	while(t--){
		n=read();
		if(b[n]){
			puts("-1");continue;
		}
		print(f[n]),putchar('\n');
	}
	return 0;
}
/*
4
6
33
69
300
*/
