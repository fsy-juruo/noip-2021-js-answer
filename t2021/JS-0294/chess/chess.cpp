#include<bits/stdc++.h>
using namespace std;
bool st;
int T,n,m,q;
int head[200005],cnt=1,lvn[200005];
bool cn[200005],v[200005];
char s[100005];
struct o{
	int opt,to,next;
	bool zl;
}e[800005];
bool en;
inline int rd(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
inline void add(int u,int v,int op,int zl){
	if(!op)return ;
	e[cnt].to=v;
	e[cnt].opt=op;
	e[cnt].zl=zl;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
inline int Run(int c,int l,int zl,int tw,int x,int y){
	int s=0;
	bool flag;
	if(zl){
		if(tw-(x*m+y)==1){//right
			++y; 
			while(y<=m){
				flag=0;
				if(cn[x*m+y]==c||lvn[x*m+y]>l)break;
				for(int i=head[x*m+y-1];i;i=e[i].next){
					if((x*m+y)==e[i].to&&e[i].opt==2)flag=1;
				}
				if(!flag)break;
				if(!v[x*m+y])++s,v[x*m+y]=1;
				if(cn[x*m+y]!=c&&l>=lvn[x*m+y])break;
				++y;
			}
		}else{//left
			--y; 
			while(y>=0){
				flag=0;
				if(cn[x*m+y]==c||lvn[x*m+y]>l)break;
				for(int i=head[x*m+y+1];i;i=e[i].next){
					if((x*m+y)==e[i].to&&e[i].opt==2)flag=1;
				}
				if(!flag)break;
				if(!v[x*m+y])++s,v[x*m+y]=1;
				if(cn[x*m+y]!=c&&l>=lvn[x*m+y])break;
				--y;
			}
		}
	}else{
		if(tw-(x*m+y)==m){//down
			++x; 
			while(x<=n){
				flag=0;
				if(cn[x*m+y]==c||lvn[x*m+y]>l)break;
				for(int i=head[x*m+y-m];i;i=e[i].next){
					if((x*m+y)==e[i].to&&e[i].opt==2)flag=1;
				}
				if(!flag)break;
				if(!v[x*m+y])++s,v[x*m+y]=1;
				if(cn[x*m+y]!=c&&l>=lvn[x*m+y])break;
				++x;
			}
		}else{//up
			--x; 
			while(x>=0){
				flag=0;
				if(cn[x*m+y]==c||lvn[x*m+y]>l)break;
				for(int i=head[x*m+y+m];i;i=e[i].next){
					if((x*m+y)==e[i].to&&e[i].opt==2)flag=1;
				}
				if(!flag)break;
				if(!v[x*m+y])++s,v[x*m+y]=1;
				if(cn[x*m+y]!=c&&l>=lvn[x*m+y])break;
				--x;
			}
		}
	}	
	return s;
}
int dfs(int c,int l,int x,int y){
	v[x*m+y]=1;
	int s=1;
	for(int i=head[x*m+y];i;i=e[i].next){
		if(e[i].opt==3&&!v[e[i].to]){
			if(!lvn[e[i].to])s+=dfs(c,l,e[i].to/m,e[i].to%m);
			else if(cn[e[i].to]!=c&&l>=lvn[e[i].to])++s;
		}
	}
	return s; 
}
inline void se(int c,int l,int x,int y){
	int ans=0;
	for(int i=head[x*m+y];i;i=e[i].next){
		if(e[i].opt==1){
			if(!lvn[e[i].to]||(cn[e[i].to]!=c&&l>=lvn[e[i].to]))
				++ans;
		}
		else if(e[i].opt==2)ans+=Run(c,l,e[i].zl,e[i].to,x,y);
		else v[x*m+y]=1,ans+=dfs(c,l,x,y)-1;
	}
	printf("%d\n",ans);
	memset(v,0,sizeof v);
}
int main(){
//	printf("%.2f",(&en-&st)/1024.0/1024);
	freopen("chess3.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=rd();
	while(T--){
		n=rd(),m=rd(),q=rd();
		for(int i=0;i<n;++i){
			scanf("%s",s);
			for(int j=0;j<m-1;++j){
				add(i*m+j,i*m+j+1,s[j]^48,1);
				add(i*m+j+1,i*m+j,s[j]^48,1);
			}
		}
		for(int i=0;i<n-1;++i){
			scanf("%s",s);
			for(int j=0;j<m;++j){
				add(i*m+j,i*m+m+j,s[j]^48,0);
				add(i*m+m+j,i*m+j,s[j]^48,0);
			}
		}
		for(int i=1,col,lv,x,y;i<=q;++i){
			col=rd(),lv=rd(),x=rd(),y=rd();
			--x,--y;
			se(col,lv,x,y);
			lvn[x*m+y]=lv;
			cn[x*m+y]=col;
		}	
		memset(head,0,sizeof head);
		memset(lvn,0,sizeof lvn);
		memset(cn,0,sizeof cn);
		memset(e,0,sizeof e);
		cnt=1;
	}
	return 0;
}

