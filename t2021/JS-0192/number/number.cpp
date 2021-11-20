#include <bits/stdc++.h>
using namespace std;
#define gc() getchar()
typedef long long ll;

template<typename T>inline void rd(T &x){
	x=0;ll f=1;char c=gc();
	for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=gc())x=x*10+c-'0';
	x*=f;
}

bool f1[10000050]={1},f2[10000050]={1,1};
int tp1,h1[1000010],h2[1000010],tp2,ans[10000050];
int t,n;

inline int ck(int k){
	while(k){
		if(k%10==7)return 0;
		k/=10;
	}
	return 1;
}

inline void write(int k){
	if(k<0)k=-k,putchar('-');
	if(k<10)putchar(k+'0');
	else write(k/10),putchar(k%10+'0');
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10000020;i++){
		if(!f2[i])h2[++tp2]=i;
		for(int j=1;j<=tp2&&i*h2[j]<=10000020;j++){
			f2[i*h2[j]]=1;
			if(i%h2[j]==0)break;
		}
	}
	for(int i=1;i<=10000020;i++){
		if(!f1[i]&&ck(i))h1[++tp1]=i;
		else{f1[i]=1;for(int j=1;j<=tp2&&i*h2[j]<=10000020;j++)f1[i*h2[j]]=1;}
	}
	for(int i=1,k=1;i<=10000020;i++){
		if(i>=h1[k])++k;
		ans[i]=f1[i]?-1:h1[k];
	}
	//for(int i=1;i<=tp1;i++)printf("%d %d\n",i,h1[i]);
	//printf("%d %d\n",tp1,tp2);
	rd(t);
	for(;t;--t){
		rd(n);
		//if(f1[n])puts("-1");
		//else{
			//ans=lower_bound(h1+1,h1+tp1+1,n)-h1;
			write(ans[n]);
			puts("");
			//printf("%d\n",ans[n]);
		//}
	}
	return 0;
}

