#ifndef ShootCommand_H
#define ShootCommand_H

#include "Commands/Command.h"

class ShootCommand: public Command
{
public:
	ShootCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool done;
	bool shot;
};

#endif
