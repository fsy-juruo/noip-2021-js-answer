#include<bits/stdc++.h>
using namespace std;
int n,a[101],b[5010];
void cx(int x)
{	if(b[x]==-1) cx(x+1);
	else cout<<x<<endl;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(b,0,sizeof(b));
	cin>>n;
	for(int i=1;i<=140;i++){
		b[i*7]=-1;
		b[(i-1)*17]=-1;
		b[(i-1)*27]=-1;
	}
	for(int i=1;i<=30;i++){
		b[i*37]=-1;
		b[(i-1)*47]=-1;
	}
	for(int i=1;i<=20;i++){
		b[57*i]=-1;
		b[67*(i-1)]=-1;
		b[77*i]=-1;
		b[87*i]=-1;
		b[97*i]=-1;
	}	
	for(int i=1;i<=14;i++){
		b[i*70]=-1;
		b[(i-1)*170]=-1;
	}
	for(int i=1;i<=3;i++){
		b[i*270]=-1;
		b[(i-1)*370]=-1;
	}
	for(int i=1;i<=2;i++){
		b[i*470]=-1;
	}
	for(int i=5;i<=9;i++)
		b[100*i+70]=-1;
	for(int i=0;i<100;i++)
		b[700+i]=-1;
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
		b[i*100+70+j]=-1;
	for(int i=2;i<=15;i++)
		for(int j=0;j<=9;j++)
			b[(70+j)*i]=-1;
	for(int i=1;i<=9;i++)	
		for(int k=0;k<=9;k++)
			b[i*100+k*10+7]=-1;
	for(int i=1;i<=9;i++)	
		for(int k=0;k<=9;k++)
			b[i*100+70+k]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==-1) cout<<-1<<endl;
		else {
			cx(a[i]+1);
			}
	}
	return 0;
}
