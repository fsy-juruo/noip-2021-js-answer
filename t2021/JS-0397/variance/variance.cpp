#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
const int maxm=19260827,s=91;
int n,k,m,sum;
int a[10001];
bool p[5*maxm];
int que;
int gcum(int q[]){
	int ans=0;
	for(int i=1;i<=n;++i)ans+=q[i]*q[i];
	ans*=n;
	ans-=sum*sum;
	return ans;
}
int has(int q[]){
	int f=s,z=0;
	for(int i=1;i<=n;++i){
		z=(z+f*q[i]%maxm)%maxm;
		f=f*s%maxm;
	}
	return z;
}

void search(int q[],int ans){
	for(int i=2;i<=n-1;++i){
		ans+=n*(q[i-1]+q[i+1]-2*q[i])*(q[i-1]+q[i+1]);
		ans+=sum*sum;
		sum-=q[i];
		q[i]=q[i-1]+q[i+1]-q[i];
		sum+=q[i];
		ans-=sum*sum;
		if(p[has(q)]){
			ans+=sum*sum;
			sum-=q[i];			
			q[i]=q[i-1]+q[i+1]-q[i];
			sum+=q[i];
			ans-=sum*sum;
			ans-=n*(q[i-1]+q[i+1]-2*q[i])*(q[i-1]+q[i+1]);
			continue;
		}
		que=min(que,ans);
		p[has(q)]=1;	
		search(q,ans);
		ans+=sum*sum;
			sum-=q[i];			
			q[i]=q[i-1]+q[i+1]-q[i];
			sum+=q[i];
			ans-=sum*sum;
			ans-=n*(q[i-1]+q[i+1]-2*q[i])*(q[i-1]+q[i+1]);
	}
}
int main(){
   freopen("variance.in","r",stdin);
   freopen("variance.out","w",stdout);
   n=read();
   for(int i=1;i<=n;++i){
   	a[i]=read();
   	sum+=a[i];
   }
   que=gcum(a);
   p[has(a)]=1;
   search(a,que);
   cout<<que;
   return 0;
}

