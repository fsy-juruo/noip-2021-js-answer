#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	int res=0;
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar(); 
	}
	return res;
}
inline void pr(long long res){
	if(res==0){
		putchar('0');
		return;
	}
	int a[20],len=0;
	while(res>0){
		a[len++]=res%10;
		res/=10;
	}
	for(int i=len-1;i>=0;i--)
		putchar(a[i]+'0');
}
int n;
int a[10010];
long long ans=0;
void get_exist(int mid,vector<int>v,int id,vector<int>&nv,long long&val){
	for(int i=id-1;i>=1;i--)v[i]=max(v[i+1]+v[i-1]-v[i],v[i]);
	for(int i=id+1;i+1<n;i++)v[i]=min(v[i+1]+v[i-1]-v[i],v[i]);
	val=0;nv=v;
	for(int i=0;i<n;i++)val+=1ll*(mid-v[i])*(mid-v[i]);
	val*=1ll*n*n;
}
void get_L(int mid,vector<int>v,int id,vector<int>&nv,long long&val){
	v[id]=v[id+1]+v[id-1]-v[id];
	for(int i=id-1;i>=1;i--){
		if(v[i-1]+v[i+1]-v[i]>=mid)v[i]=v[i-1]+v[i+1]-v[i];
		else v[i]=max(v[i+1]+v[i-1]-v[i],v[i]);
	}
	for(int i=id+1;i+1<n;i++)v[i]=max(v[i+1]+v[i-1]-v[i],v[i]);
	nv=v;val=0;
	for(int i=0;i<n;i++)val+=1ll*(mid-v[i])*(mid-v[i]);
	val*=1ll*n*n; 
}
void get_R(int mid,vector<int>v,int id,vector<int>&nv,long long&val){
	v[id]=v[id+1]+v[id-1]-v[id];
	for(int i=id-2;i>=1;i--)v[i]=max(v[i+1]+v[i-1]-v[i],v[i]);
	for(int i=id+1;i+1<n;i++){
		if(v[i-1]+v[i+1]-v[i]<=mid)v[i]=v[i-1]+v[i+1]-v[i];
		else v[i]=min(v[i+1]+v[i-1]-v[i],v[i]);
	}
	nv=v;val=0;
	for(int i=0;i<n;i++)val+=1ll*(mid-v[i])*(mid-v[i]);
	val*=1ll*n*n;
}
void get(int mid,vector<int>v,int L,int R,vector<int>&nv,long long&val){
	for(int i=L-1;i>=1;i--)v[i]=max(v[i+1]+v[i-1]-v[i],v[i]);
	for(int i=R+1;i+1<n;i++)v[i]=max(v[i+1]+v[i-1]-v[i],v[i]);
	nv=v;val=0;
	for(int i=0;i<n;i++)val+=1ll*(mid-v[i])*(mid-v[i]);
	val*=1ll*n*n;
}
void solve(int mid,vector<int>v,long long tmp){
	vector<int>nv;
	long long val;
	long long sum=0,fnc=0;
	for(int i=0;i<n;i++)sum+=v[i];
	for(int i=0;i<n;i++)fnc+=1ll*(sum-v[i]*n)*(sum-v[i]*n);
//	for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl;
//	cout<<fnc<<endl;
	ans=min(ans,fnc);
	for(int i=0;i<n;i++)if(a[i]==mid){
		get_exist(mid,v,i,nv,val);
		if(val<tmp){
			solve(mid,nv,val);
			return;
		}
	}
	int L=-1,R=-1;
	for(int i=0;i<n;i++)if(a[i]<mid)L=i;
	for(int i=n-1;i>=0;i--)if(a[i]>mid)R=i;
	if(L==-1||R==-1)return;
	if(L!=0){
		get_L(mid,v,L,nv,val);
		if(val<tmp)solve(mid,nv,val);
	}
	if(R!=n-1){
		get_R(mid,v,R,nv,val);
		if(val<tmp)solve(mid,nv,val);
	}
	get(mid,v,L,R,nv,val);
	if(val<tmp)solve(mid,nv,val);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout); 
	n=rd();
	for(int i=0;i<n;i++)a[i]=rd();
	for(int i=0;i<n;i++)a[i]*=2;
	long long sum=0;
	for(int i=0;i<n;i++)sum+=a[i];
	for(int i=0;i<n;i++)ans+=1ll*(1ll*a[i]*n-sum)*(1ll*a[i]*n-sum);
//	cout<<ans<<endl;
	int mx=0;
	for(int i=0;i<n;i++)mx=max(mx,a[i]);
	for(int i=0;i<=mx;i++){
		vector<int>v;
		for(int j=0;j<n;j++)v.push_back(a[j]);
		long long tmp=0;
		for(int j=0;j<n;j++)tmp+=1ll*(a[j]-i)*(a[j]-i);
		tmp*=n*n;
		solve(i,v,tmp);
	}
	ans/=16;
	pr(ans);
	return 0;
}
/*
10
6 19 34 35 56 63 82 82 83 99
*/
