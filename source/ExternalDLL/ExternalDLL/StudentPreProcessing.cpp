#include "StudentPreProcessing.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	GrayscaleAlgorithm grayScaleAlgorithm;
	IntensityImageStudent *test = new IntensityImageStudent(image.getWidth(), image.getHeight());

	//Loop through all pixels and apply the choses algorithm
	for (int i = 0; i < test->getWidth()*test->getHeight(); i++) {

		// Intensity  algorithm
		//test->setPixel(i, 0.3*((float)image.getPixel(i).r + (float)image.getPixel(i).g + (float)image.getPixel(i).b));

		// Luminance algorithm
		test->setPixel(i, ((float)image.getPixel(i).r*0.299) + ((float)image.getPixel(i).g * 0.587) + ((float)image.getPixel(i).b * 0.114));

		//value algorithm
		//test->setPixel(i, std::max({ image.getPixel(i).r, image.getPixel(i).g, image.getPixel(i).b}));

		//single-collor channel algorithm
		//test->setPixel(i, Intensity(image.getPixel(i).g));


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