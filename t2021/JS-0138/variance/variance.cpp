
//1~5 20pts

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=10005;

inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)){
		x=x*10+(c^48);
		c=getchar();
	}
	return x;
}

void putint(int x){
	if(x>9) putint(x/10);
	putchar(x%10+'0');
}

int n;
int a[N],b[N],minb=1e9;
int ans[N],minf=1e9;
int cnt[605];
int sum[N],now[N];

void dfs(int u,int last){
	if(last==minb){
		for(int i=minb;i<=600;++i)
			for(int j=cnt[i];j;--j) now[u++]=i;
		int res=0,S=0;
		for(int i=1;i<=n;++i){
			sum[i]=sum[i-1]+now[i],
			S+=sum[i],res+=n*sum[i]*sum[i];
		}
		res-=S*S;
		if(res<minf)
			minf=res,memcpy(ans,now,sizeof ans);
		return;
	}
	for(int i=last-1;i>=minb;--i)
		for(int j=cnt[i];j;--j){
			for(int k=1;k<=j;++k) now[u++]=i,--cnt[i];
			dfs(u,i);
			for(int k=1;k<=j;++k) --u,++cnt[i];
		}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=getint();//,printf("%d\n",n);
	for(int i=1;i<=n;++i)
		a[i]=getint(),b[i]=a[i]-a[i-1],++cnt[b[i]];//,printf("%d ",a[i]);
	for(int i=2;i<=n;++i) minb=min(minb,b[i]);//puts("\n");
	--cnt[sum[1]=now[1]=ans[1]=b[1]];
	dfs(2,601);
	printf("%d\n",minf);
	//for(int i=1;i<=n;++i) printf("%d ",ans[i]);puts("");
	//for(int i=1;i<=n;++i) printf("%d ",ans[i]+=ans[i-1]);
	
	return 0;
}
/*
9
0 4 9 15 18 27 31 33 39

10332
0 6 6 4 3 2 4 5 9

*/
