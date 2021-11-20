#include<bits/stdc++.h>
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
int t,x,tot ;
int q ;
int a[10] ;
bool vis[10000000+10],use[10] ;
void dfs(int dep){
	if(dep==7){
		int ret = 0 , p = 1 ;
		for(int i = 0 ; i < 7 ; i++)
			ret+=p*a[i] , p*=10 ;
		//cout<<ret<<endl ; system("pause") ;
		if(vis[ret]==0)
			for(int i = ret ; i < 10000000 ; i+=ret)
				vis[i] = 1 ;
				
		//	}
	//	if(ret==17)cout<<vis[34]<<endl ;
		return ; 
	}
	if(use[dep]==1){
		a[dep] = 7 ;
		dfs(dep+1) ;
		return ;
	}
	else for(register int i = 0 ; i < 10 ; i++){
			if(i==7)continue ;
			a[dep] = i , dfs(dep+1) , a[dep] = 0 ;
		}
}
int b[10000000] ;
int lowbit(int num){
	return num&(-num) ;
}
void write(int x){
	if(x==-1){
		printf("-1") ;
		return ;
	}
	if(x<10){
		putchar(x+'0') ;
		return ;
	}
	write(x/10) ;
	putchar((x%10)+'0') ;
}
int main(){
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	for(int i = 1 ; i <= 127 ; i++){
		int tmp = i ;
		memset(use,0,sizeof(use)) ;
		while(tmp>0){
			int d = lowbit(tmp) ;
			use[(int)log2(d)] = 1 ;
			tmp-=d ;
		}
		dfs(0) ;
	}
	for(register int i = 1 ; i < 10000000 ; i++)
		if(vis[i]==0)b[++tot] = i ;
//	cout<<b[16176]<<endl ;
//	cout<<tot<<endl ;
	read(t) ;
	while(t--){
		read(x) ;
		if(x==10000000){
			printf("-1\n") ;
			continue ;
		}
		int ans = 10000001 ;
		if(vis[x]==1)ans = -1 ;
		else{
			int l = 1 ,r = tot ,mid ;
			while(l<=r){
				mid = (l+r)>>1 ;
				if(b[mid]>x){
					ans = min(ans,b[mid]) ;
					r = mid-1 ;
				}
				else l = mid+1 ;
			}
		}
		write(ans) ; puts("") ;
	}
	return 0 ;
}

