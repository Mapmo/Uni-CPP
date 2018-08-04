If you test this code you will receive messeges:

Object erased
Object erased
Data erased

The second object is actually the int 5 cast to an object of type sharedPtr that gets destryoed after the end of operator=()
