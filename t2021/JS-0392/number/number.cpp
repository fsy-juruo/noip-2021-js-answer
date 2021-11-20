#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
const int maxn=2e5+5;
int vis[N],id[N],s=10000;//是否可用,是否为含有数字7的倍数 
int a[maxn];
template<typename _T>
void read(_T &x){
	int f=1;x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=f;
}
bool find(int y){//有没有7 
	while(y){
		int x=y%10;
		y/=10;
		if(x==7){
			return true;//有7 
		}
	}
	return false;
}
bool check(int num){
	if(find(num)==true){//有没有7 
		int k=1;
		while(num*k<=s){
			if(id[num*k]==1) {
				k++;
				continue;
			}
			id[num*k]=1;
			k++;
		}
	}
	if(id[num]==1) return false;
	return true;
}
void work(){//枚举打表 
	for(int i=1;i<=s;i++){
		if(check(i)==true){//可行 
			vis[i]=1;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(vis,0,sizeof(vis));
    memset(id,0,sizeof(id));
	int T,ch=0;
	read(T);
	for(int i=1;i<=T;i++){
		read(a[i]);
		if(a[i]+5>maxn){
			s=N;
			ch=1;
		} else if(a[i]>10000&&ch==0){
			s=maxn;
			ch=1;
		}
	}
	work();
	for(int i=1;i<=T;i++){
		int x=a[i];
		if(vis[x]==0){
			printf("-1\n");
			continue;
		}
		while(x){
			++x;
			if(vis[x]==1){
				printf("%d\n",x);
				break;
			} 
		}
	}
	return 0;
}
