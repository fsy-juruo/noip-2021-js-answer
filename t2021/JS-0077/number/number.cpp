#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x);
int _,n;
int nxt[10000107];
bool vis[10000107];
void pre(){
	for(int i=6;i<=10000100;i++){
		if(vis[i])continue;
		int x=i;
		while(x){
			if(x%10==7){
				vis[i]=1;
				break;
			}
			x/=10;
		}
		if(vis[i])
		for(int j=i;j<=10000100;j+=i){
			vis[j]=1;
		}
	}
	int lst=10000100;
	for(int j=10000100;j>=1;--j){
		if(vis[j])nxt[j]=-1;
		else{
			nxt[j]=lst;
			lst=j;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	pre();
	read(_);
	while(_--){
		read(n);
		printf("%d\n",nxt[n]);
	}
	return 0;
}
void read(int &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	x*=f;
}

