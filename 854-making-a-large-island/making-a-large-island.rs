use std::collections::HashSet;

impl Solution {
    fn dfs(grid: &mut Vec<Vec<i32>>, group: i32, i: isize, j: isize) -> i32 {
        let n = grid.len() as isize;
        if i < 0 || j < 0 || i >= n || j >= n || 
            grid[i as usize][j as usize] == 0 || grid[i as usize][j as usize] >= 5000 {
            return 0;
        }
        
        grid[i as usize][j as usize] = group;
        1 + Self::dfs(grid, group, i + 1, j) 
          + Self::dfs(grid, group, i - 1, j) 
          + Self::dfs(grid, group, i, j + 1) 
          + Self::dfs(grid, group, i, j - 1)
    }

    pub fn largest_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut res = 0;
        let mut group = 5000;
        let mut groups = vec![0; n * n];

        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 {
                    let size = Self::dfs(&mut grid, group, i as isize, j as isize);
                    groups[(group - 5000) as usize] = size;
                    group += 1;
                }
            }
        }

        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 0 {
                    let mut new_size = 1;
                    let mut set = HashSet::new();

                    if i > 0 { set.insert(grid[i - 1][j] - 5000); }
                    if i < n - 1 { set.insert(grid[i + 1][j] - 5000); }
                    if j > 0 { set.insert(grid[i][j - 1] - 5000); }
                    if j < n - 1 { set.insert(grid[i][j + 1] - 5000); }

                    for &x in set.iter() {
                        if x >= 0 {
                            new_size += groups[x as usize];
                        }
                    }

                    res = res.max(new_size);
                }
            }
        }

        res = res.max(*groups.iter().max().unwrap());
        res
    }
}