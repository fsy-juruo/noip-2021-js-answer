#include <bits/stdc++.h>
using namespace std;

const int maxn = 100003;
int n;
int arr[maxn];
double arv_old,arv;
long long int total_x;
int dirtx;
int x_now;
double fc;
double tmp;
double ans = 1e6;
// calc: dirt(x)*dirt(x) + 2 * n * arv_old * dirt(x) - 2 * (total_x + dirt(x)) * dirt(arv) + 2 * n * arv_old * dirt(arv) + n * dirt(arv) * dirt(arv)
//fc + (x_now * x_now - (x_now - dirtx) * (x_now - dirtx)  + 2 * n * arv_old * dirtx - 2 * (total_x + dirtx) * (arv - arv_old) + 2 * n * arv_old * (arv - arv_old) + n * (arv - arv_old) * (arv - arv_old))/(double)n << endl;


double calc_new(){
	double tmp1 = 0;
	for(int i = 1 ; i <= n ; i++){
		tmp1 += ((arr[i] - arv) * (arr[i] - arv));
	}
	return tmp1/(double)n;
	//return fc + (x_now * x_now - (x_now - dirtx) * (x_now - dirtx) + (2*(total_x / (double)n)*(arv_old-arv) + 2*(x_now - dirtx)*arv_old -2*x_now*arv) - n * arv_old*arv_old + n*arv*arv)/(double)n;
}
void calc(){
	for(int i = 2 ; i <= n - 1 ; i++){
		x_now = arr[i - 1] + arr[i + 1] - arr[i];
		dirtx = x_now - arr[i];
		arr[i] = x_now;
		//arv_old = arv;
		//arv = (total_x + dirtx) / (double)n;
		total_x += dirtx;
		arv = total_x / double(n);
		fc = calc_new();
		cout << fc*n*n << endl;
		//total_x += dirtx;
		ans = min(ans,fc);
	}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin >> n;
	int x;
	for(int i = 1 ; i <= n; i++){
		cin >> x;
		arr[i] = x;
		total_x += x;
	}
	arv = total_x / (double)n;
	for(int i = 1 ; i <= n ; i++){
		tmp += (arr[i] - arv) * (arr[i] - arv);
	}
	fc = tmp / double(n);
	calc();
	cout << ans*n*n ;
	return 0;
} 
