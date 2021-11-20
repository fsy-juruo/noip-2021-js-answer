#include<iostream>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;
int a[109];
int hmin,hmax;
int ans=0;
int n,m,k;
int cz[109];

int com(int n,int m){//jisuan C(m,n)
	int ret=1;
	if(n==0||m==0)return 1;
	if(n==m)return 1;
	if(n>m/2)n=m-n;
	for(int i=1;i<=n;i++){
		ret*=(m-i+1)/i;
	}
	return ret;
}
int qiunum(){
	int num=n;
	int ac=1;//return de shu
	for(int i=0;i<=m;i++){
		//cout<<endl<<cz[i]<<" "<<num<<endl;
		ac*=com(cz[i],num);
		num-=cz[i];
	}
	//cout<<ac;
	return ac;
}

void dfs(int n,int mj,int gs){//n dangqian shengyv de zonghe     mj zhengzaimeijv de shu       gs  dangqianshengyv de geshu
	if(mj*gs<n)return ;//jianzhi  wangxai sousuo kendingmeiyou jieguo
	//gs<=0
	if(mj==0){
		//ans+=gs*a[0];
		cz[mj]=gs;
		int zh=1;//zonghe
		for(int i=0;i<=m;i++){
			int a1=1;//v[i]^?
			
			for(int j=0;j<cz[i];j++){
				a1*=a[i];
			}
			zh*=a1;
		}
		int nnn=qiunum();
		ans+=zh*nnn;
		//cout<<nnn;
		//ans+=zh;
		//for(int i=0;i<=m;i++)cout<<cz[i]<<" ";
		//cout<<endl;
		//cout<<endl<<ans<<endl;
		return ;
	}
	int nn=min(n/mj,gs);
	for(int i=0;i<=nn;i++){//meijv mj de geshu =i
		//ans+=a[mj]*i;
		cz[mj]=i;
		dfs(n-mj*i,mj-1,gs-i);
	}
	return ;
}


int main(){
	ios::sync_with_stdio(false);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	memset(a,1,sizeof(a));
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)cin>>a[i];
	hmin=(int)log2(n)+1,hmax=(int)log2(n)+m;
	//cout<<hmin<<hmax;
	for(int i=hmin;i<=hmax;i++){
		dfs(i,m,n);
	}
	cout<<ans;
	return 0;
}








































//
//bool ck[108];
//int a[108];
//int main(){
//	int n,m,k;
//	memset
//	cin>>n>>m>>k;
//	int num=0;
//	for(int i=0;i<=m;i++){
//		cin>>a[i];
//		if(!ck[i]){
//			ck[i]=true;
//			num++;
//		}
//	}
//	if(num<=k){
//		unsigned long long ans;
//		ans=1;
//		for(int i=0;i<=m;i++)ans*=a[i];
//	
//	}
//	cout<<ans;
//	return 0;
//} 
