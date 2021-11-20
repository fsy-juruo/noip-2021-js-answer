#include<bits/stdc++.h>
#define N 2000100
using namespace std;
int M=11000000;
inline int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();	
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int t,n,p,pt[N],cnt;
bool v[11000000];
inline bool check(int x){
	while(x){
		if(x%10==7)return 1;x/=10;
	}return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	if(t<=10000)M=1000000;
	for(int i=1;i<M;++i){
		if(v[i])continue;
		if(check(i)){
			int k=i;
			while(k<M){
				v[k]=1;
				k+=i;
			}continue;
		}pt[++cnt]=i;
	}
	while(t--){
		n=read();
	    p=lower_bound(pt+1,pt+1+cnt,n)-pt;
	    if(pt[p]!=n){
	    	printf("-1\n");
		}else printf("%d\n",pt[p+1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
