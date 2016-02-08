#include "BG.h"

namespace spacey{
	namespace background{
	
		BG::BG(){
			planets.clear();
		}

		BG::BG(Window* window){
			m_window = window;
		}

		void BG::loadEntity(string filename, string type){
			if (type == "CIRCLE")
				loadObject(planets, filename);

			if (type == "BASE_ENEMY")
				loadObject(B_Enemy, filename);

			if (type == "WALL")
				loadObject(walls, filename);

			cout << "Elements added to BG vector\n";
		}

		void BG::update(Motion* motion, PlayerObject* player){
			glPushMatrix();
			motion->applySpeed();
			move(motion);

			for (unsigned int i = 0; i < planets.size(); i++){
				if (planets[i].x_coord < 800 && planets[i].x_coord > -800){
					if (planets[i].y_coord < 600 && planets[i].y_coord > -600){
						planets[i].Draw();
					}
				}
			}
			orb.orbit(planets);

			for (unsigned int i = 0; i < B_Enemy.size(); i++){
				if (B_Enemy[i].x_coord < 800 && B_Enemy[i].x_coord > -800){
					if (B_Enemy[i].y_coord < 600 && B_Enemy[i].y_coord > -600){
						B_Enemy[i].Draw(motion);
					}
				}
			}

			for (unsigned int i = 0; i < walls.size(); i++){
				if (walls[i].x_coord < 800 && walls[i].x_coord > -800){
					if (walls[i].y_coord < 600 && walls[i].y_coord > -600){
						walls[i].Draw();
					}
				}
			}

			checkBullets(player);
			glPopMatrix();
		}

		void BG::move(Motion* motion){
			
			for (unsigned int i = 0; i < planets.size(); i++){
				planets[i].x_coord += motion->xspeed;
				planets[i].y_coord += motion->yspeed;
			}

			for (unsigned int i = 0; i < B_Enemy.size(); i++){
				B_Enemy[i].x_coord += motion->xspeed;
				B_Enemy[i].y_coord += motion->yspeed;
				for (unsigned int c = 0; c < B_Enemy[i].delaware.size(); c++){
					B_Enemy[i].delaware[c].bX += motion->xspeed;
					B_Enemy[i].delaware[c].bY += motion->yspeed;
				}
			}
			
			for (unsigned int i = 0; i < walls.size(); i++){
				walls[i].x_coord += motion->xspeed;
				walls[i].y_coord += motion->yspeed;

			}

		}

		void BG::checkBullets(PlayerObject* player){
			for (unsigned int i = 0; i < B_Enemy.size(); i++){ //For every enemy in world

				//Enemy to player bullet collision
				for (unsigned int c = 0; c < B_Enemy[i].delaware.size(); c++){ //
					if (B_Enemy[i].delaware[c].bX >= -15 && B_Enemy[i].delaware[c].bX <= 15){ //The X coordinateCheck their bullet vectors to see if...s
						if (B_Enemy[i].delaware[c].bY >= -15 && B_Enemy[i].delaware[c].bY <= 15){//and Y coordinates are the same as the players region
							
							//If so, delete the bullet that collided, and remove health from the player
							B_Enemy[i].delaware.erase(B_Enemy[i].delaware.begin() + c);
							player->takeDamage(10);
						}
					}
				}

				//Player to enemy bullet collision
				for (unsigned int c = 0; c < player->shot.size(); c++){
					if (player->shot[c].bX >= B_Enemy[i].x_coord - 16 && player->shot[c].bX <= B_Enemy[i].x_coord + 16){
						if (player->shot[c].bY >= B_Enemy[i].y_coord - 16 && player->shot[c].bY <= B_Enemy[i].y_coord + 16){

							player->shot.erase(player->shot.begin() + c);
							B_Enemy[i].health -= 10;
							cout << "Enemy now has " << B_Enemy[i].health << " hp\n";
						}
					}
				}
			}
		}

		int BG::testCollision(){
			collided();

			if (hit && m_window->isKeyPressed(GLFW_KEY_A) &&
				colCode == 0){
				colCode = 1;
			}
			else if (hit && m_window->isKeyPressed(GLFW_KEY_D) &&
				colCode == 0){
				colCode = 2;
			}
			else if (hit && m_window->isKeyPressed(GLFW_KEY_W) &&
				colCode == 0){
				colCode = 3;
			}
			else if (hit && m_window->isKeyPressed(GLFW_KEY_S) &&
				colCode == 0){
				colCode = 4;
			}
			else if (!hit){
				colCode = 0;
			}

			return colCode;
		}


		void BG::collided(){
			hit = false;

			for (int i = 0; i < planets.size(); i++){
				if (planets[i].x_coord + (planets[i].radius / 2) >= -5 && planets[i].x_coord - (planets[i].radius / 2) <= 5){
					if (planets[i].y_coord + (planets[i].radius / 2) >= -5 && planets[i].y_coord - (planets[i].radius / 2) <= 5){
						hit = true;
					}
				}
			}

		}

	}
}