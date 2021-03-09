require 'minitest/autorun'          #We need Ruby's unit testing library
require_relative 'Recipe'

class RecipeTest < MiniTest::Test
  def setup
    @bread = BasicFood.new("Bread", 80)
    @pb = BasicFood.new("Peanut Butter", 175)
    @jelly = BasicFood.new("Jelly", 155)
    @recipe = Recipe.new("PB&J", [@bread, @pb, @jelly, @bread])
  end

  #Tests the initial construction of a Recipe
  def test_construction
    @recipe = setup
    assert @recipe.is_a?(Recipe)
  end

  #Test the calorie count of the recipe
  def test_calories
    @recipe = setup
    cals = 490
    assert_equal(cals, @recipe.calories)
  end 
  
  #Tests the 'to_s' method of Recipe
  def test_to_s
    @recipe = setup
    actual = "PB&J 490\n  Bread 80\n  Bread 80\n  Jelly 155\n  Peanut Butter 175"
    assert_equal(actual, @recipe.to_s)
  end
  
end
