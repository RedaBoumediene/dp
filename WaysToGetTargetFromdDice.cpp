#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
/*
 You have d dice, and each die has f faces numbered 1, 2, ..., f.
 Return the number of possible ways (out of fd total ways) 
 modulo 10^9 + 7 to roll the dice so the sum of the face up 
 numbers equals target.
*/

int numRollsToTarget(int d, int f, int target) {
       if(d==0||f==0||target==0||d*f<target)
		return 0;
		
		int dp[d+1][target+1];
		memset(dp,0,sizeof(dp));
		
		for(int i=1;i<=target && i<=f ;i++)
			dp[1][i]=1;
		
		for(int i=2;i<=d;i++){
			for(int j=1;j<=target && j<=f*i ;j++){
				for(int k=1;k<=f;k++){
					if(j-k>0)
						dp[i][j] = (dp[i][j]+dp[i-1][j-k])%MOD;
				}
							
			}
		}
		
		
		
		return dp[d][target];
}


int main(){
	
	cout<< numRollsToTarget(30,30,500) <<endl;
	
	return 0;
}
