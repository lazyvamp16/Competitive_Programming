# Stock

m = min(prices)
i = prices.index(m)
u=max(prices[i:])
if (u > i):
    return(u-i)
else:
    return 0 
