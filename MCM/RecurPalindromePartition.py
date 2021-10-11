def isPalindrome(s):
  return s==s[::-1]

def mincost(arr,i,j):
  if i>=j or isPalindrome(arr[i:j+1])==True:
    return 0
  mini = sys.maxsize
  for k in range(i,j):
    temp = (mincost(arr,i,k)
          +mincost(arr,k+1,j)
          +1)
    if temp<mini:
      mini = temp
  return mini

arr = "nitisanas"
print(mincost(arr,0,len(arr)-1))
