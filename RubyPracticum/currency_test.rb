require_relative 'currency_util' 
require 'minitest/autorun'          

class CurrencyTest <  MiniTest::Test 

  def close_enough(expected, actual, epsilon = 0.001)
    return (expected - actual).abs <= epsilon
  end

  ### Tests of to_dollars ###

  def test_001a_convert_3_33_units_to_dollars
    assert close_enough(5.13, to_dollars('GBP', 3.33))
    assert close_enough(2.66, to_dollars('CAN', 3.33))
    assert close_enough(4.26, to_dollars('AUD', 3.33))
    assert close_enough(3.73, to_dollars('EUR', 3.33))
    assert close_enough(3.33, to_dollars('USD', 3.33))
  end

  def test_001b_your_tests
    assert close_enough(-4.26, to_dollars('AUD', -3.33))
    assert close_enough(0.00, to_dollars('EUR', 0.00))
  end

  ### Tests of from_dollars ###

  def test_002a_convert_3_33_units_to_dollars
    assert close_enough(2.16, from_dollars('GBP', 3.33))
    assert close_enough(4.16, from_dollars('CAN', 3.33))
    assert close_enough(2.60, from_dollars('AUD', 3.33))
    assert close_enough(2.97, from_dollars('EUR', 3.33))
    assert close_enough(3.33, from_dollars('USD', 3.33))
  end

  def test_002b_your_tests
    assert close_enough(0.00, from_dollars('GBP', 0.00))
    assert close_enough(-4.16, from_dollars('CAN', -3.33))
  end

  ### Tests of parse ###
  
  def test_003a_normal_line
    expect = ['AUD', '1.56' ,'EUR']
    actual = parse('AUD,1.56,EUR')
    assert_equal(expect, actual)
  end

  def test_003b_your_first_test
    assert_equal [], parse(""), "Should be empty list"
  end

  def test_003c_your_second_test
    exp = ['i know', 'this', 'isnt a currency', 'thing', 'but', 'this should', 'work', 'with any', 'file', ' 45.7', ' -3']
    act = parse('i know,this,isnt a currency,thing,but,this should,work,with any,file, 45.7, -3')
    assert_equal(exp, act)
  end
end
