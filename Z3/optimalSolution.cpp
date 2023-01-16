#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#include <cmath>
#include <cstring>


using namespace std;
bool visited[500][500];
int matrix[500][500];
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };



int isValidPos(int n, int i, int j){
    if(i < n && i >= 0 && j < n && j >= 0){
        return 1;
    }
    return 0;
}


int bfs(int n, int i, int j,int merdevine) {
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push({ i, j });
    int count = 1;
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        for (int z = 0; z < 4; z++)
        {
            int r = curr.first + row[z];
            int c = curr.second + col[z];


            if (isValidPos(n,r, c) && !visited[r][c] && abs(matrix[curr.first][curr.second] - matrix[r][c]) <= merdevine){
                count++;
                visited[r][c] = true;
                q.push({ r, c });
            }
        }
    }
    return count;
}

bool check(int x,int mid) {
    //ova funkcija treba da pokrene bfs na svim elementima matrice i da vidi da li se sa njima i sa
    //visinom merdevina odnosno mid, moze stici do susjednih polja, tako da ukupan broj susjednih polja bude polovina
    //od n*n/2+1
    int n = x;
    //memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(visited[i][j] == true)continue;
            int count = bfs(n,i,j,mid);
            if(n % 2){
                if(count >= n*n/2+1){
                    return true;
                }
            }else{
                if(count >= n*n/2){
                    return true;
                }

            }

        }
    }
    return false;
}
int main() {
    int x;
    cin >> x;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cin >> matrix[i][j];
        }
    }
    memset(visited, false, sizeof(visited));

    if(x == 1){
        cout<<0;
        return 0;
    }
    int max = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            if(matrix[i][j] > max){
                max = matrix[i][j];
            }
            /*
            if(isValidPos(N,i+1,j)){
                merdevine.insert(abs(matrix[i][j] - matrix[i+1][j]));
            }
            if(isValidPos(N,i-1,j)){
                merdevine.insert(abs(matrix[i][j] - matrix[i-1][j]));
            }
            if(isValidPos(N,i,j+1)){
                merdevine.insert(abs(matrix[i][j] - matrix[i][j+1]));
            }
            if(isValidPos(N,i,j-1)){
                merdevine.insert(abs(matrix[i][j] - matrix[i][j-1]));
            }
             */
        }
    }

    //binarna da nadje za jedne merdevine kada se pusti bfs na koliko spratova moze da se popne
    //ako moze da se popne na n*n/2+1 spratova onda je to to
    /*
    vector<int> vectorMerdevina;
    vectorMerdevina.reserve(merdevine.size());
    copy(merdevine.begin(),merdevine.end(), back_inserter(vectorMerdevina));
    */
    int mid;
    int left = 0, right = max;
    while (left < right) {
        memset(visited, false, sizeof(visited));
        mid = (left + right)/2;
        if(check(x,mid)){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    cout<<right;
    return 0;
}
/*
5
0 0 0 3 3
0 0 0 0 3
0 9 9 3 3
9 9 9 3 3
9 9 9 9 3
 */



