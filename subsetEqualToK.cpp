#include<bits/stdc++.h>
using namespace std;

int n,k,arr[100];

void solve1(){
    bool dp[n+1][k+1];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j<arr[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
            }
        }
    }
    cout<< ((dp[n][k])?"YES":"NO") <<endl ;
}

void solve2(){
    bool dp[k+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int curr_ele = arr[i];
        for(int j=k;j>=curr_ele;--j){
            if(dp[j]||dp[j-arr[i]]==0)
                continue;
            else
                dp[j] = 1;
        }
    }
    //for(int i=0;i<=k;i++)
    //    cout<<dp[i]<<' ';
    cout<< (dp[k]?"YES":"NO")<<endl;
}
void solve3(){
    int dp[k+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int curr_ele = arr[i];
        for(int j=k;j>=curr_ele;--j){
            if(dp[j]!=0 || dp[j-curr_ele]==0)
                continue;
            else
                dp[j] = curr_ele;
        }
    }
    if(dp[k]==0)
        cout<<-1<<endl;
    else{
        int curr = k;
        while(curr>0){
            cout<<dp[curr]<<" ";
            curr-=dp[curr];
        }
        cout<<endl;
    }
    /*for(int i=0;i<=k;i++)
        cout<<dp[i]<<" ";
    cout<<endl;*/
}
int main(){

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cout<<"number of querys ? \n";
    int t;cin>>t;
    while(t--){
        cin>>k;
        //solve1();
        //solve2();
        solve3();

    }

return 0;}
