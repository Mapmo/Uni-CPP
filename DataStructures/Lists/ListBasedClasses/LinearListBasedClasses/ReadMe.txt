As the directory name suggests these are implementations of data structures based on linear lists, it's important to note that because of the method used to implement the linear lists, a linear list cannot be entirely empty, because then it will be nullptr and therefore useless(this problem will be resolved when I create a list structure that acts like a container)

-Queue3 is a queue based on LinearList1, I chose LinearList1, because it uses dynamicly allocated memory and is easier for use, while it consumes a lot of memory, it is also fast and has lower chance to emit an exception. I chose to inherit privately LinearList1, rather than using it as composition, because I wanted to try out non-public inheritance.

-Stack3 is a stack based on LinearList1, almost the same as Queue3, but it's a stack, not a queue
