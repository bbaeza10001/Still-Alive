#include "LoadLevel.h"

namespace spacey{ namespace level{

	void loadObject(vector<CircleObject> &systemVector, string fileName){
		ifstream file;

		file.open(fileName);

		if (file.fail()){ //Check if the file is openable
			cout << "Opening circle file named '" << fileName << "' failed.\n";
		}
		else{
			string line, filename;
			int x, y, size, amount;

			while (file.is_open()){
				file >> line;

				if (line == "START"){ //Check if keyword is start
					file >> amount;

					for (int i = 0; i < amount; i++){
						file >> x >> y >> size >> filename; //read the values for the planet and add them to the vector

						CircleObject temp(x, y, size, filename);

						systemVector.push_back(temp);
						cout << "Added element to vector.\n";
					}

				}
				else if (line == "ENDF"){//Check if the keyword is the end of the file
					cout << "Reached end of file.\n";
					file.close();
				}
			}
		}

	}

	void loadObject(vector<BaseEnemy> &systemVector, string fileName){
		ifstream file;

		file.open(fileName);

		if (file.fail()){ //Check if the file is openable
			cout << "Opening enemy file named '" << fileName << "' failed.\n";
		}
		else{
			string line, filename;
			int x, y, size, amount, texWidth, texHeight;

			while (file.is_open()){
				file >> line;

				if (line == "START"){ //Check if keyword is start
					file >> amount;

					for (int i = 0; i < amount; i++){
						file >> x >> y >> texWidth >> texHeight>> filename ; //read the values for the enemy and add them to the vector

						BaseEnemy temp(x, y, texWidth, texHeight, filename);

						systemVector.push_back(temp);
						cout << "Added element to vector.\n";
					}

				}
				else if (line == "ENDF"){//Check if the keyword is the end of the file
					cout << "Reached end of file.\n";
					file.close();
				}
			}
		}

	}
	
	void loadObject(vector<BaseMedic> &systemVector, string fileName){
		ifstream file;

		file.open(fileName);

		if (file.fail()){ //Check if the file is openable
			cout << "Opening enemy file named '" << fileName << "' failed.\n";
		}
		else{
			string line, filename;
			int x, y, size, amount, tWidth, tHeight;

			while (file.is_open()){
				file >> line;

				if (line == "START"){ //Check if keyword is start
					file >> amount;

					for (int i = 0; i < amount; i++){
						file >> x >> y >> tWidth >> tHeight >> filename; //read the values for the enemy and add them to the vector

						BaseMedic temp(x, y, tWidth, tHeight, filename);

						systemVector.push_back(temp);
						cout << "Added element to vector.\n";
					}

				}
				else if (line == "ENDF"){//Check if the keyword is the end of the file
					cout << "Reached end of file.\n";
					file.close();
				}
			}
		}

	}

	void loadObject(vector<MeleeEnemy> &systemVector, string fileName){
		ifstream file;

		file.open(fileName);

		if (file.fail()){ //Check if the file is openable
			cout << "Opening enemy file named '" << fileName << "' failed.\n";
		}
		else{
			string line, filename;
			int x, y, size, amount, tWidth, tHeight;

			while (file.is_open()){
				file >> line;

				if (line == "START"){ //Check if keyword is start
					file >> amount;

					for (int i = 0; i < amount; i++){
						file >> x >> y >> tWidth >> tHeight >> filename; //read the values for the Enemy and add them to the vector

						MeleeEnemy temp(x, y, tWidth, tHeight, filename);

						systemVector.push_back(temp);
						cout << "Added element to vector.\n";
					}

				}
				else if (line == "ENDF"){//Check if the keyword is the end of the file
					cout << "Reached end of file.\n";
					file.close();
				}
			}
		}

	}

	void loadObject(vector<Wall> &systemVector, string fileName){
		ifstream file;

		file.open(fileName);

		if (file.fail()){ //Check if the file is openable
			cout << "Opening wall file named '" << fileName << "' failed.\n";
		}
		else{
			string line, type;
			int x, y, size, width, height, amount;

			while (file.is_open()){
				file >> line;

				if (line == "START"){ //Check if keyword is start
					file >> amount;

					for (int i = 0; i < amount; i++){
						file >> width >> height >> x >> y >>  type; //read the values for the planet and add them to the vector

						Wall temp(width, height, x, y,  type);

						systemVector.push_back(temp);
						cout << "Added element to wall vector.\n";
					}

				}
				else if (line == "ENDF"){//Check if the keyword is the end of the file
					cout << "Reached end of file.\n";
					file.close();
				}
			}
		}

	}

	void loadObject(vector<Door> &systemVector, string fileName){
		ifstream file;

		file.open(fileName);

		if (file.fail()){ //Check if the file is openable
			cout << "Opening door file named '" << fileName << "' failed.\n";
		}
		else{
			string line, type;
			int x, y, size, width, height, cDir, oDir,amount;

			while (file.is_open()){
				file >> line;

				if (line == "START"){ //Check if keyword is start
					file >> amount;

					for (int i = 0; i < amount; i++){
						file >> x >> y >> width >> height >> cDir >> oDir >> type; //read the values for the planet and add them to the vector

						Door temp(x, y, width, height, cDir, oDir, type);

						systemVector.push_back(temp);
						cout << "Added element to door vector.\n";
					}

				}
				else if (line == "ENDF"){//Check if the keyword is the end of the file
					cout << "Reached end of file.\n";
					file.close();
				}
			}
		}

	}
} }