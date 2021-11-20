#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10000000;
template<typename tn>void read(tn &n){
	tn x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	n=x*f;
}
int t,x;
int len[maxn+1];
bool ans[maxn+1];
int nxt[maxn+1];
int temp;
bool in[maxn+1];
bool check(int x){
	int tmp;
	while(x%10==0)
		x/=10;
	if(in[x])
		return 0;
	int num=x;
	while(x){
		tmp=x%10;
		x/=10;
		if(tmp==7){
			in[num]=true;
			return 1;			
		}		
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=maxn;++i){
		if(check(i)){
			len[++len[0]]=i;
			ans[i]=1;
		}
	}
	for(int i=1;i<=len[0];++i)
		for(int j=2;j*len[i]<=maxn;++j)
			ans[len[i]*j]=1;
	for(int i=1;i<=maxn;++i){
		if(!ans[i]){
			nxt[temp]=i;
			temp=i;
		}
		else
			nxt[i]=-1;
	}
	read(t);
	while(t--){
		read(x);
		printf("%d\n",nxt[x]);
	}
	return 0;
}

