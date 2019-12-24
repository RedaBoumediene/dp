#include <bits/stdc++.h>
#define debug(x) cout<<#x<<"="<<x<<endl;
using namespace std;


int subSolve(vector<int> &prices,int s,int e){
    int n=e-s;
    if(n<=1)
        return 0;
    int ans=prices[s+1]-prices[s];
    int minElement=min(prices[s],prices[s+1]);
    for(int i=s+2;i<e;i++){
        if(prices[i]-minElement>ans)
            ans=prices[i]-minElement;
        if(minElement>prices[i])
            minElement=prices[i];
        //debug(i);debug(ans);debug(minElement);
    }
    return ans;
}

int maxProfit(vector<int> &prices){
    int n=prices.size();
    if(prices.size()<=1)
        return 0;
    if(prices.size()==2)
        return max(prices[1]-prices[0],0);
    if(prices.size()==3)
        return max(max(prices[1]-prices[0],max(prices[2]-prices[0],prices[2]-prices[1])),0);

    vector<int> res(prices.size(),0);

    for(int i=1;i<n-2;i++){
        res[i]=subSolve(prices,0,i+1)+subSolve(prices,i+1,n);
    }
    int ans = subSolve(prices,0,n);
    for(int i=0;i<n;i++)
        ans=max(ans,res[i]);
    return ans;

}

int main(void) {

    vector<int> v{1,2,3,4,5};
    cout<<maxProfit(v);



	return 0;
}
