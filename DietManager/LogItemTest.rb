require 'minitest/autorun'          #We need Ruby's unit testing library
require_relative './LogItem'

class LogItemTest < MiniTest::Test
  def setup
    @item = LogItem.new("Orange", Date.today)
  end
  
  #Tests the basic construction of a LogItem object
  def test_construction
    @item = setup
    assert @item.is_a?(LogItem)
  end
  
  #Tests the 'to_s' method of LogItem
  def test_to_s
    @item = setup
    actual = "#{@item.date},Orange"
    assert_equal(actual, @item.to_s)
  end
  
end
