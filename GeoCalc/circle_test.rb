require_relative 'point'	#used to access the points used to make the circle
require_relative 'circle'	#used to test
require 'minitest/autorun'	#access Ruby's unit testing library

class CircleTest < MiniTest::Test

	# test the initialization of the circle
	def test_initialize
		@circle1 = Circle.new(Point.new(0.0, 0.0), Point.new(1.0, 0.0))
		assert @circle1.is_a?(Circle), "Circle1 should be a circle"
	end

	# test the diameter of the circle
	def test_diameter
		@circle1 = Circle.new(Point.new(0.0, 0.0), Point.new(1.0, 0.0))
		assert_equal 2.0, @circle1.diameter, "Diameter should be 2"
	end

	# test the diameter of the circle with the point on the circle being negative
	def test_diameter_negative
		@circle1 = Circle.new(Point.new(0.0, 0.0), Point.new(-1.0, 0.0))
		assert_equal 2.0, @circle1.diameter, "Diameter should be 2"
	end

	# test the circumference of the circle
	def test_circumference
		@circle1 = Circle.new(Point.new(0.0, 0.0), Point.new(1.0, 0.0))
		assert_equal 2.0 * Math::PI, @circle1.circumference, "Circumference should be 2 * PI"
	end

	# test the circumference of the circle, but with a negative number
	def test_circumference_negative
		@circle1 = Circle.new(Point.new(0.0, 0.0), Point.new(-1.0, 0.0))
		assert_equal 2.0 * Math::PI, @circle1.circumference, "Circumference should be 2 * PI"
	end

	# test the area function of the circle
	def test_area
		@circle1 = Circle.new(Point.new(0.0, 0.0), Point.new(1.0, 0.0))
		assert_equal Math::PI, @circle1.area, "Area should be PI"
	end

	# test the area function with a negative number
	def test_area_negative
		@circle1 = Circle.new(Point.new(0.0, 0.0), Point.new(-1.0, 0.0))
		assert_equal Math::PI, @circle1.area, "Area should be PI"
	end



end
