class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash = {}
        new_list = []

        for string in strs:
            key = ''.join(sorted(string))
            
            if key in hash:
                hash[key].append(string)

            else:
                hash[key] = [string]
        return list(hash.values())