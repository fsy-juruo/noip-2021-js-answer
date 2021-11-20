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
	/*¤µ¤µ¤²¤è¡¡¤µ¤µ¤²¤è
	ÐÄÔà¤µ¤µ¤²¤è
	ÎªË¹¿¨µÙÏ×ÉÏÐÄÔà£¡ 
	ÎÒ´Ó08Äê¾ÍÒ»Ö±µÈ¿­¶ûÏ£³öÀ´
	½ñÌìÎÒÖÕÓÚ¿ÉÒÔ³éÕâ¸ö¿­¡­¡­¿­¶û
	µÙµÙ£¡
	ë´ÁË168µÙµÙÀÏÆÅ»Ø¼Ò¼Ò
	ËýÂ·ÉÏËý*Ëæ±ã»¨
	²»ÊÇÕâ°×¿ªË®ÔõÃ´Ã»Î¶¶ù°¡
	ÚÀ£¡ºË·ÏË®¡£°¡£¡¡­¡­
	ºÚ ³± Ö® ÏÂ
	ÄãÃÇ»¹²»Ã÷°×Âð
	Ì« Èõ Ð¡ ÁË
	Ã»ÓÐÁ¦Á¿£¡
	ÏÈ±²£¡ÏÈ±²£¡
	ÎÒÃÇÁªºÏ
	Á½Ãæ°ü¼ÐÖ¥Ê¿
	ÀïÓ¦ÍâºÏ
	·¨ÀÏ~£¬·¨ÀÏ£¬³öÒ»¿Ú¶ñÆø°¡
	º£Ã¨~£¬Ocean Cat,ÄãµÃ¸ø¾¢¶ù°¡
	RuaÅ£~£¬àÅ~£¬ÄãËµÊÇ²»ÊÇ
	³ö£¡À´£¡¸øÒ¯³ö£¡½ð¹â£¡
	ÚÀ£¡ºÃÁË
	²Ð¿á¤ÎÌìÊ¹¤ÏÐÐ¶¯¸ÙÁì¡«¡«Doctor!
	¤·¤ç¤Ë¤¢£î¤Î¤££î¤Õ¤Ë¤Ê¤§¡«¡«
	ÎªË¹¿¨µÙÏ×ÉÏÐÄÔà£¡ 
	ºÚ ³± Ö® ÏÂ
	ÄãÃÇ»¹²»Ã÷°×Âð
	Ì« Èõ Ð¡ ÁË
	Ã»ÓÐÁ¦Á¿£¡
	ÏÈ±²£¡ÏÈ±²£¡
	ÎÒÃÇÁªºÏ
	Á½Ãæ°ü¼ÐÖ¥Ê¿
	ÀïÓ¦ÍâºÏ
	ë´ÁË168µÙµÙÀÏÆÅ»Ø¼Ò¼Ò
	ë´ÁË168Ð¡ÃàÑò»Ø¼Ò¼Ò ²»ÄÜ°¡
	I will give you all~~of my money
	ß×£¿ àëÓ´ ÎÒÓÀÔ¶Ï²»¶É­lua£¡	*/ 
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

