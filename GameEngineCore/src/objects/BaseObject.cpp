#include "BaseObject.h"

namespace spacey{
	namespace objects{

		bool loadImage(string filename, vector<unsigned char> &m_image, size_t &u2, size_t &v2, double &u3,
			double &v3, unsigned &width, unsigned &height){

			// Load file and decode image.
			vector<unsigned char> image;
			unsigned error = lodepng::decode(image, width, height, filename);
			// If there's an error, display it.
			if (error != 0)
			{
				std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
				return false;
			}

			// Make some OpenGL properties better for 2D and enable alpha channel.
			glDisable(GL_CULL_FACE);
			glDisable(GL_DEPTH_TEST);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);
			glDisable(GL_ALPHA_TEST);
			//glEnable(GL_ALPHA);

			// Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
			u2 = 1;  while (u2 < width) u2 *= 2;
			v2 = 1;  while (v2 < height) v2 *= 2;
			// Ratio for power of two version compared to actual version, to render the non power of two image with proper size.
			u3 = (double)width / u2;
			v3 = (double)height / v2;

			// Make power of two version of the image.
			std::vector<unsigned char> image2(u2 * v2 * 4);
			for (size_t y = 0; y < height; y++)
				for (size_t x = 0; x < width; x++)
					for (size_t c = 0; c < 4; c++)
					{
						image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
					}

			m_image = image2;

			return true;
		}

		bool loadAnimateable(string filename, vector<unsigned char> &m_image, size_t &u2, size_t &v2, 
			unsigned &width, unsigned &height){

			// Load file and decode image.
			vector<unsigned char> image;
			unsigned error = lodepng::decode(image, width, height, filename);
			// If there's an error, display it.
			if (error != 0)
			{
				std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
				return false;
			}

			// Make some OpenGL properties better for 2D and enable alpha channel.
			glDisable(GL_CULL_FACE);
			glDisable(GL_DEPTH_TEST);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);
			glDisable(GL_ALPHA_TEST);

			// Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
			u2 = 1;  while (u2 < width) u2 *= 2;
			v2 = 1;  while (v2 < height) v2 *= 2;

			// Make power of two version of the image.
			std::vector<unsigned char> image2(u2 * v2 * 4);
			for (size_t y = 0; y < height; y++)
				for (size_t x = 0; x < width; x++)
					for (size_t c = 0; c < 4; c++)
					{
						image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
					}

			m_image = image2;

			return true;
		}
	}
}