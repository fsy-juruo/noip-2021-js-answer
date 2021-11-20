#include<bits/stdc++.h>
const int  maxnum=1e7+1050;
const int maxn=200000+500;
using namespace std;
inline int read(){
	char c=getchar();bool f=0;int num=0;
	for(;c<'0'||c>'9';f=(c=='-')?1:0,c=getchar());
	for(;c>='0'&&c<='9';num=(num<<3)+(num<<1)+(c^'0'),c=getchar());
	return  f?-num:num;
}
bool vis[maxnum];
int a[maxn];
int n,m,tmp;
int v;
bool check(int num){
	if(num%7==0) return true;
	while(num>=1){
		if(num%10==7) return true;
		num/=10;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=read();
	for(int i=1;i<=T;i++){
		a[i]=read();
		n=max(n,a[i]);
	}
	tmp=n;
	while(tmp>=1){
		m++;
		tmp/=10;
	}
	for(int i=1;i<=n;i++){
		if(check(i)){
			
			if(!vis[i]){
				for(int j=1;i*j<=n+100;j++){
					vis[i*j]=1;
					
				}
			}
		}
	}
	for(int i=1;i<=T;i++){
		if(vis[a[i]]) printf("-1\n");
		else{
			for(int j=a[i]+1;j;j++){
				if(j>=n+100){
					if(check(j)==false){
						printf("%d\n",j);
						break;
					}
				}else{
					if(vis[j]==0){
						printf("%d\n",j);
						break;
					}
				}
			}
		}
	}
	return 0;
}
/*
5
90
99
106
114
169
*/
