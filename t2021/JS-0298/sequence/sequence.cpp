#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int  n,m,k,v[105],tot;

int cf(int num,int cs){
	int r=1;
	for(int i=1;i<=cs;i++)
	  r*=num;
	return r;
}
int check(int num){
	int y=num,yp=0;
	while(y>0){
		int u=y|1;
		if(u==1) yp++;
		y=y>>1;
	}
	return yp;
}
void spd(int num,int ce,int al,long long sz){
	if(num==0&&al==0){
//		ans+=sz;
		return ;
	}
	if(num==0) return;
	if(ce>m) return ;
	for(int i=1;i<=n;i++){
		if(cf(2,ce)*i<=num){
//			spd(num-cf(2,ce)*i,ce+1,al-i,sz*)
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%d",&v[i]);
	}
	tot=cf(2,m);
//	for(int i=n;i<=n*tot){
//		if(check(i)<=k){
//			spd(i,1,n,1);
//		}
//	}
	return 0;
}
