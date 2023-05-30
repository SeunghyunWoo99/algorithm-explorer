#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comparePair(pair<int, double> &a, pair<int, double> &b) {
    return a.second > b.second || (a.second == b.second && a.first < b.first);
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> dp(N+2,0);
    vector<pair<int, double>> rates(N);
    
    // count
    for (auto stage : stages) {
        if (stage <= N)
            dp[stage]++;
        else
            dp[N+1]++;
    }
    
    // accumulate
    for (int i=N; i>0; i--) {
        int temp = dp[i];
        dp[i]+=dp[i+1];
        
        if (dp[i] == 0)
            rates[i-1] = make_pair(i-1, 0.0f);
        else
            rates[i-1] = make_pair(i-1, (double)temp/(double)dp[i]);
    }
    
    sort(rates.begin(), rates.end(), comparePair);
    
    for (auto rate : rates)
        answer.push_back(rate.first+1);
    
    return answer;
}
