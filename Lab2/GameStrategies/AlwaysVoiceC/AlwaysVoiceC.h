//
// Created by Макар Михалёв on 22.10.2022.

#ifndef LAB2_ALWAYSVOICEC_H
#define LAB2_ALWAYSVOICEC_H
#include "../GameStrategy/GameStrategy.h"

class AlwaysVoiceC : public GameStrategy {
public:
    Voice vote() override;
    void update(Voice playerA, Voice playerB) override;
    ~AlwaysVoiceC()  = default;
};


#endif