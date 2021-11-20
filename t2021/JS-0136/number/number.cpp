#include<bits/stdc++.h>
using namespace std;
int const N=1e7;
int t,n;
int nxt[N*2],p,k,b,m;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
bool check(int x){
	while(x){
		b=x%10;
		if(b==7) return 1;
		x/=10;
	}
	return 0;
}
int main(){

freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
nxt[0]=1;
nxt[1]=2;
nxt[2]=3;
p=2;
	for(int i=3;i<=1e7*2-1;i++){
		if(nxt[i]==-1) continue;
			if(check(i)){
			k=1;
		m=i;
		while(m<=1e7*2-1){
			nxt[m]=-1;
			k++;
			m=k*i;
		}	
			}
			else{
				nxt[p]=i;
				p=i;
			}
		
	}
	t=read();
	while(t--){
		n=read();
		printf("%d\n",nxt[n]);
	}
return 0;
}

