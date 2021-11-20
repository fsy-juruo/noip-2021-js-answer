#include<bits/stdc++.h>
using namespace std;

bool b[10000012]={0};
int i,j,T,tst,xm=0,ed=0;
deque <int> q[8];

int _pow(int x,int y)
{   int ans=1;
	for (int i=1;i<=y;i++) ans*=x;
	return ans;
}

void dis(int _bit)
{   int i,k,x;
	unsigned j;
	int _now;
	unsigned int _size=q[_bit-1].size();
	int h=_pow(10,_bit-1);
	for (i=0;i<=6;i++)
	{   _now=i*h;
		for (j=0;j<_size;j++)
		{   x=_now+q[_bit-1][j];
			q[_bit].push_front(x);
			if (b[x]) continue;
			for (k=1;k*x<=10000010;k++) b[k*x]=1;
		} 
	}
	
	for (i=8;i<=9;i++)
	{	_now=i*h;
		for (j=0;j<_size;j++)
		{   x=_now+q[_bit-1][j];
			q[_bit].push_front(x);
			if (b[x]) continue;
			for (k=1;k*x<=10000010;k++) b[k*x]=1;
		} 
	}
	
	_now=7*h;
	int ed=h-1;
	for (i=0;i<=ed;i++) 
	{   x=_now+i;
		q[_bit].push_front(x);
		if (b[x]) continue;
		for (k=1;k*x<=10000010;k++) b[k*x]=1;
	}
	
	return ;
}

int main()
{   freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	int a[T+1];
	q[1].push_front(7);
	for (i=1;i<=T;i++)
	{   scanf("%d",&a[i]);
		xm=max(xm,a[i]);
	}

	for (i=1;i<=10000010/7;i++) b[i*7]=1;
    while (xm)
    {   ++ed;
    	xm/=10;
	}
	ed=min(ed,7);
	for (i=2;i<=ed;i++) dis(i);
	
	for (i=1;i<=T;i++)
	{   if (b[a[i]]) printf("%d\n",-1);
	       else {  tst=a[i]+1;
	       		   while (b[tst]) tst++;
	       		   printf("%d\n",tst);
	            }
    } 
    /* for (i=1;i<=ed;i++)
      {  for (j=0;j<q[i].size();j++)cout<<q[i][j]<<' ';
      	cout<<endl;
	  }*/
    
    return 0;
}



/*#include<bits/stdc++.h>
using namespace std;

bool b[10000012]={0};
bool ispr[10000002]={0};
int pr[1000002]={0};
int i,j,T,tst,xm=0,ed=0;

bool ispr(int x)
{   for (int i=2;i<=x/i;i++) if (x%i==0) return 0;
	return 1;
}

int main()
{   //freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	scanf("%d",&T);
	int a[T+1];
	for (i=1;i<=T;i++)
	{   scanf("%d",&a[i]);
		xm=max(xm,a[i]);
	}
	pr[1]=2; ispr[2]=1;
    int l
}*/










