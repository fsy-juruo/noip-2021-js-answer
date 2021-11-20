#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;char ch=getchar();
	   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	   while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	   return x*f;
}
int cf(int x){
	int cnt=1,a,ans=0;
	while(x>0){
		a=x%10;
		if(a==7){
			ans=cnt;
		}
		x/=10;
	}
	return ans;
}
int vis[10000010],nxt[10000010];
void pre_work(){
	int tot=7,k,maxn=10000000,lst=6;
	for(int i=1;i<=5;i++){
		nxt[i]=i+1;
	}
	while(1){
		if(tot==maxn){
			nxt[lst]=maxn;
			break;
		}
		if(vis[tot]){
			tot++;
			continue;
		}
		k=cf(tot);
		if(k){
			for(int i=1;i<=maxn/tot;i++){
				vis[i*tot]=1;
			}
		}else{
			nxt[lst]=tot;
			lst=tot;
		}
		tot++;
	}
	return ;
}
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
	int n,a;
	n=read();
	pre_work();
	for(int i=1;i<=n;i++){
		a=read();
		if(vis[a]){
			cout<<"-1"<<endl;
		}else{
			cout<<nxt[a]<<endl;
		}
	}
	return 0;
}

