#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int rdi(){//signed
	int x=0,y=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')y=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*y;
}
int rdui(){//unsigned
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
bool good(int x){
	while(x){
		if(x%10==7)return 0;
		x/=10;
	}
	return 1;
}
int p[10000010];
vector<int>v;
void precalc(int N=1e7+5){
	for(int i=1;i<=N;i++){
		if(p[i])continue;
		if(good(i)){v.pb(i);continue;}
		p[i]=1;
		for(int j=1;i*j<=N;j++)p[i*j]=1;
	}
}
int main(){
#ifndef OFFLINE
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
#endif
	// freopen("number4.in","r",stdin);
	// freopen("number4.out","w",stdout);
	precalc();
	// for(int i=1;i<=100;i++)printf("%d ",p[i]);
	// for(int i=0;i<40;i++)printf("%d\n",v[i]);
	int t=rdui();
	while(t--){
		int x=rdui();
		if(p[x])puts("-1");
		else{
			int id=lower_bound(v.begin(),v.end(),x)-v.begin();
			printf("%d\n",v[id+1]);
		}
	}
	return 0;
}

/*
4
6
33
69
300


5
90
99
106
114
169
*/