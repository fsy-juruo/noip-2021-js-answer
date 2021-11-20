#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

int const N1 = 10000105;

int const N2 = 200010;

bool mem[N1];
int nxt[N1];

int que[N2];

inline void read(int &x){
    x = 0;
    char c = getchar();
    int f = 1;
    while(!isdigit(c)){ if(c=='-') f=-1; c = getchar();}
    while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
    x *= f;
}

inline bool check(int x){
    while(x > 0){
        if (x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}

int T;

int mx = 0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    read(T);
    for(int i = 1;i <= T;++i){
        read(que[i]);
        mx = max(mx,que[i]);
    }

    int N = mx + 100;

    for(int i = 1;i < N;++i){
        mem[i] = check(i);
    }

    for(int i = 1;i < N;++i){
        if(!mem[i]) continue;
        for(int j = 1;j * i < N;++j){
            mem[i*j] = 1;
        }
    }
    
    int lst;
    int i;
    for(i = N-1;i >= 1;--i){
        if(mem[i] == 0){
            lst = i;
            nxt[i] = -1;
            break;
        }
    }
    for(i;i >= 1;--i){
        if(mem[i] == 0){
            nxt[i] = lst;
            lst = i;
        }
    }
    
    for(int i = 1;i <= T;++i){
        if(mem[que[i]]) puts("-1");
        else{
            printf("%d\n",nxt[que[i]]);
        }
    }

    return 0;
}