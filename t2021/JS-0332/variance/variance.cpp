#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10014;
int n;
double a[N];
double x,ans,sum;
inline double ab(double a,double b){
	if(a > b){
		return a-b;
	} else{
		return b-a;
	}
}
inline double make(int i){
	return a[i-1]+a[i+1]-a[i];
}
inline double va(double xx){
	double su = double(0);
	for(int i = 1;i <= n;i++){
		su += ab(a[i],xx)*ab(a[i],xx);
	}
	return su;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin >> n;
	sum = double(0);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum += a[i];
	}
	x = sum/(double(1)*n);
	bool flag = true;
	ans = va(x);
	while(flag){
		flag = false;
		for(int i = 2;i < n;i++){
			double sw = a[i];
			a[i] = make(i);
			double anss = va(x + (a[i]-sw)/(double(1)*n));
			if(anss < ans){
				ans = anss;
				flag = true;
				x += (a[i]-sw)/(double(1)*n);
			} else{
				a[i] = sw;
			}
		}
	}
	cout << int(ans*(double(1)*n));
	return 0;
}
