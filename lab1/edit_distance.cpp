#include <iostream>
#include <cstring>
#include <algorithm>



using namespace std;

int main(void) {

    char s1[10000], s2[10000];
    cin.getline(s1, 10000);
    cin.getline(s2, 10000);


    int dp[strlen(s1) + 2][strlen(s2) + 2];


    int n = strlen(s1), m = strlen(s2);




    for(int i = 0; i < n; i ++) {
        if (i < m) {
            if (s1[i] == s2[i]) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1;
            }
        }
    }


    for(int j = 0; j <= m; j++) {
       dp[0][j] = j;
    }
    for(int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int cost = 0;

            if(s1[i - 1] != s2[j - 1]) {
                cost = 1;
            }

            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost);
        }
    }


    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++ ) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << endl<<  dp[n][m];

        


    return 0;

}



// https://cses.fi/problemset/task/1639 (enunt)