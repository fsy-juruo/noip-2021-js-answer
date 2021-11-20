#include <bits/stdc++.h>
using namespace std;

//number
//Predicted Score: 70pts

int cnt = -1;
const int maxn = 200010;
bool a7[maxn+10];
int a[maxn+10];

inline bool has7(int x){
	while (x){
		if (x%10 == 7) return true;
		x /= 10;
	}
	return false;
}

void make_table(){
	for (int i=1;i<=maxn;i++){
		if (has7(i)) {
			for (int j=1;i*j<=maxn;j++){
				a7[i*j] = true;
			}
		}
	}
	
	for (int i=1;i<=maxn;i++) if (a7[i]) a[++cnt] = i;
}

int determine_next(int x){
	x++;
	while (*lower_bound(a,a+cnt,x) == x) x++;
	return x;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	make_table();

	int T,x;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&x);
		if (*lower_bound(a,a+cnt,x) == x)
			printf("-1\n");
		else
			printf("%d\n",determine_next(x));
		
	}
}
