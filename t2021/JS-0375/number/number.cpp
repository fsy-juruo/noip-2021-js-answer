#include <bits/stdc++.h>
#define M 10000005
using namespace std;
int T,a,pr[M],cnt; 
bool bok[M];

void prim(int x){
	for(int i=1;i<=cnt;++i)
		if(!x%pr[i]) return;
	pr[++cnt]=x;
}
//
//bool dev(int x){
//	for(int i=1;i<=pcnt;++i){
//		if(!x%pr[i]) de[i]=0;
//		while(!x%pr[i]){
//			x/=pr[i];
//			++de[i];
//		}
//	}
//	for(int )
//}

bool p(int x)
{ 
	if(bok[x]) return true;
	for(int i=2;i<=sqrt(x);++i){
		if(x%i==0){
			if(p(i)){
				bok[i]=1;
				return true;
			}
			if(p(x/i)){
				bok[x/i]=1;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	for(int i=1;i<=M;++i){
//		prim(i);
		int t=i;
		while(t){
			if(t%10==7){
				bok[i]=1;
				break;
			}
			t/=10;
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&a);
		if(p(a)){
			printf("%d\n",-1);
			continue;
		}
		++a;
		while(p(a))
			++a;
		printf("%d\n",a);
	}
	return 0;
 } 
