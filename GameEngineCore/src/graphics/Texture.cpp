#include "Texture.h"

namespace spacey{ namespace graphics{

	Texture::Texture(const std::string& filename) 
		: m_FileName(filename)
	{
		m_TID = load();
	}

	Texture::~Texture(){

	}

	GLuint Texture::load(){
		BYTE* pixels = load_image((const char*)&m_FileName, &m_Width, &m_Height);
		
		GLuint result;
		glGenTextures(1, &result);
		glBindTexture(GL_TEXTURE_2D, result);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);

		return result;
	}

	void Texture::bind() const{
		glBindTexture(GL_TEXTURE_2D, m_TID);
	}

	void Texture::unbind() const{
		glBindTexture(GL_TEXTURE_2D, 0);

	}
} }