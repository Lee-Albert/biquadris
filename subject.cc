#include <algorithm>
#include <vector>
#include "subject.h"

Subject::attach(Observer *o) {
	observers.emplace_back(o);
}

Subject::detach(Observer *o) {
	observers.erase(std::remove(v.begin(), v.end(), o), v.end());	
}

Subject::notify(){
	for (auto &ob : observers) {
		ob->notify(*this);
	}
}
