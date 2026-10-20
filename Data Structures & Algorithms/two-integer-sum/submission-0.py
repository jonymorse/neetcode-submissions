class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = {}
        for index, element in enumerate(nums):  
            comp = target - element

            if comp not in hash:
                hash[element] = index
            else:
                return([hash[comp], index])