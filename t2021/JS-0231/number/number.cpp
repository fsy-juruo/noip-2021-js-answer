#include<bits/stdc++.h>
using namespace std;
const int N=2000055;
vector<int> v;
bool vis[N];
bool chk(int x){
	while(x){
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
} 
void init(int n){
	for(int i=2;i<=n;++i){
		if(vis[i]||chk(i)){
			for(int j=1;j*i<=n;++j){
				vis[j*i]=1;
			}
		}else v.push_back(i);
	}
}
int t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init(2000050);
//	for(int i=v[v.size()-1];i<=100;++i){
//		if(vis[i]) continue;
//		vis[i]=chk(i);
//		if(!vis[i]) v.push_back(i);
//	}
//	printf("%d\n",v.size());
//	for(int i=0;i<v.size();++i){
//		printf("%d,",v[i]);
//	}
//	printf("%d:%d\n",v.size(),v[v.size()-1]);
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		int x;
		scanf("%d",&x);
		vector<int>::iterator it=lower_bound(v.begin(),v.end(),x);
		if(*it==x) printf("%d\n",*(++it));
		else puts("-1");
	}
	return 0;
}
