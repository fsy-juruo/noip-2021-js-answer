#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=0;int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10+48);
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	print(x);putchar('\n');
}
const int MAXSIZ=10000005;
int T,nex[MAXSIZ+5];
bool vis[MAXSIZ+5];
bool check(int x){
	while(x){
		if(x%10==7)return true;
		x=x/10;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=7;i<=MAXSIZ;++i){
		//cout<<i<<" "<<vis[i]<<endl;
		if(vis[i])continue;
		vis[i]=check(i);
		if(!vis[i])continue;
		for(int j=2;j*i<=MAXSIZ;++j)vis[i*j]=1;
	}
	int pre=0,tmp;
	for(int i=1;i<=MAXSIZ;++i){
		if(!vis[i])nex[pre]=i,pre=i;
	}
	T=read();
	while(T--){
		tmp=read();
		if(!nex[tmp])write(-1);
		else write(nex[tmp]);
	}
	return 0;
}
//-std=c++14
/*
5
90
99
106
114
169
*/
