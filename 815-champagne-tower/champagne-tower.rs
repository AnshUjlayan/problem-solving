impl Solution {
    pub fn champagne_tower(poured: i32, query_row: i32, query_glass: i32) -> f64 {
        let mut row: Vec<f64> = vec![0.0; 101];
        let mut next_row: Vec<f64> = vec![0.0; 101];
        row[1] = poured as f64;

        for i in 1..=query_row as usize {
            for j in 1..=i+1 {
                next_row[j] = 0.0_f64.max(row[j - 1] - 1.0) / 2.0 
                            + 0.0_f64.max(row[j] - 1.0) / 2.0;
            }
            std::mem::swap(&mut row, &mut next_row);
        }

        row[query_glass as usize + 1].min(1.0)
    }
}