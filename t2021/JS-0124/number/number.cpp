#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;
const int maxn=200000;
bool seven[200005];
int next_ok[200005];
inline bool check_digit(int x){
	while(x){
		if(x%10==7){
			return 1;
		}
		x/=10;
	}
	return 0;
}
inline void print_number(int x){
	int s=x;
	while(s<=maxn){
		seven[s]=1;
		s+=x;
	}
}
void init(){
	for(int i=1;i<=maxn;i++){
		if(check_digit(i)&&!seven[i]){
			//cout<<i<<" ";
			print_number(i);
		}
	}
	int pre=0;
	for(int i=1;i<=maxn;i++){
		if(!seven[i]){
			next_ok[pre]=i;
			pre=i;
		}
	}
	next_ok[200000]=200001;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	init();
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(seven[x]){
			printf("-1\n");
		}
		else{
			printf("%d\n",next_ok[x]);
		}
	}
	return 0;
}
