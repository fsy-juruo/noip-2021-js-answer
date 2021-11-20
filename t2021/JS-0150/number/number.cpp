#include<bits/stdc++.h>
using namespace std;
const int N=1e7+20,MN=1e7;
int n,T;
bool disab[N];
int nm[N],cnt;
int num=0,vnum=0,vn[N];
void getfac(){
	int i=7;
	while(i<=MN){
		disab[i]=true;
		i+=7;	
	}
}
void getnum(){
	for(int i=8;i<=MN;i++){
		if(i%10==7||(i/10)%10==7||(i/100)%10==7||(i/1000)%10==7||(i/10000)%10==7||(i/100000)%10==7||(i/1000000)%10==7){
			disab[i]=true;
			vn[++vnum]=i;
		}
	}
	for(int tp=1;tp<=vnum;tp++){
		int i=vn[tp];
		for(int j=2;j<=MN/i;j++)
			if(!disab[i*j]){
				disab[i*j]=true;
				num++;
			}
	}
}
void getenab(){
	for(int i=1;i<=MN;i++)
		if(!disab[i]){
			nm[++cnt]=i;
		}
	nm[++cnt]=10000001;
}
inline int read(){
	char c=getchar();
	int res=0;
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)){
		res=10*res+c-'0';
		c=getchar();
	}
	return res;
}
inline int lookfor(int x){
	int l=1,r=cnt,mid;
	while(r-l>1){
		mid=l+r>>1;
		if(nm[mid]<=x)
			l=mid;
		else
			r=mid;
	}
	return l;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getfac();
	getnum();
	getenab();
	T=read();
	while(T--){
		int x;
		x=read();
		if(disab[x])
			puts("-1");
		else{
			printf("%d\n",nm[lookfor(x)+1]);
		}
	}
	return 0;
} 
