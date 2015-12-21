#include "Background.h"

namespace spacey { namespace objects {

	void BG::loadObjects(char* fileName){
		ifstream file;

		file.open(fileName);

		if (file.fail()){ //Check if the file is openable
			cout << "Opening level file named '" << fileName << "' failed.\n";
		}
		else{
			cout << "Opening " << fileName << endl;
			string line;
			int x, y, size, amount;

			while (file.is_open()){
				file >> line;

				if (line == "START"){ //Check if keyword is start
					file >> amount;

					for (int i = 0; i < amount; i++){
						file >> x >> y >> size; //read the values for the planet and add them to the vector

						CircleObject temp(x, y, size);

						circles.push_back(temp);
						cout << "Added element to circle vector.\n";
					}
					//RECTUM OF GEORGE WASHINGTON
				}
				else if (line == "ENDF"){//Check if the keyword is the end of the file
					cout << "Reached end of file.\n";
					file.close();
				}
			}


			//Not needed anymore because the system works
			/*cout << "Finished with while loop" << endl;

			for (unsigned int i = 0; i < systemVector.size(); i++){
			cout << "Planet " << i << ": " << systemVector[i].x_coord << ", " << systemVector[i].y_coord << endl;
			}*/
		}

	}

	void BG::draw(){
		if (circles.size() != 0){
			//Draw all the circles in the vector
			const float full_angle = 2.0f*3.141592654f;
			float xN = 0.0f;
			float yN = 0.0f;

			for (int i = 0; i < circles.size(); i++){
				//Drawing all points on the circle
				glPushMatrix();
				glTranslatef(circles[i].x_coord, circles[i].y_coord, 0);
				glBegin(GL_POLYGON);
				for (float i = 0; i < 180; i++)
				{
					xN = circles[i].radius * (std::cos(i * full_angle / 180.0f));
					yN = circles[i].radius * (std::sin(i * full_angle / 180.0f));


					glColor3f((xN * 0.01), (yN * 0.01), 0.5f); //Sets color of planets
					glVertex2d(xN, yN);
				}
				glEnd();

				glPopMatrix();
			}
		}
	}

} }