#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

long long t,n;

long long read(){
	long long sum = 0;
	int neg = 1;
	char c = getchar();
	while(c<'0'||c>'9'){
		if(c == '-')neg = -1;
		c = getchar();
	}
	while(c>='0'&&c<='9'){
		sum = sum*10+(c-'0');
		c = getchar();
	}
	return sum * neg;
}

bool judge(long long num){
	long long i = 7;
	bool  l = 1;
	while(i<=num){
		l = 1;	
		for(long long cop = i*10;cop>0;cop/=10){
			if(cop%10 == 7){
				l = 0;break;
			}
		}
		if(l==0&&num%i == 0){
			return false;
		}
		i++;
	}
	return true;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t = read();
	//cout<<judge(7)<<endl;
	while(t--){
		n = read();
		if(judge(n) == 0){
			cout<<-1<<endl;
			continue;
		}
		while(judge(++n) == 0){continue;}
		cout<<n<<endl;
	}
	return 0;
}
