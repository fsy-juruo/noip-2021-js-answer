#include<bits/stdc++.h>
using namespace std;
int T,x;
bool f[10001005];
int read() {
	char c=getchar();
	int f=1,res=0;
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {res=(res<<1)+(res<<3)+c-'0';c=getchar();}
	return f*res;
} 
bool check(int a) {
	while(a!=0) {
		if(a%10==7)return 1;
		a/=10;
	}
	return 0;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	memset(f,0,sizeof(f));
	for(int i=1;i<=10000500;i++) {
		if(f[i]==1)continue;
		if(check(i)==1) {
			for(int j=i;j<=10000500;j+=i)
				f[j]=1;
		}
		
	}
	while(T--) {
		x=read();
		if(f[x]==1)cout<<-1<<endl;
		else{
			x++;
			while(f[x]==1) {
				x++;
			}
			printf("%d\n",x);
		} 
	}
}
