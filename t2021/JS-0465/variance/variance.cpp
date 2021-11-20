#include<bits/stdc++.h>
using namespace std;
int n,a[10005],b[10005];
int read(){
	char c=' ';
	int x=0,y=1;
	while(c==' '||c=='\n')c=getchar();
	while(c!=' '&&c!='\n'){
		if(c!='-')x=x*10+c-'0';
		else y=-1;
		c=getchar();
	}
	return x*y;
}
void put(int x,char y){
	string s="";
	if(x<0){
		putchar('-');
		x=-x;
	}
	while(x!=0){
		s=s+char(x%10+'0');
		x/=10;
	}
	for(int i=s.size()-1;i>=0;i--){
		putchar(s[i]);
	}
	putchar(y);
}
int d1(int cnt){
	int ans2=-1,ans=0;
	while(ans2!=ans){
		ans2=ans;
		ans=0;
		for(int i=2;i<n;i++){
			if(abs(cnt-b[i]*n)>abs(cnt-b[i]-(n-1)*(b[i-1]+b[i+1]-b[i]))){
				cnt-=b[i];
				b[i]=b[i-1]+b[i+1]-b[i];
				cnt+=b[i];
			}
		}
		for(int i=1;i<=n;i++){
			ans=ans+(cnt-b[i]*n)*(cnt-b[i]*n);
		}
	}
	return ans2;
}
int d2(int cnt){
	int ans2=-1,ans=0;
	while(ans2!=ans){
		ans2=ans;
		ans=0;
		for(int i=n;i>n;i++){
			if(abs(cnt-b[i]*n)>abs(cnt-b[i]-(n-1)*(b[i-1]+b[i+1]-b[i]))){
				cnt-=b[i];
				b[i]=b[i-1]+b[i+1]-b[i];
				cnt+=b[i];
			}
		}
		for(int i=1;i<=n;i++){
			ans=ans+(cnt-b[i]*n)*(cnt-b[i]*n);
		}
	}
	return ans2;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	int cnt=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[i]=a[i];
		cnt+=a[i];
	}
	int d=d1(cnt);
	for(int i=1;i<=n;i++)b[i]=a[i];
	cout<<min(d,d2(cnt))/n;
	return 0;
}

