# project euler problem 13
# sum of 100 50-digit numbers

def main():
	f = open("prob13.txt","r")
	num = 0
	for line in f:
		num = num + eval(line)

	print("The answer:", str(num)[:10])


main()