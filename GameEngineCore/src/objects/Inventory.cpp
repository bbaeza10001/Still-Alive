#include "Inventory.h"

namespace spacey{
	namespace GUI{
		Inventory::Inventory(){
			
		}


		Inventory::Inventory(Window* window, string filename){
			m_window = window;

			imageLoaded = loadImage(filename, m_image, u2, v2, u3, v3, width, height);

		}
		void Inventory::addtoInventory(BaseItem item){
			for (int i = 0; i < 9; i++){

				if (i == container.size()){
					container.push_back(item);
				}
				else if (i >= 9){
					container[i] = item;
				}

			}
		}
	}
}