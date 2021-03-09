require 'minitest/autorun'          #We need Ruby's unit testing library
require './FoodDB'

class FoodDBTest < MiniTest::Test
  def setup							#setup method is run automatically before each test_xxx
    @fdb = FoodDB.new("FoodDB.txt")
  end
  
  #Tests if there are entries in the DB after FoodDB.txt is read
  def test_DB_initialization
    @fdb = setup
    assert(@fdb.size > 0, "Database entries not correctly read in")
  end
  
  #Tests the 'contains_food?' method of FoodDB
  def test_contains_food
    @fdb = setup
    assert(@fdb.contains_food?("Jelly") == true, "Database does not contain Jelly")
    assert(@fdb.contains_food?("Cake") == false, "False positive found")
  end
  
  #Tests the 'contains_recipe?' method of FoodDB
  def test_contains_recipe
    @fdb = setup
    assert(@fdb.contains_recipe?("PB&J Sandwich") == true, "Database does not contain recipe when it should")
    assert(@fdb.contains_recipe?("Lemon Pie") == false, "False positive found")
  end
  
  #Tests the 'contains?' method of FoodDB
  def test_contains
    @fdb = setup
    assert(@fdb.contains?("PB&J Sandwich") == true, "Database does not contain recipe when it should")
    assert(@fdb.contains?("Lemon Pie") == false, "False positive found")
    assert(@fdb.contains?("Jelly") == true, "Database does not contain Jelly")
    assert(@fdb.contains?("Cake") == false, "False positive found")

  end
  
  #Tests the 'get_food' method of FoodDB
  def test_get_food
    @fdb = setup
    @food = @fdb.get_food("Jelly")
    assert(@food != nil, "basicFood not gotten")
    assert(@food.name == "Jelly", "wrong food gotten")

    @food = @fdb.get_food("Ice cream")
    assert(@food == nil, "Food gotten when food doesn't exist in database")
  end
  
  #Tests the 'get_recipe' method of FoodDB
  def test_get_recipe
    @fdb = setup
    @food = @fdb.get_recipe("PB&J Sandwich")
    assert(@food != nil, "Recipe not gotten")
    assert(@food.name == "PB&J Sandwich", "wrong recipe gotten")

    @food = @fdb.get_recipe("Chocolate Cake")
    assert(@food == nil, "Recipe gotten when recipe doesn't exist in database")
  end
  
  #Tests the 'get' method of FoodDB
  def test_get
    @fdb = setup
    @food = @fdb.get("Jelly")
    assert(@food != nil, "basicFood not gotten")
    assert(@food.is_a?(BasicFood), "Not a BasicFood")
    assert(@food.name == "Jelly", "wrong food gotten")

    @food = @fdb.get("Ice cream")
    assert(@food == nil, "Food gotten when food doesn't exist in database")

    
    @food = @fdb.get("PB&J Sandwich")
    assert(@food != nil, "Recipe not gotten")
    assert(@food.is_a?(Recipe), "not a recipe found")
    assert(@food.name == "PB&J Sandwich", "wrong recipe gotten")

    @food = @fdb.get("Chocolate Cake")
    assert(@food == nil, "Recipe gotten when recipe doesn't exist in database")
  end
  
  #Tests the 'find_matches' method of FoodDB
  def test_find_matches
    @fdb = setup
    @list = @fdb.find_matches("Ch")
    assert(@list.length >= 2, "Expected at least 2 entries to be found, didn't get that much")
  end
  
  #Tests the 'add_basicFood' method
  def test_add_food
    @fdb = setup
    assert(@fdb.basicFoods.length >= 7, "at least 7 foods were originally read into the file")
  end
  
  #Tests the 'add_recipe' method
  def test_add_recipe
    @fdb = setup
    assert(@fdb.recipes.length >= 2, "at least 2 recipes were originally added from the file")
  end
  
  #Tests the addition of a Recipe with a Recipe as one of its ingredients
  def test_recipe_within_recipe
    @fdb = setup
    idk = Recipe.new("Double PB&J", [@fdb.get_recipe("PB&J Sandwich"), @fdb.get_recipe("PB&J Sandwich")])
    
    bool = @fdb.add_recipe("Double PB&J", ["PB&J Sandwich", "PB&J Sandwich"])
    assert(bool == true, "whoops fuck you")
  end
end
