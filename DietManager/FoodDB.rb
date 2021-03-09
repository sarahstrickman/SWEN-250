#require './BasicFood'
require './Recipe'

class FoodDB
  attr_reader :size, :basicFoods, :recipes
  
  #filename is the name of the FoodDB file to be used, ex: "FoodDB.txt"
  def initialize(filename)
    @size = 0
  
    @dbFile = File.new(filename) #Open the database file
    
    @basicFoods = []
    @recipes = []
    
    #Read in the FoodDB file
    @dbFile.each{|line|
      values = line.split(',') #Split the line up at the commas
      
      if values[1] == 'b' #BasicFood case
        add_basicFood(values[0], values[2].to_i) #Add the new food to our list
      elsif values[1] == 'r' #Recipe case
        values[2..values.length].each{|ingredient| ingredient.chomp!} #Remove newline characters
        add_recipe(values[0], values[2..values.length]) #Add the new Recipe to the recipes list
      else #The entry is invalid
        values[0].chomp.eql?("") ? nil : puts("Invalid food type found in FoodDB.txt")
      end
    }
  end
  
  #Returns true if a BasicFood with the name foodName exists in the database
  def contains_food?(foodName)
    contains = false
     
      @basicFoods.each { |food|
        if foodName == food.name
	  contains = true
	    end
	}
	
    contains
  end
  
  #Returns true if a Recipe with the name recipeName exists in the database
  def contains_recipe?(recipeName)
    contains = false
    
      @recipes.each { |entry|
	if entry.name == recipeName
	  contains = true
	    end
	}
	
    contains
  end
  
  #Returns true if there exists some entry in the database with the name itemName
  def contains?(itemName)
  
    contains_food?(itemName) || contains_recipe?(itemName)
	
  end
  
  #Returns the BasicFood of the given name if it exists within the database, nil otherwise
  def get_food(foodName)
    item = nil
    @basicFoods.each { |food|
      if food.name == foodName
      item = food
      end
    }
  item
  end
  
  #Returns the Recipe of the given name if it exists within the database, nil otherwise
  def get_recipe(recipeName)
    item = nil
    @recipes.each { |recipe|
      if recipe.name == recipeName
        item = recipe
      end
    }
    item
  end
  
  #Returns the item of the given name if it exists within the database, nil otherwise
  def get(itemName)
    #If the item is a BasicFood and is in the database, return it
    #Else, if the item is a Recipe and is in the database, return it
    #Return nil otherwise
    item = nil
    @basicFoods.each { |bfood|
      if bfood.name == itemName
        item = bfood
        return item
      end
    }
    @recipes.each { |rec|
      if rec.name == itemName
	item = rec
	return item
      end
    }

    item
  end
  
  #Returns a list of all items in the database that begin with the given prefix
  def find_matches(prefix)
    items = []
    @basicFoods.each { |basicfood|
    if basicfood.name.start_with?(prefix)
      items.push(basicfood)
    end
    }
    @recipes.each { |recipe|
      if recipe.name.start_with?(prefix)
	items.push(recipe)
      end
    }
    items
  end
  
  #Constructs a new BasicFood and adds it to the database, returns true if successful, false otherwise
  def add_basicFood(name, calories)
    #Don't add if it is already in the database
    if !contains_food?(name)
      food = BasicFood.new(name, calories)
      @basicFoods.push(food)
      @size += 1
      return true
    end

    false
  end
  
  #Constructs a new Recipe and adds it to the database, returns true if successful, false otherwise
  def add_recipe(name, ingredientNames)
    #Don't add if it is already in the database
	
    if !contains_recipe?(name)
      ingredients = []
      ingredientNames.each { |name|
	actualfood = get(name)
	if actualfood == nil
	  return false
	end
	ingredients.push(actualfood)
      }

      newrecipe = Recipe.new(name, ingredients)

      @recipes.push(newrecipe)
      @size += 1
      return true
    end
	 
    false
  end
  
  #Saves the database to @dbFile
  def save
    File.open(@dbFile, "w+"){|fOut|
      #Write all BasicFoods to the database
      @basicFoods.each{|food| fOut.write("#{food.name},b,#{food.calories}\n")}
      fOut.write("\n")
      
      #Write all Recipes to the database
      @recipes.each{|recipe|
        fOut.write("#{recipe.name},r")
        
        #List the ingredients after the recipe name
        recipe.ingredients.each{|ingredient| fOut.write(",#{ingredient.name}")}
        fOut.write("\n")
      }
    }
  end
end
