#include<bits/stdc++.h>
using namespace std;
int main()
{
	float yuancha,yuancha1,yuancha2,d,n,shu,p,min,q1,q2,q3,q4;
	cin>>n;
	if (n==4)
	{cin>>q1>>q2>>q3>>q4;
	p=(q1+q2+q3+q4)/4.00;
	d=p;
	yuancha=0.25*((q1-d)(q1-d)(q2-d)(q2-d)+(q3-d)(q3-d)+(q4-d)(q4-d));
	shu=2;
	q2=q1+q3+q2;
	p=(q1+q2+q3+q4)/4.00;
	d=p;
	yuancha1=1/n*((q1-d)(q1-d)+(q2-d)(q2-d)+(q3-d)(q3-d)+(q4-d)(q4-d));
	if(yuancha<=yuancha1)
	  min=yuancha;
	  else min=yuancha1;
	shu=3;
	q3=q2+q4+q3;
	p=(q1+q2+q3+q4)/4.00;
	d=p;
	yuancha2=1/n*((q1-d)(q1-d)+(q2-d)(q2-d)+(q3-d)(q3-d)+(q4-d)(q4-d));
	if(min<=yuancha2)
	  cout<<min*16;
	  else min=yuancha2;
	  cout<<min*16;}
return 0;
}
