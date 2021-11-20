#include<bits/stdc++.h>
#define ge getchar()
#define pu putchar
#define N 10000001
using namespace std;
inline void read(int &x){
	x=0;int f=0,c=ge;
	for(;c<48||c>57;c=ge)if(c==45)f=1;
	for(;48<=c&&c<=57;c=ge)x=(x<<3)+(x<<1)+(c^48);
	if(f)x=-x;
}
void write(int x){
	if(x<0){pu(45);x=-x;}
	if(x>9)write(x/10);
	pu(x%10+48);
}
int t,n=0,a[N],p[N+5],si=0;bool f[N+5];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(t);
	for(int i=1;i<=t;++i){
		read(a[i]);
		if(n<a[i])n=a[i];
	}
	n=min(n*10,N);
	for(int i=1;i<=n;++i)if(!f[i]){
		bool fl=0;
		for(int c=i;c;c/=10){
			if(c%10==7){fl=1;break;}
		}
		if(fl){
			for(int j=i;j<=n;j+=i)f[j]=1;
		}
	}
	for(int i=1;i<=n;++i)if(!f[i])p[++si]=i;
	for(int i=1;i<=t;++i){
		if(f[a[i]]){write(-1);pu('\n');}
		else{
			int l=1,r=si,h,m;
			while(l<=r){
				m=(l+r)>>1;
				if(p[m]>a[i]){h=m;r=m-1;}
				else l=m+1;
			}
			write(p[h]);pu('\n');
		}
	}
	return 0;
}
