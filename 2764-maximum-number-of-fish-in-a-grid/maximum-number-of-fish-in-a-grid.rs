impl Solution {
    fn dfs(grid: &mut Vec<Vec<i32>>, i: isize, j: isize) -> i32 {
        let m = grid.len() as isize;
        let n = grid[0].len() as isize;

        if i < 0 || j < 0 || i >= m || j >= n || grid[i as usize][j as usize] == 0 {
            return 0;
        }

        let temp = grid[i as usize][j as usize];
        grid[i as usize][j as usize] = 0;

        temp
            + Self::dfs(grid, i, j + 1)
            + Self::dfs(grid, i, j - 1)
            + Self::dfs(grid, i + 1, j)
            + Self::dfs(grid, i - 1, j)
    }

    pub fn find_max_fish(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut grid = grid;
        let mut res = 0;

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] != 0 {
                    res = res.max(Self::dfs(&mut grid, i as isize, j as isize));
                }
            }
        }

        res
    }
}