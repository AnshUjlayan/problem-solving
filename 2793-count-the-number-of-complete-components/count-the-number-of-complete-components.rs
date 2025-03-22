use std::collections::HashSet;

struct DSU {
    groups: usize,
    parent: Vec<usize>,
    size: Vec<usize>,
}

impl DSU {
    pub fn new(n: usize) -> Self {
        Self {
            groups: n,
            parent: (0..n).collect(),
            size: vec![1; n],
        }
    }

    pub fn find(&mut self, u: usize) -> usize {
        if self.parent[u] != u {
            self.parent[u] = self.find(self.parent[u]);
        }
        self.parent[u]
    }

    pub fn join(&mut self, u: usize, v: usize) -> bool {
        let root_u = self.find(u);
        let root_v = self.find(v);

        if root_u == root_v {
            return false;
        }

        if self.size[root_u] < self.size[root_v] {
            self.parent[root_u] = root_v;
            self.size[root_v] += self.size[root_u];
        } else {
            self.parent[root_v] = root_u;
            self.size[root_u] += self.size[root_v];
        }

        self.groups -= 1;
        true
    }
}

impl Solution {
    pub fn count_complete_components(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut dsu = DSU::new(n as usize);
        let mut deg = vec![0; n as usize];
        let mut set = HashSet::new();

        for edge in edges.iter() {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            dsu.join(u, v);
            deg[u] += 1;
            deg[v] += 1;
        }

        for i in 0..(n as usize) {
            set.insert(dsu.find(i));
        }

        for i in 0..(n as usize) {
            let root = dsu.find(i);
            if deg[i] != dsu.size[root] - 1 {
                set.remove(&root);
            }
        }

        set.len() as i32
    }
}