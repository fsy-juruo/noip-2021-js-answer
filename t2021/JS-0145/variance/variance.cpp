#include<bits/stdc++.h>
using namespace std;
int a[10010],b[10010];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);

   int n;
   scanf("%d",&n);
   int sum=0;
   for (int i=1;i<=n;i++){
   	 scanf("%d",&a[i]);
   	 sum+=a[i];
   }
   memcpy(b,a,sizeof(a));
   int tot=0;
   for (int i=1;i<=n;i++){
   	   tot+=(n*a[i]-sum)*(n*a[i]-sum);
   }
   int ans=tot,p=2;
   int count=0;
   while (true){
   	count++;
   	
    int aa=p;
    bool flag=1;
    while (b[p-1]+b[p+1]==b[p]*2){
    	p++;
    	if (p==n) p=2;
    	if (aa==p){
    		flag=0;
    		break;
		}
	}
	if (flag==0) break;
	
	flag=1;
   	for (int i=1;i<=n;i++){
   		if (b[i]!=a[i]){
   			flag=0;
   			break;
		   }
	   }
	if (flag&&p==2&&count!=1) break;
	
	sum-=b[p];
	b[p]=b[p-1]+b[p+1]-b[p];
	sum+=b[p];
	tot=0;
	for (int i=1;i<=n;i++){
		tot+=(n*b[i]-sum)*(n*b[i]-sum);
	}
	ans=min(tot,ans);
	p++;
	if (p==n) p=2;
	
   }
   printf("%d\n",ans/n);

	return 0;
}