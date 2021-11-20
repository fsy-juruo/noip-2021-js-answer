#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int n,sm;
double pj,pf;
int a[maxn];
int f[maxn];

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	f[1]=a[1];f[n]=a[n];
	if(n==1) printf("0");
	else if(n==2 || n==3){
		for(int i=1;i<=n;i++){
			sm+=a[i];
		}
		pj=(double)sm/n;
		for(int i=1;i<=n;i++){
			pf=pf+(double)((double)a[i]-pj)*((double)a[i]-pj);
		}
		pf=(double)n*pf;
		printf("%d",(int)pf);
	}
	else if(n%2==0){
		for(int i=2;i<=n/2-1;i++){
			f[i]=max(a[i],a[i-1]+a[i+1]-a[i]); 
		}
		for(int i=n-1;i>=n/2+2;i--){
			f[i]=min(a[i],a[i-1]+a[i+1]-a[i]);
		}
		int x=f[n/2-1]+a[n/2+1]-2*a[n/2];
		int y=2*a[n/2+1]-a[n/2]-f[n/2+2];
		if(x<=0){
			f[n/2]=a[n/2];
			if(y<=0){
				f[n/2+1]=a[n/2+1];
			}else{
				f[n/2+1]=a[n/2]+f[n/2+2]-a[n/2+1];
				for(int i=n/2+2;i<=n-1;i++){
					f[i]=min(f[i-1]+f[i+1]-f[i],f[i]);
				}
			}
		}
		if(x>0){
			if(y<=0){
				f[n/2+1]=a[n/2+1];
				f[n/2]=a[n/2+1]+f[n/2-1]-a[n/2];
				for(int i=n/2-1;i>=2;i--){
					f[i]=max(f[i-1]+f[i+1]-f[i],f[i]);
				}
			}else{
				if(y>x){
					f[n/2]=a[n/2];
					f[n/2+1]=a[n/2]+f[n/2+2]-a[n/2+1];
					for(int i=n/2+2;i<=n-1;i++){
						f[i]=min(f[i-1]+f[i+1]-f[i],f[i]);
					}
				}else{
					f[n/2+1]=a[n/2+1];
					f[n/2]=a[n/2+1]+f[n/2-1]-a[n/2];
					for(int i=n/2-1;i>=2;i--){
						f[i]=max(f[i-1]+f[i+1]-f[i],f[i]);
					}
				}
			}
		}
		bool f1=1,f2=1;
		while(f1){
			bool flag1=0;
			for(int i=2;i<=n/2-1;i++){
				if(f[i]<f[i-1]+f[i+1]-f[i]){
					flag1=1;
					f[i]=f[i-1]+f[i+1]-f[i];
				}
			}
			if(!flag1) f1=0;
		}
		while(f2){
			bool flag2=0;
			for(int i=n/2+2;i<=n-1;i++){
				if(f[i]>f[i-1]+f[i+1]-f[i]){
					flag2=1;
					f[i]=f[i-1]+f[i+1]-f[i];
				}
			}
			if(!flag2) f2=0;
		}
		for(int i=1;i<=n;i++){
			sm+=f[i];
		}
		pj=(double)sm/n;
		for(int i=1;i<=n;i++){
			pf+=((double)f[i]-pj)*((double)f[i]-pj);
		}
		pf=(double)n*pf;
		printf("%d",(int)pf);
	}else{
		for(int i=1;i<=n;i++) f[i]=a[i];
		bool f1=1,f2=1;
		while(f1){
			bool flag1=0;
			for(int i=2;i<=n/2;i++){
				if(f[i]<f[i-1]+f[i+1]-f[i]){
					flag1=1;
					f[i]=f[i-1]+f[i+1]-f[i];
				}
			}
			if(!flag1) f1=0;
		}
		while(f2){
			bool flag2=0;
			for(int i=n/2+2;i<=n-1;i++){
				if(f[i]>f[i-1]+f[i+1]-f[i]){
					flag2=1;
					f[i]=f[i-1]+f[i+1]-f[i];
				}
			}
			if(!flag2) f2=0;
		}
		for(int i=1;i<=n;i++){
			sm+=f[i];
		}
		pj=(double)sm/n;
		for(int i=1;i<=n;i++){
			pf+=((double)f[i]-pj)*((double)f[i]-pj);
		}
		pf=(double)n*pf;
		printf("%d",(int)pf);
	}
	return 0;
} 
