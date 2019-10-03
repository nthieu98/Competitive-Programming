t = int(raw_input())

def mul(x, e, b):
  if e == 1:
    return x
  r = mul(x, e // 2, b)
  if e & 1:
    return (r*r*x) % b
  else:
    return (r*r) % b

for i in range(t):
  n, a, b, B = [int(x) for x in raw_input().split()]
  # print(n, a, b, B)
  a = (a*mul(B, n-1, b)) % b
  print a*B//b
