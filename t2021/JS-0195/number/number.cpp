#include <bits/stdc++.h>
#define nwah cout<<"nwah"<<endl;
using namespace std;

const int MAXN=10000+20,MAXX=200000+10;
int n,a[MAXN]; 
bool sev[MAXX];

bool has_sev(int tmp) {
	while(tmp) {
		if(tmp%10==7) {
			return true;
		}
		tmp/=10;
	}
	return false;
}

void init() {
	for(int i=0;i<MAXX;i++) sev[i]=false;
	for(int i=1;i<MAXX;i++) {
		if(has_sev(i)) {
			for(int k=i;k<MAXX;k=k+i) {
				sev[k]=true;
			}
		}
	}
}

void read_in() {
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
//	sort(a,a+n);
}

void shit_solve() {
	for(int i=0;i<n;i++) {
		if(sev[a[i]]) cout<<-1<<endl;
		else {
			for(int k=a[i]+1; ; k++) {
				if(!sev[k]) {
					cout<<k<<endl;
					break;
				}
			}
		}
	}
}
/*
void solve() {
	int p=0;
	for(int i=1;i<a[n-1];i++) {
		if()
	}
	a[n-1] judge
}
*/
int main() {
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	read_in();
	shit_solve();
//	solve();
	return 0;
} 











//  chao, 数学比赛，飞仙保佑
//wa，飞仙要400pts了  

































