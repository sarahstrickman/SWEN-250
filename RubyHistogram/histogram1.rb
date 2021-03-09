

$stdin.each { |line|
	line.chomp!
	line.downcase!
	line.gsub!(/[^a-zA-Z]/,"")
	line.gsub!(/ /, "")
	line.gsub!(/[\n]+/, "")
	line.sub!(/^\s+/, "")
	puts(line)
}
