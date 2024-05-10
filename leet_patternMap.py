#pattern map
def func():
    pattern = "abba"
    s = "dog cat cat fish"
    
    d={}
    k=0
    i=0
    for j in range(k,len(s)):
        if(s[j]==' '):
            if(pattern[i] not in d):
                d[pattern[i]]=s[k:j]
                i+=1
                k=j+1
            else:
                if(d[pattern[i]]!=s[k:j]):
                    return("False")
    if(pattern[i] in d):
        print("in",pattern[i],s[k::])
        if(d[pattern[i]]==s[k::]):
            return("False")
    
    return("True")
                
print(func())
