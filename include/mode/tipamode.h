#ifndef TIPAMODE_H
#define TIPAMODE_H

#include "mode.h"

class TipaMode : public Mode
{
public:
    TipaMode(EditableDoc &doc);

    Result keyboard(char key, bool top) override;
    Result onPushed() override;
    const char *name() override;
};

#endif // TIPAMODE_H
