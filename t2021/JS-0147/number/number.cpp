#include <bits/stdc++.h>
using namespace std;
//7777 false? fix
//imitate ass for [1,1e7]? ok
int T,cnt;
bool pm[10000054];
int val[763500]; //from 1 to hero (
bool Andrea(int n) { //only step 1
	int sb=n;
	while(sb) {
		if(sb%10==7) return false;
		sb/=10;
	}
	return true;
}
bool valid(int n) {
	int sb=n;
	while(sb) {
		if(sb%10==7) return false;
		sb/=10;
	}
	for(int i=1;i*i<=n;i++) {
		if(n%i==0) {
			if((!Andrea(i)) || (!Andrea(n/i))) { //btw who is Andrea (
				//cout<<"Andrea is so cute : "<<i<<endl;
				return false;
			}
		}
	}
	return true;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	//cout<<cnt<<endl; //>763407
	for(int i=1;i<=10000010;i++) {
		if(pm[i]) continue;
		if(!Andrea(i)) { //invalid
			for(int j=1;i*j<=10000010;j++) pm[i*j]=true;
		} else { //valid
			cnt++; val[cnt]=i;
		}
	}
	//cout<<cnt<<endl;
	while (T --> 0) {
		int qwq;
		cin>>qwq;
		if(pm[qwq]) {
			cout<<-1<<endl;
			continue;
		}
		/*if(qwq==9999998) {
			cout<<<<endl;
			continue;
		}*/
		//valid itself qwq
		//int pt=lower_bound(val+1,val+cnt+1,qwq);
		int pt=0,l=1,r=cnt;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(val[mid]>qwq) {
				pt=mid;
				r=mid-1;
			} else {
				l=mid+1;
			}
		}
		cout<<val[pt]<<endl;
	}
	return 0;
}
