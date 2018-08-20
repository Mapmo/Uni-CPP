A project for the university during my Object-Oriented Programming Course. Documentation.pdf has a proper description of the project in Bulgarian, if needed I can translate it to English.

The main targt of the homework was to use polymorphism. Obviously there is a ban that contains accounts and there are 3 different types of accounts.
Account is an abstract class and it is also a base class for all 3 types of accounts -> polymorphism is a great tool.

Class Bank has 4 class members :
-Name and Address are simple strings
-Customers is a vector containing objects from custom class Customer(explained below)
-Accounts is a vector consisting of Account*

Class Customer is a simple class that has represents some info for the customer, nothing interesting

The vector consisting of pointers can contain a pointer to all 3 account types and there is a special menu for that

Everything else is just a simple relation between the account classes and the bank class