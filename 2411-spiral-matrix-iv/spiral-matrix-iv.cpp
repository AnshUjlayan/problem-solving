/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> mat(m, vector<int>(n, -1));
        vector<int> dirX {0, 1, 0, -1};
        vector<int> dirY {1, 0, -1, 0};
        int i = 0, j = 0, d = 0;
        while (head) {
            mat[i][j] = head->val;
            head = head->next;
            int nextI = i + dirX[d];
            int nextJ = j + dirY[d];
            if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n || mat[nextI][nextJ] != -1)
                d = (d + 1) % 4;
            i += dirX[d];
            j += dirY[d];
        }
        return mat;
    }
};