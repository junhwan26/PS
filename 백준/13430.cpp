#include <iostream>
#include<vector>
using namespace std;
long long MOD = 1000000007;


int K, N;

vector<long long> v;
vector<long long> ans;

vector<long long> matrix_product(vector<long long> V1, vector<long long> V2) { // 행렬 곱
    if (V1.empty()) return V2;

    vector<long long> result;
    
    for (int i = 0; i < K + 2; ++i) {
        for (int j = 0; j < K + 2; ++j) {
            long long r = 0;
            for (int k = 0; k < K + 2; ++k) {
                r += V1[i * (K + 2) + k] * V2[k * (K + 2) + j];
                r %= MOD;
            }
            result.push_back(r);
        }
    }

    return result;
}

int main() {

    cin >> K >> N;
    
    if (N == 1) {
        cout << 1 << '\n';
        return 0;
    }

    for (int i = 0; i < K+2; ++i) {
        for (int j = 0; j < K+2; ++j) {
            if (j <= i) v.push_back(1); 
            else v.push_back(0);
        }
    }
    N--;
    while (N) {
        if (N % 2)
            ans = matrix_product(ans, v);
        v = matrix_product(v, v);
        N /= 2;
    }

    int result = 0;
    for (int j = 0; j < K + 2; ++j) {
        result += ans[(K + 1) * (K + 2) + j];
        result %= MOD;
    }

    cout << result << '\n';

    return 0;
}
