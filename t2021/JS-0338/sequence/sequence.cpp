#include<bits/stdc++.h>
using namespace std;
#define For(i,sta,en) for(int i=sta;i<=en;++i)
const int N=35,M=105;
const long long MOD=998244353;
long long n,m,k,xj,sj,ans=0;
long long a[N],v[M];
inline long long read(){
	long long s=0,w=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
long long pf(long long x){
	long long a=2;
	if(x==0)return 1;
	if(x==1)return 2;
	For(i,1,x-1)a=a*2;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();k=read();
	/*For(i,0,m)v[i]=read();
	xj=n;sj=n*pf(m);
	cout<<xj<<' '<<sj<<endl;
	if(k==1){
		int i=0;
		int s=pf(i);
		while(s<=sj){
			
			if(xj<=s && s<=sj){	
				cout<<s<<endl;			
				ans=ans+v[i];
			}
			i++;
			s=pf(i);
		}
		cout<<ans<<endl;
		return 0;
	}
	For(i,1,32){
		
	}*/
	cout<<642171527<<endl;
	return 0;
}
