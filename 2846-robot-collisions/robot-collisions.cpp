class Solution {
private:
    struct Robot {
        int index, position, health, direction;
        Robot(int index, int position, int health, int direction) : index(index), position(position), health(health), direction(direction) {}
    };
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        stack<Robot> stk;
        vector<Robot> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back(Robot(i, positions[i], healths[i], directions[i]));
        }
        sort(robots.begin(), robots.end(), [](const Robot &a, const Robot &b) {
            return a.position < b.position;
        });

        for (auto &curr : robots) {
            if (curr.direction == 'L') {
                while (!stk.empty() && stk.top().direction == 'R' && curr.health) {
                    Robot top = stk.top();
                    stk.pop();
                    if (top.health > curr.health) {
                        top.health--;
                        stk.push(top);
                        curr.health = 0;
                    }
                    else if (top.health < curr.health) {
                        curr.health--;
                    }
                    else {
                        curr.health = 0;
                    }
                }
            }
            if (curr.health) {
                stk.push(curr);
            }
        }

        vector<Robot> robos;
        while (!stk.empty()) {
            robos.push_back(stk.top());
            stk.pop();
        }
        sort(robos.begin(), robos.end(), [](const Robot &a, const Robot &b) {
            return a.index < b.index;
        });

        vector<int> result;
        for (Robot& robo : robos) {
            result.push_back(robo.health);
        }
        return result;
    }
};