#include <iostream>
#include <vector>

using namespace std;

bool canGetTwoSum(vector<int> &nums, vector<bool> &exist, int target) {
    for(int e: nums) {
        if(target - e > 0 && exist[target-e]) {
            return true;
        }
    }
    return false;
}

int main() {
    const int maxn = 200;
    vector<bool> isprime(maxn+1, true);
    isprime[0] = false;
    isprime[1] = false;
    for(int p = 2; p*p <= maxn; p++) {
        if(isprime[p]) {
            for(int comp = p*p; comp <= maxn; comp += p) {
                isprime[comp] = false;
            }
        }
    }
    vector<int> primes;
    for(int i = 2; i <= maxn; i++) {
        if(isprime[i]) {
            primes.push_back(i);
        }
    }
    vector<int> semiprimes;
    int maxval = 0;
    for(int i = 0, len = primes.size(); i < len; i++) {
        for(int j = i+1; j < len; j++) {
            semiprimes.push_back(primes[i]*primes[j]);
            if(semiprimes.back() > maxval) {
                maxval = semiprimes.back();
            }
        }
    }
    vector<bool> issemiprime(maxval+1, false);
    for(int sp: semiprimes) {
        issemiprime[sp] = true;
    }
    int n = 0, t = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(canGetTwoSum(semiprimes, issemiprime, t)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}