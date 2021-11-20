#include <bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int t,n,x,nxt[N];
bool vis[N],mok[N];
int read(){
	int x=0;char c;
	c=getchar(); 
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
bool check(int x){
	while(x){
		int r=x%10;x/=10;
		if(r==7)return true;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=7;i<=1e7+5;i++)mok[i]=check(i);
	for(int i=1;i<=5;i++)nxt[i]=i+1;
	int last=6;
	for(int i=7;i<=1e7+5;i++){
		if(vis[i])continue;
		if(!mok[i]){
			nxt[last]=i;
			last=i;
			continue;
		}
		vis[i]=true;
		for(int j=i*2;j<=1e7+5;j+=i)vis[j]=true;
	}
	t=read();
	while(t--){
		x=read();
		if(vis[x])puts("-1");
		else printf("%d\n",nxt[x]);
	}
	return 0;
} //
/*
5
90
99
106
114
169 
*/
