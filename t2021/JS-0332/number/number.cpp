#include <bits/stdc++.h>
using namespace std;
const int N = 200014;
const int M = 1e7+100;
int t,mq;
int q[N];
bool flag[M];
char o;
bool judge(int x){
	int a;
	while(x){
		a = x/10;
		if(x-a*10 == 7){
			return false;
		}
		x = a;
	}
	return true;
}
int rea(){
	char a = getchar();
	while(a<'0'||a>'9'){
		if(a == '-'){
			return -1;
		}
		a = getchar();
	}
	int ans = 0;
	while(a>='0'&&a<='9'){
		ans = ans*10+a-'0';
		a = getchar();
	}
	return ans;
}
void writ(int a){
	int x[14];
	int l = 1,b = a/10;
	while(a > 0){
		x[l] = a-b*10;
		l++;
		a = b;
		b = a/10;
	}
	l--;

	while(l){
		o = '0'+ x[l];
		putchar(o);
		l--;
	}
	o = 10;
	putchar(o);
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> t;
	memset(flag,true,sizeof(flag));
	mq = 0;
	for(int i = 1;i <= t;i++){
		q[i] = rea();
		mq = max(mq,q[i]);
	}
	mq +=200;
	for(int i = 1;i < mq;i++){
		if(!flag[i]){
			continue;
		}
		if(!judge(i)){
			for(int j = i;j < mq;j += i){
				flag[j] = false;
			}
		}
	}
	for(int i = 1;i <= t;i++){
		if(q[i] < 0||!flag[q[i]]){
			o = '-';
			putchar(o);
			o = '1';
			putchar(o);
			o = 10;
			putchar(o);
			continue;
		}
		q[i]++;
		while(!flag[q[i]]){
			q[i]++;
		}
		writ(q[i]);
	}
	return 0;
}
