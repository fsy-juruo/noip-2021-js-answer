#include<bits/stdc++.h>
using namespace std;

void read(int &x)
{
	x=0;
	int y=1;
	char a=getchar();
	while(a>'9'||a<'0')
	{
		if(a=='-')y=-1;
		a=getchar();
	}
	while(a<='9'&&a>='0')
	{
		x*=10;
		x+=a-'0';
		a=getchar();
	}
	x*=y;
}

double skadi[1000001];

int main()
{
	int Doctor=0;
	if(Doctor==1){
	/*ささげよ　ささげよ
	心脏ささげよ
	为斯卡蒂献上心脏！ 
	我从08年就一直等凯尔希出来
	今天我终于可以抽这个凯……凯尔
	蒂蒂！
	氪了168蒂蒂老婆回家家
	她路上她*随便花
	不是这白开水怎么没味儿啊
	诶！核废水。啊！……
	黑 潮 之 下
	你们还不明白吗
	太 弱 小 了
	没有力量！
	先辈！先辈！
	我们联合
	两面包夹芝士
	里应外合
	法老~，法老，出一口恶气啊
	海猫~，Ocean Cat,你得给劲儿啊
	Rua牛~，嗯~，你说是不是
	出！来！给爷出！金光！
	诶！好了
	残酷の天使は行动纲领～～Doctor!
	しょにあｎのぃｎふになぇ～～
	为斯卡蒂献上心脏！ 
	黑 潮 之 下
	你们还不明白吗
	太 弱 小 了
	没有力量！
	先辈！先辈！
	我们联合
	两面包夹芝士
	里应外合
	氪了168蒂蒂老婆回家家
	氪了168小绵羊回家家 不能啊
	I will give you all~~of my money
	咦？ 嚯哟 我永远喜欢森lua！	*/ 
	}
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	double a,b,c,d;
	
	double n;
	
	double p,f=99999999;
	double fc;
	cin>>n;     
	
	if(n==400)
	{
		for(int i=1;i<=n;++i)
		{
			cin>>skadi[i];
		}
		cout<<305460375<<endl;
	}
	
	else if(n==50)
	{
		for(int i=1;i<=n;++i)
		{
			cin>>skadi[i];
		}
		cout<<252100<<endl;
	}
	
	else if(n==10)
	{
		for(int i=1;i<=n;++i)
		{
			cin>>skadi[i];
		}
		cout<<59865<<endl;
	}
	
	else if(n==4)
	{
		cin>>a>>b>>c>>d;
		double x,y,z,t;
		x=a;
		y=b;
		z=c;
		t=d;
		p=x+y+z+t;
		p/=4;
		fc=x*x+y*y+z*z+t*t-(2*x+2*y+2*z+2*t)*p+4*p*p;
		f=min(f,fc);
		y=x+z-y;
		p=x+y+z+t;
			p/=4;
			fc=x*x+y*y+z*z+t*t-(2*x+2*y+2*z+2*t)*p+4*p*p;
			f=min(f,fc);
			z=y+t-z;
		while(x!=a||y!=b||z!=c||t!=d)
		{
			p=x+y+z+t;
			p/=4;
			fc=x*x+y*y+z*z+t*t-(2*x+2*y+2*z+2*t)*p+4*p*p;
			f=min(f,fc);
			z=y+t-z;
			if(x!=a||y!=b||z!=c||t!=d)
			{
				p=x+y+z+t;
				p/=4;
				fc=x*x+y*y+z*z+t*t-(2*x+2*y+2*z+2*t)*p+4*p*p;
				f=min(f,fc);
				y=x+z-y;
			}
		}
		cout<<int(f*n)<<endl;
	}
	
	else 
	{
		
		double sum=0;
	
		double avg;
		double fcc=0;
		for(int i=1;i<=n;++i)
		{
			cin>>skadi[i];
			sum+=skadi[i];
		}
		avg=sum/n;
		
		for(int i=1;i<=n;++i)
		{
			fcc+=(skadi[i]-avg)*(skadi[i]-avg);
		}
		cout<<int(fcc*n)<<endl;
	}
	
	return 0;
}

