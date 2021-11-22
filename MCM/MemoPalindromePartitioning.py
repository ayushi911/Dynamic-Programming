def isPalindrome(s):
  return s==s[::-1]

t = [[ -1 for _ in range(1001)] for _ in range(1001)]
def solve(s,i,j):
    if i>=j:
        return 0
    if isPalindrome(s[i:j+1]):
        return 0
    if t[i][j]!=-1:
        return t[i][j]
    mn = sys.maxsize
    for k in range(i,j):
        temp = 1+ solve(s,i,k) + solve(s,k+1,j)
        mn = min(mn,temp)
    t[i][j]=mn
    return mn

# now to optimize the above problem further we do the following

def Optimizedsolve(s,i,j):
    if i>=j:
        return 0
    if isPalindrome(s[i:j+1]):
        return 0
    if t[i][j]!=-1:
        return t[i][j]
    mn = sys.maxsize
    for k in range(i,j):
        if t[i][k]!=-1:
            left = t[i][k]
        else:
            left = Optimizedsolve(s,i,k)
            t[i][k]=left
        if t[k+1][j]!=-1:
            right = t[k+1][j]
        else:
            right = Optimizedsolve(s,k+1,j)
            t[k+1][j]=right
        temp = 1+ left + right
        mn = min(mn,temp)
    t[i][j]=mn
    return mn
  
print(solve(arr,0,len(arr)-1))
print(Optimizedsolve(arr,0,len(arr)-1))
