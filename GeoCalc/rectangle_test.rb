require_relative 'point'	# access the point to make the rectangle
require_relative 'rectangle'	# access rectangle
require 'minitest/autorun'	# access Ruby's unit testing library

class RectangleTest < Minitest::Test

	# test the initialization of the rectangle
	def test_initialization
		@rect1 = Rectangle.new(Point.new(0.0, 0.0), Point.new(1.0, 2.0))
		assert @rect1.is_a?(Rectangle), "This should be a rectangle you dipshit"
	end

	# test the width function from left to right
	def test_width_forward
		@rect1 = Rectangle.new(Point.new(0.0, 0.0), Point.new(1.0, 2.0))
		assert_equal 1.0, @rect1.width, "Width should be 1"
	end

	# tests the width of the rectangle but backward
	def test_width_backward
		@rect1 = Rectangle.new(Point.new(1.0, 2.0), Point.new(0.0, 0.0))
		assert_equal 1.0, @rect1.width, "Width should be 1"
	end

	# test the height from top to bottom
	def test_height_forward
		@rect1 = Rectangle.new(Point.new(0.0, 0.0), Point.new(1.0, 2.0))
		assert_equal 2.0, @rect1.height, "Height should be 2"
	end

	# test the height from bottom to top
	def test_height_backward
		@rect1 = Rectangle.new(Point.new(1.0, 2.0), Point.new(0.0, 0.0))
		assert_equal 2.0, @rect1.height, "Height should be 2"
	end

	# test the perimeter of the rectangle
	def test_perimeter
		@rect1 = Rectangle.new(Point.new(0.0, 0.0), Point.new(1.0, 2.0))
		assert_equal 6.0, @rect1.perimeter, "Perimeter should be 6"
	end

	# test the area of the rectangle
	def test_area
		@rect1 = Rectangle.new(Point.new(0.0, 0.0), Point.new(1.0, 2.0))
		assert_equal 2.0, @rect1.area, "area should be 2"
	end

end
