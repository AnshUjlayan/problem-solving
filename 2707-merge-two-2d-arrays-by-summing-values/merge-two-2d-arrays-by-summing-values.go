func mergeArrays(nums1 [][]int, nums2 [][]int) [][]int {
    i, j, m, n := 0, 0, len(nums1), len(nums2)
    res := [][]int{}
    for i < m || j < n {
        if i < m && (j == n || nums1[i][0] < nums2[j][0]) {
            res = append(res, nums1[i])
            i++
        } else if j < n && (i == m || nums1[i][0] > nums2[j][0]) {
            res = append(res, nums2[j])
            j++
        } else {
            res = append(res, []int{nums1[i][0], nums1[i][1] + nums2[j][1]})
            i++
            j++
        }
    }
    return res
}