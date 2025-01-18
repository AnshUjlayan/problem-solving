use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn min_cost(grid: Vec<Vec<i32>>) -> i32 {
        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        let rows = grid.len();
        let cols = grid[0].len();
        let mut visited = vec![vec![false; cols]; rows];
        let mut heap = BinaryHeap::new();

        heap.push(Reverse((0, 0, 0)));
        while let Some(Reverse((cost, x, y))) = heap.pop() {
            if x == rows - 1 && y == cols - 1 {
                return cost;
            }
            if visited[x][y] {
                continue;
            }
            visited[x][y] = true;
            for (i, (dx, dy)) in directions.iter().enumerate() {
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;
                if nx >= 0 && ny >= 0 && (nx as usize) < rows && (ny as usize) < cols {
                    let nx = nx as usize;
                    let ny = ny as usize;
                    let new_cost = cost + if (i as i32 + 1) != grid[x][y] { 1 } else { 0 };
                    heap.push(Reverse((new_cost, nx, ny)));
                }
            }
        }
        -1
    }
}