#include <iostream>
#include <string>
#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
/*---------------------------------------------------------------------*/
#include "ColorAberrationCorrection.h"

int main(int argc, char *argv[]) {
	if (argc<2) {
		std::cout << "No input file(s) !" << std::endl;
		return -1;
	}
	for (int i=1; i<argc; i++){
		std::string inputfile = std::string(argv[i]);
		std::string outputfile = inputfile+"_CAC.bmp";
		cv::Mat src = cv::imread(inputfile, cv::IMREAD_COLOR);
		
		cv::Mat dst;

		CAC::CACorrection(src, dst);

		cv::imshow(inputfile+" [original]", src);
		cv::imshow(outputfile+" [result]", dst);
		
		cv::imwrite(outputfile, dst);

		cv::waitKey(0);
		cv::destroyAllWindows();
	}

	return 0;
}