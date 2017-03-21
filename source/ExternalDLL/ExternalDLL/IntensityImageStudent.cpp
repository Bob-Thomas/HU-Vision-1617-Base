#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	for (int i = 0; i<getWidth()*getHeight(); i++) {
		pixels[i] = other.getPixel(i);
	}
	//TODO: Create a copy from the other object
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height), pixels(new Intensity[width*height]) {
	//TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {
	//TODO: delete allocated objects
	delete[] pixels;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] pixels;
	this->pixels = new Intensity[width*height];
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	delete[]pixels;
	this->pixels = new Intensity[getWidth()*getHeight()];
	for (int i = 0; i<getWidth()*getHeight(); i++) {
		pixels[i] = other.getPixel(i);
	}
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	//TODO: no comment needed :)
	pixels[y*getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	pixels[i] = pixel;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	//TODO: no comment needed :)
	return 	pixels[y*getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	//TODO: see setPixel(int i, RGB pixel)
	return pixels[i];
}