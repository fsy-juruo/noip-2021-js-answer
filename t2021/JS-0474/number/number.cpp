#include<bits/stdc++.h>
using namespace std;
const int m=10000000;
int n,q,has[10000010],p=0,nex[10000010],last;
bool f[10000010],vh[10000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(f,0,sizeof(f));
	memset(vh,0,sizeof(vh));
	memset(nex,0,sizeof(nex));
	for(int i=1;i<=m;++i){
		if(i%7==0){
			f[i]=1;
			has[++p]=i;
			continue;
		}
		int x=i;
		while(x>0){
			if(x%10==7){
				f[i]=1;
				has[++p]=i;
				break;
			}
			x/=10;
		}
	}
	for(int i=1;i<=p;++i){
		if(vh[has[i]]) continue;
		else{
			int x=1;
			while(x*has[i]<=m){
				f[x*has[i]]=1;
				vh[x*has[i]]=1;
				++x;
			}
		}
	}
	int i=1;
	while(i<=m){
		int x=i;
		++i;
		while(f[i]) ++i;
		nex[x]=i;
	}
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>q;
		if(f[q]) cout<<-1<<endl;
		else cout<<nex[q]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
