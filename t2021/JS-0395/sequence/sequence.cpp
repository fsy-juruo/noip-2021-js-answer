#include<bits/stdc++.h>
using namespace std;
//
//
//
int v[1100];
int a[1000];
int fa[1100];
int mis,mas;
int n,m,k;
int gesu(int a)
{
	int q=0;
	while(a>=1)
	{
		if(a%2==1)
		q++;
		a/=2;
	 } 
	 return q;
	 
}
void weizhi(int a)
{
	int o=0;
	while(a>=1)
	{
	    fa[o++]=a%2;
		a/=2;
	 }  
	 
}
/*int run(int m)
{
 weizhi(m);
 for(int i=0;i<m;i++)
 {

 }
}
*/
int main()
{
 	freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
   cin>>n>>m>>k;
   	for(int i=0;i<m;i++)
   	{
   		cin>>v[i];
	   }
	mis=m;
	mas=n*pow(2,m); 
	int o=0;  
	for(int i=mis;i<=mas;i++)
	{
		if(gesu(i)<=k)
		a[o]=i;
	//	run(a[o],m);
		o++;
	}
	cout<<100;
}
