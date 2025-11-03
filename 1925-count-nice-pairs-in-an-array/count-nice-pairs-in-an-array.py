class Solution(object):
    def countNicePairs(self, nums):
        ls = {}
        MOD = 1e9+7
        cnt=0
        for i in nums:
            sm = i - int(str(i)[::-1])
            if(sm in ls): 
                cnt= int((cnt + ls[sm])%MOD)
                ls[sm]+=1
            else: ls[sm]=1
        return cnt
        """
        :type nums: List[int]
        :rtype: int
        """
        