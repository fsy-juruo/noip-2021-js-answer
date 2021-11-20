#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=1e8+10;

LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int T;
bool st[N];
int p[100],top;
bool check(int k){
	while(k!=0){
		int t=k%10;
		k/=10;
		if(t==7)return true;
	}
	return false;
}
void init(){
	for(int i=1;i<=1e7;i++){
		if(st[i])continue;
		if(i%8==0||check(i)==true){
			int j=1;
			while(i*j<=1e7){
				st[i*j]=1;
				j++;
			}
		}
	}
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	scanf("%d",&T);
	while(T--){
		LL k=read();
		if(st[k]==1){
			puts("-1");
			continue;
		}
		k+=1;
		while(st[k]==1)
			k++;
		printf("%lld\n",k);
	}
	return 0;
}

