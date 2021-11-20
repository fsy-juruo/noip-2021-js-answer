#include <bits/stdc++.h>

using namespace std;

short f[10000010];//0 = unchecked,-1 = false,1 = true

int read(){
	int q = 1,n = 0;
	char c;
	c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-'){
			q = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		n = n * 10 + c - '0';
		c = getchar();
	}
	return q * n;
}

void check(int n){
	int on = n;
	while(n > 0){
		if(n % 10 == 7){
			int i = 1;
			while(i * on <= 10000010){
				f[i * on] = 1;
				i++;
			}
			return;
		}
		n /= 10;
	}
	f[on] = -1;
	//printf("f[%d] is now %d\n",on,f[on]);
	return;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt = 0;tt < t;tt++){
		int num;
		num = read();
		if(f[num] == 0){
			for(int i = 1;i <= num;i++){
				if(f[i] == 0){
					check(i);
				}
			}
			//printf("Checked %d,f[%d] = %d\n",num,num,f[num]);
		}
		if(f[num] == 1){
			printf("-1\n");
			continue;
		}
		int nowcheck = num + 1;
		while(f[nowcheck] != -1){
			//printf("f[%d] = %d\n",nowcheck,f[nowcheck]);
			if(f[nowcheck] == 0){
				//check(nowcheck);
				for(int i = 1;i <= nowcheck;i++){
					if(f[i] == 0){
						check(i);
					}
				}
			}
			//printf("Checked %d,f[%d] = %d\n",nowcheck,nowcheck,f[nowcheck]);
			if(f[nowcheck] != -1){
				nowcheck++;
			}
		}
		printf("%d\n",nowcheck);
	}
	return 0;
}
