#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x);
int n,s,s1,a[10007],flag=1,ans;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);s+=a[i];s1+=a[i]*a[i];
	}
	if(n<=4){
		if(n<=2){
			cout<<n*s1-s*s<<endl;
			return 0;
		}
		if(n<=3){
			ans=n*s1-s*s;
			int tmp=a[1]+a[3]-a[2];
			s-=a[2];s+=tmp;
			s1-=a[2]*a[2];s1+=tmp*tmp;
			ans=min(ans,n*s1-s*s);
			cout<<ans<<endl;
			return 0;
		}
		ans=n*s1-s*s;
		int b[5];
		for(int i=1;i<=4;i++)b[i]=a[i];
		int os=s,os1=s1;
		int tmp=b[1]+b[3]-b[2];
		s-=b[2];s+=tmp;
		s1-=b[2]*b[2];s1+=tmp*tmp;
		ans=min(ans,n*s1-s*s);
		tmp=b[2]+b[4]-b[3];
		s-=b[3];s+=tmp;
		s1-=b[3]*b[3];s1+=tmp*tmp;
		ans=min(ans,n*s1-s*s);
		
		for(int i=1;i<=4;i++)b[i]=a[i];
		s=os,s1=os1;
		tmp=b[2]+b[4]-b[3];
		s-=b[3];s+=tmp;
		s1-=b[3]*b[3];s1+=tmp*tmp;
		ans=min(ans,n*s1-s*s);
		tmp=b[1]+b[3]-b[2];
		s-=b[2];s+=tmp;
		s1-=b[2]*b[2];s1+=tmp*tmp;
		ans=min(ans,n*s1-s*s);
		
		cout<<ans<<endl;
		s=os,s1=os1;
		return 0;
	}
	
	while(flag){
		flag=0;
		int ave=s/n;
		int pos=lower_bound(a+1,a+n+1,ave)-a;
		for(int i=pos;i>=2;--i){
			int tmp=a[i-1]+a[i+1]-a[i];
			if(tmp>a[i]){
				++flag;
				s-=a[i];s+=tmp;
				s1-=a[i]*a[i];s1+=tmp*tmp;
				a[i]=tmp;
			}
		}
		for(int i=pos+1;i<n;++i){
			int tmp=a[i-1]+a[i+1]-a[i];
			if(tmp<a[i]){
				++flag;
				s-=a[i];s+=tmp;
				s1-=a[i]*a[i];s1+=tmp*tmp;
				a[i]=tmp;
			}
		}
	}
	cout<<n*s1-s*s<<endl;
	return 0;
}
void read(int &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	x*=f;
}

