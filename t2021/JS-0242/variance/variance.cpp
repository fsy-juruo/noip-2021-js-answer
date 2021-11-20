#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn=1000007;
float ave;
int n;
float minn;
float dl[maxn];
float num;
bool flag[maxn];
float minnn(float x,float y) {
	if(x<y) return x;
	else return y;
}
void fc() {
	num=0;
	for(int i=1; i<=n; i++) {
		float cz=dl[i]-ave;
		num+=cz*cz;
	}
	num=num/n;
	minn=minnn(minn,num);
}
int main() {
	minn=9999999;
	float ans;
	cin>>n;
	ans=0;
	for(int i=1; i<=n; i++) {
		cin>>dl[i];
		ans+=dl[i];
	}
	ave=ans/n;
	fc();
	for(int i=2; i<n; i++) {
		ans=ans-dl[i];
		dl[i]=dl[i-1]+dl[i+1]-dl[i];
		ans=ans+dl[i];
		ave=ans/n;
		fc();
	}
	cout<<minn*n*n;
	return 0;
}
