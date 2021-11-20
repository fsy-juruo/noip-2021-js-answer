#include<bits/stdc++.h>
using namespace std;

int f(int a,int b,int c){
	return 3*(a*a+b*b+c*c)-(a+b+c)*(a+b+c);
}
int f(int a,int b,int c,int d){
	return 4*(a*a+b*b+c*c+d*d)-(a+b+c+d)*(a+b+c+d);
}

int n,a,b,c,d;
int main(){
	
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
 cin>>n;
 if(n==1)cout<<"0"<<endl;
 if(n==2){
 cin>>a>>b;
 cout<<2*(a*a+b*b)-(a+b)*(a+b)<<endl;
 }
 if(n==3){
 cin>>a>>b>>c;
  cout<<min(f(a,b,c),f(a,a+c-b,c))<<endl;; 	
 }
 
 if(n==4){
 	cin>>a>>b>>c>>d;
 	int x;
 	x=min(min(f(a,b,c,d),f(a,a+c-b,c,d)),f(a,a+c-b,a+d-b,d));
 	x=min(x,f(a,a+d-c,a+d-b,d));
 	x=min(x,f(a,a+d-c,b+d-c,d));
 	x=min(x,f(a,b,b+d-c,d));
 	cout<<x<<endl;
 }

	return 0;
}
