#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=(ch=='-');
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
inline string read_s(){
	string s;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while('0'<=ch&&ch<='9'){
		s=s+ch;
		ch=getchar();
	}
	return s;
}

struct point{
	int up,down,left,right,col,lv;
	point(){ up=down=left=right=col=lv=-1; }
};

const int inf=INT_MAX-10;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

string s;
point **a;
bool **f;
int T,n,m,q,ans;

int __d1[10];

void scan(){
	for(int i=0; i<10; i++) __d1[i]=0;
	delete a;
	
	cin>>n>>m>>q;
	a=new point*[n+5];
	for(int i=0; i<n+5; i++)
		a[i]=new point[m+5];
	f=new bool*[n+5];
	for(int i=0; i<n+5; i++)
		f[i]=new bool[m+5];
	
	for(int i=1; i<=n; i++){
		s=read_s();
		for(int j=0; j<s.size(); j++){
			__d1[s[j]-'0']++;
			a[i][j+1].right=a[i][j+2].left=s[j]-'0';
		}
	}
	for(int i=1; i<=n-1; i++){
		s=read_s();
		for(int j=0; j<s.size(); j++){
			__d1[s[j]-'0']++;
			a[i][j+1].down=a[i+1][j+1].up=s[j]-'0';
		}
	}
	
	for(int i=0; i<=n+1; i++){
		a[i][0].col=a[i][m+1].col=inf;
		a[i][0].lv=a[i][m+1].lv=inf;
	}
	for(int j=0; j<=m+1; j++){
		a[0][j].col=a[n+1][j].col=inf;
		a[0][j].lv=a[n+1][j].lv=inf;
	}
}

void work_simple(int x, int y){
	if(a[x-1][y].col!=a[x][y].col&&a[x-1][y].lv<=a[x][y].lv&&a[x][y].up!=0) ans++;
	if(a[x+1][y].col!=a[x][y].col&&a[x+1][y].lv<=a[x][y].lv&&a[x][y].down!=0) ans++;
	if(a[x][y-1].col!=a[x][y].col&&a[x][y-1].lv<=a[x][y].lv&&a[x][y].left!=0) ans++;
	if(a[x][y+1].col!=a[x][y].col&&a[x][y+1].lv<=a[x][y].lv&&a[x][y].right!=0) ans++;
}

void work_no_anyway(int x, int y){
	if(a[x][y].up==1){ if(a[x-1][y].col!=a[x][y].col&&a[x-1][y].lv<=a[x][y].lv) ans++; }
	else if(a[x][y].up==2){
		for(int i=x-1; i>=1; i--){
			if(a[i][y].down==2&&a[i][y].col!=a[x][y].col&&a[i][y].lv<=a[x][y].lv){
				ans++; if(a[i][y].col!=-1) break;
			}
			else break;
		}
	}
	if(a[x][y].down==1){ if(a[x+1][y].col!=a[x][y].col&&a[x+1][y].lv<=a[x][y].lv) ans++; }
	else if(a[x][y].down==2){
		for(int i=x+1; i<=n; i++){
			if(a[i][y].up==2&&a[i][y].col!=a[x][y].col&&a[i][y].lv<=a[x][y].lv){
				ans++; if(a[i][y].col!=-1) break;
			}
			else break;
		}
	}
	if(a[x][y].left==1){ if(a[x][y-1].col!=a[x][y].col&&a[x][y-1].lv<=a[x][y].lv) ans++; }
	else if(a[x][y].left==2){
		for(int j=y-1; j>=1; j--){
			if(a[x][j].right==2&&a[x][j].col!=a[x][y].col&&a[x][j].lv<=a[x][y].lv){
				ans++; if(a[x][j].col!=-1) break;
			}
			else break;
		}
	}
	if(a[x][y].right==1){ if(a[x][y+1].col!=a[x][y].col&&a[x][y+1].lv<=a[x][y].lv) ans++; }
	else if(a[x][y].right==2){
		for(int j=y+1; j<=m; j++){
			if(a[x][j].left==2&&a[x][j].col!=a[x][y].col&&a[x][j].lv<=a[x][y].lv){
				ans++; if(a[x][j].col!=-1) break;
			}
			else break;
		}
	}
}

void work_no_straight(int x, int y){
	work_simple(x,y);
	memset(f,false,sizeof(f));
}

void work_small(int x, int y){
	
}

int main(){
//	freopen("in.txt","r",stdin);
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int col,lv,x,y;
	
	cin>>T;
	while(T--){
		scan();
		if(__d1[2]==0&&__d1[3]==0){
			while(q--){
				ans=0;
				col=read(); lv=read(); x=read(); y=read();
				a[x][y].col=col;
				a[x][y].lv=lv;
				work_simple(x,y);
				cout<<ans<<endl;
			}
		}
		else if(__d1[3]==0){
			while(q--){
				ans=0;
				col=read(); lv=read(); x=read(); y=read();
				a[x][y].col=col;
				a[x][y].lv=lv;
				work_no_anyway(x,y);
				cout<<ans<<endl;
			}
		}
		else if(__d1[2]==0){
			while(q--){
				ans=0;
				col=read(); lv=read(); x=read(); y=read();
				a[x][y].col=col;
				a[x][y].lv=lv;
				work_no_straight(x,y);
				cout<<ans<<endl;
			}
		}
		else if(n*m<=5000&&q<=2000){
			while(q--){
				ans=0;
				col=read(); lv=read(); x=read(); y=read();
				a[x][y].col=col;
				a[x][y].lv=lv;
				work_small(x,y);
				cout<<ans<<endl;
			}
		}
	}
	
	return 0;
}

