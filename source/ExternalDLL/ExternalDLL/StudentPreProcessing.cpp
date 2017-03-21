#include "StudentPreProcessing.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent *test = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (int i = 0; i < test->getWidth()*test->getHeight(); i++) {
		test->setPixel(i, std::max({image.getPixel(i).r, image.getPixel(i).b,image.getPixel(i).b}));
	}
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