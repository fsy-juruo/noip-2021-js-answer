#include<bits/stdc++.h>
#define maxn 100007
using namespace std;
char m[3000];
int a1,a2,b1,b2,xx=0;
string s[maxn];
vector<string> k1;
vector<string> k2;
int l=0,r=0;
int quick_get()
{
	int num=0;
	char ch='0';
	while(ch!='\n'&&ch!=' ')
	{
		ch=getchar();
		num=num*10+(ch-'0');
	}
	num=num-(ch-'0');
	return num/10;
}
int deal(int num){
	int n=0,m=0;
	while(num>0){
		m=num%10;
		num/=10;
		n+=m;
		n*=10;
	}
	return n/10;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n=quick_get();
	int a[n+10];
	int b[n+10];
	for(int i=1;i<=n;i++){
		a[i]=quick_get()*n;
		a1+=a[i];
		m[xx++]='*';
		int ctf=a[i];
		while(ctf>0){
			m[xx++]=ctf%10+'0';
			ctf/=10;
		}
	}
	a1/=n;
	for(int i=1;i<=n;i++){
		a2+=(a[i]-a1)*(a[i]-a1);
	}
	a2/=n;
	k1.push_back(m);
	s[l]=m;
	while((l<r)||((l==r)&&(l==0))){
		int leng=s[l].size();
		char head[leng];
		for(int i=0;i<leng;i++) head[i]=s[l][i];
		l++;
		int x=0;
		for(int i=1;i<=n;i++){
			int num=0;
			while(head[x]=='*'&&x<leng){
				x++;
			}
			while(head[x]!='*'&&x<leng){
				num*=10;
				num+=head[x]-'0';
				x++;
			}
			b[i]=deal(num);
		}
		for(int ictf=2;ictf<=n-1;ictf++){
			b[ictf]=b[ictf-1]+b[ictf+1]-b[ictf];
			xx=0;
			for(int i1=1;i1<=n;i1++){
				b1+=b[i1];
				m[xx++]='*';
				int ctf=b[i1];
				while(ctf>0){
					m[xx++]=ctf%10+'0';
					ctf/=10;
				}
			}
			b1/=n;
			for(int i2=1;i2<=n;i2++){
				b2+=(b[i2]-b1)*(b[i2]-b1);
			}
			b2/=n;
			a2=min(a2,b2);
			bool flag=true;
			while(!k1.empty())
			{
				string mn=k1.front();
				k1.pop_back();
				k2.push_back(mn);
				int c[n+10];
				leng=mn.size();
				int x=0;
				for(int i=1;i<=n;i++){
					int num=0;
					while(mn[x]=='*'&&x<leng){
						x++;
					}
					while(mn[x]!='*'&&x<leng){
						num*=10;
						num+=mn[x]-'0';
						x++;
					}
					c[i]=deal(num);
				}
				bool flagg=true;
				for(int jkl=1;jkl<=n;jkl++){
					if(c[jkl]!=b[jkl]) flagg=false;
				}
				if(flagg==true) flag=false;
			}
			while(!k2.empty())
			{
				string mn=k2.front();
				k2.pop_back();
				k1.push_back(mn);
			}
			if(flag == true){
				s[++r]=m;
				k1.push_back(m);
			}
			b[ictf]=b[ictf-1]+b[ictf+1]-b[ictf];
		}
	}
	cout<<a2<<"\n";
	return 0;
} 
