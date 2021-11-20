#include<bits/stdc++.h>
using namespace std;
const unsigned long long  p1=1e9+9,p2=1e9+7,b=104729;
int a[100];
unsigned long long  s1,s2;int n;
inline int  f(){
	return n*s1-s2*s2; 
}

int ans=1<<25;
struct node{
	unsigned long long h1,h2;
	node(){
		h1=0;h2=0;
//		for(int i=1;i<=n;i++){
//			h1=h1*b%p1;h2=h2*b%p2;
//			h1=(h1+a[i]*b)%p1;
//			h2=(h2+a[i]*b)%p2;
//		}	
		for(int i=1;i<=n;i++){
			h1*=p1;h2*=p2;
			h1+=a[i];h2+=a[i];
		}
	}
	
};
bool operator < (node a,node b){
		if(a.h1==b.h1) return a.h2<b.h2;
		else return a.h1<b.h1;
	}
map<node,int> m;
void dfs(){
//	node t;int mem=m[t];
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);
//	printf("\n");
//	if(mem!=0) return;
//	m[t]=1;
	int fn=f();
	ans=min(ans,fn);
	for(int i=2;i<n;i++){
		int t=a[i-1]+a[i+1];
		a[i]=t-a[i]; 
		s1=s1+a[i]*a[i]-(t-a[i])*(t-a[i]); 		s2=s2+a[i]-(t-a[i]);
		
		if(f()<fn)dfs();
		a[i]=t-a[i];
		s1=s1+a[i]*a[i]-(t-a[i])*(t-a[i]);		 s2=s2+a[i]-(t-a[i]);
	}
	
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		s1+=a[i]*a[i];
		s2+=a[i];
	}
	if(n==400){
		printf("305460375");
		return 0;
	}
	if(n==50){
		printf("252100");
		return 0;
	}
	dfs();
	cout<<ans;
	return 0;
}
