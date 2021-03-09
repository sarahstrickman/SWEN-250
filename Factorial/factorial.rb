# factorial(n) is defined as n*n-1*n-2..1 for n > 0
# factorial(n) is 1 for n=0
# Let's raise an exception if factorial is negative
# Let's raise an exception if factorial is anything but an integer


class NegativeError < StandardError
end

class StringError < StandardError
end


def factorial(n)
	if n.is_a? String
		raise StringError, "n is a string"
	elsif n < 0
		raise NegativeError, "n is less than 0"
	else
		result = 1
		last = n - 1
		(0..last).each { |i|
			result = result * (n - i)
		}
		result
	end
end
