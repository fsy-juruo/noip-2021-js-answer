#include<iostream>
#include<cstdio>
using namespace std;
int inline read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int t,a[200010],m;
bool b[20000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++)
	{
		a[i]=read();
		m=max(m,a[i]);
	}
	if(m>1000000)m*=2;
	else m*=10;
  if(m>=7)
	for(int i=7;i<m;i+=10)
	{
		if(b[i]==0)
		    for(int j=1;j*i<=m;j++)b[i*j]=1;
	}
   if(m>70)
	for(int k=0;k<=9;k++)
	{
		if(k-7==0)k++;
		for(int i=70+k;i<m;i+=100)
		    if(b[i]==0)
		        for(int j=1;j*i<=m;j++)b[i*j]=1;
		    
	}
  if(m>700)
    for(int k=0;k<=99;k++)
    {
    	if((k/10)-7==0)k+=10;
    	if(k-7==0)k++;
    	for(int i=700+k;i<m;i+=1000)
		    if(b[i]==0)
		        for(int j=1;j*i<=m;j++)b[i*j]=1;
	}
  if(m>7000)
    for(int k=0;k<=999;k++)
    {
    	if((k/100)-7==0)k+=100;
    	if((k/10)-7==0)k+=10;
    	if(k-7==0)k++;
    	for(int i=7000+k;i<m;i+=10000)
		    if(b[i]==0)
		        for(int j=1;j*i<=m;j++)b[i*j]=1;
	}
  if(m>70000)
    for(int k=0;k<=9999;k++)
    {
    	if((k/1000)-7==0)k+=1000;
    	if((k/100)-7==0)k+=100;
    	if((k/10)-7==0)k+=10;
    	if(k-7==0)k++;
    	for(int i=70000+k;i<m;i+=100000)
		    if(b[i]==0)
		        for(int j=1;j*i<=m;j++)b[i*j]=1;
	}
  if(m>700000)
    for(int k=0;k<=99999;k++)
    {
    	if((k/10000)-7==0)k+=10000;
    	if((k/1000)-7==0)k+=1000;
    	if((k/100)-7==0)k+=100;
    	if((k/10)-7==0)k+=10;
    	if(k-7==0)k++;
    	for(int i=700000+k;i<m;i+=1000000)
		    if(b[i]==0)
		        for(int j=1;j*i<=m;j++)b[i*j]=1;
	}
  if(m>7000000)
    for(int k=0;k<=999999;k++)
    {
    	if((k/100000)-7==0)k+=100000;
    	if((k/10000)-7==0)k+=10000;
    	if((k/1000)-7==0)k+=1000;
    	if((k/100)-7==0)k+=100;
    	if((k/10)-7==0)k+=10;
    	if(k-7==0)k++;
    	for(int i=7000000+k;i<m;i+=10000000)
		    if(b[i]==0)
		        for(int j=1;j*i<=m;j++)b[i*j]=1;
	}
	for(int i=1;i<=t;i++)
	{
		if(b[a[i]]==1)cout<<"-1\n";
		else
		    for(int j=a[i]+1;;j++)
		    {
		    	if(b[j]==0)
		    	{
		    		cout<<j<<"\n";
		    		break;
				}
			}
	}
	return 0;
}
