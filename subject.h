#ifndef SUBJECT_H 
#define SUBJECT_H

#include <algorithm>
#include <vector>
#include "observer.h"
#include "info.h"

class Observer;

class Subject {
	std::vector<Observer*> observers;
  public:
	~Subject();
	void attach(Observer *o);
	void detach(Observer *o);
	void notifyObservers();
	virtual Info getInfo() = 0;
};
#endif
