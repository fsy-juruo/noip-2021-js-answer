#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read() {
	int x(0),neg(1);char ch(getchar());
	while(!isdigit(ch)) {
		if (ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*neg;
}
const int MAXN=1e7+5;
int cnt;
int num[MAXN+5];
bool ok[MAXN+5];
int ans[MAXN+5];
int tot;
int T;
int q[200000+5];
inline void Subtask1() {
	for (int i=1;i<=1000000;++i) {
		if (i%10==7 || i/10%10==7 || i/100%10==7 || i/1000%10==7 || i/10000%10==7 || i/100000%10==7 || i/1000000%10==7) {
			num[++tot]=i;
			ok[i]=1;
		}
	}
	for (int i=1;i<=tot;++i) {
		for (int j=1;j*num[i]<=1000000;++j) {
			ok[j*num[i]]=1;
		}
	}
	int lst=0;
	for (int i=1000000;i>=1;--i) {
		ans[i]=lst;
		if (!ok[i]) lst=i;
	}
	for (int i=1;i<=T;++i) {
		if (ok[q[i]]) puts("-1");
		else printf("%d\n",ans[q[i]]);
	}
}
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	int flag=0;
	for (int t=1;t<=T;++t) {
		q[t]=read();
		if (q[t]>200000) flag=1;
	}
	if (!flag) Subtask1();
	else {
		for (int i=1;i<=10000000;i+=8) {
			if (i%10==7 || i/10%10==7 || i/100%10==7 || i/1000%10==7 || i/10000%10==7 || i/100000%10==7 || i/1000000%10==7) {
				num[++tot]=i;
				ok[i]=1;
			}
			if ((i+1)%10==7 || (i+1)/10%10==7 || (i+1)/100%10==7 || (i+1)/1000%10==7 || (i+1)/10000%10==7 || (i+1)/100000%10==7 || (i+1)/1000000%10==7) {
				num[++tot]=(i+1);
				ok[(i+1)]=1;
			}
			if ((i+2)%10==7 || (i+2)/10%10==7 || (i+2)/100%10==7 || (i+2)/1000%10==7 || (i+2)/10000%10==7 || (i+2)/100000%10==7 || (i+2)/1000000%10==7) {
				num[++tot]=(i+2);
				ok[(i+2)]=1;
			}
			if ((i+3)%10==7 || (i+3)/10%10==7 || (i+3)/100%10==7 || (i+3)/1000%10==7 || (i+3)/10000%10==7 || (i+3)/100000%10==7 || (i+3)/1000000%10==7) {
				num[++tot]=(i+3);
				ok[(i+3)]=1;
			}
			if ((i+4)%10==7 || (i+4)/10%10==7 || (i+4)/100%10==7 || (i+4)/1000%10==7 || (i+4)/10000%10==7 || (i+4)/100000%10==7 || (i+4)/1000000%10==7) {
				num[++tot]=(i+4);
				ok[(i+4)]=1;
			}
			if ((i+5)%10==7 || (i+5)/10%10==7 || (i+5)/100%10==7 || (i+5)/1000%10==7 || (i+5)/10000%10==7 || (i+5)/100000%10==7 || (i+5)/1000000%10==7) {
				num[++tot]=(i+5);
				ok[(i+5)]=1;
			}
			if ((i+6)%10==7 || (i+6)/10%10==7 || (i+6)/100%10==7 || (i+6)/1000%10==7 || (i+6)/10000%10==7 || (i+6)/100000%10==7 || (i+6)/1000000%10==7) {
				num[++tot]=(i+6);
				ok[(i+6)]=1;
			}
			if ((i+7)%10==7 || (i+7)/10%10==7 || (i+7)/100%10==7 || (i+7)/1000%10==7 || (i+7)/10000%10==7 || (i+7)/100000%10==7 || (i+7)/1000000%10==7) {
				num[++tot]=(i+7);
				ok[(i+7)]=1;
			}
		}
		for (int i=1;i<=tot;++i) {
			for (int j=1;j*num[i]<=MAXN;++j) {
				ok[j*num[i]]=1;
			}
		}
		int lst=0;
		for (int i=MAXN;i>=1;--i) {
			ans[i]=lst;
			if (!ok[i]) lst=i;
		}
		for (int i=1;i<=T;++i) {
			if (ok[q[i]]) puts("-1");
			else printf("%d\n",ans[q[i]]);
		}
	}
	return 0;
}
/*
5
90
99
106
114
169
*/
