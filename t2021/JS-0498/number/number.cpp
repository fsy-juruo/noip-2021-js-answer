#include <bits/stdc++.h>
using namespace std;
const int MAXX=10000000+5;
bool is_seven[MAXX],book[MAXX];
int check(int x){
	int n=1;
	while(x){
		if(x%10==7)	return n;
		x/=10,n++;
	}
	return 0;
}
bool p(int x){
	if(book[x])	return is_seven[x];
	book[x]=1;
	int limit=sqrt(x)+1;
	for(int i=1;i<=limit;i++)
		if(x%i==0){
			if(is_seven[i])
				return is_seven[x]=1;
			if(is_seven[x/i])
				return is_seven[x]=1;
		}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t,x,i;
	for(i=1;i<MAXX-1;i++){
		is_seven[i]=check(i);
		book[i]=is_seven[i];
	}
	cin>>t;
	while(t--){
		scanf("%d",&x);
		if(p(x)==1){
			cout<<-1<<endl;
			continue;
		}
		for(int i=x+1;i<=MAXX;i++){
			if(check(i)){
				int k=1,n=check(i);
				for(int j=1;j<n;j++)	k*=10;
				i/=k;
				i++;
				i*=k;
			}
			if(!p(i)){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
