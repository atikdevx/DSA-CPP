#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<queue>


vector<vector<int>> adj_list_rev;
vector<int> prerequisites;
vector<bool> visited;

int countPrerequisites(int start_node) {
    // reset visited

    int n = 0;
    queue<int> q;
    q.push(start_node);
}

int main() {

    int n, m; cin >> n >> m;
    // n nodes, m edges
    adj_list_rev.resize(n + 1, vector<int>());
    visited.resize(n + 1, false);

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list_rev[b].push_back(a);
    }

    prerequisites.resize(n + 1, 0);



}