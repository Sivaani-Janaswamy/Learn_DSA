def fun_fib(n):
    i,j = 0,1
    f = [i,j]
    if n==1: 
        return [i]
    if n==2:
        return f
    for k in range(0,n-2):
        f.append(i+j)
        i,j =j,i+j
    return f
print("Enter input: ")
n = int(input())
print(*fun_fib(n),sep=",")