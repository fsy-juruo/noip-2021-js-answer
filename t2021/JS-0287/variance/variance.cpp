#include<iostream>
using namespace std;
int arr[10001],sum,n;
long long answer=1145141919810;
long long sq(long long x)
{
	return x*x;
}
void getv()
{
	long long x=0;
	for(int i=0;i<n;i++)
		x+=sq(arr[i]*n-sum);
	x/=n;
	if(x<answer)
		answer=x;
}
void d(int dep)
{
	if(dep>10)
		return;
	getv();
	int temp,tr;
	for(int i=1;i<n-1;i++)
	{
		temp=arr[i-1]+arr[i+1]-arr[i];
		if(arr[i-1]<=temp&&arr[i+1]>=temp&&temp!=arr[i])
		{
			sum=sum-arr[i]+temp;
			tr=arr[i];
			arr[i]=temp;
			d(dep+1);
			arr[i]=tr;
			sum=sum+tr-temp;
		}
	}
	return;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i],sum+=arr[i];
	d(0);
	cout<<answer;
}
