#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf=0x3f3f3f3f;
const int N=2e5+10;
const int MAXV=1e7;

int T;
int x[N];
int f[MAXV+100];
int q[MAXV+100],top;

int read(){
	int f=1,x=0;char ch=getchar();
	while (ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){x=x*10-'0'+ch;ch=getchar();}
	return f*x;
}

bool seven(int x){
	while (x){
		if (x%10==7)return 1;
		x/=10;
	}
	return 0;
}

void init(){
	for (int i=1;i<=MAXV;i++){
		if (seven(i)){
			for (int j=i;j<=MAXV;j+=i){f[j]=1;}
		}
	}
	for (int i=1;i<=MAXV;i++){
		if (!f[i]){q[++top]=i;}
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	init();
//	cerr<<"aha!"<<endl;
	while (T--){
		int x=read();
		if (f[x])puts("-1");
		else{
			int ans=*upper_bound(q+1,q+top+1,x);
			printf("%d\n",ans);
		}
	}

	return 0;
}

