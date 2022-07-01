Lab 5 ReadMe

Group Member Names: Brendan Long, Austin Bick, Josh Pearlson

We met in person multiple times to do the work for this lab, so the work was all collaborative.

Extra command: touch and cat
This is implemented by calling "tc <filename>" on the command line.
We tried calling tc on image and text files, with and without a password.
Initially, it did not work with a password.
This was fixed by making the tc command compatable with a passwordProxy object.

Errors we ran in to:
Most of our issues had to do with copying and renaming password-protected files.
This was due to sloppy memory handling within the Password Proxy destructor, but was easily fixed.
We also had problems with using cat -a on image files. Originally, the original contents were removed,
but we fixed this by created a new vector of the contents to be appended.
Another problem we had was that copied files did not have an extention in their name.
We fixed this by appending the correct extension in each file type's implementation of copy().

Tests we did:
We created different types of files with and without passwords.
We wrote and appended to those files using cat and cat -a.
We copied and renamed all types of files with and without passwords.
We changed the copies and then viewed the copies and originals.
We used ls to make sure all files existed.
We deleted files.

Extra credit work:
We chose to create the chmod <filename> - command which sucessfully creates readable only files
then reverts the readable only files to writable when invoked with the chmodd <filename> + 
When a user tries to write to a readable only file, it tells them after enter :wq that 
the file is a read only file and does not update any of the information in the file

Errors we ran into (for extra credit):
Initially we forgot to close a file prior to deleting it and replacing it with the chmod file.
upon chmodding a chmod file, the new chmod file's file variable was also a 
	chmod file (whose member variable isWritable is still the same as before).
	we fixed this by changing the copy command which is used in the constructor.
