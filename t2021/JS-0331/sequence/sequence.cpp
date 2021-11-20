#include <bits/stdc++.h>
using namespace std;
int n=0,m=0,k=0;
int S=0;
int smin=0,smax=0;
int sp[100005],s2[100005],s3[100005];
int v[100005]; 
int m2[18]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
int onen(int s)
{ 
	int u=0;
	while(s>0)
	{
		if(s%2==0)
		{
			s/=2;
		}
		else
		{
			u++;
			s/=2;
		}
	} 
	return u;
}
int pqz(int u,int b,int c,int d,int e,int f,int g,int h)
{
	int r=1;
	for(int i=1;i<=u;i++)
		r*=v[0];
	for(int j=1;j<=b;j++)
		r*=v[1];
	for(int k=1;k<=c;k++)
		r*=v[2];
	for(int l=1;l<=d;l++)
		r*=v[3];
	for(int m=1;m<=e;m++)
		r*=v[4];
	for(int n=1;n<=f;n++)
		r*=v[5];
	for(int o=1;o<=g;o++)
		r*=v[6];
	for(int p=1;p<=h;p++)
		r*=v[7];
	return r;
 } 
int qz=0;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	{
		cin>>v[i];
	}
	smin=n;
	smax=n*m2[m];
	int a=1;
	for(int i=0;i<=17;i++)//枚举出S的可能值 
	{
		if(m2[i]>=smin && m2[i]<=smax && onen(m2[i])<=k)
		{
			sp[a]=m2[i];
			//cout<<"***"<<sp[a]<<"***"<<endl;
			s2[a]=onen(m2[i]);
			s3[a]=i;
			a++;
		}
	}
	a--;
	for(int i=1;i<=a;i++)//S有可能的数的枚举 
	{
		int to=0;
		for(int j=0;j<=n;j++)//0
		{
			to=0;
			to+=m2[0]*j;
			//cout<<"2^0??"<<j<<"??"<<to<<"??"<<"    "<<endl; 
			if(to<sp[a])
			
				for(int k=0;k<=n;k++)//1
				{
					to+=m2[1]*k;
					//cout<<"2^1??"<<k<<"??"<<to<<"??"<<"    "<<endl; 
					if(to<sp[a] &&m>1)
						for(int d=0;d<=n;d++)//2
						{
							to+=m2[2]*d;
							if(to<sp[a] && m>2)
								for(int e=0;e<=n;e++)//3
								{ 
									to+=m2[3]*e;
									if(to<sp[a] && m>3)
										for(int f=0;f<=n;f++)//4
										{
											to+=m2[4]*f;
											if(to<sp[a] && m>4)
												for(int g=0;g<=n;g++)//5
												{
													to+=m2[5]*g;
													if(to<sp[a] && m>5)
														for(int h=0;h<=n;h++)//6
														{
															to+=m2[6]*h;
															if(to<sp[a] && m>6)
																for(int l=0;l<=n;l++)//7
																{
																	to+=m2[7]*l;
																	if(to>sp[a] && m>7)
																	{
																		to-=m2[7]*l;
																		break;
																	}
																	if(to==sp[a] && j+k+d+e+f+g+h+l==n)
																	{
																		//cout<<endl<<"***l"<<endl;
																		to=0;
																		qz+=pqz(j,k,d,e,f,g,h,l);
																		qz*=n*j;
																	}
																	if(to==sp[a] && j+k+d+e+f+g+h+l!=n)
																	{
																		to=0;
																		break;
																	}
																}
															if(to>sp[a])
															{
																to-=m2[6]*h;
																break;
															}
															if(to==sp[a]&& j+k+d+e+f+g+h==n)
															{
																//cout<<endl<<"***h"<<endl;
																to=0;
																qz+=pqz(j,k,d,e,f,g,h,0);
																qz*=n*j;
															}
															if(to==sp[a]&& j+k+d+e+f+g+h!=n)
															{
																to=0;
																break;
															}
														}
													if(to>sp[a])
													{
														to-=m2[5]*g;
														break;
													}
													if(to==sp[a]&& j+k+d+e+f+g==n)
													{
														//cout<<endl<<"***g"<<endl;
														to=0;
														qz+=pqz(j,k,d,e,f,g,0,0);
														qz*=n*j;
													}
													if(to==sp[a]&& j+k+d+e+f+g!=n)
													{
														to=0;
														break;
													}
												}
											if(to>sp[a])
											{
												to-=m2[4]*f;
												break;
											}
											if(to==sp[a]&& j+k+d+e+f==n)
											{
												//cout<<endl<<"***f"<<endl;
												to=0;
												qz+=pqz(j,k,d,e,f,0,0,0);
												qz*=n*j;
											}
											if(to==sp[a]&& j+k+d+e+f!=n)
											{
												to=0;
												break;
											}
										}
									if(to>sp[a])
									{
										to-=m2[3]*e;
										break;
									}
									if(to==sp[a]&& j+k+d+e==n)
									{
										//cout<<endl<<"***e"<<endl;
										to=0;
										qz+=pqz(j,k,d,e,0,0,0,0);
										qz*=n*j;
									}
									if(to==sp[a]&& j+k+d+e!=n)
									{
										to=0;
										break;
									}
								}
							if(to>sp[a])
							{
								to-=m2[2]*d;
								break;
							}
							if(to==sp[a]&& j+k+d==n)
							{
								cout<<endl<<"***d"<<endl;
								to=0;
								qz+=pqz(j,k,d,0,0,0,0,0);
								qz*=n*j;
								break;
							}
							if(to==sp[a]&& j+k+d!=n)
							{
								to=0;
								break;
							}
						}
					if(to>sp[a])
					{
						to-=m2[1]*k;
						break;
					}
					if(to==sp[a]&& (j+k)==n)
					{
					//	cout<<endl<<"***k"<<endl;
						
						qz+=pqz(j,k,0,0,0,0,0,0);
						qz*=n*j;
						to=0;
						break;
					}
					if(to==sp[a]&& (j+k)!=n)
					{
						to=0;
						break;
					}
					to-=m2[1]*k;
				}
			if(to>sp[a])
			{
				to-=m2[0]*j;
				break;
			}
			if(to==sp[a]&& j==n)
			{
				//cout<<endl<<"***j"<<endl;
				qz+=pqz(j,0,0,0,0,0,0,0);
				qz*=n;
				to-=m2[0]*j;
				break;
			}
			if(to==sp[a]&& j!=n)
			{
				to-=m2[0]*j;
				break;
			}
			to-=m2[0]*j;
		}
	}
	cout<<qz<<endl;
	//cout<<a<<endl;
	//for(int i=1;i<=a;i++)
	//{
	//	cout<<sp[a]<<"   "; 
	//}
	return 0;
}
