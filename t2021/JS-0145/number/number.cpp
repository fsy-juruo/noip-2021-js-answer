#include<bits/stdc++.h>
using namespace std;
int a[10000010],b[10000010];
bool f[10000010];
bool check(int k){
	bool flag=1;
	while (k>0){
		if (k%10==7){
			flag=0;
			break;
		}
		else k/=10;
	}
	if (flag==1) return 1;
	else return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int T;
    scanf("%d",&T);
    int tot=0;
    int n;
    if (T<=10000) n=200010;
    else n=10000010;
    memset(f,sizeof(f),0);
    for (int i=1;i<=n;i++){
    	if (f[i]==2) continue;
    	else if (!check(i)){
    		for (int j=1;j<=n/i;j++){
    			f[j*i]=2;
			}
		}
		else if (i%7==0) f[i]=1;
		else if (f[i]==0){
			a[++tot]=i;
			for (int j=a[tot-1];j<=a[tot]-1;j++)
			   b[j]=a[tot];
		}
	}
	while (T--){
		int m;
		scanf("%d",&m);
		if (f[m]==1||f[m]==2){
			printf("-1\n");
			continue;
		}
		else{
			printf("%d\n",b[m]);
		}
	}

	return 0;
}