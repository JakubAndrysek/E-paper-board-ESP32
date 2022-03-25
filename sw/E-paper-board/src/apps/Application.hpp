#pragma once

class Application
{
private:
	/* data */
public:
	Application(/* args */);
	~Application();

	virtual int update() = 0;
};
