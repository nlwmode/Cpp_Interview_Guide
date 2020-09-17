/**
 *  create by NLWMODE 09/1７/2020
 *  子串子序列相关问题整理
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * 字符串所有子串　，　暴力法
 */
vector<string> getAllSubString(string str)
{
    vector<string> ans;
    if(str.empty())
        return ans;
    for(int i = 0 ; i < str.size() ; ++i)
    {   
        string tmp;
        for(int j = i ; j < str.size() ; ++j)
        {
            tmp += str[j];
            ans.push_back(tmp);
        }
    }
    return ans;
}


/**
 * 最长回文子串 , 暴力解法
 */
 bool isPalindromic(string str)
 {
     int left = 0 , right = str.size() - 1;
     while(left < right)
     {
         if(str[left] != str[right])
         {
             return false;
         }
         ++left , --right;
     }
 }

string getMaxSubStringPalindromic(string str)
{   
    string ans;
    int length = 0;
    for(int i = 0 ; i < str.size() ; ++i)
    {   
        string tmp;
        for(int j = i ; j < str.size() ; ++j)
        {
            tmp += str[j];
            if(tmp.size() < length)
                continue;
            if(tmp.size() > 1 && isPalindromic(tmp))
            {
                if(tmp.size() > length)
                {
                    ans = tmp;
                    length = tmp.size();
                }
            }
        }
    }
    return ans;
}
/**
 * 最长回文子串 , 动态规划解法
 */
string getMaxSubStringPalindromic_DP(string str)
{   
    int n = str.size();
    vector< vector<bool> > dp(n  ,vector<bool>(n) );
    int max = 0 , left = 0;
    for(int r = 0 ; r < n ; ++r)
    {
        for(int l = 0 ; l <= r ; ++l)
        {
            if(l == r)
                dp[l][r] = true;
            else if(r-l == 1)
                dp[l][r] = str[l] == str[r];
            else if(str[l] == str[r])
                dp[l][r] = dp[l+1][r-1];
            else
                dp[l][r] = false;
            if(dp[l][r] && r-l+1 > max)
            {
                max == r-l+1;
                left + l;
            }
        }
    }
    return str.substr(left , max);
}

/**
 * 最长回文子序列的长度 , 动态规划解法
 */
int  getMaxSubSequencePalindromic_DP(string str)
{   
    int n = str.size();
    vector< vector<bool> > dp(n  ,vector<bool>(n) );
    for(int i = 0 ; i < n ; ++i)
        dp[i][i] = 1;
    
    for(int i = n-1 ; i >= 0 ; ++i)
    {
        for(int j = i + 1 ; j < n ; ++j)    // 相邻的开始
        {
                if(str[i] == str[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

/**
 * 最长公共子串长度
 */

int getCommonString(string str1  ,string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    vector< vector<int> > dp(len1 + 1  ,vector<int>(len2 + 1 , 0));
    int max_count = 0;
    string res;
    for(int i = 1 ; i <= len1 ; ++i)
    {
        for(int j = 1 ; j <= len2 ; ++j)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(max_count < dp[i][j])
                {
                    max_count = dp[i][j];
                }
                
            }
            else
                dp[i][j] = dp[i-1][j-1];
        }
    }
    return max_count;
}

/**
 * 最长公共子序列
 */

string getCommonSequence(string str1  ,string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    vector< vector<int> > dp(len1 + 1  ,vector<int>(len2 + 1 , 0));
    int max_count = 0;
    string res;
    for(int i = 1 ; i <= len1 ; ++i)
    {
        for(int j = 1 ; j <= len2 ; ++j)
        {
            if(str1[i-1] == str1[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                res.push_back(str1[i-1]);
            }
            else
                dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
        }
    }
    return res;
}

/**
 * 最长上升子序列、子数组
 */
int getMaxUpSequence(string str)
{
    int n =str.size();
    vector<int> dp(n , 1);
    int res = 0;
    for(int i = 0 ; i< n  ;++i)
    {
        for(int j = 0 ; j < i ; ++j)
        {
            if(str[i] > str[j])
                dp[i] = max(dp[i] , dp[j] + 1 );
        }
        res = max(res , dp[i]);
    }
    return res;
}



int main()
{
    cout << "hello world!" << endl;
    return 0;
}