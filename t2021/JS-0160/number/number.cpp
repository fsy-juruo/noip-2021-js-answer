#include<bits/stdc++.h>
#define LL long long
#define MP  make_pair
#define mo 1000000007
using namespace std;
void read(int &sum){
	sum=0;char ch=getchar();int p=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')p=-1;
	for(; isdigit(ch);ch=getchar())sum=sum*10+ch-'0';
	sum=sum*p;
}
void write(int sum){
	if(sum<0){
		putchar('-');
		sum=0-sum;
	}
	if(sum>=10){
		write(sum/10);
		sum=sum%10;
	}
	putchar(sum+'0');
}
bool che(int x){
	while(x){
		if(x%10==7){
			return false;
		}
		x/=10;
	}
	return true;
}
bool check(int num){
	int i;
	for(i=1;i*i<num;i++){
		if(num%i==0){
			if(!(che(i)&&che(num/i))){
				return false;
			}
		}
	}
	int x=int(sqrt(num));
	if(x*x==num){
		if(!che(x)){
			return false;
		}
	}
	return true;
	
}
void work1(int T){
	while(T--){
		int x;
		read(x);
		if(!check(x)){
			puts("-1");
			continue;
		}
		x++;
		for(;;x++){
			if(check(x)){
				write(x);
				putchar('\n');
				break;			
			}			
		}		
	}
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	read(T);
	work1(T);
	return 0;
}

