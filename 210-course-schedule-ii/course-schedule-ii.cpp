class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int visited = 0;
        vector<int> result, degree(numCourses);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        for(auto& preqequisite : prerequisites) {
            adj[preqequisite[1]].push_back(preqequisite[0]);
            degree[preqequisite[0]]++;
        }
        for(int i = 0; i < numCourses; i++) {
            if(degree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);
            visited++;
            for(auto& neighbour : adj[course]) {
                degree[neighbour]--;
                if(degree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        if(numCourses == visited) {
            return result;
        }
        return {};
    }
};