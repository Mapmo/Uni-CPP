This is a project that was given by my OOP lector in FMI. The task was to make an object-oriented database.

The task was to create a data structure that contains data similar to a real database and to implement some functions similar to those in mySQL.
This is the UML of the project:


              __________                                                
              |Database|
              |--------|
              |        |
              |--------|
              |________|
                  |1
 		  |
		  |
		  |*
	      ____|_____
              | Table  |
              |--------|
              |        |
              |--------|
              |________|_____________________________________________________________
                  |1      1                                           * |PageToPrint|                                                            
             	  |							|-----------|                                                           
              	  |							|           |                  
              	  |*							|-----------|                                                      
              ____|_____						|___________|                                                         
              | Column |                                                            
              |--------|                                                
              |        |                                                         
              |--------|                                                          
              |________|                                                             
                  |1  
                  |
                  |
	          |*
	      ____|_____                                                         
              | Cell   |                                                              
              |--------|                                                
              |        |                                                         
              |--------|                                                          
              |________|                                                               


I use the principle Devide and Conquer to implement the databse. 

The main class is Database. It contains a Table * and its role is to load, contain and save items from class Table. Most of the database functions call functions with the same name from class Table.
Class table contains a Column* and its role is to represent a single table, that can later be saved in a file. Its functions use loops and call functions with the same name from class Column on each member of the Column*
Class column contains an enum that represents the 3 possible data type - string, int and double, it has 4 members:
-name
-number(id)
-type
-Cell * 
Column's functions use setters and getters to interact with the members of class Cell
Class Cell represents a class with a single member that contains the data of cell in the form of a string. It has only a setter and getter and its only role is to be a container

*I chose to represet all data as string instead of using polymoorphism, because there were no functions in the task that required me to use polymorphism in order to save time from conversion between types. 
The only function that requires data validation is Database::Aggregate(), but it's not slowing down the program as much as polymorphism will, because it's only 1 function and it's not necessarily used, while polymorphism and dynamic casting will be used all the time if used

Class PageToPrint is a help class used for the function Database::Print() and it's used to store multiple lines in it in order to be prited in the console by the function Print().I needed it because there were specific reuirements for this function.

All the main fuctions are explained in Documentation.pdf. The description is in Bulgarian and if needed I can translate it.


As it wasn't pointed how to contain the info in files, i chose to use a simple text file to contain each table.
The data is spread this way:

<table name>
-----
<type> <column name>
<values>
-----
.......
E

<table name> is obviously a string that contains the name of table
----- is a keyword for end of column(this way the parser works easily)
<type> is a letter I, D or S that represents the type of the column (used for aggregate)
<column name> is just like table name
<values. are the different cells
----- indicates end of column
after all the data has been researched we reach E which means end of file and the parser stops.