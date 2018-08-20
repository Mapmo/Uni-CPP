These are some useful functions and classes that can be reused many times and are not bound to a single class:


-sharedPtr is an own implementation of std::tr1::shared_ptr that contains a pointer to a sharedPtrContainer and upon destruction it checks whether it is the last object pointing to the container, if it is the last object pointing to it, it deletes the container

-sharedPtrContainer contains data and a counter, its role is to contain the data while there are sharedPtr objects pointing to it. It has a counter displaying how many sharedPtr point to it, if the umber reaches zero, then it gets deleted by the last sharedPtr pointing to it.

-Useful Functions contains own implementation of cstring functions and some other functions that i needed during the development of the classes in this directory and I thought that I may need them again