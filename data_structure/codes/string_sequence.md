### 子串子序列相关问题整理

明确两个概念：
    1. 子串是连续的
    2. 子序列可以不连续

[CPP文件](./strings.cpp)包含下面有的没得算法都有

在做这两种类型相关的问题时，再不济也要基础保底的暴力方法，尽管确实可能有很多人连暴力的方法猛地一想都写不出来：

来点小菜：

1. 暴力求解字符串的所有子串
```cpp
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
```
有没有注意到上面这种写法是做到了暴力求解，但是字符串的子串可能会有很几率是相同的，在正常的出题里面，相同的应该只能算一个，所以这里可以借用set来保存结果,当有重复的数据时，会自动过滤。，使用 set< string >作为返回值即可。

2. 暴力法求解字符串的子序列个数
```cpp
// 有没有感觉，对于这个题用暴力法真的是无能为力！！！
// 想不出来！！！ 
```


#### 正文 

**注意**： 看完之后，再把处理子串和子序列的分开看一下，他们的方法有什么不同，或者有什么相同之处。

- 回文子串，回文子序列问题：

    - **最长回文子串**(抓住精髓，掐头去尾仍相等)
    ```cpp
    // 暴力算法是遍历所有子串，然后判断是否为回文串，时间复杂度很可观
    // 这里主要说一下动态规划解:
    // 状态：dp[l][r] 表示 l->r 之间是否为回文串 , bool数组
    // 子问题：dp[l][r] = dp[l+1][r-1] && str[l] = str[j]
    // base-case:
        // if(l == r)   dp[l][r] = true;                           相等
        // if(r-l == 1) dp[l][r] = str[l] == str[j];               相邻
        // else         dp[l][r] = dp[l+1][r-1] && str[l] = str[j] 大于等于三个普通问题
    string getMaxSubStringPalindromic_DP(string str)
    {   
        int n = str.size();
        vector< vector<bool> > dp(n  ,vector<bool>(n) );
        int max = 0 , left = 0;
        for(int r = 0 ; r < n ; ++r)
        {
            for(int l = 0 ; l <= r ; ++l)
            {
                if(l == r)              // 对应上面的 case
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
    ```
    - **最长回文子序列个数**
    ```cpp
    // 状态：dp[l][r] 表示 l->r 之间最长回文子串的长度 
    // 子问题：
        // if(str[i] == str[j])
        //     dp[i][j] == dp[i+1][j-1] + 2;
        // else
        //     dp[i][j] == max(dp[i+1][j] , dp[i][j-1]); // 非左即右
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
    ```
    - **最长公共子串长度**
    ```cpp
    /// 这题显然也有暴力解法，真的很暴力
    // 动态规划：
    // 状态 ： dp[i][j] 表示 第一个字符串 0...i 第二个字符串 0...j之间的最长公共子串
    // 子问题： 
    //         if s_a[i-1] == s_b[j-1]:   
                    // dp[i][j] = dp[i-1][j-1] + 1  // 匹配上字符，增加 1
    //         else:                      
                    // dp[i][j] = dp[i-1][j-1];      // 不相等
    // base-case:
    //         dp[i][0] = 0 , dp[0][j] = 0
    // return dp[len1][len2]
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
    ```
    - **最长公共子序列**
    ```cpp
    // dp[len1 + 1][len2 + 1]
    // 状态 ： dp[i][j] 表示 第一个字符串 0...i 第二个字符串 0...j之间的最长公共子序列
    // 子问题： 
    //         if s_a[i-1] = s_b[j-1] ： dp[i][j] = dp[i-1][j-1] + 1         //匹配上字符，增加 1 
    //         else dp[i][j] = max(dp[i-1][j] , dp[i][j-1] );              // 匹配不到字符，则为之前两个区间最大的
    // base-case:
    //         dp[i][0] = 0 , dp[0][j] = 0
    // return dp[len1][len2]
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
    ```
    - **最长上升子序列**
    ```cpp
    // 这题的核心是，每次 i 前进之后 ， 然后在重新去更新 dp[i]
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
    ```