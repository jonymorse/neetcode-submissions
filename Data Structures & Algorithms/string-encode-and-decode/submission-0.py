class Solution:

    def encode(self, strs: List[str]) -> str:
        sl = []
        new_char = "/"
        for string in strs:
            update_string = string + new_char
            char_list = list(update_string)
            sl.extend(char_list)
        comb = ''.join(sl)

        return comb 

    def decode(self, s: str) -> List[str]:
        new_char = "/"
        uplist = []
        restring = "" 
        for char in s:
            if char != new_char:
                restring += char
            else:
                uplist.append(restring)
                restring = ""
        return uplist
