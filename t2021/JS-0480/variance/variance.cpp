#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n; cin>>n>>a>>b>>c>>d;
	int cha[4]={0,b-a,c-b,d-c}; sort(cha+1,cha+3+1);
	if((cha[1]<cha[2]&&cha[2]==cha[3])||(cha[1]<cha[2]&&cha[2]<cha[3])) b=a+cha[2],c=b+cha[1],d=c+cha[3];
	else b=a+cha[1],b=a+cha[2],c=a+cha[3];
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	int sum=a+b+c+d;
	double pj=double(sum)/4.0;
	double chaa=4*(a-pj)*(a-pj)+4*(b-pj)*(b-pj)+4*(c-pj)*(c-pj)+4*(d-pj)*(d-pj);
	cout<<chaa;
	return 0;
}
