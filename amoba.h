#ifndef AMOBA_H
#define AMOBA_H
#include "widget.h"
#include <vector>

class amoba : public widget{
    int seg;
    std::vector<std::vector<int>>v;
public:
    void rajzol();
    amoba(int size_x, int size_y, int pos_x , int pos_y, int seg);
        void event(genv::event ev);

};
#endif // AMOBA_H
