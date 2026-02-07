impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut cnt = 0;
        let mut res = i32::MAX;
        let mut right = vec![0; n + 1];

        for i in (0..n).rev() {
            if s[i] == b'a' { cnt += 1; }
            right[i] = cnt;
        }

        cnt = 0;
        for i in 0..n {
            res = res.min(cnt + right[i + 1]);
            if s[i] == b'b' { cnt += 1; }
        }

        res
    }
}