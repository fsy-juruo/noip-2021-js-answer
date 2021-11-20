#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
struct node(){
	int l,r,u,d;
	int que,c=-1;
}f[1001][1001];
int t,ans;
int fa[200015];
int px[4]={-1,0,1,0};
int py[4]={0,1,0,-1};
void search(int dc,int dl,int dx,int dy){
	if(f[dx][dy].l!=0){
		if(f[dx-1][dy].que!=0){
			if(f[dx-1][dy].c!=dc&&f[dx-1][dy].que<dl)ans++;
		}
		else if(f[dx-1][dy].l==1)ans++;
		else if(f[dx-1][dy].l==2){
			int qx=dx-1;
			ans++;
			while(f[qx][dy].l==2&&f[dx-1][dy].que==0){
				qx--;
				ans++;
			}
			if(f[qx-1][dy].c!=dc&&f[qx-1][dy].que<dl&&f[qx-1][])ans++;
		}
	}
}
int main(){
//   freopen("test.in","r",stdin);
//   freopen("test.out","w",stdout);
   t=read();
   for(int i=1;i<=t;++i){
   	memset(f,0,ziseof(f));
   	int n=read(),m=read,q=read();
   		string s;
   		for(int j=1;j<=n;++i){
   			cin>>s;
   			
		}
		for(int j=1;j<=n-1;++i){
   			cin>>s;
   			
		}
		for(int j=1;j<=q;++j){
			int col=read(),lv=read(),x=read(),y=read(); 
			
		}
   }
   return 0;
}

