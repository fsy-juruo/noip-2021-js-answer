#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define re return
#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a.size()))
#define rept(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) rept(i,0,a)
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 500000
#define MOD 998244353
bool ok[10000007];
bool ok2[10000007];
int nxt[10000007];
void chk1(){
	rept(i,1,MAXN+5){
		ok[i]=1;
		int j=i;
		while(j){
			if(j%10==7)ok[i]=0;
			j/=10;
		}
	}
}
void chk2(){
	rept(i,1,MAXN+5){
		ok2[i]=1;
		for(int j=1;j*j<=i;j++){
			if(i%j==0&&(ok[j]==0||ok[i/j]==0)){
				ok2[i]=0;
				break;
			}
		}
	}
}
void chk3(){
	for(int i=MAXN+2;i>=0;i--){
		if(ok2[i])nxt[i]=i;
		else nxt[i]=nxt[i+1];
	//	if(i<100)cout<<i<<":"<<nxt[i]<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	chk1(),chk2(),chk3();
	int n;
	cin>>n;
	rep(i,n){
		int x;
		cin>>x;
		if(!ok2[x])cout<<"-1\n";
		else cout<<nxt[x+1]<<"\n";
	}
	re 0;
}

