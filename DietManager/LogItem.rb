require 'date'

class LogItem
  attr_accessor :name, :date

  #itemName is the name of the BasicFood and date is the date (civil format : xx/xx/xxxx) for which the food was added
  def initialize(itemName, date)
    @name = itemName
    @date = date.strftime("%m/%d/%Y")
  end
  
  #Returns a string representation of this LogItem formatted for printing
  def to_s
    result = "#{@date},#{name}"
  end
end
