impl Solution {
    pub fn grid_game(mut grid: Vec<Vec<i32>>) -> i64 {
        let n = grid[0].len();
        let mut prefix_top: Vec<i64> = vec![0; n];
        let mut prefix_bottom: Vec<i64> = vec![0; n];

        prefix_top[0] = grid[0][0] as i64;
        prefix_bottom[0] = grid[1][0] as i64;
        for j in 1..n {
            prefix_top[j] = prefix_top[j - 1] + grid[0][j] as i64;
            prefix_bottom[j] = prefix_bottom[j - 1] + grid[1][j] as i64;
        }

        let mut result = i64::MAX;
        for j in 0..n {
            let top_remaining = if j + 1 < n { prefix_top[n - 1] - prefix_top[j] } else { 0 };
            let bottom_remaining = if j > 0 { prefix_bottom[j - 1] } else { 0 };
            result = result.min(top_remaining.max(bottom_remaining));
        }

        result
    }
}