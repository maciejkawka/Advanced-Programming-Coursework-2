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
	int stepCounter, waitInRowCounter, roundCounter;
	bool isActivate,blocked;

public:
	
	Player();
	Player(Point _position);

	void SetPosition(int x, int y);
	void SetPosition(Point _position);
	inline void Disactivate() { isActivate = false; }
	void MoveTo(int x, int y);
	void MoveTo(Point _position);
	void Wait();

	inline void NextRound() { roundCounter++; }
	inline Point GetPosition() const { return position; }
	inline int GetStepNumber() const { return stepCounter; }
	inline bool GetState() const { return isActivate; }
	inline int GetRoundNumber() const { return roundCounter; }
	inline bool IsBlocked() const { return blocked; }
};