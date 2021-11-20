#include<bits/stdc++.h>
using namespace std;
struct chess {
	int col,lv,x,y;
};
chess a[200005];
struct opt {
	int x,y;
};
opt b[1005][1005];
int mp0[1005][1005],mp1[1005][1005];
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,m,q;
		char c1[100005];
		char c2[100005];
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1; i<=n; i++) {
			scanf("%c",&c1[i]);
		}
		int i1=1;
		for(int j=1;j<m;j++){
			b[i1++][j].x=c1[j];
		}
		for(int i=1; i<n; i++) {
			scanf("%c",&c2[i]);
		}
		int i2=1;
		for(int j=1;j<m;j++){
			b[i2++][j].y=c2[j];
		}
		for(int i=1; i<=q; i++) {
			int cnt=0;
			int x,y;
			scanf("%d%d%d%d",&a[i].col,&a[i].lv,&a[i].x,&a[i].y);
			x=a[i].x;
			y=a[i].y;
			if(a[i].col==0) mp0[x][y]=a[i].lv;
			else mp1[a[i].x][a[i].y]=a[i].lv;
			if((a[i].x+1)<=n) cnt=cnt+b[x][y].y;
			if((a[i].y+1)<=m) cnt=cnt+b[x][y].x;
			if((a[i].x-1)>=1) cnt=cnt+b[x-1][y].y;
			if((a[i].y-1)>=1) cnt=cnt+b[x][y-1].x;
			for(int i1=x-1; i1<=x+1; i1++) {
				for(int j1=y-1; j1<=y+1; j1++) {
					if(i1<1||i1>n||j1<1||j1>m||(i1==x&&j1==y)) continue;
					if(mp0[i1][j1]!=0&&a[i].col==0) cnt--;
					else if(mp1[i1][j1]!=0&&a[i].col==1) cnt--;
					else if(mp0[i1][j1]!=0&&a[i].lv<mp0[i1][j1]) cnt--;
					else if(mp1[i1][j1]!=0&&a[i].lv<mp1[i1][j1]) cnt--;
				}
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
