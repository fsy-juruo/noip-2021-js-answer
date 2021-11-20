#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[31],b[101],ans,v[101];
long long lzc(long long u){
	long long op=0;
	while(u>0){
		op+=u%2;
		u/=2; 
	}
	return op;
}
long long C(long long v,long long u){
	long long sum=1;
	v=min(v,u-v);
	for(long long i=u;i>=u-v+1;i--){
		sum=sum*i;
	}
	for(long long i=1;i<=v;i++){
		sum/=i;
	}
	return sum;
}
long long yay(){
	long long www=1,lefn;
	for(long long i=1;i<=n;i++){
		b[a[i]]++;
	}
	lefn=n;
	for(long long i=0;i<=m;i++){
		if(b[i]!=0&&lefn>0&&lefn!=b[i]){
			long long uu=1;
			for(int j=1;j<=b[i];j++){
				uu*=v[i];
				uu%=998244353;
			}
			www=www*C(b[i],lefn)*uu;
			www%=998244353;
			lefn-=b[i];
		} 
	}
	return www;
}
void fj(long long xp,long long wz,long long maa){
	//cout<<xp<<" "<<wz<<" "<<maa<<endl;
	if(wz==n){
		if(lzc(xp)==1){
			long long tt=0;
			while(pow(2,tt)<xp&&tt+1<=maa)tt++;
			if(pow(2,tt)==xp){
				a[n]=tt;
			//	for(long longi=1;i<=n;i++)cout<<a[i];
			//	cout<<endl;
				ans=(ans+yay())%998244353;
			}
		}
		return;
	} 
	long long r=0;
	while(n*pow(2,r)<xp)r++;
	while(pow(2,r)+n-wz-1<=xp&&r<=maa){
		a[wz]=r;
		fj(xp-pow(2,r),wz+1,r);
		r++; 
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=0;i<=m;i++){
		cin>>v[i];
		v[i]%=998244353;
	}
	for(long long i=n;i<=n*pow(2,m);i++){
		if(lzc(i)<=k){
			fj(i,1,m);
		}
	}
	cout<<ans;
	return 0;
} 
