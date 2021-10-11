def mincost(arr,i,j):
  if i==j:
    return 0
  mini = 10**9
  for k in range(i,j):
    temp = mincost(arr,i,k)+mincost(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j])
    if temp<mini:
      mini = temp
  return mini

arr = [1, 2, 3, 4, 3]
print(mincost(arr,1,len(arr)-1))
