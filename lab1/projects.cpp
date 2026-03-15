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

    sort(v + 1, v + n + 1, [](const projects &a, const projects &b) {
        if(a.sf != b.sf)
            return a.sf < b.sf;
        else
            return a.value > b.value;
    });


    long dp[200001];


    dp[0] = 0;


    for (int i = 1; i <= n; i++) {
        long long ieri_max = dp[i - 1];

        int data_inceput = v[i].in;
        long long max_trecut = 0;

        // binary search
        int st = 1, dr = i - 1;
        while (st <= dr) {
            int mid = (st + dr) / 2;
            if (v[mid].sf < data_inceput) {
                max_trecut = dp[mid];
                st = mid + 1;
            } else {
                dr = mid - 1;
            }
        }

        dp[i] = max(ieri_max, (long long)v[i].value + max_trecut);
    }




    
    cout << dp[n] << endl;

    
}


//enunt https://cses.fi/problemset/task/1140 