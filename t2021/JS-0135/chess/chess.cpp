#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	int y=1;
	char a;
	a=getchar();
	while(a<'0'||a>'9'){
		if(a=='-')y=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=y;
}
int t;
int n,m,q;
struct ffff{
	int co,lv;
};
ffff f[200008];
string ff[400008];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(t);
	while(t--){
		read(n);read(m);read(q);
		for(int i=1;i<=n;++i){
			cin>>ff[i];
			ff[i]=" "+ff[i];
		}
		for(int i=1;i<=n-1;++i){
			cin>>ff[i+n];
			ff[i+n]=" "+ff[i+n];
		}
		for(int i=1;i<=q;++i){
			int co,lv,x,y;
			read(co);read(lv);read(x);read(y);
			++co;
			f[x+(y-1)*n].co=co,f[x+(y-1)*m].lv=lv;
			int fans=0;
			if(y+1<=m&&ff[x][y]=='1'&&(f[x+(y-1+1)*n].co==0||f[x+(y-1+1)*n].co!=co&&f[x+(y-1+1)*n].lv<=lv))++fans;
			if(y-1>=1&&ff[x][y-1]=='1'&&(f[x+(y-1-1)*n].co==0||f[x+(y-1-1)*n].co!=co&&f[x+(y-1-1)*n].lv<=lv))++fans;
			if(x+1<=n&&ff[x+n][y]=='1'&&(f[x+1+(y-1)*n].co==0||f[x+1+(y-1)*n].co!=co&&f[x+1+(y-1)*n].lv<=lv))++fans;
			if(x-1>=1&&ff[x+n-1][y]=='1'&&(f[x-1+(y-1)*n].co==0||f[x-1+(y-1)*n].co!=co&&f[x-1+(y-1)*n].lv<=lv))++fans;
			cout<<fans<<endl;
		}
		memset(f,0,sizeof(f));
	}
	return 0;
}


