#include<bits/stdc++.h>
#define N 10000005
using namespace std;
int anss[10000005],t[10000005],j,k,i=1  ;
void pr()
{
	int i2,i3,i4,i5,i6,i7;
for(i2=0;i2<=9;i2++)
for(i3=0;i3<=9;i3++)
for(i4=0;i4<=9;i4++)
	for(i5=0;i5<=9;i5++)
	for(i6=0;i6<=9;i6++)
	for(i7=0;i7<=9;i7++)
	{
		j=7+i2*10+i3*100+i4*1000+i5*10000+i6*100000+i7*1000000;
	if(t[j]==1)
	continue;
	k=1;
	while(j*k<=N)
		{
			t[j*k]=j;
			k++;
		}
		}

for(i2=0;i2<=9;i2++)
	for(i3=0;i3<=9;i3++)
	for(i4=0;i4<=9;i4++)
	for(i5=0;i5<=9;i5++)
	for(i6=0;i6<=9;i6++)
	for(i7=0;i7<=9;i7++)
	{
		j=i2+7*10+i3*100+i4*1000+i5*10000+i6*100000+i7*1000000;
	if(t[j]==1)
	continue;
	k=1;
	while(j*k<=N)
		{
			t[j*k]=j;
			k++;
		}
		}
for(i2=0;i2<=9;i2++)
	for(i3=0;i3<=9;i3++)
	for(i4=0;i4<=9;i4++)
	for(i5=0;i5<=9;i5++)
	for(i6=0;i6<=9;i6++)
	for(i7=0;i7<=9;i7++)
	{
		j=i2+i3*10+7*100+i4*1000+i5*10000+i6*100000+i7*1000000;
	if(t[j]==1)
	continue;
	k=1;
	while(j*k<=N)
		{
			t[j*k]=j;
			k++;
		}
		}
		for(i2=0;i2<=9;i2++)
	for(i3=0;i3<=9;i3++)
	for(i4=0;i4<=9;i4++)
	for(i5=0;i5<=9;i5++)
	for(i6=0;i6<=9;i6++)
	for(i7=0;i7<=9;i7++)
	{
		j=i2+i3*10+i4*100+7*1000+i5*10000+i6*100000+i7*1000000;
	if(t[j]==1)
	continue;
	k=1;
	while(j*k<=N)
		{
			t[j*k]=j;
			k++;
		}
		}
		for(i2=0;i2<=9;i2++)
	for(i3=0;i3<=9;i3++)
	for(i4=0;i4<=9;i4++)
	for(i5=0;i5<=9;i5++)
	for(i6=0;i6<=9;i6++)
	for(i7=0;i7<=9;i7++)
	{
		j=i2+i3*10+i4*100+i5*1000+7*10000+i6*100000+i7*1000000;
	if(t[j]==1)
	continue;
	k=1;
	while(j*k<=N)
		{
			t[j*k]=j;
			k++;
		}
		}
		for(i2=0;i2<=9;i2++)
	for(i3=0;i3<=9;i3++)
	for(i4=0;i4<=9;i4++)
	for(i5=0;i5<=9;i5++)
	for(i6=0;i6<=9;i6++)
	for(i7=0;i7<=9;i7++)
	{
		j=i2+i3*10+i4*100+i5*1000+i6*10000+7*100000+i7*1000000;
	if(t[j]==1)
	continue;
	k=1;
	while(j*k<=N)
		{
			t[j*k]=j;
			k++;
		}
		}

for(i2=0;i2<=9;i2++)
	for( i3=0;i3<=9;i3++)
	for( i4=0;i4<=9;i4++)
	for( i5=0;i5<=9;i5++)
	for(i6=0;i6<=9;i6++)
	for(i7=0;i7<=9;i7++)
	{
		j=i2+i3*10+i4*100+i5*1000+i6*10000+i7*100000+7*1000000;
	if(t[j]==1)
	continue;
	k=1;
	while(j*k<=N)
		{
			t[j*k]=j;
			k++;
		}
		}
	
	i=10000000;
	int temp=10000001;	
while(i>=1)
{
if(t[i])
{ i--;
	continue;
}
anss[i]=temp;
temp=i;
i--;
}

return ;
}

int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
pr();

int T,a;
scanf("%d",&T);
while(T--)
{
	scanf("%d",&a);
	if(anss[a]==0||a%7==0)
	{
		printf("%d\n",-1);
	continue;
	}
	printf("%d\n",anss[a]);
}
	return 0;
}
