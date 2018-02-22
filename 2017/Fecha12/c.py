import math
import atexit, io, sys

buffer = io.BytesIO()
sys.stdout = buffer

@atexit.register
def write():
	sys.__stdout__.write(buffer.getvalue())

def binomial(n, k):
	res = 1
	if k > n - k:
		k = n - k
	for i in xrange(0, k):
		res *= (n - i)
		res /= (i + 1)
	return res


T = int(raw_input( ))
for t in xrange(0, T):
	n = int(raw_input( ))
	if n == 0:
		print 1
		continue
	if n == 1:
		print("x+y")
		continue

	px = n
	py = 0
	s = ""
	for i in xrange(0, n + 1):
		coef = binomial(n, i)
		if i == 0:
			s += "x^" + str(px) + "+"
			px -= 1
			continue
		if i == n:
			py += 1
			s += "y^" + str(py)
			continue
		s += str(coef) + "x"
		if px > 1:
			s += "^" + str(px)
		px -= 1
		py += 1
		s += "y"
		if py > 1:
			s += "^" + str(py)
		s += "+"
	print s