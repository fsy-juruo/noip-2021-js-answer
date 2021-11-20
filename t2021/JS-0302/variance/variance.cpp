#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read(){
	int x=0,sign=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-'){
		sign=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*sign;
}
int a[10005];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int minn=1000000;
	for(int i=1;i<=6;i++){
		int x=(i&1)+2;
		a[x]=a[x+1]+a[x-1]-a[x];
		int s=0;
		for(int j=1;j<=n;j++){
			s+=a[j];
		}
		int fc=0;
		for(int j=1;j<=n;j++){
			fc+=(a[j]*n-s)*(a[j]*n-s);
		}
		minn=min(fc/n,minn);
	}
	printf("%d",minn);
	
	return 0;
}
