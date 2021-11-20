#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000005
#define hMAXN 5000000 
bool p[MAXN];
int pt=0;//[++pt] pt is the last one //p->false can be the answer
int num[MAXN];

/*bool if7(int x)
{
/*	int a1,a2,a3,a4,a5,a6,a7,a8;
	a8=x/10000000;
	a7=(x/1000000)%10;
	if(a7==7)return true;
	a6=(x/100000)%10;
	if(a6==7)return true;
	a5=(x/10000)%10;
	if(a5==7)return true;
	a4=(x/1000)%10;
	if(a4==7)return true;
	a3=(x/100)%10;
	if(a3==7)return true;
	a2=(x/10)%10;
	if(a2==7)return true;
	a1=x%10;
	if(a1==7)return true;*/
/*	while(x!=0)
	{
		if(x%10==7)return true;
		x=x/10;
	}
	return false;
}*/
/*void tp(int x)//x>hMAXN
{
	int xx=x;
/*	while(xx!=0)
	{
		if(xx%10==7){
			cout<<-1<<endl;return;
		}
		xx=xx/10;
	}*/
/*	if(if7(x))cout<<-1<<endl;
	++x;
	while(if7(x)||p[x])++x;
	cout<<x<<endl;
}*/
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int  T=0,x=0;
	ios::sync_with_stdio(false);
	memset(p,false,sizeof(p));
//	int UPPERB=sqrt(MAXN);
//	cout<<UPPERB<<endl; //3162*********************************£¡ 
	int y=0;
//	for(int i=0;i<=1;++i)
		for(int j=0;j<=4;++j)
			for(int k=0;k<=9;++k)
				for(int l=0;l<=9;++l)
					for(int m=0;m<=9;++m)
						for(int n=0;n<=9;++n)
							for(int q=0;q<=9;++q)
									{
										y=j*1000000+k*100000+l*10000+m*1000+n*100+q*10+7;
										if(p[y])continue;
										num[++pt]=y;
										p[y]=true;
									}//5000000 is ok
		for(int j=0;j<=4;++j)
			for(int k=0;k<=9;++k)
				for(int l=0;l<=9;++l)
					for(int m=0;m<=9;++m)
						for(int n=0;n<=9;++n)
								for(int r=0;r<=9;++r)
									{
										y=j*1000000+k*100000+l*10000+m*1000+n*100+70+r;
										if(p[y])continue;
										num[++pt]=y;
										p[y]=true;
									}//5000000 is ok
		for(int j=0;j<=5;++j)
			for(int k=0;k<=9;++k)
				for(int l=0;l<=9;++l)
					for(int m=0;m<=9;++m)
							for(int q=0;q<=9;++q)
								for(int r=0;r<=9;++r)
									{
										y=j*1000000+k*100000+l*10000+m*1000+700+q*10+r;
										if(p[y])continue;
										num[++pt]=y;
										p[y]=true;
									}//5000000 is ok
		for(int j=0;j<=5;++j)
			for(int k=0;k<=9;++k)
				for(int l=0;l<=9;++l)
						for(int n=0;n<=9;++n)
							for(int q=0;q<=9;++q)
								for(int r=0;r<=9;++r)
									{
										y=j*1000000+k*100000+l*10000+7000+n*100+q*10+r;
										if(p[y])continue;
										num[++pt]=y;
										p[y]=true;
									}//5000000 is ok
		for(int j=0;j<=5;++j)
			for(int k=0;k<=9;++k)
					for(int m=0;m<=9;++m)
						for(int n=0;n<=9;++n)
							for(int q=0;q<=9;++q)
								for(int r=0;r<=9;++r)
									{
										y=j*1000000+k*100000+70000+m*1000+n*100+q*10+r;
										if(p[y])continue;
										num[++pt]=y;
										p[y]=true;
									}//5000000 is ok
		for(int j=0;j<=5;++j)
				for(int l=0;l<=9;++l)
					for(int m=0;m<=9;++m)
						for(int n=0;n<=9;++n)
							for(int q=0;q<=9;++q)
								for(int r=0;r<=9;++r)
									{
										y=j*1000000+700000+l*10000+m*1000+n*100+q*10+r;
										if(p[y])continue;
										num[++pt]=y;
										p[y]=true;
									}//5000000 is ok
//									cout<<pt<<endl;
	for(int i=2;i<=pt;++i)
	{
		y=num[i];int upb=MAXN/y;
//		cout<<"**"<<upb<<endl;
		for(int j=2;j<=MAXN/y;++j)
			p[y*j]=true;
	}
/*	
	cout<<endl;
	for(int i=1;i<=MAXN;++i)
		if(p[i])cout<<'*'<<i<<endl;
	cout<<endl;*/
	
	cin>>T;
	while(T--)
	{
		cin>>x;
//		if(x>hMAXN)tp(x);
//		else
//		{
			if(p[x]||(x%7==0))cout<<-1<<endl;
			else
			{
				++x;
				while(p[x])++x;
				cout<<x<<endl;
			}
//		}
	}
}
