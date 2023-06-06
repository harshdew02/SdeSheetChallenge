class Solution {
public:

    int solve(string &a , int n , string &b , int m , vector<vector<int>> &t ){
        if(n == 0 || m== 0)
        return 0;

        if(t[n][m] != -1){
        return t[n][m];

        }
            
        if(a[n-1] == b[m-1]){
            return t[n][m] = 1+solve(a , n-1 , b , m-1 , t);
        }else{
            return t[n][m] = max(solve(a , n-1 , b , m , t), solve(a , n , b , m-1 , t));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(1001 , vector<int>(1001 , -1));
        return solve(text1 , text1.size()  , text2 , text2.size() , dp);
    }
};
