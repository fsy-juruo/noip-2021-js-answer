#include<bits/stdc++.h>
#define filename "number"
using namespace std;
const int maxn=4005;
int read(){
	int re=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		re=(re<<3)+(re<<1)+(ch^48);
		ch=getchar();
	}
	return f*re;
}
bool contain(int x){
	while(x){
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
bool check(int x){
	for(int i=2;i<=sqrt(x);i++)
	  if(x%i==0&&(contain(i)||contain(x/i))) return 0;
	return 1;
}
int to(int x){
	x++;
	if(!contain(x)) return x;
	int re=0,pos=0,a[10]={0};
	while(x){
		a[++pos]=x%10;
		x/=10;
	}
	bool flag=0;
	for(int i=pos;i>=1;i--)
	  if(a[i]!=7&&!flag) re=(re<<3)+(re<<1)+a[i];
	  else if(a[i]==7&&!flag){
	  	  re=(re<<3)+(re<<1)+8;
	  	  flag=1;
	  }
	  else re=(re<<3)+(re<<1);
	return re;
}
int cnt,b[maxn],seven[maxn];
bool solve(int x){
	for(int i=1;seven[i]<=sqrt(x);i++)
	  if(x%seven[i]==0){
	  	if(contain(seven[i])||contain(x/seven[i])) return 0;
	  }
	return 1;
}
int main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
    for(int i=1;i<=maxn-5;i++)
      if(check(i)&&contain(i)) seven[++cnt]=i;
      else if((!contain(i))&&check(i)) seven[++cnt]=i;
    int t=read();
    while(t--){
    	int x=read();
    	if(!solve(x)){
    		printf("-1\n");
    		continue;
		}
		for(int i=to(x);i<=1e7+1000;i=to(i))
		  if(solve(i)){
		  	  printf("%d\n",i);
		  	  break;
		  }
	}
	return 0;
}
