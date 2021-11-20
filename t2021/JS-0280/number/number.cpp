#include<bits/stdc++.h>
using namespace std;
int read(){
	 int r=0,f=1;char ch=getchar();
	 while (!isdigit(ch)&&ch!='-') ch=getchar();
	 if (ch=='-') f=-1,ch=getchar();
	 while (isdigit(ch)) r=(r<<3)+(r<<1)+ch-'0',ch=getchar();
	 return r*f;
}
int v[20000005],a[20000005];
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int N=1e7+1000;
	for (int i=1;i<=N;i++){
		int x=i,f=1;
		if (v[i]) continue;
		while (x){
			if (x%10==7){f=-1;break;}
			x/=10;
		}
		if (f==1) continue;
		for (int j=i;j<=N;j+=i) v[j]=1;
	}
	int now=N+1;
	for (int i=N;i>=1;i--){
		a[i]=now;
		if (v[i]==0) now=i;
	}
	int T,x;
	T=read();
	while (T--){
		x=read();
		if (v[x]) putchar('-'),putchar('1'),putchar('\n');
		else write(a[x]),putchar('\n');
	}
	return 0;
}

