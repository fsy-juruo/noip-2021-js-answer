#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long mi=INT_MAX;
vector <int> v;
int a[1010],s[1010],va[1010];
void dfs(int dep,int r,int k,int x){
	if(r==0){
		long long res=n,an=1,ans=1;
		for(int i=m;i>=1;i--){
			for(int j=res;j>=res-a[i]+1;j--){
				an=an*j/(res-j+1)%998244353;
			}
			res-=a[i];
			for(int j=1;j<=a[i];j++){
				ans=ans*va[i]%998244353;
			}
		}
		ans=ans*an%998244353;
		mi=min(mi,ans);
		return ;
	}
	if(dep==0)return ;
	int t=x,p=r;
	if(t>=s[dep]){
		t-=s[dep];
		p++;
	}
	int i=0;
	while(i<=k&&i<=p){
		a[dep]=i;
		dfs(dep-1,(p-i)*2,k-i,t);
		i++;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>va[i];
	}
	int p=1;
	for(int i=1;i<=15;i++){
		s[i]=p;
		p*=2;
	}
	int ma=1;
	p=1;
	for(int i=1;i<=m;i++)ma*=2;
	for(int i=1;i<=k;i++)p*=2;
	p--;
	bool flag=false;
	for(int i=k;i<=m+4;i++){
		for(int j=k;j>=1;j--){
			if(p>=n){
				if(p>n*ma){
					flag=true;
					break;
				}
				v.push_back(p);
			}
			p-=s[j+i-k];
			p+=s[j+i-k+1];
		}
		if(flag)break;
	}
	for(int i=0;i<v.size();i++){
		int t=v[i],p=0,l=15;
		while(l>m){
			if(t>=s[l]){
				t-=s[l];
				p++;
			}
			p*=2;
			l--;
		}
		dfs(m,p,n,t);
	}
	cout<<mi<<endl;
	return 0;
}

