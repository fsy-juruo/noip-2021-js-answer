#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	scanf("%d",&n);
	if( n == 1 ) printf("0");
	if( n == 2 ) {
		int a, b;
		scanf("%d %d",&a,&b);
		printf("%d\n",2*(2*(a*a+b*b)-(a+b)*(a+b)));
	} 
	if( n == 3 ) {
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		int ans = 3*(3*(a*a+b*b+c*c)-(a+b+c)*(a+b+c));
		b = a+c-b;
		ans = min( ans, 3*(3*(a*a+b*b+c*c)-(a+b+c)*(a+b+c)) );
		printf("%d\n",ans);
	}
	if( n == 4 ) {
		int a1, a2, a3, a4;
		scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
		int a = a1, b = a2, c = a3, d = a4;
		int ans = 4*(4*(a*a+b*b+c*c+d*d)-(a+b+c+d)*(a+b+c+d));
		c = a2+a4-a3;
		ans = min( ans, 4*(4*(a*a+b*b+c*c+d*d)-(a+b+c+d)*(a+b+c+d)) );
		b = a1+a4-a3;
		ans = min( ans, 4*(4*(a*a+b*b+c*c+d*d)-(a+b+c+d)*(a+b+c+d)) );
		c = a1+a4-a2;
		ans = min( ans, 4*(4*(a*a+b*b+c*c+d*d)-(a+b+c+d)*(a+b+c+d)) );
		b = a1+a3-a2;
		ans = min( ans, 4*(4*(a*a+b*b+c*c+d*d)-(a+b+c+d)*(a+b+c+d)) );
		c = a3;
		ans = min( ans, 4*(4*(a*a+b*b+c*c+d*d)-(a+b+c+d)*(a+b+c+d)) );
		printf("%d\n",ans);
	}
	return 0;
}
