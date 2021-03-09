# Movie Manager 
# 
# Manages a collection of Movie objects. 
class MovieList
  def initialize
    @movies = Hash.new
    @numberOfMovies = 0    
  end
  
  def size
    @numberOfMovies
  end
  
  def add( movieToAdd )
    #Original code
    #@movies.store( movieToAdd.name, movieToAdd)
    #@numberOfMovies += 1
	
    #solution
    if ( ! @movies.has_key?(movieToAdd.name) )
      @movies.store( movieToAdd.name, movieToAdd )
      @numberOfMovies += 1
    end
  end
  
  def delete( movieToDelete )    
    @movies.delete(movieToDelete.upcase)
  end
  
  def getMovie(movieToFind)    
    @movies.fetch(movieToFind.upcase, nil) 
  end
  
  def sortByName	
    #Original code
    #@movies.sort
	
    #solution
    @movies.keys.sort
  end
  
  def sortByRating
    #Original code
    #list = @movies.values.sort_by { |x| x.rating }
	
    #solution
    list = @movies.values.sort_by { |x| x.rating }.reverse
  end    
    
 end

# Movie Class - Models a movie entry - maintains movie title as an uppercase string,
#               rating (1-10) and text review.
class Movie
  attr_reader :rating
  attr_reader :review
  #solution add this reader
  attr_reader :name
  
  #Original code
  #def initialize( aName, aRating=1, aReview="No Review Entered" )
  
  #solution (just the one line below was changed)
  def initialize( aName, aRating=5, aReview="No Review Entered" )
    @name=aName.upcase! 
	self.rating=aRating
    @review=aReview
  end

  def rating=(value)
    #Original code
    #if value <=10 || value >=1
    #  @rating = value
    #end
	
    #solution
    if value >=1 and value <=10
      @rating = value
    else
      @rating = 5
    end
  end
end
