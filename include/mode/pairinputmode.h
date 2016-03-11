#ifndef PAIRINPUTMODE_H
#define PAIRINPUTMODE_H

#include "mode/mode.h"

class PairInputMode : public Mode
{
public:
    PairInputMode(EditableDoc &doc);

    Result onPushed() override;
    void onResume() override;
    const char *name() override;

private:
    enum class Stage { KEY_DONE, VALUE_DONE };
    Stage stage;
};

#endif // PAIRINPUTMODE_H
