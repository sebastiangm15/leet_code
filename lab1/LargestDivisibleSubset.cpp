#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());


        vector<int> dp(nums.size(), 1);

        vector<int> prev(nums.size(), -1);


        int n = nums.size();


        for (int i = 1; i < nums.size(); i++) {
            
            for (int j = i - 1; j >= 0; j--) {
                
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i] ) {
                    prev[i] = j;
                    dp[i] = dp[j] + 1;
                }

            }

        }

        vector <int> returner;


        int maxim = 0;
        int indice = -1;



        for(int i = 0; i < nums.size(); i++)
            if(dp[i] > maxim) {
                maxim = dp[i];
                indice = i;

            }



        

        
        while (indice != 0) {

            if(indice == -1) {
                break;
            }
            
            returner.insert(returner.begin(), nums[indice]);

            indice = prev[indice];

        }

        if(indice == 0)
            returner.insert(returner.begin(), nums[0]);


        cout << returner.size();






        return returner;


        
    }
};

// maxim pe leetcode


//enunt https://leetcode.com/problems/largest-divisible-subset/description/