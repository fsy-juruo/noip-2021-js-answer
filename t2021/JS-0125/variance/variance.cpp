#include<iostream>
#include<algorithm>
#include<cstdio>
#include<fstream>
using namespace std;

long long read(){
	long long sum = 0;
	int neg = 1;
	char c = getchar();
	while(c<'0'||c>'9'){
		if(c == '-')neg = -1;
		c = getchar();
	}
	while(c>='0'&&c<='9'){
		sum = sum*10+(c-'0');
		c = getchar();
	}
	return sum * neg;
}

long long n,a[1000010];
long long d1[1000010],d2[1000010];
long long s,minn = 9999999999;
long long a2[1000010];
bool vis[1000010];

void check(){
	a2[0] = a[0];
	s = a2[0];
	long long s2 = a2[0]*a2[0];
	for(long long i = 1;i<n;i++){
		a2[i] = d2[i]+a2[i-1];
		s += a2[i];
		s2 += a2[i]*a2[i];
	}
	minn = min(minn,s2*n-s*s);
}

void dfs(long long cur){	
	for(long long i = 1;i<n;i++){
		if(!vis[i]){
			vis[i] = 1;
			d2[cur] = d1[i];
			dfs(cur+1);	
			vis[i] = 0;
		}
	}
	if(cur == n){
		check();
		return;
	}
}



int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	n = read();
	for(long long i = 0;i<n;i++){
		a[i] = read();
	}
	d1[0] = a[0];
	d2[0] = a[0];
	for(long long i = 1;i<n;i++){
		d1[i] = a[i]-a[i-1];
	}
	dfs(1);
	cout<<minn<<endl;
	return 0;
}
