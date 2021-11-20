#include<bits/stdc++.h>
using namespace std;

int t,a[200005];
bool p[10000005];
inline bool check(int x){
	while(x){
		int t=x%10;
		if(t==7) return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	int maxx=0;
	for(int i=1;i<=t;i++){
		scanf("%d",&a[i]);
		maxx=max(a[i],maxx);
		
	}
	maxx=min(10000005,2*maxx);
	for(register int i=7;i<=maxx;i++){
		if(p[i]==0&&check(i)){
			register int c=i;
			while(c<=maxx){
				p[c]=1;
				c+=i;
			}
		}
	}
	for(int i=1;i<=t;i++){
		if(p[a[i]]) cout<<-1<<endl;
		else{
			a[i]++;
			while(p[a[i]]){
				a[i]++;
			}
			cout<<a[i]<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
