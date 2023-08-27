class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        unordered_map<char,int> ump;
        priority_queue<pair<int,char>> taskList;
        priority_queue<pair<int,pair<int,char>>, vector<pair<int,pair<int,char>>>, greater<pair<int,pair<int,char>>>> waitingList;
        for(char& task : tasks) {
            ump[task]++;
        }
        for(auto& record : ump) {
            taskList.push({record.second, record.first});
        }

        while(!taskList.empty() || !waitingList.empty()) {
            if(!taskList.empty()) {
                pair<int,char> currTask = taskList.top();
                taskList.pop();
                if(--currTask.first > 0) {
                    waitingList.push({time + n, currTask});
                }
            }
            while(!waitingList.empty() && waitingList.top().first <= time) {
                taskList.push(waitingList.top().second);
                waitingList.pop();
            }
            time++;
        }
        return time;
    }
};