#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rl(){
	int a=0,nega=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')nega=-1;c=getchar();}
	while(isdigit(c)){a=(a*10)+(c^48);c=getchar();}
	return a*nega;
}
bool pd(int x){
	while(x!=0){
		int ss=x%10;
		if(ss==7)return 0;
		x/=10;
	}
	return 1;
}
bool p[10005000],pp[10005000];
int v[10005000];
int T,n,tot;
int check(int x){
	if(p[x]==0||pp[x]==1)return -1;
	int l=1,r=tot;
	while(l<r){
		int mid=(l+r)>>1;
		if(v[mid]>x)r=mid;
		else l=mid+1;
	}
	return v[l];
}
ll sws;
void doit(){
	p[1]=0;
	for(int i=1;i<=10001000;i++){
		p[i]=pd(i);
	}
	for(int i=1;i<=10001000;i++){
		if(p[i]==0){
			for(int j=i*2;j<=10001000;j+=i){
				//if(j%i==0)break;
				//if(i*j>10001000)break;
				pp[j]=1;p[j]=1;
				//sws++;
			}
		}
		if(p[i]==1&&pp[i]==0)v[++tot]=i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	doit();
	//cout<<sws<<endl;
	cin>>T;
	//for(int i=1;i<=100;i++)cout<<v[i]<<' ';cout<<endl;
	while(T--){
		cin>>n;
		cout<<check(n)<<endl;
	}
	return 0;
}
