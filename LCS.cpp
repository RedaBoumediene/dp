#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int dp[N][N],memo[N][N];
int n,m;

//using memoisaton
int LCS(string s,string t,int n,int m){
    if(memo[n][m]!=-1)
        return memo[n][m];
    if(n==0||m==0)
        return memo[n][m] = 0;
    if(s[n-1]==t[m-1])
        return memo[n][m] = 1+LCS(s,t,n-1,m-1);
    return memo[n][m] = max(LCS(s,t,n-1,m),LCS(s,t,n,m-1));
}

//using DP
void LCSdp(string s,string t,int n,int m){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else{
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
}

//Get one LCS
string getOneLCS(string s,string t){
    string res;
    int taille = dp[n][m];
    int i=n,j=m;
    while(taille){
        if(s[i-1]==t[j-1]){
            res = s[i-1] + res;
            taille--;
            i--;j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    return res;
}

//Get All LCS
set<string> getAllLCS(string s,string t,int n,int m){
    set<string> ans;
    if(n==0||m==0){
        ans.insert("");
        return ans;
    }

    if(s[n-1]==t[m-1]){
        set<string> tmp = getAllLCS(s,t,n-1,m-1);
        for(auto x:tmp){
            ans.insert(x+s[n-1]);
        }
    }
    else{
        if(dp[n-1][m]>=dp[n][m-1]){//can be from TOP side of the Matrix
            set<string> tmp = getAllLCS(s,t,n-1,m);
            for(auto x:tmp){
                ans.insert(x);
            }
        }
        //ELSE will be error !!!!
        if(dp[n][m-1]>=dp[n-1][m]){//can be from Left side of the Matrix
            set<string> tmp = getAllLCS(s,t,n,m-1);
            for(auto x:tmp){
                ans.insert(x);
            }
        }
        //dont to forget to merge :-) Left or Top
    }
}

int LCSwithAtmostKchanges(int a[],int b[],int n,int m,int k){
    int dp[k+1][n+1][m+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[0][i][j]=dp[0][i-1][j-1]+1;
            }
            else{
                dp[0][i][j] = max(dp[0][i-1][j],dp[0][i][j-1]);
            }
        }
    }

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                if(a[j-1]!=b[l-1]){
                    dp[i][j][l] = max(dp[i-1][j-1][l-1]+1,max(dp[i-1][j][l-1],dp[i-1][j-1][l]));
                }
                else
                    dp[i][j][l] = max(max(dp[i][j-1][l],dp[i][j][l-1]),dp[i][j-1][l-1]+1);
            }
        }
    }

    return dp[k][n][m];
}


int main(){
    memset(memo,-1,sizeof(memo));
    string s,t;
    cin>>s>>t;
    n=s.size(),m=t.size();

    //Filling table dp
    LCSdp(s,t,s.size(),t.size());

    cout<<"Lenght of LCS using memoistion : "<<LCS(s,t,n,m)<<endl;
    cout<<"Lenght of LCS using DP : "<<dp[n][m]<<endl;
    cout<<"One LCS : "<<getOneLCS(s,t)<<endl<<endl;
    cout<<"All LCS : "<<endl;
    set<string> rere = getAllLCS(s,t,n,m);
    for(auto x : rere)
        cout<<x<<endl;

return 0;}
