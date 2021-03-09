# Rectangles are defined by to diagonal corner Points.
# Rectangles are immutable - once constructed the corner
# points cannot be changed.

require './point'

class Rectangle
  # Methods below are private.
  private

  # Initialize the Rectangle corner points from those
  # provided to Rectangle.new.
  # The instance variables are @c1 and @c2
  def initialize(c1 = Point.new, c2 = Point.new)
    @c1 = c1
    @c2 = c2
  end

  # Methods below are public
  public

  # Allow read access to the two corner points.
  attr_reader :c1, :c2

  # Return the width of the rectangle (absolute value of difference between
  # the corner X coordinates).
  # You must define the method named 'width' in its entirety. Use the code in
  # line.rb and circle.rb as templates for creating such a method.
  def width
    if c1.x > c2.x
      c1.x - c2.x
    else
      c2.x - c1.x
    end
  end

  # Return the height of the rectangle (absolute value of difference between
  # the corner Y coordinates).
  # You must define the method named 'height' in its entirety. Use the code in
  # line.rb and circle.rb as templates for creating such a method.
  def height
    if c1.y > c2.y
      c1.y - c2.y
    else
      c2.y - c1.y
    end
  end


  # Return the perimeter of the rectangle.
  # You must define the method named 'perimeter' in its entirety.
  # This *MUST* be written using the width and height methods
  def perimeter
    (2 * height) + (2 * width)
  end


  # Return the area of the rectangle
  # You must define the method named 'area' in its entirety.
  # This *MUST* be written using the width and height methods
  def area
    width * height
  end


  def to_s
    "Rectangle corners #{c1} and #{c2}"
  end
end
