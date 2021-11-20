#include<iostream>

using namespace std;

//int a[10000];
int b[10000];
int n=0;

int ans=0x3f;
int fc(){
	int zh=0;
	int fh=0;
	for(int i=0;i<n;i++){
		zh+=b[i];
	}
	zh/=n;
	for(int i=0;i<n;i++){
		fh+=(b[i]-zh)*(b[i]-zh);
	}
	return n*fh;
}
void dfs(int wz){//1~n-2
	if(wz==n-1){
		ans=min(ans,fc());
		return ;
	}
	dfs(wz+1);
	b[wz]=b[wz-1]+b[wz+1]-b[wz];
	dfs(wz+1);
	b[wz]=b[wz-1]+b[wz+1]-b[wz];
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
		//b[i]=a[i];
	}
	dfs(1);
//	b[1]=b[0]+b[2]-b[1];
//	ans=fc();
//	b[2]=b[1]+b[3]-b[2];
//	ans=min(ans,fc());
//	cpy(n);
//	b[2]=b[1]+b[3]-b[2];
//	ans=min(ans,fc());
//	b[1]=b[0]+b[2]-b[1];
//	ans=min(ans,fc());
//	cout<<ans;
//	//else cout<<fc();
	cout<<ans;
	return 0;
}
