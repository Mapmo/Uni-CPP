These are implementations of Linked Lists (lists that have two way connection between neighbours)

-LinkedList1 - similar to LinearList1, it uses dynamicly allocated memory, but doesn't create copies of the m_Next and m_Prev when operator= or copy ctor are used,
the core (this) is never nullptr an so it's safe to call this->m_Prev and this->m_Next without expecting any problems

-just like the linear lists these are primitive implementations and their purpose is to be used for practice, therefore there is some logic problems like empty() always being false in terms of what is considered false and returns true when there is 1 member(this problem get fixed with List)

*LinkedList1 is very similar to a binary tree and can be used as such