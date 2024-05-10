#permutaions

num=[1,2,4]
permutations=[]
ar=num

def swap(a,b):
    ar=num
    temp = ar[a]
    ar[a]=ar[b]
    ar[b]=temp
n=len(num)
for j in range (n):
    for k in range(n):
        swap(j,k)
        print(ar)
