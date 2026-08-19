class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
     sort(reservedSeats.begin(),reservedSeats.end());
        int families = 2 * n;
        int m = reservedSeats.size();
        for (int i = 0; i < m;) {
            families -= 2;
            int row = reservedSeats[i][0];
            array<bool, 11> reserved{};
            while (i < m && reservedSeats[i][0] == row) {
                reserved[reservedSeats[i][1]] = true;
                i++;
            }
            if (!reserved[2] && !reserved[3] && !reserved[4] && !reserved[5]) {
                families++;
            } else if (!reserved[4] && !reserved[5] && !reserved[6] && !reserved[7] && (reserved[8] || reserved[9])) {
                families++;
            }
            if (!reserved[6] && !reserved[7] && !reserved[8] && !reserved[9]) {
                families++;
            }
        }
        return families;
    }
};