#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubSequence1(string str){
    int n=str.length();
    vector<vector<int> > dp(n,vector<int>(n));

    for(int j=0;j<n;j++){
        dp[j][j]=1;
        for(int i=j-1;i>=0;i--){
            if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

int longestPalindromeSubSequence2(string str){
    int n=str.length();
    vector<vector<int> > dp(n,vector<int>(n));

    for(int i=n-1;i>=0;i--){
        dp[i][i]=1;
        for(int j=i+1;j<n;j++){
            if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

int main()
{
    string s;
    int length;
    while(cin>>s){
        for(auto& ele : s)
            if(isalpha(ele))
                ele = tolower(ele);
        length=longestPalindromeSubSequence2(s);
        cout<<s.length() - length<<endl;
    }
    return 0;
}