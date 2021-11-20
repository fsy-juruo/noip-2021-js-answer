#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0,w=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*w;
}
void print(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9){
		print(x/10);
	}
	putchar(x%10+'0');
}
int n,m,k,v[105],sum,tmp[50];
int pow(int x){
	int ret=1;
	for(int i=1;i<=x;i++){
		ret*=2;
	}
	return ret;
}
void dfs(int pos){
	if(pos==n+1){
		int res=0;
		for(int i=1;i<=n;i++){
			res+=pow(tmp[i]);
		}
		if(__builtin_popcount(res)<=k){
			int t=1;
			for(int i=1;i<=n;i++){
				t*=v[tmp[i]];
			}
			sum+=t;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		tmp[pos]=i;
		dfs(pos+1);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;i++){
		v[i]=read();
	}
	dfs(1);
	print(sum);
	return 0;
}

