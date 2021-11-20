#include<bits/stdc++.h>
using namespace std;
long long n,w;
int a[37]={7,14,17,21,27,28,34,35,37,42,47,49,51,54,56,57,63,67,68,70,71,72,73,74,75,76,77,78,79,81,84,85,87,91,94,97,98};
bool pan(long long x){
	w=0;
	long long q=x;
while(q!=0){
	w++;
	if(q%10==7){
		return 0;
	}
	q=floor(q/10);
	
}
w=1;
for(int i=0;i<37;i++){
	if(x%a[i]==0){
		return 0;
	}
}

	return 1;
}
	

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		long long t;
			scanf("%lld",&t);
			if(!pan(t)){
			cout<<-1<<endl;
			}
			else{
				t++;
			while(!pan(t))
			{
				t+=pow(10,w-1);
			}
			cout<<t<<endl;
		}
	}

}
