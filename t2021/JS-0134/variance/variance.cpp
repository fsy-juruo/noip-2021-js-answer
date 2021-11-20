#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
int main(){
	freopen("varience.in","r",stdin);
	freopen("varience.out","w",stdout);
	srand(time(0));
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int s1=0,s2=0;
	for(int i=0;i<n;i++){
		s1+=a[i];
		b[i]=a[i];
		s2+=a[i]*a[i];
	}
	int mi=1e9;
	for(int i=0;i<500000;i++){
		int x=rand()%(n-2)+1;
		int s12=s1-2*a[x]+a[x-1]+a[x+1],s22=s2-a[x]*a[x]+(a[x]-a[x-1]-a[x+1])*(a[x]-a[x-1]-a[x+1]);
		if(s22*n-s12*s12<s2*n-s1*s1){
			s1=s12,s2=s22,a[x]=a[x-1]+a[x+1]-a[x];
		}
	}
	mi=s2*n-s1*s1;
	for(int T=0;T<500;T++){
		s1=s2=0;
		for(int i=0;i<n;i++){
			s1+=a[i];
			b[i]=a[i];
			s2+=a[i]*a[i];
		}
		for(int i=0;i<10000;i++){
			int x=rand()%(n-2)+1;
			int s12=s1-2*a[x]+a[x-1]+a[x+1],s22=s2-a[x]*a[x]+(a[x]-a[x-1]-a[x+1])*(a[x]-a[x-1]-a[x+1]);
			if(s22*n-s12*s12<s2*n-s1*s1||rand()>60000){
				s1=s12,s2=s22,a[x]=a[x-1]+a[x+1]-a[x];
			}
		}
		mi=min(mi,s2*n-s1*s1);
	}
	for(int T=0;T<100000;T++){
		s1=s2=0;
		for(int i=0;i<n;i++){
			s1+=a[i];
			b[i]=a[i];
			s2+=a[i]*a[i];
		}
		for(int i=0;i<400;i++){
			int x=rand()%(n-2)+1;
			int s12=s1-2*a[x]+a[x-1]+a[x+1],s22=s2-a[x]*a[x]+(a[x]-a[x-1]-a[x+1])*(a[x]-a[x-1]-a[x+1]);
			s1=s12,s2=s22,a[x]=a[x-1]+a[x+1]-a[x];
		}
		mi=min(mi,s2*n-s1*s1);
	}
	cout<<mi;
	return 0;
}
