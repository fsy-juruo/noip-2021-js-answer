#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define N 11000005
int n,m,a[200003],p[N];
bool f[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	int m=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		m=max(m,a[i]);
	}
	m+=1000001;
	memset(f,true,sizeof f);
	for(int i=1;i<=m;++i){
		if(!f[i]) continue;
		int b=i;
		bool fl=false;
		while(b){
			if(b%10==7)
				{fl=true;break;}
			b/=10;
		}
		if(fl) for(int j=1;i*j<=m;++j)
			f[i*j]=false;
	}
	int cnt=0;
	for(int i=1;i<=m;++i)
		if(f[i]) p[++cnt]=i;
	for(int i=1;i<=n;++i){
		if(!f[a[i]]) puts("-1");
		else printf("%d\n",p[upper_bound(p+1,p+cnt+1,a[i])-p]);
	}
	return 0;
}
//就算这机子一秒四亿也不可能放暴力过的 
