# Exercise 7: Odd Iterator
**Name of exercise** 

The project name is "exercise7", this project should in the direction "your student number/exercise7".

**Requirements** 

Please refer to the textbook pp 162.

Write an iterator class for odd numbers named odd_iterator. The class must model (realize) the ForwardIterator
concept http://www.sgi.com/tech/stl/ForwardIterator.html. That means it must provide the following
members:

• Default and copy constructor;

• operator++ to the next odd element, as pre-increment and post-increment;

• operator* as dereference which returns an (odd) int;

• operator== and operator!=; and

• operator=.

with the obvious semantics. In addition, the class should contain a constructor that accepts an int value. This
value will be returned in the dereference operator (as long as the iterator is not incremented). This constructor
should throw an exception if the value is even. Likewise the default constructor should initialize the internal value
with 1 to provide a legal state.
