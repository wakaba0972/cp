t = int(input())

for i in range(t):
    n = int(input())
    
    s1 = bin(n)
    s2 = ""

    for j in str(n):
        s2 += bin(ord(j) - ord('0'))
    
    print(s1.count('1'), s2.count('1'))