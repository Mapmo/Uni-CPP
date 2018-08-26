These are implementations of STL classes that use std::vector<T> as their core

-Vector - an implementation of std::vector<T>, it uses dynamicly allocated array as its core, has special size formula that guarantees that the size is always a power of 2, and of course it can grow and shrink

-String2 - an implementation of std::string, it inherits Vector and has all std::string functions, it's fully functional

-Stack2 - although it is a template class that has a container within itself, it uses Vector as its default container, but can also have Deque as its core

-Queue2 - same as Stack2

-Deque2 - same as Stack2