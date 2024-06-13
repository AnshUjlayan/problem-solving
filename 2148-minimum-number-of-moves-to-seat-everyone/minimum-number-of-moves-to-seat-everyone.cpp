class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size(), result = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        while (--n >= 0)
            result += abs(seats[n] - students[n]);
        return result;
    }
};