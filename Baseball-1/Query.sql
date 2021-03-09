--Sarah Strickman

SELECT * from Player where position = 2;
SELECT name, age from Player where position = 1 and team = "Rays";
SELECT name, number, team from Player where position >= 7 and position <= 9 and age <= 25;
SELECT name, number from Player where position >= 3 and position <= 6 and team = "Red Sox";
SELECT name, number, team from Player where position = 1 and age > 30;
