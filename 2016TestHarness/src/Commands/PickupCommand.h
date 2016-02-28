#ifndef PickupCommand_H
#define PickupCommand_H

#include "Commands/Command.h"

class PickupCommand: public Command
{
public:
	PickupCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
