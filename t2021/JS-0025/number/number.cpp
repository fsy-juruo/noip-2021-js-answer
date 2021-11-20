#include<bits/stdc++.h>
#define N 10000505
using namespace std;
bool ban[N],kk[N];
int nxt[N];
int tot=0;
void sieve(int n){
	//cerr<<n<<endl;
	for(int i=1;i<=n;++i){
		if(kk[i/10]|(i%10==7)){
			if(!ban[i]){
				for(int j=i;j<=n;j+=i){
					ban[j]=1;
					//++tot;
				}
			}
			ban[i]=kk[i]=1;
			//cerr<<i<<endl; 
//			if(ban[i]==0){
//				for(int j=1;j<=cnt&&i*pr[j]<=10000500;++j){
////					assert(ban[i*pr[j]]==0);
////					if(ban[i*pr[j]]==1){
////						cerr<<i<<" "<<pr[j]<<endl;
////					}
//					++tot;
//					ban[i*pr[j]]=1;
//				}
//			}
//			pr[++cnt]=i;
			//++tot; 
		}
//		for(int j=1;i*pr[j]<=10000000&&j<=cnt;++j){
//			ban[i*pr[j]]=1;
//			if(i%pr[j]==0) break;
//		}
//		ban[i]|=kk[i];
//		if(!ban[i]) pr[++cnt]=i;
//		for(int j=1;j<=cnt&&i*pr[j]<=100;++j){
//			ban[i*pr[j]]=1;
//			if(i%pr[j]) break;
//		}
//		if(ban[i]){
//			for(int j=1;j*i<=10000000;++j){
//				ban[i*j]=1;
//				if(i%j==0) break;
//			}
//		}
	}
	for(int i=n;i>=1;--i){
		if(ban[i]) nxt[i]=nxt[i+1];
		else nxt[i]=i;
		//if(i<=10000000)mx=max(mx,nxt[i]-i);
		//if(nxt[i]-i>=1000000) cerr<<i<<endl;  
	}
}
int T,x,Q[200005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//cerr<<tot<<endl;
	//int mx=0; 
//	for(int i=10000100;i>=1;--i){
//		if(ban[i]) nxt[i]=nxt[i+1];
//		else nxt[i]=i;
//		if(i<=10000000)mx=max(mx,nxt[i]-i);
//		if(nxt[i]-i>=1000000) cerr<<i<<endl;  
//	}
//	cerr<<mx<<endl;
	//cerr<<nxt[9999999]<<endl;
	scanf("%d",&T);
	int mx=0;
	for(int i=1;i<=T;++i){
		scanf("%d",&Q[i]);
		mx=max(mx,Q[i]);
	}
	//cerr<<mx<<endl;
	if(mx<=200005) sieve(500005);
	else{
		sieve(10000105);
		//puts("233");
	}
	//cerr<<tot<<endl;
	for(int i=1;i<=T;++i){
		if(nxt[Q[i]]!=Q[i]) puts("-1");
		else printf("%d\n",nxt[Q[i]+1]);
	}
//	while(T--){
//		scanf("%d",&x);
//		if(nxt[x]!=x) puts("-1");
//		else{
//			printf("%d\n",nxt[x+1]);
//		}
//	}
	return 0;
}

