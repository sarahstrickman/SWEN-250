
bag = Hash.new(0)
arr = Array.new

$stdin.each { |line|
	words = line.split(/ +/)
	words.each { |word|
		bag[word] += 1
	}
}

sorted = (bag.sort_by { |key, word| [-word, key] }.to_h)


sorted.each { |key, word|
	str = ""
	count = word
	length = 12 - key.length
	spaces = ""

	(1..count).each { |i| 
		str.insert(0, "*")	
	}

	(1..length).each { |j| 
		spaces.insert(0, " ")
	}
	puts ("#{key} #{spaces}#{str}") unless word < 2
}
