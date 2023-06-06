n=int(input("enter the no of records "))
l1=[]
table=[]
for i in range(n):
    l2=[]
    l2.append(input("enter the name"))
    l2.append(int(input("enter the phn no")))
    l1.append(l2)
print(l1)

def hashtable1():
    for i in range(n):
        table.append(0)
    for i in range(n):
        key=l1[i][1]%n
        if table[key]==0:
            table[key]=l1[i][1]
        else:
            linearprobing(key,l1[i][1])
    print(table)

def hashtable2():
    for i in range(n):
        table.append(0)
    for i in range(n):
        key=l1[i][1]%n
        if table[key]==0:
            table[key]=l1[i][1]
        else:
            doublehashing(key,l1[i][1])
    print(table)

def linearprobing(key,i):
    r=(key+1)%n
    while(table[r]!=0):
        r=(r+1)%n
    table[r]=i
def doublehashing(key,i):
    h=key
    d=1
    while(table[h]!=0):
        h=(key+d*(1+i%(n-1)))%n
        d+=1
    table[h]=i

hashtable1()
#hashtable2()



