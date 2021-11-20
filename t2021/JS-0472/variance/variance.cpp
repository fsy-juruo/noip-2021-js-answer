#include<bits/stdc++.h>
using namespace std;
int n,ans=99999999;
int varia4(int a,int b,int c,int d)
{
	return ((3*a-b-c-d)*(3*a-b-c-d)+(3*b-a-c-d)*(3*b-a-c-d)+(3*c-a-b-d)*(3*c-a-b-d)+(3*d-a-b-c)*(3*d-a-b-c))/4;
}
int varia3(int a,int b,int c)
{
	return ((2*a-b-c)*(2*a-b-c)+(2*b-a-c)*(2*b-a-c)+(2*c-b-a)*(2*c-b-a))/3;
}
int varia2(int a,int b)
{
	return (a-b)*(a-b);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	if (n==4)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ans=min(ans,varia4(a,b,c,d));
		ans=min(ans,varia4(a,a+c-b,c,d));
		ans=min(ans,varia4(a,a+c-b,a+d-b,d));
		ans=min(ans,varia4(a,a+d-c,a+d-b,d));
		ans=min(ans,varia4(a,a+d-c,b-c+d,d));
		ans=min(ans,varia4(a,b,b-c+d,d));
		cout<<ans;
	}
	if (n==3)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ans=min(ans,varia3(a,b,c));
		ans=min(ans,varia3(a,a+c-b,c));
		cout<<ans;
	}
	if (n==2)
	{
		int a,b;
		cin>>a>>b;
		cout<<(varia2(a,b));
	}
	if (n==1)
	{
		int a;
		cin>>a;
		cout<<0;
	}
	return 0;
}
/*
We are no strangers to love
You know the rules and so do I
A full conmmiment's what I am thinking of
You wouldn't get this from any other guys
I just wanna tell you how I'm feeling
Gotta make you understand
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you
We have known each other for so long
Your heart's been aching but you're too shy to say it
Inside we both know what's been going on
We both know the game and we're gonna play it
And if you ask me how I'm feeling
Don't tell me you're too blind to see
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you
Oooooooooooooo Give you up
Oooooooooooooo Give you up
Never gonna give never gonna give  give you up
Never gonna give never gonna give  give you up
We have known each other for so long
Your heart's been aching but you're too shy to say it
*/
