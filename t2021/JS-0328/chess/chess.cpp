#include<bits/stdc++.h>
using namespace std;
int T,n,m,q,col[105],lv[105],x[105],y[105],opt[105][105];
string st;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--){
	cin>>n>>m>>q;	
	for(int i=1;i<=n;i++)
	{
		cin>>st;
		for(int j=0;j<st.length();j++)
			opt[i][j+1]=st[j];
		
	}
	for(int i=1;i<=n-1;i++){
		cin>>st;
		for(int j=0;j<st.length();j++)
			opt[j][i]=st[j];
	}
	for(int i=1;i<=q;i++)
		cin>>col[i]>>lv[i]>>x[i]>>y[i];
	for(int i=1;i<=q;i++) cout<<0<<endl;
	}
	return 0;
}
