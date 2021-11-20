#include<bits/stdc++.h>
using namespace std;
const int maxn=10100000;
vector<int>s;
int rep[maxn];
bool p(int n){
	int ss=n;
	while(ss>0){
		int a=ss%10;
		if(a==7)return true;
		ss/=10;
	}
	return false;
}
void _rep(){
	for(int i=7;i<=maxn;i++){
		if(p(i)&&rep[i]==0){
			int k=1;
			for(int j=i;;k++){
				int cnt=j*k;
				if(cnt>maxn)break;
				rep[cnt]=1;
			} 
		}
	}
}
bool check(int x){
	int k=x;
	int t=lower_bound(s.begin(),s.end(),k)-s.begin();
	if(t>s.size()-1)return false;
	if(s[t]==k||s[t-1]==k)return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	s.push_back(-1);
	int T,x;
	cin>>T;
	_rep();
	for(int i=1;i<=maxn;i++){
		if(rep[i]==1)s.push_back(i);
	}
	while(T--){
		cin>>x;
		if(check(x)){
			cout<<-1<<endl;
			continue;
		}
		else {
			int k=0;
			int t=lower_bound(s.begin(),s.end(),x)-s.begin();
			if(s[t]-x==1){	
				for(int i=t+1;i<=maxn;i++){
					if(s[i]-s[i-1]>1){
						cout<<s[i-1]+1<<endl;
						break;
					}
				}
			}
			else cout<<x+1<<endl;
		}
	}
	return 0;
}
