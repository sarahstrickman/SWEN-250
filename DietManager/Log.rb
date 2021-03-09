require './LogItem'

class Log
  attr_accessor :size
  
  #filename is the name of the Log file to be used
  def initialize(filename)
    @log = Hash.new
    @size = 0
    @logFile = File.new(filename) #Open the log file
    
    #Read in the Log file
    @logFile.each{|line|
      values = line.split(',') #Split the line at the commas
      dateParts = values[0].split('/') #Split the date field up at the slashes
      
      date = Date.parse("#{dateParts[2]}-#{dateParts[0]}-#{dateParts[1]}") #Parse the date string into a valid Date object
      
      add_logItem(values[1].chomp!, date)
    }
  end
  
  #Adds a LogItem to the Log for the given date and name, returns true if successful, false otherwise
  def add_logItem(name, date)
    
    #If there are already entries for logItem's date, add the LogItem
    #Otherwise add a new entry for logItem's date and add the LogItem to its list
     
    if @log.has_key?(date)
      foods = log[date]
      foods.push(name)
      @log[date] = foods
      @size += 1
      return true
    else
      foods = []
      foods.push(name)
      @log[date] = foods
      @size += 1
      return true
    end
    false
  end
  
  #Removes a LogItem from the Log for the given date and name
  def remove_logItem(name, date)
    toreturn = nil
      if @log[date] != nil
	origsize = @log[date].length
	toreturn = LogItem.new(@log[date].delete(name), date)
	newsize = @log[date].length
	@size -= (origsize - newsize)
      else
	toreturn
      end
      toreturn

  end
  
  #Returns true if there is an entry for this date with the given name, false otherwise
  def contains?(name, date)
    contain = false
    foods = @log[date]
    if foods != nil
      foods.each { |food|
      if food == name
	contain = true
      end
      }
    else
      contain
    end
    contain
  end
  
  #Returns an Array of LogItems for the given date, nil if there are no entries for the date
  #If no date is passed, returns all entries in the Log
  def get_entries(date = nil)
    entries = nil
    if date == nil && @log != nil
      entries = []
      dates = @log.keys
      dates.each { |date|
	if @log[date] != nil
 	  foods = @log[date]
	  foods.each { |food|
	    item = LogItem.new(food, date)
	    entries.push(item)
	  }
	else
	  entries
	end
      }

      elsif date != nil && @log[date] != nil
        entries = []
        foods = @log[date]
        foods.each { |name|
	  item = LogItem.new(name, date)
 	  entries.push(item)
        }
      else
	entries
      end

      entries
  end
  
  #Saves the log to @logFile
  def save
    #Write all save data to the log file
    File.open(@logFile, "w+"){|fOut|
      get_entries.flatten.each{|logItem|
        fOut.write(logItem.to_s)
        fOut.write("\n")
      }
    }
  end
end
