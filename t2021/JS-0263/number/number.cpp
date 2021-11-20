#include<bits/stdc++.h>
using namespace std;
const int N=200005;
bool a[10000050];int id[N+500];
bool dp[N];
int ne[N];
bool judge(int x){
	int t=10;bool ans=0;
	for(int i=1;i<=7;i++){
		int k=x%t;k=k/(t/10);
		if(k==7) ans=1;;
		
		t*=10;
	}
	return ans;
}

bool not_p[N];int p[N];int tot;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=2;i<=N;i++){
		if(!not_p[i]) {
			p[++tot]=i;
		}
		for(int j=1;j<=tot&&i*p[j]<=N;j++){
			not_p[i*p[j]]=1;
		}
	}

	for(int i=1;i<=N;i++){
		if(a[i]||judge(i)){
		//	cout<<i<<endl;
			a[i]=1;
		//	cout<<"sdlkjfds";
			for(int j=max((int)id[i],1);j<=tot&&(long long )p[j]*i<N;j++){
			//	if(i==126091)cout<<p[j]*i<<endl;
			//	id[i*p[j]]=j;
				a[p[j]*i]=1;
				
			} 
		}
		
	}
	int now =-1;
	for(int i=N;i>=1;i--){
		if(a[i]) ne[i]=-1;
		else {
			ne[i]=now;
			now=i;
		}
	}
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		printf("%d\n",ne[x]);
	}
	return 0;
}
