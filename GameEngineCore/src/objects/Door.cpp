#include "Door.h"

namespace spacey{ namespace environment{

	Door::Door(){
		x_coord = 0;
		y_coord = 0;
		width = 0;
		height = 0;
		stateFlag = "CLOSED";
		cDir = oDir = 0;
		m_width = 0;
		m_height = 0;
	}

	Door::~Door(){

	}

	Door::Door(int x, int y, int w,
		int h, int closed_dir, int open_dir, string filename){

		x_coord = x;
		y_coord = y;
		m_width = w;
		m_height = h;
		cDir = closed_dir;
		oDir = open_dir;
		dir = cDir;
		imageLoaded = loadImage(filename, m_image, u2, v2, u3, v3, width, height);
	}

	void Door::draw(Window* window){
		update(checkRadius(window));

		// Enable the texture for OpenGL.
		glEnable(GL_TEXTURE_2D);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GL_NEAREST = no smoothing
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//GL_LINEAR = smoothing
		glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &m_image[0]);
		
		glPushMatrix();

		motionObj.applyRotation(x_coord, y_coord);

		glBegin(GL_QUADS);
		glTexCoord2d(0, v3);	glVertex2d(x_coord - (m_height / 2), y_coord - (m_height / 2));
		glTexCoord2d(0, 0);		glVertex2d(x_coord - (m_height / 2), y_coord + (m_height / 2));
		glTexCoord2d(u3, 0);	glVertex2d(x_coord + (m_width - (m_height / 2)), y_coord + (m_height / 2));
		glTexCoord2d(u3, v3);	glVertex2d(x_coord + (m_width - (m_height / 2)), y_coord - (m_height / 2));
		glEnd();
		glPopMatrix();
	}

	bool Door::checkRadius(Window* window){
		if (x_coord - (m_width + 20) <= 16 && x_coord + (m_width + 20) >= -16
			&& y_coord + (m_height + 20) >= -16 && y_coord - (m_height + 20) <= 16 && window->isKeyPressed(GLFW_KEY_SPACE)){
			cout << "Player input detected\n";
			return true;
		}

		return false;
	}

	void Door::update(bool radiusCheck){
		//Check if player is within door's check radius
		if (counter >= waitTime && radiusCheck){
			counter = 0;

			//Update State flag
			if (stateFlag == "CLOSED"){
				stateFlag = changeState("OPEN");
			}
			else{
				stateFlag = changeState("CLOSED");
			}	
			
		}

		counter++;

	}

	string Door::changeState(string state){
		if (state == "OPEN"){
			
			rotate(oDir);

			cout << "Opened Door\n";
			return "OPEN";
		}

		else if (state == "CLOSED"){
			
			rotate(cDir);

			cout << "Closed Door\n";
			return "CLOSED";
		}
	}

	void Door::rotate(int nState){

		/*switch (dir){
		case 1:
		if (m_height < 0)
		m_height = -m_height;
		break;
		case 3:
		if (m_width < 0)
		m_width = -m_width;
		break;
		case 5:
		if (m_height > 0)
		m_height = -m_height;
		break;
		case 7:
		if (m_width > 0)
		m_width = -m_width;
		break;
		default:
		cout << "Door is not in a valid direction\n";
		}*/

		if (nState < dir){
			motionObj.rotateLeft(90);
		}
		else{
			motionObj.rotateRight(90);
		}
	}
} }