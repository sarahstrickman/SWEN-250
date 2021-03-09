require_relative 'line'		#access line.rb to test
require_relative 'point'	#access point.rm to build the line
require 'minitest/autorun'	#access Ruby's unit testing library

class LineTest < MiniTest::Test


	#test the initialize for the line
	def test_initialize
		@line1 = Line.new(Point.new(1.0, 5.0), Point.new(4.0, 1.0))
		assert @line1.is_a?(Line), "Line1 should be a line"
	end

	#test with points that are not aligned vertically or horizontally
	def test_length_hypotenuse
		@line1 = Line.new(Point.new(1.0, 5.0), Point.new(4.0, 1.0))
		assert_equal 5.0, @line1.length, "Line1 length should be 1"
	end

	# test with point 2 to the right of point 1
	def test_length_right
		@line1 = Line.new(Point.new(1.0, 1.0), Point.new(5.0, 1.0))
		assert_equal 4.0, @line1.length, "Line1 should have length 4"
	end

	# test with point 2 to the left of point 1
	def test_length_left
		@line1 = Line.new(Point.new(5.0, 1.0), Point.new(1.0, 1.0))
		assert_equal 4.0, @line1.length, "Line1 should have length 4"
	end

	# test with point 2 above point 1
	def test_length_up
		@line1 = Line.new(Point.new(1.0, 1.0), Point.new(1.0, 5.0))
		assert_equal 4.0, @line1.length, "Line1 should have length 4"
	end

	# test with point 2 below point 1
	def test_length_up
		@line1 = Line.new(Point.new(1.0, 5.0), Point.new(1.0, 1.0))
		assert_equal 4.0, @line1.length, "Line1 should have length 4"
	end

	#test with one of the coordinates having a negative attribute
	def test_negative
		@line1 = Line.new(Point.new(-1.0, 4.0), Point.new(2.0, 0.0))
		assert_equal 5.0, @line1.length, "Line1 should have length 5"
	end

end
