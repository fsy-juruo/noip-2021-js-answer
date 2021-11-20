#include<bits/stdc++.h>
using namespace std;
int read()
{
	int res=1,num=0;
	char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') res=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){num=num*10+ch-'0';ch=getchar();}
	return res*num;
}
int n;
int a[10010];
int sum;
long long sqr;
long long work1(){
	sum=0;sqr=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	long long sqr=0;
	for(int i=1;i<=n;i++) sqr+=(long long)a[i]*(long long)a[i];
	sqr*=(long long)n;
	bool f=1;
	while(f==1){
		f=0;
		int l=1,r=n,mid,p;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]*n<=sum){
				p=mid;
				l=mid+1;
			}else r=mid-1;
		}
		for(int i=2;i<=p;i++){
			if(a[i-1]+a[i+1]-a[i]>a[i]){
				int x=a[i-1]+a[i+1]-a[i];
				int sum1=sum-a[i]+x;
				long long tmp=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n-(long long)sum1*(long long)sum1;
				if(tmp<sqr-(long long)sum*(long long)sum){
					sqr=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n;
					sum=sum1;
					a[i]=x;
					f=1;
				}
			}
		}
		l=1;
		r=n;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]*n<=sum){
				p=mid;
				l=mid+1;
			}else r=mid-1;
		}
		for(int i=n-1;i>=p;i--){
			if(a[i-1]+a[i+1]-a[i]<a[i]){
				int x=a[i-1]+a[i+1]-a[i];
				int sum1=sum-a[i]+x;
				long long tmp=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n-(long long)sum1*(long long)sum1;
				if(tmp<sqr-(long long)sum*(long long)sum){
					sqr=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n;
					sum=sum1;
					a[i]=x;
					f=1;
				}
			}
		}
	}
	return sqr-(long long)sum*(long long)sum;
}
long long work2(){
	sum=0;sqr=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	long long sqr=0;
	for(int i=1;i<=n;i++) sqr+=(long long)a[i]*(long long)a[i];
	sqr*=(long long)n;
	bool f=1;
	while(f==1){
		f=0;
		int l=1,r=n,mid,p;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]*n<=sum){
				p=mid;
				l=mid+1;
			}else r=mid-1;
		}
		for(int i=p;i>=2;i--){
			if(a[i-1]+a[i+1]-a[i]>a[i]){
				int x=a[i-1]+a[i+1]-a[i];
				int sum1=sum-a[i]+x;
				long long tmp=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n-(long long)sum1*(long long)sum1;
				if(tmp<sqr-(long long)sum*(long long)sum){
					sqr=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n;
					sum=sum1;
					a[i]=x;
					f=1;
				}
			}
		}
		l=1;
		r=n;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]*n<=sum){
				p=mid;
				l=mid+1;
			}else r=mid-1;
		}
		for(int i=p;i<n;i++){
			if(a[i-1]+a[i+1]-a[i]<a[i]){
				int x=a[i-1]+a[i+1]-a[i];
				int sum1=sum-a[i]+x;
				long long tmp=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n-(long long)sum1*(long long)sum1;
				if(tmp<sqr-(long long)sum*(long long)sum){
					sqr=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n;
					sum=sum1;
					a[i]=x;
					f=1;
				}
			}
		}
	}
	return sqr-(long long)sum*(long long)sum;
}
long long work3(){
	sum=0;sqr=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	long long sqr=0;
	for(int i=1;i<=n;i++) sqr+=(long long)a[i]*(long long)a[i];
	sqr*=(long long)n;
	bool f=1;
	while(f==1){
		f=0;
		int l=1,r=n,mid,p;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]*n<=sum){
				p=mid;
				l=mid+1;
			}else r=mid-1;
		}
		for(int i=n-1;i>=p;i--){
			if(a[i-1]+a[i+1]-a[i]<a[i]){
				int x=a[i-1]+a[i+1]-a[i];
				int sum1=sum-a[i]+x;
				long long tmp=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n-(long long)sum1*(long long)sum1;
				if(tmp<sqr-(long long)sum*(long long)sum){
					sqr=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n;
					sum=sum1;
					a[i]=x;
					f=1;
				}
			}
		}
		l=1;
		r=n;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]*n<=sum){
				p=mid;
				l=mid+1;
			}else r=mid-1;
		}
		for(int i=2;i<=p;i++){
			if(a[i-1]+a[i+1]-a[i]>a[i]){
				int x=a[i-1]+a[i+1]-a[i];
				int sum1=sum-a[i]+x;
				long long tmp=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n-(long long)sum1*(long long)sum1;
				if(tmp<sqr-(long long)sum*(long long)sum){
					sqr=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n;
					sum=sum1;
					a[i]=x;
					f=1;
				}
			}
		}
	}
	return sqr-(long long)sum*(long long)sum;
}
long long work4(){
	sum=0;sqr=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	long long sqr=0;
	for(int i=1;i<=n;i++) sqr+=(long long)a[i]*(long long)a[i];
	sqr*=(long long)n;
	bool f=1;
	while(f==1){
		f=0;
		int l=1,r=n,mid,p;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]*n<=sum){
				p=mid;
				l=mid+1;
			}else r=mid-1;
		}
		for(int i=p;i<n;i++){
			if(a[i-1]+a[i+1]-a[i]<a[i]){
				int x=a[i-1]+a[i+1]-a[i];
				int sum1=sum-a[i]+x;
				long long tmp=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n-(long long)sum1*(long long)sum1;
				if(tmp<sqr-(long long)sum*(long long)sum){
					sqr=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n;
					sum=sum1;
					a[i]=x;
					f=1;
				}
			}
		}
		l=1;
		r=n;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]*n<=sum){
				p=mid;
				l=mid+1;
			}else r=mid-1;
		}
		for(int i=p;i>=2;i--){
			if(a[i-1]+a[i+1]-a[i]>a[i]){
				int x=a[i-1]+a[i+1]-a[i];
				int sum1=sum-a[i]+x;
				long long tmp=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n-(long long)sum1*(long long)sum1;
				if(tmp<sqr-(long long)sum*(long long)sum){
					sqr=sqr-(long long)a[i]*(long long)a[i]*(long long)n+(long long)x*(long long)x*(long long)n;
					sum=sum1;
					a[i]=x;
					f=1;
				}
			}
		}
	}
	return sqr-(long long)sum*(long long)sum;
}
int b[10010];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	long long ans1=work1();
	for(int i=1;i<=n;i++)
		a[i]=b[i];
	long long ans2=work2();
	for(int i=1;i<=n;i++)
		a[i]=b[i];
	long long ans3=work3();
	for(int i=1;i<=n;i++)
		a[i]=b[i];
	long long ans4=work4();
	printf("%lld\n",min(ans1,min(ans2,min(ans3,ans4))));
	return 0;
}
