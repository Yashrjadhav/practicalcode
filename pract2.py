class setop:
    def input(self):
        self.set1=[]
        self.set2=[]
        n=int(input("enter the no of elements in set 1"))
        for i in range(n):
            n1=int(input("enter elements"))
            if(n1 not in self.set1):
                self.set1.append(n1)
        print("{",end=" ")
        for i in range(len(self.set1)-1):
            print(self.set1[i],end=" ,")
        print(self.set1[len(self.set1)-1],end=" ")
        print("}")

        m=int(input("enter the no of elements in set 1"))
        for i in range(m):
            m1=int(input("enter elements"))
            if(m1 not in self.set2):
                self.set2.append(m1)
        print("{",end=" ")
        for i in range(len(self.set2)-1):
            print(self.set2[i],end=" ,")
        print(self.set2[len(self.set2)-1],end=" ")
        print("}")

    def remove(self):
        a=int(input("enter the element you want to remove"))
        self.set1.remove(a)
        print("{",end=" ")
        for i in range(len(self.set1)-1):
            print(self.set1[i],end=" ,")
        print(self.set1[len(self.set1)-1],end=" ")
        print("}")

    def intersection(self):
        self.set3=[]
        for i in self.set1:
            if i in self.set2:
                self.set3.append(i)
        for i in range(len(self.set3)-1):
            print(self.set3[i],end=" ,")
        print(self.set3[len(self.set3)-1],end=" ")
        print("}")
    
    def union(self):
        self.set4=self.set1+self.set2
        for i in self.set1:
            if i in self.set2:
                self.set4.remove(i)
        print("{",end=" ")
        for i in range(len(self.set4)-1):
            print(self.set4[i],end=" ,")
        print(self.set4[len(self.set4)-1],end=" ")
        print("}")
    
    def diffrence(self):
        self.set5=[]
        for i in self.set1:
            if i not in self.set2:
                self.set5.append(i)
        for i in self.set2:
            if i not in self.set1:
                self.set5.append(i)
        for i in range(len(self.set5)-1):
            print(self.set5[i],end=" ,")
        print(self.set5[len(self.set5)-1],end=" ")
        print("}")

s=setop()
s.input()
s.remove()
s.intersection()
s.union()
s.diffrence()
        
        
        



