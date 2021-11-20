#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std; 
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=11000005;
bool p[Maxn],b[Maxn];
int nxt[Maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (int i=1;i<Maxn;i++){
		p[i]=p[i/10]|(i%10==7);b[i]=0;
	}
	for (int i=1;i<Maxn;i++){
		if (p[i]){
			for (int j=i;j<Maxn;j+=i){
				b[j]=1;
			}
		}
	}
	
	nxt[Maxn-1]=Maxn-1;
	for (int i=Maxn-2;i>=0;i--){
		if (b[i]) nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
	
	int T=read();
	while (T--){
		int n=read();
		if (b[n]){
			printf("-1\n");
		}else{
			printf("%d\n",nxt[n+1]);
		}
	}
	return 0;
}
