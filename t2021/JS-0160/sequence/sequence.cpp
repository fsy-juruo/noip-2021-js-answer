#include<bits/stdc++.h>
#define LL long long
#define MP  make_pair
#define mo 998244353
using namespace std;
void read(int &sum){
	sum=0;char ch=getchar();int p=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')p=-1;
	for(; isdigit(ch);ch=getchar())sum=sum*10+ch-'0';
	sum=sum*p;
}
void write(int sum){
	if(sum<0){
		putchar('-');
		sum=0-sum;
	}
	if(sum>=10){
		write(sum/10);
		sum=sum%10;
	}
	putchar(sum+'0');
}
LL ans=0;
int num[200];
int n,m,K,nu[200],v[200];
void dfs(int dep,LL sum){
	int i;
//	cout<<dep<<" "<<sum<<endl;
//	for(i=0;i<=m;i++){
//		cout<<num[i]<<' ';
//	}cout<<endl;
	if(dep>n){
		int s=0;
//		cout<<"NUM\n";
		for(i=0;i<=m+1;i++){
			nu[i]=0;
		}
		for(i=0;i<=m;i++){
			nu[i]+=num[i];
//			cout<<nu[i];
			nu[i+1]+=nu[i]/2;
			nu[i]=nu[i]%2;
//			cout<<nu[i]<<" ";
		}
//		cout<<endl;
		for(i=0;i<=m;i++){
//			cout<<num[i]<<" ";
			s+=nu[i];
//			cout<<s<<endl;
		}
//		cout<<nu[m+1]<<endl;
		while(nu[m+1]){
			if(nu[m+1]&1){
				s++;
			}
			nu[m+1]>>=1;
		}
//		for(i=0;i<=m;i++){
//			cout<<num[i]<<" ";
//		}cout<<endl;
//		cout<<s<<endl;
		if(s>K){
			return ;
		}
//		for(i=0;i<=m;i++){
//			cout<<num[i]<<' ';
//		}
//		cout<<endl;
		ans+=sum;
		ans%=mo;
//		cout<<s<<endl; 
		return ;
	}
	for(i=0;i<=m;i++){//a[dep]=i
		num[i]++;
		dfs(dep+1,sum*(v[i]*1ll)%mo);
		num[i]--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(K);
	int i;
	for(i=0;i<=m;i++){
		read(v[i]);
	}
	dfs(1,1ll);
	cout<<ans<<endl;
	return 0;
}


