#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Prime contributions [count of 2, 3, 5, 7] for digits 0 to 9
    const vector<vector<int>> contrib = {
        {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0},
        {2, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1},
        {3, 0, 0, 0}, {0, 2, 0, 0}
    };

    // Calculate minimum digits needed to satisfy remaining required factors [e2, e3, e5, e7]
    int minDigitsNeeded(int e2, int e3, int e5, int e7) {
        e2 = max(0, e2); e3 = max(0, e3); e5 = max(0, e5); e7 = max(0, e7);
        int count = e5 + e7;
        
        int d9 = e3 / 2; e3 %= 2;
        int d8 = e2 / 3; e2 %= 3;

        if (e2 == 2 && e3 == 1) count += 2;      // 4 and 3 or 6 and 2
        else if (e2 == 1 && e3 == 1) count += 1; // 6
        else count += (e2 > 0 ? 1 : 0) + (e3 > 0 ? 1 : 0);

        return count + d9 + d8;
    }

    void subtractDigit(vector<int>& req, int d) {
        for (int i = 0; i < 4; ++i) req[i] = max(0, req[i] - contrib[d][i]);
    }

    // Greedily fill remaining L digits with the smallest valid numbers
    string fillGreedy(vector<int> req, int L) {
        string res = "";
        for (int i = 0; i < L; ++i) {
            int slotsLeft = L - 1 - i;
            for (int d = 1; d <= 9; ++d) {
                vector<int> nextReq = req;
                subtractDigit(nextReq, d);
                if (minDigitsNeeded(nextReq[0], nextReq[1], nextReq[2], nextReq[3]) <= slotsLeft) {
                    res += to_string(d);
                    req = nextReq;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        // Step 1: Extract required prime factors of t
        vector<int> req(4, 0);
        int primes[4] = {2, 3, 5, 7};
        for (int i = 0; i < 4; ++i) {
            while (t % primes[i] == 0) {
                req[i]++;
                t /= primes[i];
            }
        }
        if (t > 1) return "-1"; // Invalid if t has prime factors > 7

        int n = num.length();

        // Step 2: Check if num itself (if zero-free) is already valid
        if (num.find('0') == string::npos) {
            vector<int> curReq = req;
            for (char c : num) subtractDigit(curReq, c - '0');
            if (minDigitsNeeded(curReq[0], curReq[1], curReq[2], curReq[3]) == 0) {
                return num;
            }
        }

        // Step 3: Compute remaining requirements after prefixing
        vector<vector<int>> prefixReq(n + 1, req);
            int firstZero = n;
            for (int i = 0; i < n; ++i) {
                if (num[i] == '0') { firstZero = i; break; }
                    prefixReq[i + 1] = prefixReq[i]; // Carry forward the remaining requirements
            subtractDigit(prefixReq[i + 1], num[i] - '0');
        }

        // Step 4: Try matching longest valid prefix and replacing current digit with a larger one
        int maxPos = min(n - 1, firstZero);
        for (int pos = maxPos; pos >= 0; --pos) {
            int startDigit = (num[pos] - '0') + 1;
            vector<int> baseReq = prefixReq[pos];

            for (int d = startDigit; d <= 9; ++d) {
                vector<int> curReq = baseReq;
                subtractDigit(curReq, d);
                int slotsLeft = n - 1 - pos;

                if (minDigitsNeeded(curReq[0], curReq[1], curReq[2], curReq[3]) <= slotsLeft) {
                    return num.substr(0, pos) + to_string(d) + fillGreedy(curReq, slotsLeft);
                }
            }
        }

        // Step 5: If same length fails, increase string length
        int targetLen = max(n + 1, minDigitsNeeded(req[0], req[1], req[2], req[3]));
        return fillGreedy(req, targetLen);
    }
};