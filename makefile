all: test.cpp test2.cpp
	 g++ -o draw test.cpp -lglut -lGL -lGLU -g
	 g++ -o drawWithoutResize test2.cpp -lglut -lGL -lGLU -g
clean:
	rm -f *.o
	rm -f draw
	rm -f drawWithoutResize 
