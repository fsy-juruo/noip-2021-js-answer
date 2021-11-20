#include<bits/stdc++.h>
using namespace std;

double total,num[5],a[5],ans1,ans2,out = 1000000;
bool v[100][100];
int n;

double c(int number) {return (total / n - number) * (total / n - number);}

void test(int a2,int a3)
{
	double nans;
	total = a[1] + a2 + a3 + a[4];
	nans = c(a[1]) + c(a2) + c(a3) + c(a[4]);
	out = min(out,nans);
}

void find()
{
	queue < double > q1,q2;
	q1.push(a[2]),q2.push(a[3]);
	v[(int)a[2]][(int)a[3]] = 1;
	while(!q1.empty())
	{
		double a2,a3;
		a2 = q1.front(),a3 = q2.front();
		test(a2,a3);
		if(v[(int)(a[1] + a3 - a2)][(int)a3] == 0)
		{
			q1.push(a[1] + a3 - a2);
			q2.push(a3);
			v[(int)(a[1] + a3 - a2)][(int)a3] = 1;
		}
		if(v[(int)a2][(int)(a2 + a[4] - a3)] == 0)
		{
			q1.push(a2);
			q2.push(a2 + a[4] - a3);
			v[(int)a2][(int)(a2 + a[4] - a3)] = 1;
		}
		q1.pop(),q2.pop();
	}
}


int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	cin>>a[i];
	if(n == 3)
	{
		total = a[1] + a[2] + a[3];
		ans1 = c(a[1]) + c(a[2]) + c(a[3]);
		total = 2 * a[1] + 2 * a[3] - a[2];
		ans2 = c(a[1]) + c(a[1] + a[3] - a[2]) + c(a[3]);
		printf("%.0lf",min(ans2,ans1) * n);
	}
	else if(n == 4)
	{
		find();
		printf("%.0lf",out * n);
	}
	
	return 0;
}

