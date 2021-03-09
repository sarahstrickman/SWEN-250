require './FoodDB'
require './Log'

class DietManager
  def initialize()
    @dbFile = "FoodDB.txt"
    @logFile = "DietLog.txt"
    @database = FoodDB.new(@dbFile)
    @log = Log.new(@logFile)
    @dbChanged = false
    @logChanged = false

  end


  
  #Handles the 'quit' command which exits the DietManager
  def command_quit
    command_save
    exit(0)
  end
  
  #Handles the 'save' command which saves the FoodDB and Log if necessary
  def command_save
    if @dbChanged == true
      @database.save
      @dbChanged = false
    end
    if @logChanged == true
      @log.save
      @logChanged = false
    end
  end

  #Handles the 'new food' command which adds a new BasicFood to the FoodDB
  def command_newFood(name, calories)
    bool = @database.add_basicFood(name, calories)
    if bool == false
      puts "Food already in database"
    end
    @dbChanged = true
  end

  #Handles the 'new recipe' command which adds a new Recipe to the FoodDB
  def command_newRecipe(name, ingredients)
    bool = @database.add_recipe(name, ingredients)
    if bool == false
      puts "Recipe already in database or ingredients not in database"
    end
    @dbChanged = true
  end

  #Handles the 'print' command which prints a single item from the FoodDB
  def command_print(name)
    food = @database.get(name)
    if food.is_a?(BasicFood) || food.is_a?(Recipe)
      puts food.to_s
    else
      puts "Error in pinting the specified food."
    end
  end

  #Handles the 'print all' command which prints all items in the FoodDB
  def command_printAll
    words = @database.basicFoods
    print = ""
    words.each { |name|
      print += "#{name.to_s} \n"
    }

    words = @database.recipes
    words.each { |name|
      print += "\n #{name.to_s}"
    }

    puts print
 
  end

  #Handles the 'find' command which prints information on all items in the FoodDB matching a certain prefix
  def command_find(prefix)
    items = @database.find_matches(prefix)
    items.each { |i|
      puts i.to_s
    }
  end

  #Handles both forms of the 'log' command which adds a unit of the named item to the log for a certain date
  def command_log(name, date = Date.today)
    if @database.contains?(name)
      @log.add_logItem(name, date)
      @logChanged = true
    else
      puts "Food not in database"
    end
  end

  #Handles the 'delete' command which removes one unit of the named item from the log for a certain date
  def command_delete(name, date)
    if @log.contains(name, date)
      @log.remove_logItem(name, date)
      @logChangedDB = true
    else
      puts "Item not in log"
    end
  end

  #Handles both forms of the 'show' command which displays the log of items for a certain date
  def command_show(date = Date.today)
    entries = @log.get_entries(date)
    if entries != nil
      entries.each { |i|
        puts i.to_s
      }
    end
  end

  #Handles the 'show all' command which displays the entire log of items
  def command_showAll
    entries = @log.get_entries()
    entries.each { |i|
      puts i.to_s
    }
  end
  
end #end DietManager class


#MAIN

dietManager = DietManager.new

puts "Input a command > "

#Read commands from the user through the command prompt
$stdin.each{|line|

  line.strip!

  if line == "quit"
    dietManager.command_quit

  elsif line == "save"
    dietManager.command_save

  elsif line.start_with?("new food ")
    words = line[9..-1].split(",")
    if words.length >= 2
      dietManager.command_newFood(words[0], words[1])
    end

  elsif line.start_with?("new recipe ")
    words = line[11..-1].strip.split(",")
    if words.length >= 2
      dietManager.command_newRecipe(words[0], words[1..-1])
    end

  elsif line.start_with?("print ") && line != "print all"
    word = line[6..-1].strip
    dietManager.command_print(word)

  elsif line == "print all"
    dietManager.command_printAll

  elsif line.start_with?("find ")
    word = line[5..-1].strip
    dietManager.command_find(word)

  elsif line.start_with?("log ")
    words = line[4..-1].strip.split(",")
    if words.length == 1
      dietManager.command_log(words[0])
    elsif words.length >= 1
      dietManager.command_log(words[0], words[1])
    else
    end

  elsif line.start_with?("delete ")
    words = line[7..-1].split(",")
    if words.length >= 2
      dietManager.command_delete(words[0], words[1])
    end

  elsif line.start_with?("show") && line != "show all"
    words = line[5..-1]
    puts line
    puts words
    if words == nil
      dietManager.command_show()
    else
      dates = words.split("-")
	puts dates

      if (dates.length == 3) 
        date = Date.new(dates[2].to_i, dates[1].to_i, dates[0].to_i)
        dietManager.command_show(date)
      else
        puts "Incorrectly formatted date. Correct form is YYYY-MM-DD"
      end
    end

  elsif line == "show all"
    dietManager.command_showAll

  else
    puts "I read the line... it just wasn't right"
  end
#Handle the input
  
 } #closes each iterator

command_quit
dietmanager.save

#end MAIN
