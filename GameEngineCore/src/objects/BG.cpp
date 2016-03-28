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
			if (type == "CIRCLE"){
				loadObject(planets, filename);
			}
			else if (type == "BASE_ENEMY"){
				loadObject(B_Enemy, filename);
			}
			else if (type == "WALL"){
				loadObject(walls, filename);
			}
			else if (type == "DOOR"){
				loadObject(doors, filename);
			}
			else if (type == "MELEE_ENEMY"){
				loadObject(Ml_Enemy, filename);
			}
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
			for (unsigned int i = 0; i < Ml_Enemy.size(); i++){
				if (Ml_Enemy[i].x_coord < 800 && Ml_Enemy[i].x_coord > -800){
					if (Ml_Enemy[i].y_coord < 600 && Ml_Enemy[i].y_coord > -600){
						Ml_Enemy[i].Draw(motion);
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

			for (unsigned int i = 0; i < doors.size(); i++){
				if (doors[i].x_coord < 800 && doors[i].x_coord > -800){
					if (doors[i].y_coord < 600 && doors[i].y_coord > -600){
						doors[i].draw(m_window);
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
			
			for (unsigned int i = 0; i < Ml_Enemy.size(); i++){
				Ml_Enemy[i].x_coord += motion->xspeed;
				Ml_Enemy[i].y_coord += motion->yspeed;
			}
			
			for (unsigned int i = 0; i < walls.size(); i++){
				walls[i].x_coord += motion->xspeed;
				walls[i].y_coord += motion->yspeed;
			}

			for (unsigned int i = 0; i < doors.size(); i++){
				doors[i].x_coord += motion->xspeed;
				doors[i].y_coord += motion->yspeed;
			}

		}

		void BG::checkBullets(PlayerObject* player){
			for (unsigned int i = 0; i < B_Enemy.size(); i++){ //For every basic enemy in world

				//Basic enemy -> player
				for (unsigned int c = 0; c < B_Enemy[i].delaware.size(); c++){ //
					if (B_Enemy[i].delaware[c].bX >= -15 && B_Enemy[i].delaware[c].bX <= 15){ //The X coordinateCheck their bullet vectors to see if...s
						if (B_Enemy[i].delaware[c].bY >= -15 && B_Enemy[i].delaware[c].bY <= 15){//and Y coordinates are the same as the players region

							//If so, delete the bullet that collided, and remove health from the player
							B_Enemy[i].delaware.erase(B_Enemy[i].delaware.begin() + c);
							player->takeDamage(10);
						}
					}
				}


				//Player -> basic enemy
				for (unsigned int c = 0; c < player->shot.size(); c++){
					if (player->shot[c].bX >= B_Enemy[i].x_coord - 16 && player->shot[c].bX <= B_Enemy[i].x_coord + 16){
						if (player->shot[c].bY >= B_Enemy[i].y_coord - 16 && player->shot[c].bY <= B_Enemy[i].y_coord + 16){

							player->shot.erase(player->shot.begin() + c);
							B_Enemy[i].health -= 10;
							cout << "Enemy now has " << B_Enemy[i].health << " hp\n";
						}
					}
				}
				//Death function. Created by Kenneth.
				for (unsigned int i = 0; i < B_Enemy.size(); i++){
					if (B_Enemy[i].health <= 0){
						B_Enemy.erase(B_Enemy.begin() + i);
					}
				}
				
				//Player -> melee enemy 
				for (unsigned int c = 0; c < player->shot.size(); c++){
					if (player->shot[c].bX >= Ml_Enemy[i].x_coord - 16 && player->shot[c].bX <= Ml_Enemy[i].x_coord + 16){
						if (player->shot[c].bY >= Ml_Enemy[i].y_coord - 16 && player->shot[c].bY <= Ml_Enemy[i].y_coord + 16){

							player->shot.erase(player->shot.begin() + c);
							Ml_Enemy[i].health -= 10;
							cout << "Enemy now has " << Ml_Enemy[i].health << " hp\n";
						}
					}
				}
			}
			for (unsigned int i = 0; i < Ml_Enemy.size(); i++){
				if (Ml_Enemy[i].health <= 0){ //removes the enemy when health = 0.
					Ml_Enemy.erase(Ml_Enemy.begin() + i); //Death created by Kenneth Morgridge.
				}
			}

			for (unsigned int i = 0; i < Ml_Enemy.size(); i++){ //For every melee enemy in world
				if ((Ml_Enemy[i].x_coord + 16 >= -16 && Ml_Enemy[i].x_coord - 16 <= 16) && (Ml_Enemy[i].y_coord + 16 >= -16 && Ml_Enemy[i].y_coord - 16 <= 16)) {
					player->takeDamage(10); //Deal damage if it touches the player
					if ((Ml_Enemy[i].x_coord + 16 >= -16 && Ml_Enemy[i].x_coord + 16 < 0)){// If it touches the player run away
						if ((Ml_Enemy[i].y_coord + 16 >= -16 && Ml_Enemy[i].y_coord + 16 < 0)){
							Ml_Enemy[i].direction = 6;
						}
						else
						{
							if ((Ml_Enemy[i].y_coord - 16 <= 16 && Ml_Enemy[i].y_coord - 16 > 0)){
								Ml_Enemy[i].direction = 8;
							}
							else{
								Ml_Enemy[i].direction = 5;
							}
						}
					}
					if ((Ml_Enemy[i].x_coord - 16 <= 16 && Ml_Enemy[i].x_coord - 16 > 0)){
						if ((Ml_Enemy[i].y_coord + 16 >= -16 && Ml_Enemy[i].y_coord + 16 < 0)){
							Ml_Enemy[i].direction = 4;
						}
						else{
							if ((Ml_Enemy[i].y_coord - 16 <= 16 && Ml_Enemy[i].y_coord - 16 > 0)){
								Ml_Enemy[i].direction = 2;
							}
							else{
								Ml_Enemy[i].direction = 1;
							}
						}
					}
					Ml_Enemy[i].steps = 0;
				}
				if (Ml_Enemy[i].x_coord > 150){//If it goes too far from the player come back
					if (Ml_Enemy[i].y_coord > 150){
						Ml_Enemy[i].direction = 6;
					}
					else
						if (Ml_Enemy[i].y_coord < -150){
							Ml_Enemy[i].direction = 8;
						}
						else{
							Ml_Enemy[i].direction = 7;
						}
						Ml_Enemy[i].steps = 200;
						//cout << "bounced off tether" << endl;
				}

				if (Ml_Enemy[i].x_coord < -150){
					if (Ml_Enemy[i].y_coord > 150){
						Ml_Enemy[i].direction = 6;
					}
					else{
						if (Ml_Enemy[i].y_coord < -150){
							Ml_Enemy[i].direction = 8;
						}
						else{
							Ml_Enemy[i].direction = 3;
						}
					}
					Ml_Enemy[i].steps = 200;
				//	cout << "bounced off tether" << endl;
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
			hit = false; //This bool is only for if the PLAYER hits something, everything else should
						 //only tell the respective AI to either stop or walk away

			// For Circles && Player
			for (int i = 0; i < planets.size(); i++){
				if (planets[i].x_coord + (planets[i].radius / 2) >= -16 && planets[i].x_coord - (planets[i].radius / 2) <= 16){
					if (planets[i].y_coord + (planets[i].radius / 2) >= -16 && planets[i].y_coord - (planets[i].radius / 2) <= 16){
						hit = true;
						cout << "Player hit circle\n";
					}
				}
			}

			// For player && Wall 
			for (int i = 0; i < walls.size(); i++){
				if (walls[i].x_coord - (walls[i].m_width / 2) <= 16 && walls[i].x_coord + (walls[i].m_width / 2) >= -16
					&& walls[i].y_coord + (walls[i].m_height / 2) >= -16 && walls[i].y_coord - (walls[i].m_height / 2) <= 16){
					hit = true;
					//cout << "Player hit Wall\n";
				}
			}

			// For player && Basic Enemy 
			for (int i = 0; i < B_Enemy.size(); i++){
				if (B_Enemy[i].x_coord - (B_Enemy[i].width / 2) <= 16 && B_Enemy[i].x_coord + (B_Enemy[i].width / 2) >= -16
					&& B_Enemy[i].y_coord + (B_Enemy[i].height / 2) >= -16 && B_Enemy[i].y_coord - (B_Enemy[i].height / 2) <= 16){
					hit = true;
					cout << "Basic Enemy hit player\n";
					//Call Basic Enemy's AI to move away
				}
			}

			// For player && Melee Enemy 
			for (int i = 0; i < Ml_Enemy.size(); i++){
				if (Ml_Enemy[i].x_coord - (Ml_Enemy[i].width / 2) <= 16 && Ml_Enemy[i].x_coord + (Ml_Enemy[i].width / 2) >= -16
					&& Ml_Enemy[i].y_coord + (Ml_Enemy[i].height / 2) >= -16 && Ml_Enemy[i].y_coord - (Ml_Enemy[i].height / 2) <= 16){
					hit = true;
					//cout << "Melee Enemy hit player\n";
					//Tell Melee Enemy's AI to move away
				}
			}

			// For Basic Enemy && Wall
			for (int i = 0; i < walls.size(); i++){
				for (int e = 0; e < B_Enemy.size(); e++){

					if (walls[i].x_coord - (walls[i].m_width / 2) <= B_Enemy[e].x_coord + (B_Enemy[e].width / 2) && walls[i].x_coord + (walls[i].m_width / 2) >= B_Enemy[e].x_coord - (B_Enemy[e].width / 2)
						&& walls[i].y_coord + (walls[i].m_height / 2) >= B_Enemy[e].y_coord - (B_Enemy[e].height / 2) && walls[i].y_coord - (walls[i].m_height / 2) <= B_Enemy[e].y_coord - (B_Enemy[e].height / 2)){
						//cout << "Basic Enemy hit Wall\n";
						// Tell Basic Enemy's AI to walk away
					}
				}
			}
			
			// For Melee Enemy && Wall
			for (int i = 0; i < walls.size(); i++){
				for (int e = 0; e < Ml_Enemy.size(); e++){

					if (walls[i].x_coord - (walls[i].m_width / 2) <= Ml_Enemy[e].x_coord + (Ml_Enemy[e].width / 2) && walls[i].x_coord + (walls[i].m_width / 2) >= Ml_Enemy[e].x_coord - (Ml_Enemy[e].width / 2)
						&& walls[i].y_coord + (walls[i].m_height / 2) >= Ml_Enemy[e].y_coord - (Ml_Enemy[e].height / 2) && walls[i].y_coord - (walls[i].m_height / 2) <= Ml_Enemy[e].y_coord - (Ml_Enemy[e].height / 2)){
						//cout << "Melee Enemy hit Wall\n";
						//Tell Melee Enemy's AI to walk away
					}
				}
			}
		}

	}
}