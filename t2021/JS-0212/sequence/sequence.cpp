#include<bits/stdc++.h>
#define N 998244353
using namespace std;

int n,m,k,i,v[101];
long long cnt;
int h(int n){int ans=0;
	while (n>0)ans+=n%2,n/=2;
	return ans;
}
long long mi(int n,int k){long long ans=1;
	while(k>0){
	ans=ans*n%N;k--;
	}
   return ans;
}
long long c(int m,int n){
	long long ans=1;
   for(int i=0;i<=m-1;i++)
   ans*=n-i;
   	 for(int i=0;i<=m-1;i++)
   ans/=m-i;ans=ans%N;
	return ans;
}

void dfs(int wei,int yu,long long ans,long long value,int he,int yong){
	if(wei==m){
	 int p=n-yong;
	 int q=p+yu;
	 if(h(q)+he==k){
	 cnt=(cnt+(ans*mi(v[m],p)%N*value))%N;
	 }
	}
	else{
	 for(int i=0;i<=n-yong;i++){
	 int p=i+yu;
	 if(he+p%2<=k)
	  dfs(wei+1,p/2,ans*mi(v[wei],i)%N,value*c(i,n-yong)%N,he+p%2,yong+i);
	 
	 }
	}
	
	
}


int main(){
	
scanf("%d%d%d",&n,&m,&k);
for(i=0;i<=m;i++)cin>>v[i];
dfs(0,0,1,1,0,0);
cout<<cnt<<endl;


	return 0;
}
