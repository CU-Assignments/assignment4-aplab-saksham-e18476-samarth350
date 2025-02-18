#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> events;
    for (auto& b : buildings) {
        events.emplace_back(b[0], -b[2]); // Start of building, negative height
        events.emplace_back(b[1], b[2]);  // End of building, positive height
    }
    sort(events.begin(), events.end());

    multiset<int> heights = {0};
    vector<vector<int>> result;
    int prevHeight = 0;

    for (auto& event : events) {
        int x = event.first, h = event.second;
        if (h < 0) heights.insert(-h); // Start of a building
        else {
            auto it = heights.find(h);
            if (it != heights.end()) heights.erase(it); // End of a building
        }

        int maxHeight = *heights.rbegin();
        if (maxHeight != prevHeight) {
            result.push_back({x, maxHeight});
            prevHeight = maxHeight;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> skyline = getSkyline(buildings);

    for (auto& point : skyline) {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;
    return 0;
}
