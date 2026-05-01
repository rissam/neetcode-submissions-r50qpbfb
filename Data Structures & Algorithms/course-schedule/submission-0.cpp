class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> deps;
        vector<int> indegree(numCourses, 0);

        for(auto &prerequisite : prerequisites) {
            int precede = prerequisite[1];
            int followup = prerequisite[0];
            deps[precede].push_back(followup);
            indegree[followup]++;
        }

        int count = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        } 
        while(!q.empty()) {
            count++;
            int precede = q.front();
            q.pop();
            for(auto & dep: deps[precede]) {
                indegree[dep]--;
                if(indegree[dep] == 0) {
                    q.push(dep);
                }
            }
        }
        return count == numCourses;
        
    }
};
