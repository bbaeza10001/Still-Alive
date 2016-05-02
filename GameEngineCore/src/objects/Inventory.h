#pragma once

#include "../graphics/Window.h"
#include <GL\GLU.h>
#include <GL\GL.h>
#include "BaseObject.h"
#include "../Items/BaseItem.h"
namespace spacey{
	namespace GUI{
		using namespace objects;
		using namespace graphics;
		using namespace items;

		class Inventory : public BaseObject{
		public:
			Inventory();
			Inventory(Window* window, string filename);
			void addtoInventory(BaseItem item);
		private:

			void select(int index);
			void drop(int index);
			void moveToHotbar(int index);
			void checkForInput();

		private:
			Window* m_window;
			bool IsOpened = false;
			vector<BaseItem> container;
		};
	}
}