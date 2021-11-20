#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
int bad[10000005];
int nxt[10000005];
int cnt;
const int mx=1e7;
int t;
bool check(int x){
	while(x!=0){
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
void pre(){
	for(int i=7;i<=mx;i++){
		if(!bad[i] && check(i)) bad[i]=1;
		if(!bad[i] || bad[i]==2) continue;
		for(int j=2;j*i<=mx;j++)
			bad[i*j]=2;
	}
	int lst=10000001;
	for(int i=1e7;i>=1;i--){
		nxt[i]=lst;
		if(!bad[i]) lst=i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	pre();
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		if(bad[a]) printf("%d\n",-1);
		else printf("%d\n",nxt[a]);
	}
	return 0;
}
//int overflow
//memset
//out of bound
//corner cases
//big testcase
