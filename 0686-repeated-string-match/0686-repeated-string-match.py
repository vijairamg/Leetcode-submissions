class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        
        if b == "":
            return 0
        
        if b in a:
            return 1
        
        count = 2
        
        o = a
        a = a + a
        
        while len(a) <= 2 * len(b) and b not in a:
            a = a + o
            count = count + 1
        
        # print(count,a)
        
        return count if b in a else -1 