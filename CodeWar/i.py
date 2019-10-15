_count = 0

def _free(t, m, nr, nc):
	if t == 0:
		return False
	for it in t:
		if (it[0] < 0) or (it[1] < 0) or (it[0] >= nr) or (it[1] >= nc):
			return False 
		if m[it[0]][it[1]] == 1:
			return False
	return True

def _block(i, ra, r, c):
	if i == 0:
		if ra == 1:
			return [(r, c), (r, c+1), (r, c+2), (r, c+3)]
		if ra == 2:
			return [(r, c), (r+1, c), (r+2, c), (r+3, c)]
		else:
			return 0
	elif i == 1:
		if ra == 1:
			return [(r, c), (r, c+1), (r+1, c), (r+1, c+1)]
		else:
			return 0
	elif i == 2:
		if ra == 1:
			return [(r, c), (r+1, c), (r+1, c-1), (r+1, c-2)]
		elif ra == 2:
			return [(r, c), (r+1, c), (r+2, c), (r+2, c+1)]
		elif ra == 3:
			return [(r, c), (r+1, c), (r, c+1), (r, c+2)]
		elif ra == 4:
			return [(r, c), (r, c+1), (r+1, c+1), (r+2, c+1)]
		else:
			return 0
	elif i == 3:
		if ra == 1:
			return [(r, c), (r, c+1), (r+1, c), (r+1, c-1)]
		elif ra == 2:
			return [(r, c), (r+1, c), (r+1, c+1), (r+2, c+1)]
		else:
			return 0
	elif i == 4:
		if ra == 1:
			return [(r, c), (r, c+1), (r+1, c+1), (r+1, c+2)]
		elif ra == 2:
			return [(r, c), (r+1, c), (r+1, c-1), (r+2, c-1)]
		else:
			return 0
	elif i == 5:
		if ra == 1:
			return [(r, c), (r+1, c), (r+1, c+1), (r+1, c+2)]
		elif ra == 2:
			return [(r, c), (r+1, c), (r+2, c), (r+2, c-1)]
		elif ra == 3:
			return [(r, c), (r+1, c), (r+2, c), (r+2, c+1)]
		elif ra == 4:
			return [(r, c), (r, c+1), (r+1, c), (r+2, c)]
		else:
			return 0
	elif i == 6:
		if ra == 1:
			return [(r, c), (r+1, c-1), (r+1, c), (r+1, c+1)]
		elif ra == 2:
			return [(r, c), (r+1, c), (r+1, c+1), (r+2, c)]
		elif ra == 3:
			return [(r, c), (r+1, c), (r+1, c-1), (r+2, c)]
		elif ra == 4:
			return [(r, c), (r, c+1), (r, c+2), (r+1, c+1)]
		else:
			return 0
	else:
		return 0

def _first_free(m, nr, nc):
	for ir in range(nr):
		for ic in range(nc):
			if m[ir][ic] == 0:
				return ir, ic
	return (-1, -1)

def _valid(i, ra, m, r, c, nr, nc):
	return _free(_block(i, ra, r, c), m, nr, nc)

def _update(i, ra, m, r, c):
	global _count
	_count += 4
	for x in _block(i, ra, r, c):
		m[x[0]][x[1]] = 1


def _restore(i, ra, m, r, c):
	global _count
	_count -= 4
	for x in _block(i, ra, r, c):
		m[x[0]][x[1]] = 0

def _full(m, nr, nc):
	# for i in range(nr):
	# 	for j in range(nc):
	# 		if m[i][j] == 0:
	# 			return False
	# return True
	global _count
	return (_count == nr * nc)

def _try(blockNumber, m, nr, nc):
	if _full(m, nr, nc):
		return True

	r, c = _first_free(m, nr, nc)

	for i in range(7):
		if blockNumber[i] > 0:
			blockNumber[i] -= 1
			for ra in range(1, 5):
				if _valid(i, ra, m, r, c, nr, nc):
					_update(i, ra, m, r, c)
					if _try(blockNumber, m, nr, nc) == True:
						_restore(i, ra, m, r, c)
						return True
					_restore(i, ra, m, r, c)
			blockNumber[i] += 1

	return False

def findLargestRectangle(blockNumber):
	res = 0
	m = []
	for _ in range(80):
		m.append([0] * (80))
	for i in list(reversed(range(sum(blockNumber)+1))):
		S = i*4
		for k in range(1, S+1):
			j = k
			if S % j == 0:
				if _try(blockNumber, m, S//j, j) == True:
					res = i*4
					return res
	return res

if __name__ == "__main__":
	bn = [0,1,0,6,6,0,7]
	print(findLargestRectangle(bn))