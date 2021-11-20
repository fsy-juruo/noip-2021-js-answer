#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 500099
#define mod 998244353
#define irep(i,l,r) for(int i=l;i<=r;++i)
#define drep(i,l,r) for(int i=r;i>=l;--i)

using namespace std;

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s*=10,s+=ch-'0';
		ch=getchar();
	}
	return s*w;
}

int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-x*(a/b);
	return d;
}

vector<int>g[N],c[N];

void add_edge(int x,int y,int w){
	g[x].push_back(y);
	c[x].push_back(w);
}

//freopen("number.in","r",stdin);
//
void FILEREAD(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}

int num,cnt;
short vis[10000099];
int p[10000009],pw[120]={1,10,100,1000,10000,100000,1000000,10000000};
const int maxn=10000000;
bool check(int x){
	if(x==0)return true;
	if(x%10==7)return false;
	else return check(x/10);
}
int main(){
	FILEREAD();
	/*
	for(int i=maxn;;++i){
		int fl=1;
		for(int s=1;s*s<i;++s){
			if(i%s==0){
				if(check(s)==0||check(i/s)==0){
					cout<<i<<' '<<s<<' '<<i/s<<endl;
					fl=0;
					break;
				}
			}
		}
		if(fl==1)cout<<i<<' '<<"PASS"<<endl;
		
	}
	*/
//	int T=read();
	for(int i=0;i<=7;++i){
		for(int l=0;l<pw[i];++l){
			for(int r=0;r<pw[6-i];++r){
				vis[r*pw[i+1]+7*pw[i]+l]=1;
			//	cout<<r*pow(10,i+1)+7*pow(10,i)+l<<endl;
			}
		}
	}
	int cnt=0;
	//vis=1 ²»ÄÜ±¨ 
	for(int i=1;i<=maxn;++i){
		if(vis[i]==1){
			if(i%7==0&&i!=7)continue;
			for(int j=i*2;j<=maxn;j+=i){
				/*
				if(j==maxn){
					cout<<i<<endl;
				}
				*/
				vis[j]=2;
//				++cnt;
			}
		}
	}
	
//	cout<<cnt<<endl;
//	cout<<vis[maxn]<<endl;
	
	int lst=maxn+1;
	for(int i=maxn;i>=1;--i){
		if(vis[i]>=1)p[i]=-1;
		else p[i]=lst,lst=i;
	}
	int nxt=maxn+1;
	int T=read();
	while(T--){
		int x=read();
		printf("%d\n",p[x]);
	}
	return 0;
} 
