#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
class Tile;

class Observer {
  public:
	virtual void notify(Subject &whoFrom) = 0;
	virtual ~Observer() = default;
};

#endif
