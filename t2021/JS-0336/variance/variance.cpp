#include<bits/stdc++.h>
using namespace std;
map<multiset<int>,int> sb;
int n;
long long sum=-1;
void dfs(multiset<int> s,int sum1){
	if(sb[s]==1){
		return;
	}
	sb[s]=1;
	int f=1;
	long long sum2=0;
	for(auto i:s){
		sum2+=(((i*n)-sum1)*((i*n)-sum1));
	}
	int d1,d2;
	for(auto i:s){
		if(f>n){
			break;
		}
		if(f==1){
			f++;
			d1=i;
		}else if(f==2){
			f++;
			d2=i;
		}else{
			f++;
			int e=d1+i-d2;
			int d=d2;
			d1=d2;
			d2=i;
			int q=0;
			for(auto j:s){
				if(j==d){
					q++;	
				}
			}
			s.insert(e);
			s.erase(d);
			sum1=sum1-d+e;
			f++;
			q--;
			while(q>0){
				s.insert(d);
				q--;
			}
			dfs(s,sum1);		
		}
	}
	if(sum2<=sum||sum==-1){
		sum=sum2;
	}
	return;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	long long sum1=0;
	multiset<int> a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int b;
		scanf("%d",&b);
		a.insert(b);
		sum1+=b;
	}
	
	dfs(a,sum1);
	printf("%lld",sum/n);
	return 0;
}
