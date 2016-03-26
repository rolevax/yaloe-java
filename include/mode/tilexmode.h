#ifndef TILEXMODE_H
#define TILEXMODE_H

#include "mode.h"

class TilexMode : public Mode
{
public:
    TilexMode(EditableDoc &doc);

    Result keyboard(Key key) override;
    Result onPushed() override;
    const char *name() override;
};

#endif // TILEXMODE_H
