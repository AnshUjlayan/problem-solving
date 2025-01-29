struct DSU {
    parent: Vec<usize>,
    size: Vec<usize>,
}

impl DSU {
    fn new(n: usize) -> Self {
        let mut parent = vec![0; n];
        let size = vec![1; n];
        for i in 0..n {
            parent[i] = i;
        }

        DSU { parent, size }
    }

    fn find(&mut self, u: usize) -> usize {
        if self.parent[u] != u {
            self.parent[u] = self.find(self.parent[u]);
        }
        self.parent[u]
    }

    fn join(&mut self, u: usize, v: usize) -> bool {
        let pu = self.find(u);
        let pv = self.find(v);

        if pu == pv {
            return true;
        }

        if self.size[pu] > self.size[pv] {
            self.parent[pv] = pu;
            self.size[pu] += self.size[pv];
        } else {
            self.parent[pu] = pv;
            self.size[pv] += self.size[pu];
        }

        false
    }
}

impl Solution {
    pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let n = edges.len();
        let mut dsu = DSU::new(n + 1);

        for edge in edges.iter() {
            let u = edge[0] as usize;
            let v = edge[1] as usize;

            if dsu.join(u, v) {
                return edge.clone();
            }
        }

        vec![]
    }
}