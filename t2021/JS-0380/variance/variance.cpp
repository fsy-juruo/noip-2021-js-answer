#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10000+10;
double a[MAXN];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	cin>>n;
	double pi = 0;
	double ji = 1;
	double q=0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(i > 1 && a[i] == a[i-1]) ji++;
	}
	if( ji == n){
		cout<<0<<endl;
		return 0;
	}
	ji = 999999;
	if(n==2){
		pi = (a[1]+a[2])/2;
		cout<<2*((pi-a[1])*(pi-a[1])+(pi-a[2])*(pi-a[2]))<<endl;;
	}
	else if(n == 3){
		for(int i=1;i<=20;i++){
			pi = (a[1]+a[2]+a[3])/3;
			double j2 = 3*((pi-a[1])*(pi-a[1])+(pi-a[2])*(pi-a[2])+(pi-a[3])*(pi-a[3]));
			ji = min(ji,j2);
			a[2] = a[1] - a[2] +a[3];
			if(a[2]<1) break;
		}
		cout<<ji<<endl;
	}
	
	else if( n ==4) {
		pi = (a[1]+a[2]+a[3]+a[4])/4;
		double j2 = 4*((pi-a[1])*(pi-a[1])+(pi-a[2])*(pi-a[2])+(pi-a[3])*(pi-a[3])+(pi-a[4])*(pi-a[4]));
		ji=min(ji,j2); 
		q=a[2];
		a[2] = a[1] - a[2] +a[3];
		if(a[2]<1) a[2]=q;
		pi = (a[1]+a[2]+a[3]+a[4])/4;	
		j2 = 4*((pi-a[1])*(pi-a[1])+(pi-a[2])*(pi-a[2])+(pi-a[3])*(pi-a[3])+(pi-a[4])*(pi-a[4]));
		ji=min(ji,j2);
		a[3] = a[2] - a[3] +a[4];
		if(a[3]<1) a[3]=q;
		pi = (a[1]+a[2]+a[3]+a[4])/4;	
		j2 = 4*((pi-a[1])*(pi-a[1])+(pi-a[2])*(pi-a[2])+(pi-a[3])*(pi-a[3])+(pi-a[4])*(pi-a[4]));
		ji=min(ji,j2);
		a[3] = a[2] - a[3] +a[4];
		if(a[3]<1) a[3] = 1;
		pi = (a[1]+a[2]+a[3]+a[4])/4;	
		j2 = 4*((pi-a[1])*(pi-a[1])+(pi-a[2])*(pi-a[2])+(pi-a[3])*(pi-a[3])+(pi-a[4])*(pi-a[4]));
		ji=min(ji,j2);
		a[2] = a[1] - a[2] +a[3];
		if(a[2]<1) a[2]=q;
		pi = (a[1]+a[2]+a[3]+a[4])/4;	
		j2 = 4*((pi-a[1])*(pi-a[1])+(pi-a[2])*(pi-a[2])+(pi-a[3])*(pi-a[3])+(pi-a[4])*(pi-a[4]));
		ji=min(ji,j2);
		cout<<ji<<endl;
	}
	return 0;
}

