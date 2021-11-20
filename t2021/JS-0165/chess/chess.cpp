//WSQ
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int T;
int n,m,q;
int tot;
struct node{
	int to,next,opt;
}a[1000005];
int head[1000005];
int col[200005],lv[200005];
void add(int x,int y,int z){a[++tot].to=y;a[tot].next=head[x];head[x]=tot;a[tot].opt=z;}
void init(){
	memset(head,0,sizeof(head));
	tot=0;
	memset(a,0,sizeof(a));
	memset(lv,0,sizeof(lv));
	memset(col,-1,sizeof(col));
}
int num(int x,int y){return (x-1)*m+y;}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
			for(int j=1;j<m;j++){
				char z;
				cin>>z;
				add(num(i,j),num(i,j+1),int(z-'0'));
				add(num(i,j+1),num(i,j),int(z-'0'));
			}
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++){
				char z;
				cin>>z;
				add(num(i,j),num(i+1,j),int(z-'0'));
				add(num(i+1,j),num(i,j),int(z-'0'));
			}
		while(q--){
			int c,l,x,y,ans=0;
			scanf("%d%d%d%d",&c,&l,&x,&y);
			lv[num(x,y)]=l;
			col[num(x,y)]=c;
			for(int i=head[num(x,y)];i;i=a[i].next){
				int temp=a[i].to;
				if(a[i].opt==1&&(lv[temp]==0||(c!=col[temp]&&l>=lv[temp])))ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
