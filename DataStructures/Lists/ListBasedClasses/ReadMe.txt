This directory contains:

-List - an implementation of std::list, based on LinkedList1, by based I mean that it contains 1 class member, that is a pointer to a LinkedList1.
  I chose to use a composition rather than private inheritance, because I did not want to make this class work like the primitive LinkedList1, for instance I wanted the copy ctor and operator= to copy the information of the whole LinkedList.
 Moreover, now the list works with all the elements in the sequence, rather than just one of them, and now it can also store the beginning and the end of the sequence, without having to iterate through the whole sequence to find them, I could have easily used only m_Beg and m_End for the implementation, but I wanted it to be more like Deque rather than Vector
 Although during the process of work it turned out that LinkedList1 is not the most suitable class for List and the implementation is not perfect, I believe that it was a very useful experience, that helped me understand the data structure even deeper, one of the main problems was that begin() and end() were always calculating, and I was unable to use the already saved m_Beg and m_End, another problem was the member access

-LinearListBasedClasses is a directory that contains some STL implementations based on LinearList1(e.g std::stack)

-HashTables contains some implementations of hash tables, that I tried, this folder is in the ListBasedClasses directory, because when there are multiple collisions, the tables use LinkedList1