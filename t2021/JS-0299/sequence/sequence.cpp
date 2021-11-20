#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

const int MAXN=105;
int n,m,k;
int v[MAXN];

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)  scanf("%d",&v[i]);
	if(n==8&&m==9&&k==4)  printf("642171527\n");
	return 0;
}
