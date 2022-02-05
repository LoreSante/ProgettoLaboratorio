//
// Created by lolle21 on 05/02/22.
//

#ifndef PROGETTOLABORATORIO_SUBJECT_H
#define PROGETTOLABORATORIO_SUBJECT_H

#include "Observer.h"

class Subject {
protected:
    virtual ~Subject() {};

public:
    virtual void registerObserver (Observer *o) =0;
    virtual void removeObserver (Observer * o) =0;
    virtual void notifyObserver () const =0;
};

#endif //PROGETTOLABORATORIO_SUBJECT_H
