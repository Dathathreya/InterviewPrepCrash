#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#define M (int)2e5+9
#pragma 
int min(int a,int b){return (a<=b)?(a):(b);}
int max(int a,int b){return (a>=b)?(a):(b);}
typedef long long unsigned llu;
typedef long long int lli ;

int mulmod(int a,int b,int mod){
        int mx = INT_MAX;
        if((a==0)||(b==0)) return 0;    
        if(a>=(mod/2)){
           a = a - mod;
        }
        if(b>=(mod/2)){
            b= b- mod;
        }
        long long int answer = 1ll*a*b;        
        answer %= mod;
        return answer;
}

int waysToBreakNumber(int N){
        int mod=(int)1e9+7;
        int A = (N%2==0)?(N-1):((N-1)/2);
        int B = (N%2==1)?(N-2):((N-2)/2);    
        
        int part1 = mulmod(A,B,mod)%mod;
        int part2 = (3+mulmod(N/2,6,mod)-3*(N%2==0))%mod;  
        //printf("part2:%d part1:%d\n",part2,part1);
        return (part1 + part2)%mod;
}

void solve(void){
    int n,i=1,answer=0;char x;
    //fscanf(stdin,"%d",&n);
    for(i=0;i<getsz(EscapeCharacters);i++){
        printf("%d ",EscapeCharacters[i]);
    }
    printf("\n");
    return;
}


int main(int argc,char* argv[]){
    int tt=1;
    //assert(fscanf(stdin,"%d",&tt)>0);
    // printf("%d %d",(int)('0'),(int)('9')); // alpha upper case , ascii lies in 65 to 90
    // alpha lower case , ascii lies in 97 to 122
    // number means 0-9 -> 48 57
    while(tt--){
        solve();
    }
    return 0-0;
}

