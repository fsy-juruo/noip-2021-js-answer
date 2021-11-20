#include<bits/stdc++.h>
using namespace std;

int T;

int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>T;
	
	while(T--) {
		int n,m,q;
		cin>>n>>m>>q;
		
		for(int i=1;i<=n;i++) {
			string s;
			cin>>s;
		}
		
		for(int i=1;i<n;i++) {
			string s;
			cin>>s;
		}
		
		for(int i=1;i<=q;i++) {
			int a,b,c,d;
			cin>>a>>b>>c>>d;
		}
		
		for(int i=1;i<=q;i++) {
			cout<<rand()%(n*m)<<'\n';
		}
	}
	
	return 0;
}

