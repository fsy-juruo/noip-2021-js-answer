#include<bits/stdc++.h>
using namespace std;
int n;
float mi=10000,s2,s;
int a[10000];
int fa[10000];
void ss(){
	s2=0;
	s=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
	}
	float c=s/n;
	for(int i=1;i<=n;i++){
		s2+=pow(a[i]-c,2);
	}
}
void bfs(){
	for(int i=2;i<n;i++){
		if(!fa[i]){
			fa[i]=1;
			long long x=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			ss();
			if(s2<mi){
		    mi=s2;}
		    bfs();
		    fa[i]=0;
		    a[i]=x;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
    bfs();
    cout<<mi*n<<endl;
}
