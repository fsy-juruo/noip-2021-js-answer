/*
Nice problem for T1 (unless I'm stuck again)
---Zzzyt
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000007

int fastread(){
	int x=0;
	int f=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		ch=getchar();
		if(ch=='-')f=-1;
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

int n;

bool check7(int x){
	while(x){
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}

bool check_bf(int x){
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			if(check7(i))return false;
			if(check7(x/i))return false;
		}
	}
	return true;
}

void solver1(){
	for(int i=0;i<n;i++){
		int x=fastread();
		if(!check_bf(x)){
			printf("-1\n");
		}
		else{
			for(int j=x+1;;j++){
				if(check_bf(j)){
					printf("%d\n",j);
					break;
				}
			}
		}
	}
}

bool zjs[10000015];
int cnt=0;
int v[800005];

#define MAXN 10000010

void solver2(){
	for(int i=1;i<=MAXN;i++){
		if(check7(i)){
			for(int j=i;j<=MAXN;j+=i){
				zjs[j]=true;
			}
		}
	}
	for(int i=1;i<=MAXN;i++){
		if(!zjs[i]){
			v[cnt]=i;
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		int x=fastread();
//		scanf("%d",&x);
		int p=lower_bound(v,v+cnt,x)-v;
		if(v[p]!=x){
			printf("-1\n");
		}
		else{
			printf("%d\n",v[p+1]);
		}
	}
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	freopen("number.in","r",stdin);
#ifndef ZZZYT
	freopen("number.out","w",stdout);
#endif
//	scanf("%d",&n);
	n=fastread();
	if(n<=1000){
		solver1();
	}
	else{
		solver2();
	}
	return 0;
}

