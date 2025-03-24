def fun_fib(n):
    i,j = 0,1
    f = [i,j]
    if n==0: 
        return [i]
    if n==1:
        return f
    while(i+j<=n):
        f.append(i+j)
        i,j =j,i+j
    return f
print("Enter input: ")
n = int(input())
print(*fun_fib(n),sep=",")