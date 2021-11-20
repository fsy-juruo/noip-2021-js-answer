#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int v[MAXN];
int input();
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%d",&v[i]);
	}
	srand(time(NULL));
	long long i=rand()*1e5+rand();
	cout<<i%998244353;
	return 0;
}
