impl Solution {
    pub fn min_cost(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        use std::cmp::Reverse;
        use std::collections::BinaryHeap;

        let n = n as usize;
        let mut adj: Vec<Vec<(usize, i32)>> = vec![vec![]; n];
        let mut dp = vec![1_000_000_000i32; n];

        for edge in edges.iter() {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            let w = edge[2];

            adj[u].push((v, w));
            adj[v].push((u, w * 2));
        }

        let mut q: BinaryHeap<(Reverse<i32>, usize)> = BinaryHeap::with_capacity(n);
        q.push((Reverse(0), 0));

        while let Some((Reverse(cost), node)) = q.pop() {
            if dp[node] < cost {
                continue;
            } else if node == n - 1 {
                return cost;
            }

            for &(next, w) in adj[node].iter() {
                if dp[next] > cost + w {
                    dp[next] = cost + w;
                    q.push((Reverse(cost + w), next));
                }
            }
        }

        -1
    }
}