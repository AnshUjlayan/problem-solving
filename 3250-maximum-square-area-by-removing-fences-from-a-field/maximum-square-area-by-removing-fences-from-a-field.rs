use std::collections::HashSet;

impl Solution {

    pub fn getMonkey(fences: &[i32]) -> HashSet<i32> {
        let n = fences.len();
        let mut st = HashSet::new();

        for i in 1..n {
            for j in 0..i {
                st.insert((fences[i] - fences[j]).abs());
            }
        }

        st
    }

    pub fn maximize_square_area(m: i32, n: i32, mut h_fences: Vec<i32>, mut v_fences: Vec<i32>) -> i32 {
        let mut res: i32 = 0;

        h_fences.push(1);
        h_fences.push(m);
        v_fences.push(1);
        v_fences.push(n);

        let x = Solution::getMonkey(&h_fences);
        let y = Solution::getMonkey(&v_fences);

        for val in x {
            if y.contains(&val) {
                res = res.max(val);
            }
        }

        if res > 0 {
            ((res as i64 * res as i64) % 1_000_000_007) as i32
        } else { -1 }
    }
}