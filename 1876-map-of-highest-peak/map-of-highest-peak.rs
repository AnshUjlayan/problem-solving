use std::collections::VecDeque;

impl Solution {
    pub fn highest_peak(is_water: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = is_water.len();
        let n = is_water[0].len();

        let dirs = vec![(0, 1), (0, -1), (1, 0), (-1, 0)];
        let mut visited = vec![vec![false; n]; m];
        let mut res = vec![vec![0; n]; m];

        let mut q = VecDeque::new();
        for i in 0..m {
            for j in 0..n {
                if is_water[i][j] == 1 {
                    q.push_back((i as isize, j as isize));
                    visited[i][j] = true;
                }
            }
        }

        let mut height = 0;
        while !q.is_empty() {
            let l = q.len();
            for _ in 0..l {
                if let Some((i, j)) = q.pop_front() {
                    res[i as usize][j as usize] = height;
                    for (dx, dy) in &dirs {
                        let ni = i + dx;
                        let nj = j + dy;
                        if ni >= 0 && ni < m as isize && nj >= 0 && nj < n as isize {
                            let (ui, uj) = (ni as usize, nj as usize);
                            if !visited[ui][uj] {
                                q.push_back((ni, nj));
                                visited[ui][uj] = true;
                            }
                        }
                    }
                }
            }
            height += 1;
        }

        res
    }
}