# Jump Game

if 0 not in nums:
    return(True)
else:
    m=nums.index(0)
    for i in range(m):
        if (nums[i]>(m-i)):
            return(True)
    return (False)
