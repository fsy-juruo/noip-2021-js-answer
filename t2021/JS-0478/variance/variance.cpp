#include<bits/stdc++.h>
using namespace std;
int n, s[5], a, b, c, d, minn=99999999;
void variance(){
	int ans=0, t=0;
	for (int i=1; i<=n; i++) t+=s[i];
	for (int i=1; i<=n; i++) ans+=(t-s[i]*n)*(t-s[i]*n);
	minn=min(minn, ans/n);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d", &n);
	if (n==1){
		cout << 0 << endl;
		return 0;
	}
	
	else if (n==2){
		scanf("%d%d", &a, &b);
		
		s[1]=a, s[2]=b;
		variance();
		 
		cout << minn << endl;
		return 0;
	}
	
	else if (n==3){
		scanf("%d%d%d", &a, &b, &c);
		
		s[1]=a;
		s[2]=b;
		s[3]=c;
		variance();
		
		s[1]=a;
		s[2]=a+c-b;
		s[3]=c;
		variance();
		
		cout << minn << endl;
		return 0;
	}
	scanf("%d%d%d%d", &a, &b, &c, &d);
	
	s[1]=a;
	s[2]=a+c-b;
	s[3]=c;
	s[4]=d;
	variance();
	
	s[1]=a;
	s[2]=a+c-b;
	s[3]=a+d-b;
	s[4]=d;
	variance();
	
	s[1]=a;
	s[2]=a+d-c;
	s[3]=a+d-b;
	s[4]=d;
	variance();
	
	s[1]=a;
	s[2]=a+d-c;
	s[3]=b+d-c;
	s[4]=d;
	variance();
	
	s[1]=a;
	s[2]=b;
	s[3]=b+d-c;
	s[4]=d;
	variance();
	
	s[1]=a;
	s[2]=b;
	s[3]=c;
	s[4]=d;
	variance();
	
	printf("%d\n", minn);
	return 0;
}
