class Solution:
    def largestPerimeter(self, nums: list[int]) -> int:
        nums.sort()
        curr = sum(nums)
        while nums and curr <= nums[-1] * 2:
            curr -= nums.pop()
        return sum(nums) if len(nums) > 2 else -1
