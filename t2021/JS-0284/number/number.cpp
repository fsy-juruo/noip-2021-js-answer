#include<stdio.h>
#include<ctype.h>
const int N=1.1e7+10;
int pri[N],top,n,nopri[N],top2;
bool p[N],s[N];
bool check(int x){
	while(x){
		if(x%10==7)
			return 1;
		x/=10;
	}
	return 0;
}
int f(int x){
	int l=0,r=top2-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(nopri[mid]<x)
			l=mid+1;
		else r=mid;
	}
	return nopri[l];
}
int g(int x){
	int l=0,r=top2-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(nopri[mid]<=x)
			l=mid+1;
		else r=mid;
	}
	return nopri[l];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=1.1e7;
    for(int i=2;i<=n;++i){
        if(!p[i])
            pri[top++]=i;
        for(int j=0;j<top&&pri[j]*i<=n;++j)
        {
            p[i*pri[j]]=1;
            if(i%pri[j]==0)break;
        }
    }
    for(int i=7;i<=n;++i)
        if(s[i]||check(i)){
        	s[i]=1;
        	for(int j=0;j<top&&pri[j]*i<=n;++j)
        		s[i*pri[j]]=1;
		}
    for(int i=1;i<=n;++i)
        if(!s[i])nopri[top2++]=i;
    int T;scanf("%d",&T);
    while(T--){
        int x;
        scanf("%d",&x);
        int p=f(x);
        if(p!=x){
            printf("-1\n");
            continue;
        }
        printf("%d\n",g(x));
    }
}
