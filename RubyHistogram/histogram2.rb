
bag = Hash.new(0)

$stdin.each { |line|
	words = line.split(/ +/)
	words.each { |word| 
		#puts(word + "\n")
		bag[word] += 1
	}
	bag.each { |key, word|
		puts("#{key} : #{word}") unless word < 2
	}
}
