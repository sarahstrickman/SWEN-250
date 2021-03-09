
class Concordance

  attr_reader :hash

  def initialize
    ### FILL IN ANY CODE YOU MAY NEED HERE

    # This is will create an instance variable called @hash that that starts
    # with an empty array when the key doesn't exist. No need to modify this.
    @hash = Hash.new { |h, k| h[k] = [] }
    @line = 0
  end

  # Add a single line of text to the concordance.
  #
  # Delegates all functionality to other methods to clean, split, and index
  # according to the line.
  #
  # Modifies the concordance, hence the bang in the method name.
  #
  # THIS METHOD NEEDS NO MODIFICATION
  #
  def process!(line)
    index!(get_words(clean(line)))
  end

  # Clean the string in preparation for splitting and indexing
  #
  # The line should be converted to lower case letters
  # All non-letter characters should be replaced with a space
  #
  # returns a string of only lowercase letters and spaces
  #
  def clean(line)
    ### FILL IN YOUR CODE HERE
    n = line.downcase
    c = n.gsub(/[^a-zA-z]/," ")
  end

  # Convert the string of cleaned words into an array of words
  #
  # Multiple consecutive spaces should be treated as one
  # No empty strings in the array.
  #
  # returns an array of words
  #
  def get_words(line)
    ### FILL IN YOUR CODE HERE
    if line == nil
      
    else
      words = line.split(/ +/)
      words
    end
  end

  # Tally up line of words in the concordance dictionary for the current line
  #
  # If a word occurs multiple times in one line, the line number should not
  # occur more than once.
  #
  # Increment an instance variable that keeps track of the current line
  #
  # returns nothing, but @hash is populated with another line of text
  #
  def index!(words)
    ### FILL IN YOUR CODE HERE
    @line += 1
    if words == nil
    else
      words.each { |word|
        if !@hash[word].include?(@line)
          @hash[word].push(@line)
        else

        end
      }
    end
  end

  # Return a string of the concordance dictionary formatted prettily
  #
  # The concordance should be sorted by word, and with comma-separated integers
  # on each line. The line numbers should be sorted in ascending order as well.
  # For example,
  #
  #   apples: 4,5,6
  #   bananas: 5,8,9
  # (no indentation)
  #
  # HINT: the 'join' method on Array might be helpful.
  #        http://ruby-doc.org/core-2.4.3/Array.html#method-i-join
  #
  # returns: a formatted string for pretty printing
  #
  def pretty_format
    pretty = ""
    sorted = @hash.sort_by { |name, arrays| name }

    sorted.each { |name, array|
      pretty.concat(name)
      pretty.concat(": ")
      pretty.concat("#{@hash[name].join(",")}\n")

    }
    pretty

    ### FILL IN YOUR CODE HERE
  end

end
