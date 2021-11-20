#include <bits/stdc++.h>
using namespace std;
int T,n,nxt[10000100];
bool isok[10000100];
inline int read(){
	int FF=0,RR=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())
		if(ch=='-')
			RR=-1;
	for(;isdigit(ch);ch=getchar())
		FF=(FF<<1)+(FF<<3)+ch-48;
	return FF*RR;
}
bool check(int x){
	while(x){
		if(x%10==7)
			return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int lst=0;
	for(int i=1;i<=10000010;i++){
		if(!isok[i]&&check(i)){
			isok[i]=1;
			for(int j=i+i;j<=10000010;j+=i)
				isok[j]=1;
		}
		if(!isok[i]){
			nxt[lst]=i;
			lst=i;
		}
	}
	T=read();
	while(T--){
		n=read();
		if(isok[n])
			puts("-1");
		else
			printf("%d\n",nxt[n]);
	}
	return 0;
}

