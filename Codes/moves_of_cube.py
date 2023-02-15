import numpy as np
import random 

def op1(b):
        
    i=0
    while(1):
            
        if i>len(b)-1:
            break
        if len(b[i])==2:
            if b[i][1]=='2':
                b[i]=b[i][0]
                b=np.insert(b,i,b[i][0])
                 
        i+=1
    
    return b                
def op2(b):
    i=0
    while(1):
        if i<len(b)-1:
            if b[i][0]==b[i+1][0]:
                if len(b[i])==2 and len(b[i+1])==1:
                    b=np.delete(b,i+1)
                    b=np.delete(b,i)
                
                    if i>0:
                        i-=1
                    
                elif len(b[i+1])==2 and len(b[i])==1:
                    
                    b=np.delete(b,i)
                    b=np.delete(b,i)
                    
                    if i>0:
                        i-=1
        i+=1
        if i>len(b)-1:
            break
    return b
def rev_move(a):
    b=a[::-1]
    

    i=0
    while(1):    
        if len(b[i])>=2:
            if b[i][1]=='\'' :
                b[i]=b[i][0]
            elif b[i][1] =='2':
                pass
        elif len(b[i])==1 :
            b[i]=b[i]+"\'"
        i+=1
        if i>len(b)-1:
            break
    return b

    
print("enter a choice")
print("1. make a move")
print("2. reverse a move")
print("3. scramble")
ch=int(input())
if ch==1:
    
     b=input("enter the move")
     a=[]
     j=0
     for i in  range (0,len(b)):
         
         i=i+j
         if i>len(b)-1:
             break
         if i!=len(b)-1:
             if b[i+1]!='2' and b[i+1]!='\'':
                 a.append(b[i])
               
             else :
                 a.append(b[i]+b[i+1])
                 j=j+1
         else :
             a.append(b[i])
             
     a=np.array(a)
     
     a=op1(a)
     a=op2(a)
     print(a)
if ch==2:
    b=input("enter the move")
    #print(b)
    a=[]
    j=0
    for i in  range (0,len(b)):
        
        i=i+j
        if i>len(b)-1:
            break
        if i!=len(b)-1:
            if b[i+1]!='2' and b[i+1]!='\'':
                a.append(b[i])
              
            else :
                a.append(b[i]+b[i+1])
                j=j+1
        else :
            a.append(b[i])
            
    
    a=rev_move(a)
    a=np.array(a)
    
    a=op1(a)
    
    a=op2(a)
    print(a)
if ch==3:
    a=["U","U'","R","R'","F","F'","B","B'","D","D'","L","L'"]
    b=[]
    c=int(input("enter "))
    for i in range(0,c):
        b.append(a[random.randint(0,11)])
    b=np.array(b)
    b=op1(b)
    b=op2(b)
    print(b)
    