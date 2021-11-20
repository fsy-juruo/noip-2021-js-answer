#include<bits/stdc++.h>
using namespace std;

const int N=1e7;

int T;
bool ok[N+5];
vector<int>v;
int Pow[10]={1,10,100,1000,10000,100000,1000000,10000000};

inline void pre(){
	for(int i=1;i<=N;i++) ok[i]=1;
	for(int i=1;i<=7;i++){
		for(int j=0;j<Pow[7-i];j++){
			for(int k=0;k<Pow[i-1];k++){
				int x=j*Pow[i]+7*Pow[i-1]+k;
				for(int l=x;l<=N;l+=x) ok[l]=0;
			}
		}
	}
	for(int i=1;i<=N;i++)
		if(ok[i])
			v.push_back(i);
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	pre();
	while(T--){
		int x;
		cin>>x;
		if(!ok[x]){
			cout<<-1<<endl;
			continue;
		}
		int l=0,r=(int)v.size();
		while(l<r){
			int mid=(l+r)>>1;
			if(v[mid]>x) r=mid;
			else if(v[mid]==x){
				l=mid;
				break;
			} else l=mid+1;
		}
		cout<<v[l+1]<<endl;
	}
	return 0;
}
