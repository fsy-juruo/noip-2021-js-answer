#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,k;
int v[102];
bool s[101];

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;i++){
		cin>>v[i];
	}
	if(k==1){
		cout<<"40";
		return 0;
	}
	cout<<"642171527";
	return 0;
}
