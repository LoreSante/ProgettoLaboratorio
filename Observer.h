//
// Created by lolle21 on 05/02/22.
//

#ifndef PROGETTOLABORATORIO_OBSERVER_H
#define PROGETTOLABORATORIO_OBSERVER_H


class Observer {
protected:
    virtual ~Observer() {};
public:
    virtual void update() =0;
};

#endif //PROGETTOLABORATORIO_OBSERVER_H
