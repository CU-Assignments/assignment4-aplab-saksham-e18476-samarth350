#include <bits/stdc++.h>
using namespace std;

vector<int> beautifulArray(int n) {
    vector<int> result = {1};
    while (result.size() < n) {
        vector<int> temp;
        for (int x : result) if (2 * x - 1 <= n) temp.push_back(2 * x - 1);
        for (int x : result) if (2 * x <= n) temp.push_back(2 * x);
        result = temp;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> ans = beautifulArray(n);
    for (int num : ans) cout << num << " ";
    cout << endl;
    return 0;
}