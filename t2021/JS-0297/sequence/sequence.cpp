#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
const int mod=998244353;
const int maxm=10000000+10;
ll v[maxm],ansma,n,m,k,op[maxm],pp;
string binar[110];
string adD(string s1,string s2){
	if(s1.size()<s2.size())		swap(s1,s2);
	if(s1.size()==s2.size()) 	s1="0"+s1;
	int ms=max(s1.size(),s2.size()),ms1=min(s1.size(),s2.size());
	
	for(int i=ms-1,j=ms1-1;j>=0;i--,j--){
		int c1=s1[i]-'0';int c2=s2[j]-'0';
		int tpp=c1+c2+op[i];
		s1[i]=(tpp%2)+'0';
		op[i-1]=tpp/2;
	}
	for(int i=ms-ms1-1;i>=0;i--){
		int t=(s1[i]-'0')+op[i];
		s1[i]=(t%2)+'0';
		if(i>0)
			op[i-1]=t/2;
		if(i==0 && t/2>0){
			char c=(t/2)+'0';
			s1=c+s1;
		}
	}
	return s1;
}
string calm(int t){
	for(int i=0;i<=t;i++){
		if(binar[i]!="")
			continue;
		string temp=binar[i-1];
		binar[i]=adD(temp,temp);
	}
	return binar[t];
}

void dfs(int x,ll val,string s){
	if(x>n)	return;
	for(int i=0;i<=m;i++){
		string s1=calm(i);
		s1=adD(s,s1);
		int num=0;
		if(x==n){
			
			for(int j=0;j<s1.size();j++)
				if(s1[j]=='1')	num++;
			if(num<=k) {
				ansma+=val*v[i],ansma%=mod;
			}
		}
		else{
			if(i==0)	pp++;
			int tp=val*v[i]%mod;
			dfs(x+1,tp,s1);
			if(i==0)	pp--;
		}
				
	}
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=0;i<=101;i++)
		binar[i]="";
	binar[0]="1";
	string s="00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=0;i<=m;i++)
		cin>>v[i];
	dfs(1,1,s);
	cout<<ansma%mod;
	return 0;
}
