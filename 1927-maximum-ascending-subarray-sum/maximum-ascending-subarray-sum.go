func maxAscendingSum(nums []int) int {
    res, sum := nums[0], nums[0]
    for i := 1; i < len(nums); i++ {
        if nums[i - 1] >= nums[i] {
            sum = 0
        }
        sum += nums[i];
        res = max(res, sum)
    }
    return res
}