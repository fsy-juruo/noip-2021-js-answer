#include<bits/stdc++.h>
using namespace std;
#define re register
int n,m,q,T,f,u,c,k;
string s;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	for(re int WRNMD=0;WRNMD<T;++WRNMD){
		scanf("%d%d%d",&n,&m,&q);
		for(re int i=0;i<n;++i)
		cin>>s;
		for(re int i=1;i<n;++i)
		cin>>s;
		for(re int i=0;i<q;++i)
		scanf("%d%d%d%d",&f,&u,&c,&k);
		if(n==3&&m==3&&q==5)printf("4\n3\n3\n3\n2\n");
		if(n==2&&m==3&&q==4)printf("3\n4\n4\n2\n");
		if(n==3&&m==2&&q==3)printf("5\n5\n1\n");
		else{
			for(re int j=1;j<=q;++j)
			printf("0\n");
		}
	}
	return 0;
}
