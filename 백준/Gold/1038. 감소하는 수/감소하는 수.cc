#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int LEN = 11;

long long solution(int N) {
    vector<vector<vector<long long>>> dp(LEN, vector<vector<long long>>(10, vector<long long>(0)));
    for (int j=0; j<10; j++) {
        dp[1][j].push_back(j);
    }

    for (int i=2; i<LEN; i++) {
        for (int j=1; j<10; j++) {
            for (auto n : dp[i][j-1]) {
                dp[i][j].push_back(n + pow(10, i-1));
            }
            for (auto n : dp[i-1][j-1]) {
                dp[i][j].push_back(n + j * pow(10, i-1));
            }
        }
    }

    vector<long long> answers;

    for (auto d : dp) {
        for (auto l : d) {
            for (auto i : l) {
                answers.push_back(i);
            }
        }
    }

    return ((N < (int)answers.size()) ? answers[N] : -1);

}

int main() {
    int N;
    cin >> N;
    cout << solution(N) << endl;
    
    return 0;
}