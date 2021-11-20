#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int T,ans[N+5];
bool f[N+5];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T); 
	for(int i=7;i<=N;i+=7) f[i]=1;
	for(int i=1;i<=N;i++)
		if(!f[i]){
			int now=i;
			while(now){
				if(now%10==7){
					f[i]=1;
					break;
				}
				now/=10;
			}
			if(f[i]){
				for(int j=i;j<=N;j+=i) f[j]=1;
			}
			else{
				int j=i-1;
				while(f[j]){
					j--;
				}
				ans[j]=i;
			}
		}
	while(T--){
		int x;
		scanf("%d",&x);
		if(f[x]) puts("-1");
		else printf("%d\n",ans[x]);
	}
	return 0;
} 
