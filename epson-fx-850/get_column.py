#!/usr/bin/python

# Run for cyrillic symbol 'B':
# 
# user@comp:~$ python get_column.py 
# 
# 1 2 3 4 5 6 7 8
# 8 5 1
# 8 5 1
# 8 5 1
# 8 4 3 2
# 
# 
# 
# 0, 255, 145, 145, 145, 142, 0, 0, 0

def symb_code(column):
	res = 0
	for val in column:
		if not val:
			res += 2**14
		else:
			res += 2**(val - 1)
	return str(res)
def main():
	code = []
	for i in xrange(9):
		col_vals = map(int, raw_input().split())
		if not len(col_vals):
			code.append("0")
		else:
			code.append(symb_code(col_vals))
	print ", ".join(code)

if __name__ == "__main__":
	main()
