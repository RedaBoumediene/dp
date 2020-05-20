#include<bits/stdc++.h>
using namespace std;
int n ,arr[1005];

int main(){

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];

    int k;
    cin>>k;
    bool dp[n+1][k+1];
    memset(dp,false,sizeof(dp));

    for(int i=0;i<=n;i++)
        dp[i][0]=true;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(arr[i]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
            }
        }
    }

    cout<<dp[n][k]<<endl;

    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }*/

return 0;}
