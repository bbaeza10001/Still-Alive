#pragma once

#include <FreeImage.h>
#include <gl\glew.h>

namespace spacey{

	static BYTE* load_image(const char* filename, GLsizei* width, GLsizei* height){
		
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		FIBITMAP *dib = nullptr;
		BYTE* bits = nullptr;
		fif = FreeImage_GetFileType(filename, 0);
		if (fif == FIF_UNKNOWN)
			fif = FreeImage_GetFIFFromFilename(filename);
		if (fif == FIF_UNKNOWN)
			return nullptr;

		if (FreeImage_FIFSupportsReading(fif))
			dib = FreeImage_Load(fif, filename);
		if (!dib)
			return nullptr;

		//retrieve the image data
		BYTE* result = FreeImage_GetBits(dib);
		//get the image width and height
		*width = FreeImage_GetWidth(dib);
		*height = FreeImage_GetHeight(dib);

		return result;
	}

} 