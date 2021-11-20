#include<bits/stdc++.h>
using namespace std;
bool ccf[10000002];
bool seven(int p){
	while (p!=0){
		if (p%10==7) return true;
		p/=10;
	}
	return false;
}
void format(){
	for (int i=1; i<=10000001; i++) ccf[i]=true;
	for (int i=1; i<=10000000; i++)
		if (ccf[i]&&seven(i))
			for (int j=i; j<=10000000; j+=i) ccf[j]=false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int noip, rp;
	scanf("%d", &noip);
	format();
	for (int i=1; i<=noip; i++){
		scanf("%d", &rp);
		if (!ccf[rp]) printf("%d\n", -1);
		else{
			rp++;
			while (!ccf[rp]) rp++;
			printf("%d\n", rp);
		}
	}
	return 0;
}

