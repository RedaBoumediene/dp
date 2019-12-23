#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+1;
int n,arr[N];

int MaximumProfitOneSelBuyOneTime(int arr[],int n){
    int ans=arr[1]-arr[0];
    int minElement = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]-minElement>ans)
            ans = arr[i] - minElement;
        if(minElement>arr[i])
            minElement=arr[i];
    }
    return ans;
}

vector<pair<int,int> > MaxProfit(int arr[],int n){
    vector<pair<int,int> > ans;
    int i=0;
    if(n==1)
        return ans;
    while(i<n-1){
        while((i<n-1)&&arr[i]>=arr[i+1])
            i++;
        if(i==n-1)
            return ans;
        int buyThis=i++;
        while((i<n)&&(arr[i]>=arr[i-1]))i++;
        int sellThis=i-1;
        ans.push_back(make_pair(buyThis,sellThis));
    }
}

int main() {
    int t;cin>>t;
    vector<pair<int,int> > ans;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        ans=MaxProfit(arr,n);
        int mx=0;
        for(int i=0;i<ans.size();i++)
            mx+=(arr[ans[i].second]-arr[ans[i].first]);
        cout<<"Maximum Profit Buy and Sell one time "<<MaximumProfitOneSelBuyOneTime(arr,n)<<endl;
        cout<<"Maximum Profit Buy and Sell diff time "<<mx<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<"buy at day "<<ans[i].first<<" profit="<<arr[ans[i].first]<<",sell at"<<ans[i].second<<" profit="<<arr[ans[i].second]<<endl;
        cout<<endl;

    }

    return 0;
}
