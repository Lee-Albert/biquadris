#include <algorithm>
#include <vector>
#include "subject.h"

Subject::~Subject() {}

void Subject::attach(Observer *o) {
	observers.emplace_back(o);
}

void Subject::detach(Observer *o) {
	observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());	
}

void Subject::notifyObservers(){
	for (auto &ob : observers) {
		ob->notify(*this);
	}
}
