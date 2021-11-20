#include<bits/stdc++.h>
using namespace std;

int T;

int las;
int nex[10000010];
bool flag[10000010];

int next_seven[10000010];
int a[]={0,1,2,3,4,5,6,8,9};

void seven() {
	next_seven[10000000]=10000007;
	
	for(int b=0;b<9;b++) {
		int bw=a[b];
		int num1=bw*1000000;
		
		for(int c=0;c<9;c++) {
			int sw=a[c];
			int num2=num1+sw*100000;
			
			for(int d=0;d<9;d++) {
				int w=a[d];
				int num3=num2+w*10000;
				
				for(int e=0;e<9;e++) {
					int q=a[e];
					int num4=num3+q*1000;
					
					for(int f=0;f<9;f++) {
						int b=a[f];
						int num5=num4+b*100;
						
						for(int g=0;g<9;g++) {
							int s=a[g];
							int num6=num5+s*10;
							
							num6+=7;
							
							if (s==6) next_seven[num6]=num6+3;
							else if (s==9&&b==6) next_seven[num6]=num6+3;
							else if (s==9&&b==9&&q==6) next_seven[num6]=num6+3;
							else if (s==9&&b==9&&q==9&&w==6) next_seven[num6]=num6+3;
							else if (s==9&&b==9&&q==9&&w==9&&sw==6) next_seven[num6]=num6+3;
							else if (s==9&&b==9&&q==9&&w==9&&sw==9&&bw==6) next_seven[num6]=num6+3;
							else next_seven[num6]=num6+10;
						}
						
						num5+=70;
						
						for(int g=0;g<=9;g++) {
							next_seven[num5+g]=num5+g+1;
						}
						
						next_seven[num5+9]+=7;
					}
					
					num4+=700;
					
					for(int f=0;f<=9;f++) {
						for(int g=0;g<=9;g++) {
							next_seven[num4+f*10+g]=num4+f*10+g+1;
						}
					}
					
					next_seven[num4+99]+=7;
				}
				
				num3+=7000;
				
				for(int e=0;e<=9;e++) {
					for(int f=0;f<=9;f++) {
						for(int g=0;g<=9;g++) {
							next_seven[num3+e*100+f*10+g]=num3+e*100+f*10+g+1;
						}
					}
				}
				
				next_seven[num3+999]+=7;
			}
			
			num2+=70000;
			
			for(int d=0;d<=9;d++) {
				for(int e=0;e<=9;e++) {
					for(int f=0;f<=9;f++) {
						for(int g=0;g<=9;g++) {
							next_seven[num2+d*1000+e*100+f*10+g]=num2+d*1000+e*100+f*10+g+1;
						}
					}
				}
			}
			
			next_seven[num2+9999]+=7;
		}
		
		num1+=700000;
		
		for(int c=0;c<=9;c++) {
			for(int d=0;d<=9;d++) {
				for(int e=0;e<=9;e++) {
					for(int f=0;f<=9;f++) {
						for(int g=0;g<=9;g++) {
							next_seven[num1+c*10000+d*1000+e*100+f*10+g]=num1+c*10000+d*1000+e*100+f*10+g+1;
						}
					}
				}
			}
		}
		
		next_seven[num1+99999]+=7;
	}
	
	int num=7000000;
	
	for(int b=0;b<=9;b++) {
		for(int c=0;c<=9;c++) {
			for(int d=0;d<=9;d++) {
				for(int e=0;e<=9;e++) {
					for(int f=0;f<=9;f++) {
						for(int g=0;g<=9;g++) {
							next_seven[num+b*100000+c*10000+d*1000+e*100+f*10+g]=num+b*100000+c*10000+d*1000+e*100+f*10+g+1;
						}
					}
				}
			}
		}
	}
	
	next_seven[7999999]+=7;
}

void init() {
	seven();
	
	for(int i=7;i<=10000000;i=next_seven[i]) {
		for(int j=1;j*i<=10000000;j++) {
			flag[i*j]=1;
		}
	}
	
	for(int i=1;i<=10000000;i++) {
		if (flag[i]==0) {
			nex[las]=i;
			las=i;
		}
	}
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	init();
	
	cin>>T;
	
	while(T--) {
		int x;
		cin>>x;
		
		if (flag[x]==1) cout<<-1<<'\n';
		else cout<<nex[x]<<'\n';
	}
	
	return 0;
}

