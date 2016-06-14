# Animal
An effort to create an animal with motion using OpenGL

Screenshot :  
![alt text]( https://raw.githubusercontent.com/VarunWachaspati/animal/master/Animal.png "Animal")

Requirements to run the Program :  


1. gcc compiler (4.8.4)  
2. OpenGL Core (3.3)  

Tested on Ubuntu LTS 14.04.3  

Header Files Included :  


1. < GL/glut.h>
2. < stdio.h>
3. < stdlib.h>
4. < GL/glu.h>
5. < GL/gl.h>


Files Included :  

1. test.cpp
2. readme.txt
3. makefile
4. test2.cpp

How to run the program :  


1. In the directory containing the final.cpp, run "make" command on terminal.
2. run the following commands on commandline "./draw" for test.cpp and run "./drawWithoutResize" for test2.cpp
3. Refer the keys given below for better experience and ease of understading.

NOTE :   


1. test.cpp - Satisfies all the criteria stated in the Assignment sheet.   Keys Supported - "w"/"W"(Toggle), "f"/"F"(Forward move) and "b"/"B"(Backward Move).   Camera is Fixed and also resizing of Window is allowed.    
2. test2.cpp - Satisfies all criteria except for Resizing Compatability but user can Move around the entire scene using the following keys.Quite useful for exploring the environment created and objects rendered.  
 

Star Marked Keys(*) available in both executables namely draw and drawWithoutResize.  

Important Keys -   

|S.No|  Keys  | Function                                 |
----:|-------:|-----------------------------------------:|
| 1. |"a"/"A" | Move Left                                |
|*2. |"w"/"W" | Toggle between WiredFrame and Solid Mode |
| 3. |"d"/"D" | Move Right								               |
| 4. |"q"/"Q" | Forward Zoom                             |
| 5. |"s"/"S" | Backward Zoom                            |
| 6. |"i"/"I" | Rotate Frame Up                          |
| 7. |"k"/"K" | Rotate Frame Down                        |
| 8. |"l"/"L" | Rotate Frame Left                        |
| 9. |"j"/"J" | Rotate Frame Right                       |
|*10.|"f"/"F" | Move Animal Forward                      |
|*11.|"b"/"B" | Move Animal Backward                     |
