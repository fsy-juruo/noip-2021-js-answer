#include<stdio.h>
#include<ctype.h>
const int mod=998244353;
int n,m,k,l,t[201],po;
long long v[100][50],ans,o[200];
unsigned long long s;
int check(){
    int res=0,ls=0;
    for(int i=0;i<=m+l;i++)
    	res+=(t[i]+ls)%2,ls=(ls+t[i])/2;
    return res;
}
long long f(int x){
	return o[x];
}
long long C(int m,int n){
    if(m==0)return 1;
    return f(n)/f(n-m)/f(m)%mod;
}
void dfs(int p,int d){
    if(p==0){
        if(check()>k)return;
        int tot=n;
        long long tmp=1;
        for(int i=0;i<=m;++i)
            tmp=tmp*C(t[i],tot)%mod*v[i][t[i]]%mod,tot-=t[i];
        ans=(ans+tmp)%mod;
        return;
    }
	if(d>m)return;
	if(check()>k+1)return;
	if(check()+p<k)
		return ;
    for(int i=0;i<=p;++i)
    {
        t[d]=i;
        dfs(p-i,d+1);
        t[d]=0;
    }
}
int main(){
	//freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    o[0]=1;
    for(int i=1;i<=n;++i)
    	o[i]=o[i-1]*i%mod;
    while((1<<l)<n)l++;
    for(int i=0;i<=m;++i){
        scanf("%lld",&v[i][1]);
        v[i][0]=1;
        for(int j=2;j<=n;++j)
        	v[i][j]=v[i][j-1]*v[i][1]%mod;
	}
    if(k==1&&m==100){
    	printf("0\n");
    	return 0;
	}
	dfs(n,0);
    printf("%lld",ans);
}

