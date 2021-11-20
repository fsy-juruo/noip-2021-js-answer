#include<bits/stdc++.h>
using namespace std;
#define ri register int 
template<typename yx>inline void read(yx &a){
	yx x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
	a=x*f; 
}
const int N=1e7+1e4;
int id[N];
int pd(int x){
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int main(){
	int t,x,pre=0,n=1e7+1e3;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(ri i=1;i<=n;i++){
		if(id[i])continue;
		int t=pd(i);
		if(!t)id[pre]=i,pre=i;
		else {
			for(ri j=1;j<=n/i;j++){
				id[i*j]=-1;
			}
		}
	}
	read(t);
	while(t--){
		read(x);
		printf("%d\n",id[x]);
	}
	return 0;
}
