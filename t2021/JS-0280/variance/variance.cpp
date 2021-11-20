#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	 int r=0,f=1;char ch=getchar();
	 while (!isdigit(ch)&&ch!='-') ch=getchar();
	 if (ch=='-') f=-1,ch=getchar();
	 while (isdigit(ch)) r=(r<<3)+(r<<1)+ch-'0',ch=getchar();
	 return r*f;
}
int s1,s2,n,a[500005],ans,ans1,b[500005],ans2,cnt,ed;
int sta;
map<int,int> M;
void dfs(){
	int Ans=0,xx=1;
	for (int i=1;i<=n;i++) xx*=77,Ans+=(a[i]*xx)%77777751;
	if (M[Ans]) return ;
	M[Ans]=1; 
	if (clock()-sta>900) {
		cout<<min(ans2,ans)<<endl;
		exit(0);
	}
	for (int i=2;i<n;i++){
		int s3,s4,x,s5,s6,y,ans3;
		s3=s1-a[i]*a[i];
		s4=s2-a[i];
		x=a[i+1]+a[i-1]-a[i];
		s3+=x*x;
		s4+=x;
		ans1=n*s3-s4*s4;
		s5=s1,s6=s2,y=a[i];ans3=ans2;
		if (ans2-ans1>-1000) ans2=ans1,ans=min(ans,ans2),a[i]=x,s1=s3,s2=s4,dfs(),a[i]=y,s1=s5,s2=s6,ans2=ans3;
	}
}
void solve(int l,int r){
//	cout<<l<<' '<<r<<endl;
	if (l>r) return ;
	int s5=0,s6=0,y=0,x,s3,s4;
	for (int i=l;i<=r;i++){
		s3=s1-a[i]*a[i];
		s4=s2-a[i];
		x=a[i+1]+a[i-1]-a[i];
		s3+=x*x;
		s4+=x;
		ans1=n*s3-s4*s4;
//		cout<<i<<' '<<x<<' '<<s3<<' '<<s4<<' '<<ans1<<endl;
		if (ans>ans1) ans=min(ans,ans1),y=i,s5=s3,s6=s4;
	}
	if (l==r) return ;
	if (!y) return ;
	s3=s1,s4=s2,x=a[y],a[y]=a[y-1]+a[y+1]-a[y],s1=s5,s2=s6;
//	cout<<a[y]<<' '<<x<<endl;
	solve(l,y-1);
	solve(y+1,r);
//	cout<<a[y]<<' '<<x<<endl;
	s1=s3,s2=s4,a[y]=x;
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=a[i],s1+=a[i]*a[i],s2+=a[i];sta=clock();
	int s7=s1,s8=s2;
	ans=n*s1-s2*s2;
	for (int i=2;i<n;i++) {
		int s3,s4,x;
		s3=s1-a[i]*a[i];
		s4=s2-a[i];
		x=a[i+1]+a[i-1]-a[i];
		s3+=x*x;
		s4+=x;
		ans1=n*s3-s4*s4;
		if (ans>ans1) ans=min(ans,ans1),a[i]=x,s1=s3,s2=s4;
	}
	for (int i=1;i<=n;i++) a[i]=b[i];
	s1=s7,s2=s8;
	solve(2,n-1);
	for (int i=1;i<=n;i++) a[i]=b[i];
	s1=s7,s2=s8;ans2=n*s1-s2*s2;
	dfs();
	cout<<min(ans2,ans)<<endl;
	return 0;
}

