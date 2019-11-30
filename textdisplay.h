#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include <string>
#include "observer.h"
// other #includes

class Tile;
class TextDisplay: public Observer {
	std::vector<std::vector<string>> theDisplay;
	const int height = 18;
	const int width = 11;
  public:
	TextDisplay();
	
	void notify(Subject &whoNotified) override;
	
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
