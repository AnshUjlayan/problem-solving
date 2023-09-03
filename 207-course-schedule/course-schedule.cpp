class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int visited = 0;
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses);
        for(auto& prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            degree[prerequisite[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(degree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            visited++;
            int course = q.front();
            q.pop();
            for(int& neighbour : adj[course]) {
                degree[neighbour]--;
                if(degree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        return visited == numCourses;
    }
};