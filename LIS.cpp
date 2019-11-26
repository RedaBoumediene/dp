/***************************
    Not Finished yet !!!
*****************************/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+3;
const int MaxELe=303;
int a[N],n;

int dp[N][MaxELe];

/*
int LIS(int i,int lastIndx){
    if(i>n)
        return 0;
    if(dp[i][lastIndx]!=-1)
        return dp[i][lastIndx];
    int ans1 = LIS(i+1,lastIndx),ans2=0;
    if(a[i]>a[lastIndx])
        ans2=LIS(i+1,i)+1;
    return dp[i][lastIndx] = max(ans1,ans2);
}
*/

int LISmemo(int i,int lastEle){
    if(i>n)
        return 0;
    if(dp[i][lastEle]!=-1)
        return dp[i][lastEle];
    int ans1 = LISmemo(i+1,lastEle),ans2=0;
    if(a[i]>lastEle)
        ans2 = LISmemo(i+1,a[i])+1;
    return dp[i][lastEle] = max(ans1,ans2);
}




int LIS(vector<int> const & a){
    int n=a.size();
    const int INF = 1e9;
    vector<int> d(n+1,INF);
    d[0]=-INF;

    for(int i=0;i<n;i++){
        int indx = lower_bound(d.begin(),d.end(),a[i])-d.begin();
            d[indx]=a[i];
    }
    int ans = 0;
    for(int i=0;i<=n;i++)
        if(d[i]<INF)
            ans = i;

    return ans;
}

int main(){
    vector<int> a;
    int n;cin>>n;
    for(int x,i=0;i<n;i++)
        cin>>a[i];

    int ls = LIS(a);

    cout<<"LIS : "<<ls<<endl;


return 0;
}
