#include<bits/stdc++.h>
using namespace std;
int p[1001];
bool vis[10000];
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
bool ch777(int x){
	while(x!=0){
		int k=x%10;
		if(k==7) return false;
		x/=10;
	}
	return true;
}
bool check(int x){
	int i=1;
	while(x!=1){
		int cx=x;
		if(!ch777(cx))	return false;
		while(x%p[i]!=0){
			i++;
		}
		if(!ch777(p[i])) return false;
		x/=p[i];
	}
	return true;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=read(),len=1;
	for(int i=2;i<10000;i++){
		for(int j=1;j<=len;j++){
			if(p[j]*i>=10000) break;
			vis[p[j]*i]=true;
		}
		if(vis[i]==true) continue;
		else{
			p[len]=i;
			if(i*i<10000)	vis[i*i]=true;
			len++;
		}
	}
	for(int i=1;i<=t;i++){
		int q=read();
		if(!check(q))
			printf("-1\n");
		else{
			for(int j=q+1;j<1005000;j++){
				if(check(j)){
					printf("%d\n",j);
					break;
				}
			}
		}
	}
	return 0;
}
