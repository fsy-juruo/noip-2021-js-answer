#include<bits/stdc++.h>
using namespace std;
#define For(i,sta,en) for(int i=sta;i<=en;++i)
const int N=10010,M=10000010;
int n,a[N];
long long ans=0x3f3f3f3f;
bool v[N];
inline int read(){
	int s=0,w=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
long long fc(){
	long long x=0,y=0;
	For(i,1,n){
		x+=a[i]*a[i];
		y+=a[i];
	}
	return n*x-y*y;
}
void dfs(){
	ans=min(ans,fc());	
	For(i,2,n-1){
		if(!v[i])continue;		
		int x=a[i];
		a[i]=a[i-1]+a[i+1]-x;
		if(a[i]!=x){
			v[i]=0;
			dfs();
			a[i]=x;
			v[i]=1;
		}		
	}
	return;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	memset(v,1,sizeof(v));
	v[1]=0;v[n]=0;
	n=read();
	For(i,1,n)a[i]=read();
	dfs();
	cout<<ans<<endl;
	return 0;
}
