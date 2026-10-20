class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hash_map = {}
        for index, elements in enumerate(nums):
            if elements in hash_map:
                return True
            else:
                hash_map[elements] = index
        return False