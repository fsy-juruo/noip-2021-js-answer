#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
bool is[200007];
int ans[200007];
int t[400007];
bool F(int x){
	bool f=true;
	while(x)
	{
		if(x%10==7)
		f=false;
		x/=10;
	}
}
int C(int x){
	int cnt=0;
	while(x){
		x/=10;
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	q.push(7);
	is[7]=1;
	while(q.top()<=20000){
	//	cout<<q.top()<<endl;
		int i=q.top();
		q.pop();
		if(!F(i)){
			int s;
			for(int j=0;j<=9;j++)
			{
			s=1;
			while(i*10*s+j<=200000){
			if(!is[i*10*s+j])
			{
			q.push(i*10*s+j);
			is[i*10*s+j]=true;
			}
			s*=10;
			}
			}
			for(int j=1;j<=9;j++){
				s=1;
				for(int t=1;t<=C(i);t++){
					s*=10;
				}
				while(i+s*j<=200000)
				{
				if(!is[i+j*s])
				{
				q.push(i+s*j);
				is[i+s*j]=true;
				
				}s*=10;
			}
		}
		}
		int k=1;
		while(k*i<=200000)
		{
		if(!is[i*k]){
		q.push(i*k);
		is[i*k]=true;
		}
		k++;
		}
	}
	int next=200000;
	for(int i=200000;i>=0;i--){
		if(is[i])
		ans[i]=-1;
		else
		{
		ans[i]=next;
		next=i;
		}
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cout<<ans[x]<<endl;
	}
	
}
