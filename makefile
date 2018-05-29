CXX=clang++-5.0
CXXFLAGS=-std=c++17
a.out: Board.o Piece.o IllegalCoordinateException.o IllegalCharException.o coordinate.o
	$(CXX) $(CXXFLAGS) -c Board.o Piece.o IllegalCoordinateException.o IllegalCharException.o coordinate.o -o a.out
Board.o: Board.cpp Board.h Piece.h coordinate.h IllegalCoordinateException.h IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c  Board.cpp -o Board.o

coordinate.o: coordinate.cpp coordinate.h
	$(CXX) $(CXXFLAGS) -c coordinate.cpp -o coordinate.o

Piece.o: Piece.cpp Piece.h IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c  Piece.cpp -o Piece.o
	
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h coordinate.h
	$(CXX) $(CXXFLAGS) -c  IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c  IllegalCharException.cpp -o IllegalCharException.o

clean:
	rm *.o  a.out
