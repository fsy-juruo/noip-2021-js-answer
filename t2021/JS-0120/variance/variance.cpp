#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;char ch=getchar();
	   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	   while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	   return x*f;
}
int n,s=0;
int a[10010];
bool check(int x){
	int cnt=0;
	if(a[x+1]+a[x-1]-2*a[x]<0){
		cnt+=1;
	}
	if((n-1)*a[x+1]+(n-1)*a[x-1]+2*a[x]-2*s<0){
		cnt+=1;
	}
	if(cnt==1){
		return true; 
	}
	return false;
}
int main(){
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
	int flag;
	long long ans=0;
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		s+=a[i];
	}
	while(1){
		flag=0;
		for(int i=n-1;i>1;i--){
			if(a[i+1]+a[i-1]-2*a[i]==0){
				continue;
			}
			if(check(i)){
				s+=a[i+1]+a[i-1]-2*a[i];
				a[i]=a[i+1]+a[i-1]-a[i];
				flag=1;
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	ans=0;
	for(int i=1;i<=n;i++){
		ans+=(long long)(n*a[i]-s)*(n*a[i]-s);
	}
	cout<<ans/n<<endl;
	return 0;
}

