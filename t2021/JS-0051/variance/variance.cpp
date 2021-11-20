#include<bits/stdc++.h>
#define ll long long
#define N 55
using namespace std;
int n,pos[1010];
int top=0;
ll a[N],b[N],fz;
double ans=100000000;

double nl(){
	ll rt=0,sum=0,aan=0;
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=1;i<=top;i++){
		b[pos[i]]=b[pos[i]-1]+b[pos[i]+1]-b[pos[i]];
	}
	for(int i=1;i<=n;i++){
		sum+=b[i];
	}
	for(int i=1;i<=n;i++){
		aan+=(n*b[i]-sum)*(n*b[i]-sum);
	}
	aan/=n;
	return (double)(aan);
}

void tuih(){
	top=0;
	double t=0.998,T=2000,dlt,dd;
	while(T>0.001){
		T*=t;
		int x=rand()%(top+1)+1,fl,y;
		if(x<=n*n/4){
			top++;
			x=rand()%(n-2)+2;
			pos[top]=x;
			dlt=nl();
			fl=1;
		}
		if(x>n*n/4&&x<n*n){
			x=rand()%top+1;
			y=rand()%top+1;
			while(x==y) y=rand()%top+1;
			swap(pos[x],pos[y]);
			dlt=nl();
			fl=2;
		}
		if(x>=n*n){
			top--;
			dlt=nl();
			fl=3;
		}
		dd=dlt-ans;
		ans=min(ans,dlt);
		if(dd<=0) continue;
		if(exp(-dd/T/100)*RAND_MAX>=rand()){
			continue;
		}
		else{
			if(fl==1) top--;
			if(fl==2) swap(pos[x],pos[y]);
			if(fl==3) top++;
		}
	}
}

int main(){
	
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	srand((int)(time(0)));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<((a[1]-a[2])*(a[1]-a[2]));
		return 0;
	}
	for(int i=1;i<=100;i++) tuih();
	fz=(ll)(ans);
	cout<<fz<<endl;
	return 0;
}
