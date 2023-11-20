class Solution {
private:
    int getSlimy(vector<string>& garbage, vector<int>& travel, char target) {
        int result = 0, dist = 0;
        for(int i = 0; i < garbage.size(); i++) {
            int cost = 0;
            for(int j = 0; j < garbage[i].size(); j++) {
                cost += garbage[i][j] == target ? 1 : 0;
            }
            result += cost;
            dist = cost ? travel[i] : dist;
        }
        return result + dist;
    }
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        travel.push_back(0);
        int sum = 0;
        for(int i = 0; i < travel.size(); i++) {
            int temp = travel[i];
            travel[i] = sum;
            sum += temp;
        }
        int result = 0;
        result += getSlimy(garbage, travel, 'M');
        result += getSlimy(garbage, travel, 'P');
        result += getSlimy(garbage, travel, 'G');
        return result;
    }
};