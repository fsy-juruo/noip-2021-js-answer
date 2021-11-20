#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int t,x;
int hav[N+10];
int nex[N+10];
int read(){
	char c=getchar();int x=0;
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int judge(int num){
	while(num){
		if(num%10==7) return 2;
		num/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N;++i){
		hav[i]=max(judge(i),hav[i]);
		if(hav[i]!=2) continue;
		for(int j=i*2;j<=N;j+=i)
			if(!hav[j]) hav[j]=1;
	}
	int las=0;
	for(int i=1;i<=N;++i){
		if(hav[i]) continue;
		for(int j=las;j<=i;++j) nex[j]=i;
		las=i;
	}
	t=read();
	while(t--){
		x=read();
		if(hav[x]) printf("-1\n");
		else printf("%d\n",nex[x]);
	}
	return 0;
}
// T1 written by Skaditxdy
