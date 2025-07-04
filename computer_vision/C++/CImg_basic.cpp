#include "CImg.h"
using namespace cimg_library;

int main() {
	CImg<unsigned char> img("tmp.png");
	img.display("Hello World!");
	return 0;
}
// compile: nqbh@nqbh:~/advanced_STEM_beyond/computer_vision/C++$ g++ -O2 -Wall CImg_basic.cpp -lX11 -o CImg_basic