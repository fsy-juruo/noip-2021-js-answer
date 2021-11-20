#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],ans,tot;
void dfsq(int id){
	if(id==1)
	return;
	if(a[id]-a[id-1]>=a[id+1]-a[id])
	return;
	else{
		tot=tot-a[id]+a[id-1]+a[id+1]-a[id];
		a[id]=a[id+1]+a[id-1]-a[id];
		dfsq(id-1);
	}	
};
void dfsh(int id){
	if(id==n)
	return;
	if(a[id]-a[id-1]<=a[id+1]-a[id])
	return;
	else{
		tot=tot-a[id]+a[id-1]+a[id+1]-a[id];
		a[id]=a[id+1]+a[id-1]-a[id];
		dfsh(id+1);
	}	
};
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
    cin >> a[i];
    tot+=a[i];
	}
    if(n==2){
    	ans=2*a[1]*a[1]-2*tot*a[1]+2*a[2]*a[2]-2*tot*a[2]+tot*tot;
	}
	else
	if(n==3){
		ans=3*a[1]*a[1]-2*tot*a[1]+3*a[2]*a[2]-2*tot*a[2]+3*a[3]*a[3]-2*tot*a[3]+tot*tot;
		tot=tot+a[1]+a[3]-a[2]-a[2];
		a[2]=a[1]+a[3]-a[2];
		ans=min(ans,3*a[1]*a[1]-2*tot*a[1]+3*a[2]*a[2]-2*tot*a[2]+3*a[3]*a[3]-2*tot*a[3]+tot*tot);
	}
	else{
	for(int i=2;i<=n-1;i++){
		if(i<=(1+n)/2)
		dfsq(i);
		else dfsh(i);
	}
	for(int i=1;i<=n;i++)
	ans+=n*a[i]*a[i]-2*tot*a[i];
	ans+=tot*tot;
    }
	cout << ans << endl;
	return 0;
}
