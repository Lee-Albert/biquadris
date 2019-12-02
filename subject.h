#ifndef SUBJECT_H 
#define SUBJECT_H

#include <algorithm>
#include <vector>

class Observer;

class Subject {
	std::vector<Observer*> observers;
  public:
	~Subject();
	void attach(Observer *o);
	void detach(Observer *o);
	void notifyObservers();
};

Subject::~Subject() {}

void Subject::attach(Observer *o) {
	observers.emplace_back(o);
}

void Subject::detach(Observer *o) {
	observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
}

void Subject::notifyObservers() {
	for (auto &ob : observers) {
		ob->notify(*this);
	}
}
#endif
