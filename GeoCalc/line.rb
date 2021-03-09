# Lines are defined by their two end points.
# Lines are immutable - once constructed the end
# points cannot be changed.
require './point'
# require './math'

class Line
  # Methods below are private.
  private

  # Initialize the Line end points from those
  # provided to Line.new.
  # The instance variables are @p1 and @c2
  def initialize(p1 = Point.new, p2 = Point.new)
    @p1 = p1
    @p2 = p2
  end

  # Methods below are public
  public

  # Allow read access to the two end points.
  attr_reader :p1, :p2

  # Compute the line length (the distance between its
  # end points)
  def length
    Math.sqrt((p1.x - p2.x)**2 + (p1.y - p2.y)**2)
  end

  def to_s
    "Line from #{p1} to #{p2}"
  end
end
