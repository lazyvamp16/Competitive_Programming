#Newton raphson

x=1
while(x!=0):
    x=int(input("enter"))
    x0=x/2
    x1 = x0 - ((x0*x0-x)/(2*x0))
    while (abs((x1*x1)- x) > 0.9):
        x0=x1
        x1= x1-((x1*x1-x)/(2*x))
    print ((x1))
