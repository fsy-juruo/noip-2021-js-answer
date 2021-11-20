#include<bits/stdc++.h>
using namespace std;
int h[20000010],hh[20000010],num,T,a[200010],mx,ans;
int read(){
	int xx=0,ff=1;char ch=getchar();
	while (!isdigit(ch)) {if (ch=='-') ff=-1; ch=getchar();}
	while (isdigit(ch)) {xx=(xx<<1)+(xx<<3)+ch-'0';ch=getchar();}
	return xx*ff;
}
//void dfs(1,0);
void ef(int l,int r,int fi){
//	cout<<h[l]<<' '<<h[r]<<' '<<fi<<endl; 
	int mid=(l+r)/2;
	if (mid==l) {
		ans=l;return; 
	}
	if (fi>=h[mid]) ef(mid,r,fi);
	else ef(l,mid,fi);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    T=read();
    for (int i=1; i<=T; i++){
    	a[i]=read();
    	mx=max(a[i],mx);
	}
	mx*=2;
//    dfs(1,0);
    for (int i=1; i<=mx; i++){
    	int k=i,s=0;
    	while (k){
    		if (k%10==7) s=1;
    		k/=10;
		}
		if (s==0) continue;
		int kk=i;k=i;
		while (kk<=mx){
			hh[kk]=1;
			kk+=k;
		}
	}
	for (int i=1; i<=mx; i++){
		if (hh[i]==0) h[++num]=i; 
	}
	for (int i=1; i<=T; i++){
		int x=a[i];
		int l=1,r=num;
		ef(l,r,x);
		if (h[ans]!=x) printf("%d\n",-1);
		else printf("%d\n",h[ans+1]);
	}
//	for (int i=1; i<=100; i++){
//		cout<<i<<" "<<h[i]<<endl;
//	}
	return 0;
}
