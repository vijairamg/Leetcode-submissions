class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        
        score = collections.defaultdict(int)
        
        roadSet = set()
        
        for road in roads:
            x,y = road
            roadSet.add((min(x,y),max(x,y)))
            score[x]+=1
            score[y]+=1
        
        s = [[y,x] for x,y in score.items()]
        # s.sort()
        # print(s)
        
        res = 0
        
        for i in range(len(s)):
            for j in range(i+1,len(s)):
                t = s[i][0] + s[j][0]
                if (min(s[i][1],s[j][1]),max(s[i][1],s[j][1])) in roadSet:
                    t-=1
                res = max(res,t)
            
        return res
    
    
        