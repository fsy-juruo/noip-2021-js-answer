#include<bits/stdc++.h>
#define fz1(i,n) for((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for((i)=(n);(i)>=1;(i)--)
using namespace std;
void read(int &x)
{
	int s=0,f=1;char c;
	while((c=getchar())>'9'||c<'0') if(c=='-') f=-1;
	s=(c&15);
	while((c=getchar())>='0'&&c<='9') s=s*10+(c&15);
	x=s*f;
}
const int maxn=1.1e7;
int t,n,m,i,j,f[maxn+5],g[maxn+5],nxt[maxn+5];
int main()
{
//	cerr<<sizeof(f)/1048576*3<<endl;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	fz1(i,maxn){
		if(f[i/10]||i%10==7) f[i]=1;
	}
	fz1(i,maxn){
		if(f[i]&&!g[i]){
			for(j=i;j<=maxn;j+=i){
				g[j]=1;
			}
		}
	}
	fd1(i,maxn){
		if(!g[i]) nxt[i]=i; else nxt[i]=nxt[i+1];
	}
	read(t);
	while(t--){
		int x;read(x);
		if(g[x]) puts("-1"); else printf("%d\n",nxt[x+1]); 
	} 
	return 0;
}
