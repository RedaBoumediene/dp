#include<bits/stdc++.h>
using namespace std;

int maxProfit(int k,vector<int> &prices){
    int n=prices.size();
    if(n<=1 || k==0)
        return 0;
    if(n==2)
        return max(prices[1]-prices[0],0);

    int dp[k+1][n];
    memset(dp,0,sizeof(dp));

    int ans = max(prices[1]-prices[0],0);
    int minElement = min(prices[0],prices[1]);
    for(int i=2;i<n;i++){
        if(ans < prices[i] - minElement)
            ans = prices[i] - minElement;
        if(minElement > prices[i])
            minElement = prices[i];
        dp[1][i]= ans;
    }

    for(int i=2;i<=k;i++){
        for(int j=0;j<n;j++){
            ans = 0;    // INT_MIN
            for(int l=0;l<j;l++){
                ans = max(ans,prices[j]-prices[l]+dp[i-1][l]);
            }
            dp[i][j]=max(dp[i][max(j-1,0)],ans);
        }
    }
    /*for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }*/
    return dp[k][n-1];
}

int main(){

    int k=4;
    vector<int> v {1,2,4,2,5,7,2,4,9,0};
    cout<<maxProfit(k,v);

return 0;
}
