#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0,w=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*w;
}
void print(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9){
		print(x/10);
	}
	putchar(x%10+'0');
}
int n;
int a[10005];
int mn;
int calc(){
	int sum=0,ret=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		ret+=(n*a[i]-sum)*(n*a[i]-sum);
	}
	ret/=n;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	while(true){
		bool f=true;
		for(int i=2;i<=n-1;i++){
			int s=calc();
			int tmp=a[i];
			a[i]=(a[i-1]+a[i+1]-a[i]);
			int e=calc();
			if(e>=s){
				a[i]=tmp;
			}else{
				f=false;
			}
		}
		if(f){
			break;
		}
	}
	print(calc());
	return 0;
}
