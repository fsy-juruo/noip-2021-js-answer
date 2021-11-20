#include <bits/stdc++.h>

int main()
{	
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n,a[10050];
	scanf("%d",&n);
	long long lsum=0,rsum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		lsum += a[i]*a[i],rsum += a[i];
	}
	bool ok=true;
	while(ok)
	{
		ok=false;
		for(int i=1;i<n-1;i++)
		{
			int x=a[i-1]+a[i+1]-a[i];
			if((lsum+(x+a[i])*(x-a[i]))*n-(rsum+x-a[i])*(rsum+x-a[i])<lsum*n-rsum*rsum)
			{
				ok=true;
				lsum += (x+a[i])*(x-a[i]);
				rsum += x-a[i];
				a[i]=x;
			}
		}
	}
	printf("%lld\n",lsum*n-rsum*rsum); // ans=n*sum(ai^2)-sum(ai)^2
	return 0;
}

/*
	while(ok)
	{
		ok=false;
		for(int i=1;i<n-1;i++)
		{
			long long res=lsum*n-rsum*rsum;
			int jj=-1,kk=-1;
			
			for(int j=0;i-j>0;j++)
				for(int k=0;i+k<n;k++)
				{
					int x=a[i-j+1]+a[i+k+1]-a[i-j]-a[i+k]+a[i];
					if((lsum+(x+a[i])*(x-a[i]))*n-(rsum+x-a[i])*(rsum+x-a[i])<res)
					{
						res=(lsum+(x+a[i])*(x-a[i]))*n-(rsum+x-a[i])*(rsum+x-a[i]);
						jj=j,kk=k;
					}
				}
			
			if(~kk)
			{	
				int x=a[i-jj+1]+a[i+kk+1]-a[i-jj]-a[i+kk]+a[i];
				lsum += (x+a[i])*(x-a[i]);
				rsum += x-a[i];
				for(int j=i-jj;j<i;j++)
					a[j]=a[j-1]+a[j+1]-a[j];
				for(int j=i+kk;j>i;j--)
					a[j]=a[j-1]+a[j+1]-a[j];
				a[i]=a[i-1]+a[i+1]-a[i];
				ok=true;
			}
		}
	}
*/
