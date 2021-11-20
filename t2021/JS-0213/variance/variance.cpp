#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int cnt;
int a[10010];
int b[10010];
int xiu[110][10010];
int ans,sum,anss=INT_MAX;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++)ans+=n*a[i]*a[i],sum+=a[i];
	ans-=sum*sum;
	if(n<=4){
		if(n<=2){
			cout<<ans<<endl;
			return 0;
		}else if(n==3){
			for(int i=1;i<=100;i++)xiu[1][i]=2;
		}else{
			for(int i=1;i<=100;i++)xiu[1][i]=3-i%2;
			for(int i=1;i<=100;i++)xiu[2][i]=2+i%2;
		}
		for(int j=1;j<=n-2;j++){
			for(int k=1;k<=4;k++)b[k]=a[k];
			for(int k=1;k<=100;k++){
				int s=ans;
				int xiui;
				int i=xiu[j][k];
				int de=a[i-1]+a[i+1]-2*a[i];
	//				if(i==2)cout<<ans+n*de*(2*a[i]+de)-de*(2*sum+de)<<endl;
				if(ans+n*de*(2*a[i]+de)-de*(2*sum+de)<s){
					s=ans+n*de*(2*a[i]+de)-de*(2*sum+de);
					xiui=i;
				}
				if(ans==s){
					anss=min(ans,anss);
					break;
				}
				ans=s;
				sum+=a[xiui-1]+a[xiui+1]-2*a[xiui];
				a[xiui]+=a[xiui-1]+a[xiui+1]-2*a[xiui];	
			}
			for(int k=1;k<=4;k++)a[k]=b[k];
		}
		cout<<anss<<endl;
	}else{
		for(int i=1;i<=n;i++)ans+=n*a[i]*a[i],sum+=a[i];
		ans-=sum*sum;
		while(1){
			int s=ans;
			int xiui;
			for(int i=2;i<n;i++){
				int de=a[i-1]+a[i+1]-2*a[i];
//				if(i==2)cout<<ans+n*de*(2*a[i]+de)-de*(2*sum+de)<<endl;
				if(ans+n*de*(2*a[i]+de)-de*(2*sum+de)<s){
					s=ans+n*de*(2*a[i]+de)-de*(2*sum+de);
					xiui=i;
				}
			}
			if(ans==s){
				cout<<ans<<endl;
				return 0;
			}
			ans=s;
			sum+=a[xiui-1]+a[xiui+1]-2*a[xiui];
			a[xiui]+=a[xiui-1]+a[xiui+1]-2*a[xiui];
		}
	}
	return 0;
}
/*
4
1 2 4 6
*/
