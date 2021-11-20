#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ss=0;char cc=getchar();bool ff=1;
	for(cc;!isdigit(cc);cc=getchar()) if(cc=='-')	ff=0;
	for(cc;isdigit(cc);cc=getchar()) ss=(ss<<3)+(ss<<1)+cc-'0';
	return ff?ss:-ss;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=read(),i=7,m=2,s;
	bool f[10010],g[10010];
	memset(f,1,sizeof(f));
	while(i<=10000){
		f[i]=0;
		i=m*7;
		m++;
	}
	for(i=8;i<=10000;i++){
		s=i;
		while(s>0){
			m=s%10;
			if(m==7)	f[i]=0;
			s=s/10;
		}
	}
	for(i=1;i<=10000;i++)
		g[i]=f[i];
	for(i=8;i<=5000;i++){
		if(g[i]==0){
			s=i;
			m=2;
			while(s<=10000){
				s=i*m;
				f[s]=0;
				m++;
			}
		}
	}
	for(int k=1;k<=t;k++){
		int n=read();
		if(f[n]==0)
			cout<<"-1"<<endl;
		else{
			for(i=n+1;i<=10000;i++)
				if(f[i]==1){
					cout<<i<<endl;
					break;
				}
		}
	}
	return 0;
}
