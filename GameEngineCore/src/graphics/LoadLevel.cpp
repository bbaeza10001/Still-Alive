#include "LoadLevel.h"

namespace spacey{ namespace level{

	vector<CircleObject> Level::loadPlanets(vector<CircleObject> systemVector, string fileName){
		ifstream file;

		file.open(fileName);

		if (file.fail()){ //Check if the file is openable
			cout << "Opening level file named '" << fileName << "' failed.\n";
		}
		else{
			string line;
			int x, y, size, amount;

			while (file.is_open()){
				file >> line;

				if (line == "START"){ //Check if keyword is start
					file >> amount;

					for (int i = 0; i < amount; i++){
						file >> x >> y >> size; //read the values for the planet and add them to the vector

						CircleObject temp(x, y, size);

						systemVector.push_back(temp);
						cout << "Added element to vector.\n";
					}

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

		return systemVector;
	}

} }