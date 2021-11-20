#include<bits/stdc++.h>
#define int long long
using namespace std ;
template<typename T> void read(T &x){
	x = 0 ; int flag = 1 ;
	char c = getchar() ;
	while(!isdigit(c)){
		if(c=='-')
			flag = -1 ;
		c = getchar() ;
	}
	while(isdigit(c)){
		x = x * 10 + c - '0' ;
		c = getchar() ;
	}
	x = x*flag ;
}
int n ;
const int maxn = 10000+10 ;
int a[maxn] ;
int sol(){
	int ret = 0,sum = 0 ;
	for(int i = 1 ; i <= n ; i++)
		sum+=a[i] ;
	for(int i = 1 ; i <= n ; i++)
		ret+=a[i]*a[i] ;
	ret = ret*n-sum*sum ;
	return ret ;
}
signed main(){
	freopen("variance.in","r",stdin) ;
	freopen("variance.out","w",stdout) ;
	read(n) ;
	for(int i = 1 ; i <= n ; i++)
		read(a[i]) ;
	cout<<sol()<<endl ; 
	return 0 ;
}

