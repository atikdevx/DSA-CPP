// Section-->C
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string s1,s2,s3;
    int n=s1.length();
    int m=s2.length();
    cin>>s1>>s2>>s3;
    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
    dp[0][0]=true;
    for(int i=1;i<n;i++){
        if(s1[i-1]==s3[i-1]){
            dp[i][0]=dp[i-1][0];
        }
        else break;
    }
    for(int j=1;j<m;j++){
        if(s2[j-1]==s3[j-1]){
            dp[0][j]=dp[0][j-1];
        }
        else break;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            char c=s3[i+j-1];
            if(s1[i-1]==c && dp[i-1][j] || s2[j-1]==c && dp[i][j-1]){
                dp[i][j]=true;
            }
        }
    }
    cout<<dp[n][m];
}