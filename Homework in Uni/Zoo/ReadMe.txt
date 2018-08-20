I was preparing for my OOP exam and I had to come up with some strange ideas in order to practice some OOP things that were not present inour homeworks.
I wanted to practice multi-inheritance and so I came up with this idea:
A polymorphic class that is contained within another and it can also be presented as a class that publicly inherits 2 other chiled classes of animal
					________
					|Zoo   |
					--------
					   |1
				           |
					___|*___
					|Animal|
				        --------
					 1 /\ 1
					  /  \
				        */    \*
				____________	__________
                                |Dry	   |    |Aqua    |
				------------    ----------
					\	   /
				         \	  /
				         \/	 \/
					____________
					|Aqua-Dry  |
					------------

The classes are very simple and the only tricky thing is the combination of polymorphism and multi-inheritance:
-Zoo is a simple Animal container
-Animal is an abstract class
-Dry (animals living on the surface) and Aqua (animals living in the water) are simple classes the inherit Animal and overload its viirtual functions to show their specific class members
-Aqua-Dry (animals that live in both environments) virtually inherits Animal and the inherits Aqua and Dry and overloads the virtual functions of Animal.