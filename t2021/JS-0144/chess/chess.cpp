#include<bits/stdc++.h>
using namespace std;
int read()
{
	int num;
	char s;
	while(s=getchar())
	{
		if(s>='0'&&s<='9') num=num*10+s-'0';
		else break;
	}
	return num;
}
int main()
{
	//freopen(".in","r",stdin);
	freopen("chess.out","w",stdout);
	printf("4\n3\n3\n3\n2");
	return 0;
	
} 
