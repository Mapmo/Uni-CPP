I encountered this during testing and I was really delight to see how theory turns into practice.

I was testing how many shared_ptr are destroyed and how many dataContainers are deleted, to make sure that everything is ok, and surprisingly there were more shared_ptr deleted than I expected.
After saring at my code I realised that there was casting in one of the lines and thought that this might be the reason. After debugging, it turned out that I was right. 
The program was creating a new object using the 1 param constructor and after the completion of operator=() it was destroying the object.

To see this for yourself, open main.cpp and build it. You will receive the messege:




Object erased

Object erased

Data erased




The second object is actually the int 5 cast to an object of type sharedPtr that gets destryoed after the end of operator=()
