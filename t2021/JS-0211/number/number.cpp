#include<bits/stdc++.h>
#define LL long long
using namespace std;
int qread(){
	int s=0,f=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-'){f=-1;c=getchar();}
	while(c>='0'&&c<='9'){
		s*=10;
		s+=c-'0';
		c=getchar();
	}
	return s*f;
}
int is7(int x){
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int h[11000011],a[11000011],x[11000011],tot=0,maxx=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i){
		x[i]=qread();
		maxx=max(maxx,x[i]*2);
	}
	maxx=min(maxx,10000011);
	for(int i=1;i<=maxx;++i){
		if(!h[i]){
			if(is7(i)){
				for(int j=i;j<=maxx;j+=i){
					h[j]=1;
				}
			}else{
				a[++tot]=i;
			}
		}
	}
//	return 0;
	for(int i=1;i<=t;++i){
		if(h[x[i]]){
			printf("-1\n");
			continue;
		}else{
			int l=1,r=tot+1,mid;
			while(l<r){
				mid=(l+r)>>1;
				if(a[mid]>x[i])r=mid;
				else l=mid+1;
			}
			printf("%d\n",a[l]);
		}
	}
return 0;
}

