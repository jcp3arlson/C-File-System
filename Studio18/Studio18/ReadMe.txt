studio 18 answers here
1.	Austin Bick, Brendan Long, Josh Pearlson
2.	Having multiple file systems would increase the amount of changes we would have to make to implement a new type of file
	This would be pretty inefficient unless we create a factory.
3.	It is a much better way to design our system(s) Since we will be creating multiple of similar object types, this allows us to generalize
	the creation of new files. In order to implement a new file type, we now only have to update the file factory. Since we return pointers
	to dynamically allocated files, it doesn't matter that different file systems are using the same factory. For systems that manage 
	different file types, we may need to include exceptions within our factory depending on which system is being used.
4.	First we created a simple file system and factory. We then created and opened a simplefile and wrote then read it. It worked as expected.
5.	No, it only depends on the implementation of the abstract file
6.	All test cases passed