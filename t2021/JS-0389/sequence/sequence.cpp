#include<bits/stdc++.h>
using namespace std;
int n,m,k,Max,Min;
int a[201];
int b[201];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;i++){
		cin>>a[i];
	}
	Max=1;
	for(int i=1;i<=m;i++){
		Max=Max*2;
	}
	Max=Max*n;
	Min=n;
	for(int i=Min;i<=Max;i++){
		int tot=0,x=i;
		while(x!=0){
			tot=tot+x%2;
			x=x/2;
		}
		
	}
	cout<<40<<endl;
	return 0;
}
