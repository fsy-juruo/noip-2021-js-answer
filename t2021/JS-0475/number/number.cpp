#include<bits/stdc++.h>
using namespace std;
int a[15000000],s[250000];
bool t[15000000],t1[15000000];
inline bool ch(int x){
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
void fun(int n){
	register int i,l;
	for(i=1;i<=n;++i){
		if(!t[i]){
				if(ch(i)){
			l=i;
			while(l<=n){
				t[l]=1;
				l+=i;
			}
		    }
		}
		a[i]=a[i-1]+1-t[i];
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int t1,l,r,x=0,mid,i;
    scanf("%d",&t1);
    fun(1e7+1);
    for(i=0;i<t1;++i){
    	scanf("%d",&s[i]);
    	x=max(x,s[i]);
	}
	for(i=0;i<t1;++i){
		x=s[i];
		if(t[x])printf("%d\n",-1);
    	else{
    		l=x+1;r=10000001;
    		while(l<r){
    			mid=(l+r)>>1;
    			if(a[mid]>a[x])r=mid;
    			else l=mid+1;
			}
			printf("%d\n",l);
		}
	}
	return 0;
}
