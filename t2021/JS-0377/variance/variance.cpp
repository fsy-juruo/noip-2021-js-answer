#include<bits/stdc++.h>
using namespace std;
int qiuzhi(int a,int b,int c,int d){
	float pj,sum;
	pj=a+b+c+d;
	pj/=4;
	sum=(a-pj)*(a-pj)+(b-pj)*(b-pj)+(c-pj)*(c-pj)+(d-pj)*(d-pj);
	sum/=4;
	return sum;
}
int a[105];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	float pj,sum=1919810;
	cin>>n;
	if(n==3)
	{
		cin>>a[1]>>a[2]>>a[3];
		pj=a[1]+a[2]+a[3];
		pj/=3;
		sum=(a[1]-pj)*(a[1]-pj)+(a[2]-pj)*(a[2]-pj)+(a[3]-pj)*(a[3]-pj);
		sum/=3;

		a[2]=a[1]+a[3]-a[2];
		pj=a[1]+a[2]+a[3];
		pj/=3;
		if( ((a[1]-pj)*(a[1]-pj)+(a[2]-pj)*(a[2]-pj)+(a[3]-pj)*(a[3]-pj))/3 < sum)
		sum=((a[1]-pj)*(a[1]-pj)+(a[2]-pj)*(a[2]-pj)+(a[3]-pj)*(a[3]-pj))/3;
		sum*=9;
	}
	else
	{
		if(n==4)
		{
			cin>>a[1]>>a[2]>>a[3]>>a[4];
			sum=qiuzhi(a[1],a[2],a[3],a[4]);
			for(int i=1;i<=20;++i)
			{
				a[2]=a[1]+a[3]-a[2];
				if(qiuzhi(a[1],a[2],a[3],a[4])<sum) sum=qiuzhi(a[1],a[2],a[3],a[4]);
				a[3]=a[2]+a[4]-a[3];
				if(qiuzhi(a[1],a[2],a[3],a[4])<sum) sum=qiuzhi(a[1],a[2],a[3],a[4]);
			}
			sum*=16;
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

