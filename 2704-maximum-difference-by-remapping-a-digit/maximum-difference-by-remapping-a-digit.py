class Solution(object):
    def minMaxDifference(self, num):
        s1 = str(num)
        s2 = str(num)
        for i in s1:
            if(i!='9'):
                ch = i
                s1 = s1.replace(ch,'9')
                break
        mx = int(s1)
        
        ch = s2[0]
        s2 = s2.replace(ch,'0')
        mn = int(s2)
        
        return (mx-mn)