a = [1, 1, 3, 3]
b = [2, 2, 4, 4]

def nonOverlappingArea(a, b):
  if a[0] > b[0]: 
      swap(a, b)
  elif a[0] == b[0]:
      if a[1] > b[1]:
        swap(a, b)
    

nonOverlappingArea(a, b)