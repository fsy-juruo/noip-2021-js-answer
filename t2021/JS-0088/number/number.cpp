#include <bits/stdc++.h>
using namespace std;
bool f[10000005];
int a[10000005];
int n,t;
vector<int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=5000000;i++){
		if(!f[i]){
			bool p=0;
			for(int j=1;j<=i;j*=10)
			if((i%(j*10))/j==7){
				p=1;break;
			}
			if(p){
				bool k=0;
				for(int j=0;j<v.size();j++){
					if(v[j]*i>5000000){
						k=1;break;
					}
					f[v[j]*i]=1;
				}
				if(!k)
				for(int j=i*i;j<=5000000;j+=i)
				f[j]=1;
			}
			if(!f[i])v.push_back(i);
		}
	}
	t=5000000;
	for(int i=5000000;i>=1;i--){
		a[i]=t;
		if(!f[i])t=i;
	}
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		if(f[x])printf("%d\n",-1);
		else printf("%d\n",a[x]);
	}
	return 0;
}
