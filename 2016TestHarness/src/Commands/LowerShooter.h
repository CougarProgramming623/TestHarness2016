#ifndef LowerShooter_H
#define LowerShooter_H

#include "Commands/Command.h"

class LowerShooter: public Command
{
public:
	LowerShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
