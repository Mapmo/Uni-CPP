This directory contains:
-List - an implementation of std::list, based on LinkedList1, by based I mean that it contains 1 class member, that is a pointer to a LinkedList1.
  I chose to use a composition rather than private inheritance, because I did not want to make this class work like the primitive LinkedList1, for instance I wanted the copy ctor and operator= to copy the information of the whole LinkedList.
 Moreover, now the list works with all the elements in the sequence, rather than just one of them, and now it can also store the beginning and the end of the sequence, without having to iterate through the whole sequence to find them, I could have easily used only m_Beg and m_End for the implementation, but I wanted it to be more like Deque rather than Vector


-LinearListBasedClasses is a directory that contains some STL implementations based on LinearList1