#a pens and b pencils
#x per unit y per unit

inp = raw_input().split(" ")
a, b, x, y = map(lambda x: int(x),inp)
print(a*x + b*y)