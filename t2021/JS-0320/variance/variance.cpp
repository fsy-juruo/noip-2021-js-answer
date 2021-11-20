#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int n;
double a[10005],minn=100000000;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return f*x;
}
inline void write(int x){
	stack<int>s;char ch;
	if(x==0){putchar('0');return;}
	if(x<0){putchar('-');x=-x;}
	while(x!=0){s.push(x%10);x/=10;}
	while(!s.empty()){ch=s.top();s.pop();putchar(ch^48);}
	return;
}
void dfs(int t){
	if(t==10)return;
	for(int i=2;i<=n-1;i++){
		double temp=a[i];
		a[i]=a[i+1]+a[i-1]-a[i];
		dfs(t+1);
		a[i]=temp;
	}
	double fc,av;
	for(int i=1;i<=n;i++){
		av+=a[i];
	}
	av/=n;
	for(int i=1;i<=n;i++){
		if(a[i]>av)fc+=pow(a[i]-av,2);
		else fc+=pow(av-a[i],2);
	}
	fc*=n;
	if(fc<minn)minn=fc;
	return;
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	dfs(1);
	write(minn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
