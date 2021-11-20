#include<bits/stdc++.h>
#define del 0.9976
using namespace std;
int n,a[10005],ans,mjm=1e9;
int calc()
{
	int i,ans=0,ave=0;
	for(i=1;i<=n;i++)ave+=a[i];
		for(i=1;i<=n;i++){
			ans+=(ave-n*a[i])*(ave-n*a[i]);
		}
	ans/=4;
	return ans;
}
void fire()
{
	double t=6666.666;
	int na,j,mid;
	while(t>1e-5){
		do{j=(rand()%n)+1;
		}while(j<=1||j>=n);
		mid=a[j];a[j]=a[j+1]+a[j-1]-a[j];
		na=calc();
		if(na<ans)ans=na;
		else if(exp(-(na-ans)/t)*RAND_MAX<rand())a[j]=mid;
		t*=del;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));srand(rand());
	int i,j=0,k,x,f=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==1){printf("0");return 0;}
	if(n==2){
		int ave=(a[1]+a[2])/2;
		ans=((ave-a[1])*(ave-a[1])+(ave-a[2])*(ave-a[2]))*2;
		printf("%d",ans);return 0;
	}
	if(n==3){
		int ave=(a[1]+a[2]+a[3]);
		ans=((ave-3*a[1])*(ave-3*a[1])+(ave-3*a[2])*(ave-3*a[2])+(ave-3*a[3])*(ave-3*a[3]))/3;
		a[2]=a[3]+a[1]-a[2];
		ave=(a[1]+a[2]+a[3]);
		ans=min(ans,((ave-3*a[1])*(ave-3*a[1])+(ave-3*a[2])*(ave-3*a[2])+(ave-3*a[3])*(ave-3*a[3])/3));
		printf("%d",ans);return 0;
	}
	if(n==4){
		int ave=(a[1]+a[2]+a[3]+a[4]);
		ans=((ave-4*a[1])*(ave-4*a[1])+(ave-4*a[2])*(ave-4*a[2])+(ave-4*a[3])*(ave-4*a[3])+(ave-4*a[4])*(ave-4*a[4]))/4;
		while(j<=20){
			if(f){
				a[3]=a[2]+a[4]-a[3];f=0;
				ave=(a[1]+a[2]+a[3]+a[4]);
				ans=min(ans,((ave-4*a[1])*(ave-4*a[1])+(ave-4*a[2])*(ave-4*a[2])+(ave-4*a[3])*(ave-4*a[3])+(ave-4*a[4])*(ave-4*a[4]))/4);
			}
			else{
				a[2]=a[1]+a[3]-a[2];f=1;
				ave=(a[1]+a[2]+a[3]+a[4]);
				ans=min(ans,((ave-4*a[1])*(ave-4*a[1])+(ave-4*a[2])*(ave-4*a[2])+(ave-4*a[3])*(ave-4*a[3])+(ave-4*a[4])*(ave-4*a[4]))/4);
			}
			j++;
		}
		f=0;
		while(j<=20){
			if(f){
				a[3]=a[2]+a[4]-a[3];f=0;
				ave=(a[1]+a[2]+a[3]+a[4]);
				ans=min(ans,((ave-4*a[1])*(ave-4*a[1])+(ave-4*a[2])*(ave-4*a[2])+(ave-4*a[3])*(ave-4*a[3])+(ave-4*a[4])*(ave-4*a[4]))/4);
			}
			else{
				a[2]=a[1]+a[3]-a[2];f=1;
				ave=(a[1]+a[2]+a[3]+a[4]);
				ans=min(ans,((ave-4*a[1])*(ave-4*a[1])+(ave-4*a[2])*(ave-4*a[2])+(ave-4*a[3])*(ave-4*a[3])+(ave-4*a[4])*(ave-4*a[4]))/4);
			}
			j++;
		}
		printf("%d",ans);return 0;
	}
	ans=calc();
	while((double)clock()/CLOCKS_PER_SEC<0.8)fire();
	printf("%d",ans);
}
