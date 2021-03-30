#pragma once
class Door
{
public:
	Door(bool open, bool unlocked, int lockID);
	~Door();

	void setOpen(bool status);
	void setUnlocked(bool status);

	bool getOpen();
	bool getUnlocked();

	int getLockID();

private:
	bool open;
	bool unlocked;
	int lockID;
};

