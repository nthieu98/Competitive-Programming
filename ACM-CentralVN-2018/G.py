t = int(input())

def mul(x, e):
  if e == 1:
    return x
  r = mul(x, e // 2)
  if e & 1:
    return (r*r*x) % b
  else:
    return (r*r) % b

for i in range(t):
  n, a, b, B = [int(x) for x in input().split()]
  # print(n, a, b, B)
  a = (a*mul(B, n-1)) % b
  print(a*B//b)