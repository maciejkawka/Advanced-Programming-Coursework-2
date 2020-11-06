#ifndef POINT_STR
#define POINT_STR

struct Point {
	int x;
	int y;
};

#endif

class Player {
private:

	Point position;
	int stepCounter, waitNumber;

public:
	
	Player();
	Player(Point _position);
	void SetPosition(int x, int y);
	void SetPosition(Point _position);
	void MoveTo(int x, int y);
	void MoveTo(Point _position);
	inline void Wait() { waitNumber++; }
	inline Point GetPosition() const { return position; }
	inline int GetStepNumber() const { return stepCounter; }
	inline int GetWaitNumber() const { return waitNumber; }
};