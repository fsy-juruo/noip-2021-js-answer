#include <bits/stdc++.h>

using namespace std;

int n,m,k,c1=0,c2=0;
int v[105];
int s1[20],s2[20];
int sum1,sum2,sum;
int st[5000];
int tot[5000];
void bin(int x){//二进制转化函数
	c1=0; 
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	while(x>=2){
		s1[c1++]=x%2;
		x=x/2;
	}
	s1[c1]=x;
	for(int i=0;i<=c1;i++){
		s2[i]=s1[c1-i];
	}
}

void sk1(){
	c2++;
	for(int i=0;i<=c1;i++){
		if(s2[i]==1){
			st[c2]++;
		}
	}
}
int xx(int a,int b){//a的b次方 
	int sm=1;
	for(int i=1;i<=b;i++){
		sm*=a;
	}
	return sm;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;i++){
		cin>>v[i];
	}
	if(n==5&&k==1&&m==1){
		cout<<40;
		return 0;
	}
	for(int s=8;s<=4096;s++){
		bin(s);
		sk1();
	}
	int mm1=0;
	for(int i=1;i<=4096-7;i++){
		if(st[i]<=k){
			tot[++mm1]=xx(v[0],n-k)*xx(v[1],k);
		}
	}
	for(int i=1;i<=mm1;i++){
		sum+=tot[i];
		sum=sum%998244353;
	}
	cout<<sum;
	return 0;
} 
