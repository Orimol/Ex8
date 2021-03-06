#include "Board.h"

struct RGB {
    uint8_t red, green, blue;
public:
    RGB() {}
    RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

//new function for my example

Board& Board:: init(size_t bsize){
    this->~Board();	
    size=bsize;
    board=new Piece*[size];
    for(int i=0;i<size;i++){
        board[i]=new Piece[size];
    }
    return *this;
}


Board& Board:: operator = (string s){
    size_t counter=0;
    for (size_t i = 0; i <this->size; ++i) {
        for (size_t j = 0; j <this->size ; ++j) {
            if(counter<s.size()) board[i][j]=s[counter++];
        }
    }
    return *this;
}

//end of new function

Board:: Board(){
    size=3;
    board=new Piece*[size];
    for(int i=0;i<size;i++){
        board[i]=new Piece[size];
    }

};

Board::Board (size_t newsize){
	size=newsize;
	board=new Piece*[size];
	for(int i=0;i<size;i++){
		board[i]=new Piece[size];
	}
}

Board::Board (Board &b){
	size=b.size;
	board=new Piece*[size];
	for(int i=0;i<size;i++){
		board[i]=new Piece[size];
	}
	for (int i=0; i<size; i++){
		for (int j=0; j<size; j++){
			board[i][j]=b.board[i][j];
		}
	}
}

Board::~Board(){
	for(int i=0;i<size;i++) {
            delete board[i];
    }
	delete board;
};


Board& Board::operator = (Board newb){
	this->~Board();
	size=newb.size;
    board=new Piece*[size];
	for(int i=0; i<size; i++){
		for (int j=0; j<size; j++){
			board[i][j]=newb.board[i][j].getValue();
		}
	}

    return *this;
};

Board& Board::operator = (char c){
	if(c!='X'&&c!='O'&&c!='.') throw IllegalCharException(c);
	for (int i=0; i<size; i++){
		for (int j=0; j<size; j++){
			board[i][j]=c;
		}
	}
	return *this;
};


std::ostream& operator<<(std::ostream& o, Board const& b){
	string matrix="";
	for (int i=0; i<b.size; i++){
    for (int j=0; j<b.size; j++){
      matrix+=b.board[i][j].getValue();
    }
    matrix+="\n";
  }
  return o<<matrix;
}

Piece& Board::operator [] (const coordinate& c){
	if(c.getI()>size-1||c.getJ()>size-1){
		throw IllegalCoordinateException(c);
	}
	return board[c.getI()][c.getJ()];
}

string Board:: draw (size_t n){
//        static int counter=1;
//        string name= "board(";
//        name+=to_string(counter++)+").ppm";
    /* trying some new code found in github*/
    string filename="Board";
    struct stat buffer;
    string file=filename+".ppm";
    int i=0;
    while(stat (file.c_str(), &buffer) == 0){
        file=filename+"("+to_string(i)+").ppm";
        i++;
    }
    filename=file;
    //end of new code*/


        const size_t dimx = n, dimy = n;
		size_t box=n/this->size;
		size_t counterx=0;
        size_t countery=0;
		ofstream imageFile(filename, ios::out | ios::binary);
        imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255<< endl;
        RGB image[n*n];

		for (size_t i = 0; i <this->size ; ++i) {
			for (size_t j = 0; j <this->size ; ++j) {
				if (this->board[i][j].getValue()=='X'){
					for (int k = counterx*box; k <(counterx+1)*box ; k++) {
                        for (int l = countery*box; l <(countery+1)*box ; ++l) {
                            image[n*l+k].red = (255);
                        }
					}
                    counterx++;
				}
				if (this->board[i][j].getValue()=='O'){
                    for (int k = counterx*box; k <(counterx+1)*box ; ++k) {
                        for (int l = countery*box; l <(countery+1)*box ; ++l) {
                            image[n*l+k].green = (255);
                        }
                    }
                    counterx++;
				}
				if (this->board[i][j].getValue()=='.'){
                    for (int k = counterx*box; k <(counterx+1)*box ; ++k) {
                        for (int l = countery*box; l <(countery+1)*box ; ++l) {
                            image[n*l+k].blue = (255);
                        }
                    }
                    counterx++;
				}
			}
           counterx=0;
         countery++;
		}

        ///
        ///image processing
        ///
        imageFile.write(reinterpret_cast<char*>(&image), 3*n*n);
        imageFile.close();
    return filename;

	}



std::istream& operator >> (std::istream& in, Board& b) {
    string s,str;//s=the whole chars of the text file, str=a single row from the file
   // int counter=b.size*b.size;
    size_t str_size;
    while(getline(in,str)){
        s=s+str;
        str_size=str.length();
    }
    b.init(str_size);
    b=s;


    return in;

}
