#include<iostream>
#include<cstdio>
#define maxn 10000010
bool p[maxn] = {false};
int x,now=0;
int quick_get()
{
	int num=0;
	char ch='0';
	while(ch!='\n'&&ch!=' ')
	{
		ch=getchar();
		num=num*10+(ch-'0');
	}
	num=num-(ch-'0');
	return num/10;
}
bool check1(int num){
	while(num>0){
		int n=num%10;
		if(n==7){
			p[num]=false;
			return false;
		}
		num/=10;
	}
	return true;
}
bool check2(int num){
	bool flag=true;
	if(p[num]==true) return true;
	if(check1(num)==false) return false;
	for(int i=2;i*i<=num;i++){
		if(num%i==0){
			flag=check2(num/i);
			if(flag ==false) return false;
			flag=check2(i);
			if(flag ==false) return false;
		}
	}
	p[num]=true;
	return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=quick_get();
	for(int i=0;i<T;i++){
		x=quick_get();
		p[x] = check2(x);
		if(p[x]==false) std::cout<<"-1\n";
		else{
			x++;
			while(check2(x)!=true) x++;
			std::cout<<x<<"\n";
		}
	}
	return 0;
}

