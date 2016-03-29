#include "MeleeEnemy.h"

namespace spacey{
	namespace objects{
		MeleeEnemy::MeleeEnemy(){
			x_coord = 0;
			y_coord = 0;
		}

		MeleeEnemy::MeleeEnemy(int x, int y, int tWidth, int tHeight, string filename){
			x_coord = x;
			y_coord = y;
			m_texWidth = tWidth;
			m_texHeight = tHeight;
			imageLoaded = loadAnimateable(filename, m_image, u2, v2, width, height);

			framesPerRow = width / m_texWidth;
		}

		MeleeEnemy::~MeleeEnemy(){

		}

		void MeleeEnemy::AI(string indicator){
			walk();

			//If it walks into the player...
			if (indicator == "RETREAT"){
				AI_Flag = indicator;

				//Find a direction to retreat to
				if ((x_coord + 16 >= -16 && x_coord + 16 < 0)){// If it touches the player run away
					if ((y_coord + 16 >= -16 && y_coord + 16 < 0)){
						direction = 6;
					}
					else
					{
						if ((y_coord - 16 <= 16 && y_coord - 16 > 0)){
							direction = 8;
						}
						else{
							direction = 5;
						}
					}
				}
				if ((x_coord - 16 <= 16 && x_coord - 16 > 0)){
					if ((y_coord + 16 >= -16 && y_coord + 16 < 0)){
						direction = 4;
					}
					else{
						if ((y_coord - 16 <= 16 && y_coord - 16 > 0)){
							direction = 2;
						}
						else{
							direction = 1;
						}
					}
				}

				steps = 0;
			}
			else if (indicator == "IDLE"){
				AI_Flag = indicator;
			}
		}

		void MeleeEnemy::walk(){
			if (steps >= STEP_MAX){
				steps = 0;
				direction = rand() % 8 + 1;
			}
			else{
				switch (direction){
				case 1: //Up
					y_coord += 0.4;
					mObj.animFlag = "WALK_UP";
					break;
				case 2: //Up Right
					x_coord += 0.4;
					y_coord += 0.4;
					break;
				case 3:  //Right
					x_coord += 0.4;
					mObj.animFlag = "WALK_RIGHT";
					break;
				case 4: //Down Right
					x_coord += 0.4;
					y_coord -= 0.4;
					break;
				case 5: //Down
					y_coord -= 0.4;
					mObj.animFlag = "WALK_DOWN";
					break;
				case 6: //Left Down
					x_coord -= 0.4;
					y_coord -= 0.4;
					break;
				case 7: //Left
					x_coord -= 0.4;
					mObj.animFlag = "WALK_LEFT";
					break;
				case 8: //Left Up
					x_coord -= 0.4;
					y_coord += 0.4;
					break;
				default:
					std::cout << "Not a valid enemy movement key.\n";
					break;
				}

				steps++;

				//Check if it has walked too far from the player
				if (x_coord > 150){
					if (y_coord > 150){
						direction = 6;
					}
					else
						if (y_coord < -150){
							direction = 8;
						}
						else{
							direction = 7;
						}
						steps = 200;
						cout << "bounced off tether" << endl;
				}

				if (x_coord < -150){
					if (y_coord > 150){
						direction = 6;
					}
					else{
						if (y_coord < -150){
							direction = 8;
						}
						else{
							direction = 3;
						}
					}
					steps = 200;
					cout << "bounced off tether" << endl;
				}
			}
		}
	}
}