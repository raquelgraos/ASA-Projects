/*************************************************************
    * IST - ASA 23/24 - Projecto 2 -  *
    - Raquel Rodrigues  106987
    - Guilherme Pereira 107057
 *************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

vector<vector<int>> adj, revAdj;
vector<int> sccIndex, visited, path;
stack<int> finished;
int n, m;

void DFSVisit(int i, stack<int> &result, vector<vector<int>> &graph) {
    stack<int> stack1;
    stack1.push(i);

    while(!stack1.empty()) {
        int u = stack1.top();
        if (visited[u] == 0) {
            visited[u] = 1;
            for (int v: graph[u]) {
                if(visited[v] == 0) {
                    stack1.push(v);
                }
            }
        } else if (visited[u] == 1) {
            visited[u] = 2;
            stack1.pop();
            result.push(u);
        } else if (visited[u] == 2) {
            stack1.pop();
        }
    }   
}

void findSCCs() {
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            DFSVisit(i, finished, adj);
        }
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    sccIndex = vector<int>(n + 1, -1);
    stack<int> finishedCopy = finished;
    int i = 0;
    while (!finishedCopy.empty()) {
        int v = finishedCopy.top();
        finishedCopy.pop();
        if (!visited[v]) {
            stack<int> component;
            DFSVisit(v, component, revAdj);
            i++;
            while (!component.empty()) {
                sccIndex[component.top()] = i;
                component.pop();
            }
        }
    }
}

int findLongestLeap() {
    int longest = 0;
    while(!finished.empty()) {
        int u = finished.top();
        finished.pop();
        for (int v : revAdj[u]) {
            if (sccIndex[v] != sccIndex[u]) {
                path[u] = max(path[u], path[v]+1);
            } else {
                path[u] = max(path[u], path[v]);
                path[v] = path[u];
            }
        }
        longest = max(longest, path[u]);
    }
    return longest;
}

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    adj = vector<vector<int>>(n+1, vector<int>());
    revAdj = vector<vector<int>>(n+1, vector<int>());
    visited = vector<int>(n+1, 0);
    path = vector<int>(n+1, 0);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2) return 0;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    findSCCs();
    int result = findLongestLeap();
    printf("%d\n", result);
    return 0;
}
