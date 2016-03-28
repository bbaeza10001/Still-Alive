#include "PlayerObject.h"

namespace spacey{
	namespace objects{
		PlayerObject::PlayerObject(Window* window, string filename, int tWidth, int tHeight){
			x_coord = 0;
			y_coord = 0;
			m_texWidth = tWidth;
			m_texHeight = tHeight;
			m_window = window;
			start = clock();
			delay = clock();
			healthStart = clock();
			if (filename != "")
				imageLoaded = loadAnimateable(filename, m_image, u2, v2, width, height);

			framesPerRow = width / m_texWidth;//Important to use raw width because u2 is a modified size
		}

		void PlayerObject::Draw(Motion* motion){
			checkRotation(motion);
			checkFire();
			checkAnimState(motion);
			regenHealth();

			if (imageLoaded){
				// Enable the texture for OpenGL.
				glEnable(GL_TEXTURE_2D);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GL_NEAREST = no smoothing
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &m_image[0]);

				//Converting the texture sizes from a pixel scale to an image scale
				/*NOTE: It is important to divide the textures pixel size by the converted images full width
						and height (u2 and v2 respectively), otherwise, the texture will be overdrawn due to scaling
						issues form the conversion*/
				double tWidth = m_texWidth / (double)u2; 
				double tHeight = m_texHeight / (double)v2;

				/*Finding the current x and y coordinates in the texture based on what the current frame is.
					Note: The tX math will automatically move down a row if it is at the end of the row.*/
				double tX = (currentFrame % framesPerRow) * (double)tWidth;
				double tY = (currentFrame / framesPerRow) * (double)tHeight;

				//Draw the image on a polygon
				glPushMatrix();

				glBegin(GL_QUADS);
				glTexCoord2d(tX, tY + tHeight);				glVertex2d(-15, -15);
				glTexCoord2d(tX, tY);						glVertex2d(-15, 15);
				glTexCoord2d(tX + tWidth, tY);				glVertex2d(15, 15);
				glTexCoord2d(tX + tWidth, tY + tHeight);	glVertex2d(15, -15);
				glEnd();

				glPopMatrix();

			}
			else {

				glPushMatrix();

				glColor3f(1.0, 0.0, 0.0); //Sets the color of the player each time it's drawn
				glBegin(GL_TRIANGLES);
				glVertex2d(-5.0f, -10.0f);
				glVertex2d(0, 10.0f); //Nose of triangle
				glVertex2d(5.0f, -10.0f);
				glEnd();

				glPopMatrix();
			}


			if (!shot.empty()){
				for (int i = 0; i < shot.size(); i++){
					shot[i].Fire();
					if (shot[i].limit()){
						shot.erase(shot.begin() + i);
					}
				}
			}


		}

		bool PlayerObject::checkAnimState(Motion* motion){
			if (motion->animFlag == "IDLE"){
				currentFrame = 0;
				return true;
			}
			if (motion->animFlag == "WALK_RIGHT"){
				animate(10, 27, 35);
				return true;
			}
			if (motion->animFlag == "WALK_LEFT"){
				animate(10, 9, 17);
				return true;
			}
			if (motion->animFlag == "WALK_DOWN"){
				animate(10,18, 26);
				return true;
			}
			if (motion->animFlag == "WALK_UP"){
				animate(10, 0, 9);
				return true;
			}

			return false;
		}

		void PlayerObject::animate(int frameSpeed, int startFrame, int maxFrames){
			if (counter == (frameSpeed - 1)){
				currentFrame = (currentFrame + 1) % maxFrames;
				
				while (currentFrame < startFrame)
					currentFrame++;

			}

			counter = (counter + 1) % frameSpeed;

		}

		void PlayerObject::checkRotation(Motion* motion){
			direction = motion->angle;

			if (direction == 0){
				direction = 1;
			}
			else if (direction == 45){
				direction = 2;
			}
			else if (direction == 90){
				direction = 3;
			}
			else if (direction == 135){
				direction = 4;
			}
			else if (direction == 180){
				direction = 5;
			}
			else if (direction == 225){
				direction = 6;
			}
			else if (direction == 270){
				direction = 7;
			}
			else if (direction == 315){
				direction = 8;
			}
		}

		void PlayerObject::checkFire(){
			if (m_window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
				if (shotLast <= waited){
					Bullet bullet(direction, x_coord, y_coord);
					shot.push_back(bullet);
					waited = 0;
					delay = clock();
				}
				else
				{
					waited = (clock() - delay) / CLOCKS_PER_SEC;
					cout << "Can't shoot yet.\n";
				}
			}
		}

		void PlayerObject::takeDamage(int amount){

			if (passed >= wait){
				//Removing Health
				health -= amount;
				cout << "Player now has " << health << " health left.\n";
				
				//Resetting the timer
				passed = 0;
				start = clock();
			}
			else{
				passed = (clock() - start) / CLOCKS_PER_SEC;
				cout << "Could not remove damage yet.\n";
			}
		}
		void PlayerObject::regenHealth(){
			if (health < 100 && healthPassed > healthWait){
				//Regens the players health when its less than 100.
				//Created by Kenneth Morgridge
				healthPassed = 0;
				healthStart = clock();
				health = health + 10;
				cout << "10 health restored." << endl;
				cout << "health is now " << health << endl;
			}
			else{
				healthPassed = (clock() - healthStart) / CLOCKS_PER_SEC;
				
				
			}

			}
		}

	}
