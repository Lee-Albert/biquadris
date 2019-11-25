#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
class Tile;

class Observer {
  public:
	virtual void notify(Suject &whoFrom) = 0;
	virtual ~Observer() = default;
};

#endif
