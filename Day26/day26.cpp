// Problem Statement: An IT company is working on a large project. The project is broken into N modules...
////Please refer day26 text file for full problem statement


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int visited[100005];
int counted[100005];
int isstack[100005];


class Solution{
    public:
    bool checkCycle(int i, vector<vector<int>> &ve) {
        if (isstack[i] == 1) return true;
    
        // insert into stack
        isstack[i] = 1;
        for (auto it : ve[i]) {
            // if next node is visited 
            if (visited[it] == 1) {
                // if the node is in stack then cycle is found
                if (isstack[it] == 1) return true;
                continue;
            }
            visited[it] = 1;
            if (checkCycle(it, ve)) return true;
        }
        // removing from stack
        isstack[i] = 0;
        return false;
    }
    int dfs(int i, vector<vector<int>> &ve, int duration[]) {
        // return the time to complete the project starting from the node i if it is
        // already calculated
        if (counted[i] != -1) return counted[i];
        int x = 0;
    
        for (auto it : ve[i]) x = max(x, dfs(it, ve, duration));
    
        // time to complete this module and maximum time to complete child modules
        counted[i] = x + duration[i];
        return counted[i];
    }
    
    int minTime(vector<pair<int, int>> &vp, int duration[], int n, int m) {
        int independent[n + 5] = {0};
        vector<vector<int>> ve(n + 2);
        for (int i = 0; i < m; i++) {
            int x = vp[i].first;
            int y = vp[i].second;
            ve[x].push_back(y);
            independent[y]++;
        }
        memset(visited, -1, sizeof(visited));
        memset(counted, -1, sizeof(counted));
        memset(isstack, -1, sizeof(isstack));
    
        int flag = 0;
        for (int i = 0; i < n; i++)
            if (independent[i] == 0) flag = 1;
    
        if (flag == 0) return -1;
    
        for (int i = 0; i < n; i++) {
            if (independent[i] != 0) {
                continue;
            }
            visited[i] = 1;
            if (checkCycle(i, ve)) return -1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (independent[i] == 0) ans = max(ans, dfs(i, ve, duration));
    
        return ans;
    }
};



// { Main Code Starts

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}  // }  End

//Output Win
/* 
For Input:
6 6
1 2 3 1 3 2
5 2
5 0
4 0
4 1
2 3
3 1
your output is: 
8 */
