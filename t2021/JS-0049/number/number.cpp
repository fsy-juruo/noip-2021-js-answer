#include<bits/stdc++.h>
#define LL long long
#define PB push_back
using namespace std;
void file(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
template <typename T>void read(T&x){
	x=0;int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	x*=f;
}
const int sdx = 2e5 +10;
const int maxx = 1e7+10;
const int sq= 3180;
bool f[maxx];
int n,m;
int num[maxx],nxt[maxx],sizer;
int tomax;
int p[maxx];
bool check(int x){
	if(f[x])return 1;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			if(f[i]||f[x/i])return 1;
		}
	}
	return 0;
}
void init(){
	int nx[9]={1,1,1,1,1,1,2,1,1};
	for(int i=7,bs=10,lg=1;i<1e7;i*=10,bs*=10,lg*=10){
		int x=i;
		for(int k=0;x<1e7;k++,x=i+k*bs){
			for(int y=x,l=0,tol=0;tol<lg;tol+=nx[l],y+=nx[l],l=(l+1)%9){
				f[y]=1;
			}
		}
	}
	for(int i=1;i<=1e7;i++){
		if(!f[i])nxt[sizer]=sizer+1,++sizer,num[sizer]=i;
		else p[i]=-1;
	}
	for(int i=0;nxt[i]!=0&&(clock()<890||tomax<=2e5);tomax=num[i]){
		if(check(num[nxt[i]]))f[num[nxt[i]]]=1,p[num[nxt[i]]]=-1,nxt[i]=nxt[nxt[i]];
		else p[num[i]]=num[nxt[i]],i=nxt[i];
	}
}

int main(){
	file("number");
	init();
	read(n);
	for(int i=1;i<=n;i++){
		int x;
		read(x);
		printf("%d\n",p[x]);
	}
	return 0;
}

