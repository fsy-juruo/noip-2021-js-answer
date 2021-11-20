#include<bits/stdc++.h>
using namespace std;
int n;
int num[200010],nu[10010],l[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
//	int a=7,b=10;
//	2e5
//	for(int i=5;i>=1;i--){
//		int sum=1,t=i-1;
//		while(t--) sum*=10;
//		for(int j=0;j<=sum;j++){
//			for(int k=0;k<=a/7-1;k++){
//				int c=a+j*b+k;
//				if(num[c]==1) continue;
//				for(int i=1;c*i<=200000;i++){
//					num[c*i]=1;
//				}
//			}
//		}
//		a*=10;b*=10;
//	}
//	1e4
//	for(int i=4;i>=1;i--){
//		int sum=1,t=i-1;
//		while(t--) sum*=10;
//		for(int j=0;j<=sum;j++){
//			for(int k=0;k<=a/7-1;k++){
//				int c=a+j*b+k;
//				for(int i=1;c*i<=10000;i++){
//					num[c*i]=1;
//				}
//			}
//		}
//		a*=10;b*=10;
//	}
	int f=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&nu[i]);
		if(nu[i]>10000) f=1;
	}
	if(!f){
		int a=7,b=10;
		for(int i=4;i>=1;i--){
			int sum=1,t=i-1;
			while(t--) sum*=10;
			for(int j=0;j<=sum;j++){
				for(int k=0;k<=a/7-1;k++){
					int c=a+j*b+k;
					if(num[c]==1) continue;
					for(int i=1;c*i<=10000;i++){
						num[c*i]=1;
					}
				}
			}
			a*=10;b*=10;
		}
		int cnt=0;
		for(int i=1;i<=10000;i++){
			if(num[i]==0) l[++cnt]=i;
		}
//		for(int i=1;i<=)
//		printf("%d",num[300]);
		for(int i=1;i<=n;i++){
			if(num[nu[i]]==1) printf("-1\n");
			else printf("%d\n",l[lower_bound(l+1,l+cnt+1,nu[i])-l+1]);
		}
	}else{
		int a=7,b=10;
		for(int i=5;i>=1;i--){
			int sum=1,t=i-1;
			while(t--) sum*=10;
			for(int j=0;j<=sum;j++){
				for(int k=0;k<=a/7-1;k++){
					int c=a+j*b+k;
					if(num[c]==1) continue;
					for(int i=1;c*i<=200000;i++){
						num[c*i]=1;
					}
				}
			}
			a*=10;b*=10;
		}
		int cnt=0;
		for(int i=1;i<=200000;i++){
			if(num[i]==0) l[++cnt]=i;
		}
//		for(int i=1;i<=)
//		printf("%d",num[300]);
		for(int i=1;i<=n;i++){
			if(num[nu[i]]==1) printf("-1\n");
			else printf("%d\n",l[lower_bound(l+1,l+cnt+1,nu[i])-l+1]);
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
