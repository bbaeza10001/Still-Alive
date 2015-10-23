#include "Button.h"

namespace spacey{ namespace input{

	button::button(){
		m_width = 0;
		m_height = 0;
		m_x = 0;
		m_y = 0;
		m_window = NULL;
	}

	button::button(Window* window, double x, double y, double width, double height, string filename){
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		m_window = window;
		m_filename = filename;
	}

	void button::draw(){
		glPushMatrix();
		glTranslatef(m_x, m_y, 0);

		//Base button drawing
		glBegin(GL_QUADS);
		glVertex2d(m_x, m_y);
		glVertex2d(m_x + m_width, m_y);
		glVertex2d(m_x + m_width, m_y + m_height);
		glVertex2d(m_x, m_y + m_height);
		glEnd();
		
		Texture tool(m_filename);
		GLuint tex;
		tex = tool.m_TID;

		//Texture drawing
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex2f(m_x, m_y);

		glTexCoord2f(0, 1);
		glVertex2f(m_x + m_width, m_y);

		glTexCoord2f(1, 1);
		glVertex2f(m_x + m_width, m_y + m_height);

		glTexCoord2f(1, 0);
		glVertex2f(m_x, m_y + m_height);
		glEnd();
		
		glPopMatrix();
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);

	}

	bool button::clicked(){
		if (m_window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
			double x, y;
			m_window->getMousePosition(x, y);

			if (x >= m_x && x <= m_x + m_width){
				if (y >= m_y && y <= m_y + m_height){
					return true;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}


} }