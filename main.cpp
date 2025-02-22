#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int count = 1;

        for (int min = 0; min < n / 2; ++min) {
            const int max = n - min - 1;
            for (int i = min; i < max; ++i)
                ans[min][i] = count++;
            for (int i = min; i < max; ++i)
                ans[i][max] = count++;
            for (int i = max; i > min; --i)
                ans[max][i] = count++;
            for (int i = max; i > min; --i)
                ans[i][min] = count++;
        }

        if (n & 1)
            ans[n / 2][n / 2] = count;

        return ans;
    }
};

int main() {
    Solution solution;

    int n1 = 3;
    cout << "Input: n = " << n1 << endl;
    vector<vector<int>> result1 = solution.generateMatrix(n1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result1[i].size(); ++j) {
            cout << result1[i][j];
            if (j < result1[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    int n2 = 1;
    cout << "Input: n = " << n2 << endl;
    vector<vector<int>> result2 = solution.generateMatrix(n2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result2[i].size(); ++j) {
            cout << result2[i][j];
            if (j < result2[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
