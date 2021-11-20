#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rp(i,n) for(int i=1;i<=n;i++)
#define forn(i,a,n) for(int i=a;i<n;i++)
#define sz(s) (int)(s.size())
using namespace std;
const int N=2000010;
bool is7[N];
int l[N],r[N];
int findl(int x){
	if(!is7[l[x]]){
		return l[x];
	}
	return l[x]=findl(l[x]);
}
int findr(int x){
	if(!is7[r[x]]){
		return r[x];
	}
	return r[x]=findr(r[x]);
	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	rep(i,N)
	l[i]=i-1;
	rep(i,N)
	r[i]=i+1;
	for(int i=7;i<N;i++){
		if(is7[i])
		continue;
		int b=i;
		bool f=false;
		while(b){
			if(b%10==7){
				f=true;
				break; 
			} 
			b/=10;
		}
		if(!f){
			continue;
		}
		is7[i]=true;
		findl(i);
		findr(i); 
		l[r[i]]=l[i];
		r[l[i]]=r[i]; 
		vector<int> v; 
		for(int j=1;j<=N/i;j=findr(j)){
			if(i*j==N)
			break;
			v.push_back(i*j);
		}
		rep(j,sz(v)){
			is7[v[j]]=true;
			findl(v[j]);
			findr(v[j]);
			l[r[i]]=l[i];
			r[l[i]]=r[i];
		}
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		if(is7[x]) cout<<"-1\n";
		else cout<<findr(x)<<"\n";//printf("%d\n",r[x]);
	}
	return 0;
}

