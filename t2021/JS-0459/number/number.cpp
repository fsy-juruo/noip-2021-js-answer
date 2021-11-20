#include<bits/stdc++.h>
using namespace std;
const int MAXT=2e5+10,MAXN=2e7+10;
int a[MAXT],l[MAXN];
bool f[MAXN];
int i,j;
bool p(int x){
	while(x){
		if(x%10==7)
			return 1;
		x/=10;
	}
	return 0;
}
void build(int m){
	for(i=1;i<=m;i++){
		if(p(i)){
			for(j=1;;j++){
				f[i*j]=1;
				if(i*j>m)
					break;
			}
		}
	}
}
char ch;
int x;
int read(){
	x=0;
	while(!isdigit(ch=getchar()))
		ch=getchar();
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m=0,las;
	n=read();
	for(i=1;i<=n;++i)
		m=max(m,a[i]=read());
	build(m);
	for(las=m+1;f[las]||p(las);++las);
	for(i=m;i>=1;--i){
		if(f[i])
			l[i]=-1;
		else
			l[i]=las,las=i;
	}
	for(i=1;i<=n;++i)
		printf("%d\n",l[a[i]]);
	return 0;
}

