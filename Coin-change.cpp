#include<bits/stdc++.h>
using namespace std;
const int N = 11;
int arr[N]={5,10,20,50,100,200,500,1000,20000,50000,10000};
long long dp[12][300000],memo[12][300000];
int x;

// Using Memoisation
long long nWays(int indx,int rem){
    if(memo[indx][rem]!=-1)
        return memo[indx][rem];
    if(rem==0)
        return 1;
    if(indx==N || rem-arr[indx]<0)
        return 0;
    return memo[indx][rem] = nWays(indx+1,rem)+nWays(indx,rem-arr[indx]);
}

//using DP
long long nWaysDP1(int x){
    for(int i=0;i<11;i++)
    dp[i][0]=1;

    for(int coin=arr[0];coin<300000;coin+=5){
        for(int j=0;j<11;j++){
            if(j)
                dp[j][coin]=dp[j-1][coin];
            if(coin-arr[j]>=0)
                dp[j][coin] += dp[j][coin-arr[j]];
        }
    }
    return dp[10][x];
}

int main(){
    memset(memo,-1,sizeof(memo));
    cin>>x;

    cout<<nWays(0,x)<<"  "<<nWaysDP1(x)<<endl;


    return 0;
}
