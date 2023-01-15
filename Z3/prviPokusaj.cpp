#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool isVisited(int x, int y, unordered_set<int>& visited) {
    int key = x * 100 + y;
    if (visited.find(key) != visited.end())
        return true;
    visited.insert(key);
    return false;
}

void BFS(vector<vector<int>> &matrix, int x, int y, unordered_set<int> &result, unordered_set<int>& visited, unordered_map<int, int>& occurrences) {
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty()) {
        pair<int,int> front = q.front();
        int x = front.first;
        int y = front.second;
        q.pop();

        if (!isVisited(x, y, visited)) {
            result.insert(matrix[x][y]);
            if (occurrences.count(matrix[x][y])) {
                occurrences[matrix[x][y]]++;
            } else {
                occurrences[matrix[x][y]] = 1;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size()) {
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    unordered_set<int>res, visited;
    unordered_map<int, int> ponavljanje;
    int ukupno = n * n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    BFS(matrix,0,0,res,visited,ponavljanje);

    if(n == 1){
        cout<<matrix[0][0];
        return 0;
    }

    int min_num = INT_MAX;
    for (auto i : ponavljanje) {
        int num = i.first;
        int count = i.second;
        int less_than_count = 0;
        for (auto j : ponavljanje) {
            if (j.first < num) {
                less_than_count += j.second;
            }
        }
        if (less_than_count + count >= ukupno / 2) {
            min_num = min(min_num, num);
        }
    }

    cout<<min_num<<endl;

    return 0;
}

/*
 5
9 0 0 3 3
9 0 0 0 3
0 9 9 3 3
9 9 9 3 3
9 9 9 9 3
 */