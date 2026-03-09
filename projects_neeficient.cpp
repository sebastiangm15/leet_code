#include <iostream>
#include <algorithm>
using namespace std;


typedef struct  {
    long in, sf;
    long value;

}projects;


int main(void)
{
    int n;
    cin >> n;

    projects v[200001];

    for (int i = 1; i <= n; i++) {
        cin >> v[i].in >> v[i].sf >> v[i].value; 
    }

    for(int i = 1; i < n; i++)
        for(int j = i + 1; j <= n; j++) {
            if(v[i].sf > v[j].sf) {
                
                swap(v[i], v[j]);
 
            }
            if(v[i].sf == v[j].sf and v[i].value < v[j].value) {
                swap(v[i], v[j]);
            }
        }


    long dp[200001];


    dp[0] = 0;


    for (int i = 1; i <= n; i++) {
        long ieri_max = dp[i - 1];
 
        long data_inceput = v[i].in;
        long max_trecut = 0;
 
        for (int j = i - 1; j >= 1; j--) {
            if(v[j].sf < data_inceput) {
                max_trecut = dp[j];
                break;
            }
        }
 
 
        dp[i] = max(ieri_max, v[i].value + max_trecut);
 
    }



    
    cout << dp[n] << endl;

    
}

//enunt https://cses.fi/problemset/task/1140 