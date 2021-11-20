#include<bits/stdc++.h>
using namespace std;
#define SZ(v) ((int)(v).size())
typedef long long ll;
typedef pair<int,int> pii;
inline bool cmax(int &x,int y){if(x<y){x=y;return true;}return false;}
inline bool cmin(int &x,int y){if(x>y){x=y;return true;}return false;}
inline int fastin(){int x=0,f=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}return x*f;}

int st[10],p[10000010],ans[10000010];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	for(int i=1;i<=10000005;i++){
		if(p[i]) continue;
		
		int top=0,tmp=i;
		while(tmp){
			st[++top]=tmp%10;
			if(st[top]==7){
				p[i]=1;
				break;
			}
			tmp/=10;
		}
		
		if(p[i]){
			for(int j=i+i; j<=10000005; j+=i){
				p[j]=1;
			}
		}
	}
	
	int pre=10000005;
	for(int i=10000005;i>=1;i--){
		ans[i]=pre;
		if(!p[i])pre=i;
	}
	
	int T;
	T=fastin();
	while(T--){
		int x=fastin();
		if(p[x])printf("-1\n");
		else printf("%d\n",ans[x]);
	}

	return 0;
}

