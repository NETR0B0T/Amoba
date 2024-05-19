#include "graphics.hpp"
#include "amoba.h"
#include "widget.h"
#include <iostream>
#include <cmath>
using namespace genv;
using namespace std;

int turn=1;

amoba::amoba(int size_x, int size_y, int pos_x , int pos_y, int seg): widget(size_x, size_y, pos_x, pos_y), seg(seg), v(seg, vector<int>(seg,0)) {}
void amoba::rajzol(){
    gout << move_to(pos_x,pos_y) << color(209,209,209) << box(size_x,size_y) << move_to(pos_x+20,pos_y+20);
    //rakjuk ki a negyzeteket
    for(int y=0; y<seg; y++){
        for(int x=0; x<seg; x++){
            if(v[x][y]==0){gout << move_to(2+pos_x+(size_x/seg)*x, 2+pos_y+(size_y/seg)*y) << color(180,180,180) << box(size_x/seg-4, size_y/seg-4);} //0 szurke
            if(v[x][y]==1){gout << move_to(2+pos_x+(size_x/seg)*x, 2+pos_y+(size_y/seg)*y) << color(255,0,0) << box(size_x/seg-4, size_y/seg-4);} //1 piros
            if(v[x][y]==-1){gout << move_to(2+pos_x+(size_x/seg)*x, 2+pos_y+(size_y/seg)*y) << color(0,0,255) << box(size_x/seg-4, size_y/seg-4);} //-1 kek
        }
    }
}
void amoba :: event(genv::event ev){

        int m_x =ev.pos_x;
        int m_y =ev.pos_y;
        if(m_x > pos_x && m_x < pos_x+size_x && m_y > pos_y && m_y < pos_y+size_y && ev.button ==-btn_left){
         int p_x = std::ceil((m_x-pos_x)/(size_x/seg));
         int p_y = std::ceil((m_y-pos_y)/(size_y/seg));
         if(v[p_x][p_y]==0){ //ha szurke a hatter
            v[p_x][p_y] = turn;
            turn*=-1;
         }
            cout << p_x << " " << p_y << endl;
           }

    }
