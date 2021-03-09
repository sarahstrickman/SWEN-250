"""
	Fizzbuzz lab assignment:
checks if a number is divisible by 5 or 7
"""

def fizzbuzz(num):
	"""
	checks if a number is divizible be 5 and/or 7.
	Prints fizz if num is divisible by 5
	Prints buzz if num is divisible by 7
	Prints fizzbuzz if num is divisible by both
	Otherwise prints the integer itself
	"""
	if num % 5 == 0 and num % 7 == 0:
		print("FizzBuzz")
	elif num % 5 == 0:
		print("Fizz")
	elif num % 7 == 0:
		print("Buzz")
	else:
		print(num)


def main():
	"""
	Asks user to input a number, and converts it to
	an integer.
	"""
	num = input("Input an integer")
	try:
		int(num)
	except:
		print("Not an integer")
	fizzbuzz(num)


if __name__ == "__main__":
	main()
