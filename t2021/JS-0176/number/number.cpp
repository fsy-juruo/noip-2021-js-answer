#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+50000;
int T,f[N];
bool b[N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool check(int x){
	if(x%7==0)return true;
	while(x>0){
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<N;i++){
		if(b[i]==1)continue;
		if(check(i))
			for(int j=i;j<N;j+=i){
				b[j]=1;
				f[j]=j+1;
			}
		else f[i]=i;
	}
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		if(b[x]==1){
			puts("-1");
			continue;
		}
//		int ans=x+1;
//		while(b[ans]==1)ans++;
		int ans=find(x+1);
		printf("%d\n",ans);
	}
	return 0;
}
