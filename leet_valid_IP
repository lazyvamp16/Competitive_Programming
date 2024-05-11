# Valid IP Address

IPAddress = input("Enter IP Address")
IPAddress=IPAddress+'.'
count=0
a=''
for i in IPAddress:
    if i!='.': 
        a=a+i
    else:
        print(a)
        count+=1
        if (a.isnumeric()!=True): print(False)
        if (int(a)>255 or int(a)<0 ): print(False) 
        a=''
if count!=4: print (False)
print (True)
