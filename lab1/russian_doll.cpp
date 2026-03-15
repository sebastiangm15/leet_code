#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {


        if(envelopes.empty()) {
            return 0;
        }

        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] != b[0]) return a[0] < b[0];
            else return a[1] > b[1];            
        });
        


        vector<int> dp(envelopes.size(), 1);


        for (int i = 0; i < envelopes.size(); i++) {
            dp[i] = 1;
        }

        int maxim = 1;


        for(int i = 1; i < envelopes.size(); i++) {

            

            for(int j = i - 1; j >= 0; j--) {
                if(envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1); 
                }
            }
            maxim = max(dp[i], maxim);

        }

    return maxim;        
    }
};



int main() {
    Solution sol;

    // Exemplu de test: vector de plicuri {width, height}
    vector<vector<int>> envelopes = {
        {5,4}, {6,4}, {6,7}, {2,3}
    };

    int result = sol.maxEnvelopes(envelopes);
    cout << "Numarul maxim de plicuri care se pot introduce unul in altul: " << result << endl;

    return 0;
}


// nu e de maxim pe leetcode e de 85/87



//enunt https://leetcode.com/problems/russian-doll-envelopes/description/