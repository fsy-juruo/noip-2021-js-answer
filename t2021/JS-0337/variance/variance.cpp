#include<bits/stdc++.h>
using namespace std;
int n;
int a[10005];
long long maxx=1e10;
struct node{
	int x[25];long long sum=0;
};
vector<node>q;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	node toop;
	for(int i=1;i<=n;i++)
		cin>>toop.x[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			toop.sum+=(toop.x[i]-toop.x[j])*(toop.x[i]-toop.x[j]);
			q.push_back(toop);
			maxx=toop.sum;
			int num=0;
	while(num<=5e5){
		node toop=q[num++];
		for(int i=2;i<n;i++){
			node a=toop;
			a.x[i]=a.x[i+1]+a.x[i-1]-a.x[i];
				for(int j=1;j<=n;j++)
				a.sum=a.sum-(toop.x[i]-toop.x[j])*(toop.x[i]-toop.x[j])+(a.x[i]-a.x[j])*(a.x[i]-a.x[j]);
				q.push_back(a);

				maxx=min(a.sum,maxx);
		}
	}	
	cout<<maxx;
return 0;
}

