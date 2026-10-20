class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        containsDuplicate = False
        seen = set()

        for n in nums:
            if n in seen:
                containsDuplicate = True;
                break
            seen.add(n)
        return containsDuplicate