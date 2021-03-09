# Unit tests for concordance.rb

require_relative 'concordance'
require 'minitest/autorun'          #We need Ruby's unit testing library

class ConcordanceTest < MiniTest::Test

  # Remember: this gets run prior to each individual test_* method
  def setup
    @concordance = Concordance.new
  end

  def test_clean_identity
    assert_equal 'alpha beta', @concordance.clean('alpha beta')
  end

  def test_clean_lowercase
    assert_equal 'beta gamma', @concordance.clean('BETA gammA')
  end

  def test_clean_non_alpha
    assert_equal 'gamma delta', @concordance.clean('gamma$delta')
  end

  def test_clean_multispace
    assert_equal '  delta  epsilon', @concordance.clean(' $delta$$epsilon')
  end

  def test_get_words_singleton
    assert_equal ['apple'], @concordance.get_words('apple')
  end

  def test_get_words_two
    assert_equal ['apple', 'banana'], @concordance.get_words('apple banana')
  end

  def test_get_words_two_multispace
    assert_equal ['orange', 'pear'], @concordance.get_words('orange   pear')
  end

  def test_index_1_word_1_line
    @concordance.index! ['apple']
    assert_equal @concordance.hash, {'apple' => [1]}
  end

  def test_index_2_words_1_line
    @concordance.index! ['apple', 'banana']
    assert_equal({ 'apple' => [1], 'banana' => [1] }, @concordance.hash)
  end

  def test_index_2_words_2_lines
    @concordance.index! ['apple', 'banana']
    @concordance.index! ['apple', 'orange']
    expected = { 'apple' => [1,2], 'banana' => [1], 'orange' => [2] }
    assert_equal expected, @concordance.hash
  end

  def test_index_repeated_word
    @concordance.index! ['apple', 'banana', 'apple']
    assert_equal({ 'apple' => [1], 'banana' => [1] }, @concordance.hash)
  end

  def test_pretty_format_one_word
    @concordance.index! ['b', 'c', 'a']
    @concordance.index! ['c', 'b', 'b']
    # This next line might look unfamiliar. This is just a string that is
    # formatted over multiple lines. No need to modify - just easier to read.
    expected = <<-EOS
a: 1
b: 1,2
c: 1,2
EOS
    assert_equal expected, @concordance.pretty_format
  end

  def test_all_together
    # This next line might look unfamiliar. This is just a string that is
    # formatted over multiple lines. No need to modify - just easier to read.
    expected = <<-EOS
diggs: 1
miranda: 1,2
odom: 1,2,3
soo: 1
EOS
    @concordance.process! 'miranda$odom  soo, diggs'
    @concordance.process! 'miranda    odom'
    @concordance.process! 'odom'
    assert_equal expected, @concordance.pretty_format
  end

end
