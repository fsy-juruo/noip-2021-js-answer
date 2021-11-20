#include<bits/stdc++.h>
using namespace std;
int read(){
	int sz=0,fh=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')fh=-1;ch=getchar();}
	while(isdigit(ch)){sz=sz*10+(ch-'0');ch=getchar();}
	return sz*fh;
}
void write(int tx){
	if(tx<0){
		putchar('-');
		tx=-tx;
	}
	if(tx>9)write(tx/10);
	putchar(tx%10+'0');
}
int a[200100],f[10010000],ans[10010000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=10000000;i++){
		if(f[i]==1)continue;
		int tx=i;
		bool tf=true;
		while(tx!=0){
			if(tx%10==7){
				tf=false;
				break;
			}
			tx/=10;
		}
		if(!tf){
			for(int j=i;j<=10001000;j+=i)f[j]=1;				
		}
	}
	for(int i=10001000;i>=1;i--){
		if(f[i+1])ans[i]=ans[i+1];
		else ans[i]=i+1;
	}
	for(int i=1;i<=n;i++){
		if(f[a[i]])write(-1),putchar('\n');
		else write(ans[a[i]]),putchar('\n');
	}
	return 0;
}

