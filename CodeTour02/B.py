def computeGCD(x, y): 
   while(y): 
       x, y = y, x % y 
  
   return x

st = input()
# print(st)
Mi = st.split('-')
# print(Mi
# )
T = []
M = []
cur = 0
for i in range(len(Mi)):
  if Mi[i] == '':
    continue
  if i == 0 and st[0] != '-':
    P = Mi[i].split('+')
    for e in P:
      if e == '':
        continue
      t = e.split('/')
      T.append(int(t[0]))
      M.append(int(t[1]))
  else:
    P = Mi[i].split('+')
    # print('P', P)

    for j in range(len(P)):
      if P[j] == '':
        continue
      t = P[j].split('/')
      # print('t', t)
      if j == 0:
        z = int(t[0])
        z *= -1
        T.append(int(z))
      else:
        T.append(int(t[0]))
      M.append(int(t[1]))

# print(T)
# print(M)

Ta = T[0]
Ma = M[0]

for j in range(1, len(T)):
  Tb = T[j]
  Mb = M[j]
  Ta = Ta * Mb + Tb * Ma
  Ma = Ma * Mb
  gcd = computeGCD(Ta, Ma)
  Ta //= gcd
  Ma //= gcd

print(str(int(Ta)) + '/' + str(int(Ma)))



# print(st)