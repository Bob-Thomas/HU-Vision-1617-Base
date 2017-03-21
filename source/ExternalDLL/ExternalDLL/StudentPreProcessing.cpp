#include "StudentPreProcessing.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	GrayscaleAlgorithm grayScaleAlgorithm;
	IntensityImageStudent *test = new IntensityImageStudent(image.getWidth(), image.getHeight());
	IntensityImage * test1 = new IntensityImagePrivate(image.getWidth(), image.getHeight());

	auto t1 = std::chrono::high_resolution_clock::now();
	grayScaleAlgorithm.doAlgorithm(image, *test1);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto speed1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();


	auto t3 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < test->getWidth()*test->getHeight(); i++) {
		test->setPixel(i, ((float)image.getPixel(i).r*0.299) + ((float)image.getPixel(i).g * 0.587) + ((float)image.getPixel(i).b * 0.114));
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