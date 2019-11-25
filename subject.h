#ifndef SUBJECT_H 
#define SUBJECT_H

#include <vector>

class Observer;

class Subject {
	std::vector<Observer*> observers;
	~Subject();
  public:
	void attach(Observer *o);
	void detach(Observer *o);
	void notify();
};

#endif
