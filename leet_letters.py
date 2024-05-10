#number of letters in last word

s = "hello World "
s=s.rstrip()
c=0
b=False
for i in s[::-1]:
    c+=1
    if(i==' '):
        b=True
        break
if(b):
    print (c-1)
else:
    print(len(s))
