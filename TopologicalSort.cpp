#include <bits/stdc++.h> 

void dfs(int u , vector<vector<int>> &a ,stack<int> &st, vector<bool> &vi){
    vi[u] = true;
    for(auto v: a[u]){
        if(!vi[v]){
            dfs(v, a, st, vi);
        }
    }
    st.push(u);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    int V = v;
    vector<vector<int>> a(V);
    vector<int> ans;

    for(int i = 0 ; i< edges.size() ; i++){
        a[edges[i][0]].push_back(edges[i][1]); 
    }

    stack<int> st;
    vector<bool> vi(V , false);

    for(int i = 0 ; i< V; i++){
        if(!vi[i]){
            dfs(i ,a,  st , vi);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
    
}
