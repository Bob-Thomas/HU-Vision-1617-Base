#include "StudentPreProcessing.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	GrayscaleAlgorithm grayScaleAlgorithm;
	IntensityImageStudent *test = new IntensityImageStudent(image.getWidth(), image.getHeight());
	IntensityImage * test1 = new IntensityImagePrivate(image.getWidth(), image.getHeight());
	// get the current time
	auto t1 = std::chrono::high_resolution_clock::now();
	// execute existing algoritm
	grayScaleAlgorithm.doAlgorithm(image, *test1);
	// get the current time again
	auto t2 = std::chrono::high_resolution_clock::now();
	// get the time of t2 and substract with t1. The remaining time is the execution time of the existing grayscale algoritm
	auto speed1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	// get time again
	auto t3 = std::chrono::high_resolution_clock::now();
	// own implemented algoritm for grayscale
	for (int i = 0; i < test->getWidth()*test->getHeight(); i++) {
		// Intensity  algoritm
		//test->setPixel(i, 0.299 * (image.getPixel(i).r + image.getPixel(i).g + image.getPixel(i).b));
		// Luminace algoritm
		test->setPixel(i, ((float)image.getPixel(i).r*0.299) + ((float)image.getPixel(i).g * 0.587) + ((float)image.getPixel(i).b * 0.114));
		// value algoritm
		//test->setPixel(i, std::max({ image.getPixel(i).r, image.getPixel(i).g, image.getPixel(i).b}));
	}
	auto t4 = std::chrono::high_resolution_clock::now();
	auto speed2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count();
	return test;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}