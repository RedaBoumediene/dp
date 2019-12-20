#include <iostream>
using namespace std;
int countSubstrings(string s) {
    int n=s.size() , ans=0 ;
    bool dp[n][n]={false};

    for(int i=0;i<n;i++)
        dp[i][i]=true , ans++;

    for(int taille=2;taille<=n;taille++){
        for(int i=0;i<=n-taille;i++){
            int j=taille+i-1;
            if(s[i]==s[j]){
                if(taille==2){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=dp[i+1][j-1];
                }
            }
            else{
                dp[i][j]=false;
            }
            if(dp[i][j])
                ans++;
        }
    }

    return ans;
}
int main() {

    string s;cin>>s;

    cout<<countSubstrings(s);



    return 0;
}
