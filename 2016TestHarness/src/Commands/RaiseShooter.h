#ifndef RaiseShooter_H
#define RaiseShooter_H

#include "Commands/Command.h"

class RaiseShooter: public Command
{
public:
	RaiseShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
