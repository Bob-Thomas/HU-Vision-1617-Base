#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(),	other.getHeight()), pixels(new RGB[other.getWidth()*other.getHeight()]){
	//TODO: Create a copy from the other object
	for (int i = 0; i<getWidth()*getHeight(); i++) {
		pixels[i] = other.getPixel(i);
	}

}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height), pixels(new RGB[width*height]) {
	//TODO: Initialize pixel storage
}

RGBImageStudent::~RGBImageStudent() {
	//TODO: delete allocated objects
	delete[] pixels;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] pixels;
	this->pixels = new RGB[width*height];
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	delete[]pixels;
	this->pixels = new RGB[getWidth()*getHeight()];
	for (int i = 0; i<getWidth()*getHeight(); i++) {
		pixels[i] = other.getPixel(i);
	}
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pixels[y*getWidth() + x] = pixel;
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
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

RGB RGBImageStudent::getPixel(int x, int y) const {
	//TODO: no comment needed :)
	return 	pixels[y*getWidth() + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	//TODO: see setPixel(int i, RGB pixel)
	return pixels[i];
}