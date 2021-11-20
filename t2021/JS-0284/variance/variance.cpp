#include<stdio.h>
#include<ctype.h>
int n,a[10100],f,g,ans;
int cul(){
	f=g=0;
	for(int i=1;i<=n;++i)
        f+=a[i],g+=a[i]*a[i];
    return n*g-f*f;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    ans=cul();
    while(1){
    	int i;
        for(i=2;i<n;++i)
        {
            a[i]=a[i-1]-a[i]+a[i+1];
            if(cul()<ans){
            	ans=cul();
            	break;
			}
			a[i]=a[i-1]-a[i]+a[i+1];
		}
        if(i==n)break;
    }
    
    printf("%d\n",ans);
}

