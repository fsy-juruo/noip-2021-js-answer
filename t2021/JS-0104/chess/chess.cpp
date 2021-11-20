#include<bits/stdc++.h>
#define MAXL 200005
#define _L(a,i,j) a[(i)*(m)+(j)]


using namespace std;
class chess{
public:
	int color;
	int lvl;
	
public:
	chess();
	~chess();
	
};
chess::chess(){
	
}
chess::~chess(){
	
}
int n,m,q,ans;
const int nxt[4][2]={1,0,0,1,-1,0,0,-1};//обсриовС 
int h[MAXL],s[MAXL];
int v[MAXL];
chess* pnt[MAXL];
chess ls[100005];
char gc(){
	char c;
	do{
		c=getchar();
	}
	while(c!='0'&&c!='1'&&c!='2'&&c!='3');
	return c;
}
bool cv(int x,int y,int dt,int opt,chess* c){
	int d;
	if(dt==0) d=_L(s,x,y);
	if(dt==2) d=_L(s,x-1,y);
	if(dt==1) d=_L(h,x,y);
	if(dt==3) d=_L(h,x,y-1);
	if(d!=opt) return 0;
	int tx=x+nxt[dt][0],ty=y+nxt[dt][1];
	if(_L(pnt,tx,ty)==0) return 1;
	if(_L(pnt,tx,ty)->color!=c->color&&_L(pnt,tx,ty)->lvl<=c->lvl) return 1;
	return 0;
}
void fs(int x,int y,int opt,chess* c,int hs=0){
	if(_L(pnt,x,y)!=0){
		if(_L(pnt,x,y)->color!=c->color)
		return;
	}
	if(opt==1){
		for(int i=0;i<4;++i){
			int tx=x+nxt[i][0],ty=y+nxt[i][1];
			if(tx<0||tx>=n||ty<0||ty>=m) continue;
			if(_L(v,tx,ty)&1) continue;
			if(cv(x,y,i,opt,c)){
				if(!_L(v,tx,ty)) {++ans;//<<tx<<' '<<ty<<endl;
				}
				_L(v,tx,ty)|=1;
				//fs(..);
			}
		}
	}
	if(opt==2){
		if(!(hs&2)){
			for(int i=0;i<4;i+=2){
				int tx=x+nxt[i][0],ty=y+nxt[i][1];
				if(tx<0||tx>=n||ty<0||ty>=m) continue;
				if(_L(v,tx,ty)&2) continue;
				if(cv(x,y,i,opt,c)){
					if(!_L(v,tx,ty)) {++ans;//<<tx<<' '<<ty<<endl;
					}
					_L(v,tx,ty)|=2;
					fs(tx,ty,opt,c,1);
				}
			}
		}
		
		if(!(hs&1)){
			for(int i=1;i<4;i+=2){
				int tx=x+nxt[i][0],ty=y+nxt[i][1];
				if(tx<0||tx>=n||ty<0||ty>=m) continue;
				if(_L(v,tx,ty)&2) continue;
				if(cv(x,y,i,opt,c)){
					if(!_L(v,tx,ty)) {++ans;//<<tx<<' '<<ty<<endl;
					}
					_L(v,tx,ty)|=2;
					fs(tx,ty,opt,c,2);
				}
			}
		}
		
	}
	if(opt==3){
		for(int i=0;i<4;++i){
			int tx=x+nxt[i][0],ty=y+nxt[i][1];
			if(tx<0||tx>=n||ty<0||ty>=m) continue;
			if(_L(v,tx,ty)&4) continue;
			if(cv(x,y,i,opt,c)){
				if(!_L(v,tx,ty)) {++ans;//<<tx<<' '<<ty<<endl;
				}
				_L(v,tx,ty)|=4;
				fs(tx,ty,opt,c);
			}
		}
	}
}
void sv(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<=n-1;++i)
	for(int j=0;j<m-1;++j)
	{
		char c;
		//scanf("%c",&c);
		c=gc();
		_L(h,i,j)=c-'0';
	}
	for(int i=0;i<n-1;++i)
	for(int j=0;j<=m-1;++j)
	{
		char c;
		//scanf("%c",&c);
		c=gc();
		_L(s,i,j)=c-'0';
	}
	memset(pnt,0,sizeof(pnt));
	for(int i=0;i<q;++i){
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&b,&x,&y);
		--x;--y;
		ls[i].color=a;
		ls[i].lvl=b;
		_L(pnt,x,y)=&ls[i];
		
		ans=0;
		memset(v,0,sizeof(v));
		_L(v,x,y)=7;
		fs(x,y,1,_L(pnt,x,y));
		fs(x,y,2,_L(pnt,x,y));
		fs(x,y,3,_L(pnt,x,y));
		
		printf("%d\n",ans);
		//<<endl;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		sv();
	}
	return 0;
}

