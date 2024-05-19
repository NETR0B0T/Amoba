#include "graphics.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <sstream>
#include <fstream>
#include "widget.h"
#include "szambeiro.h"
#include "legordulo.h"
#include "button.h"
#include "amoba.h"
using namespace genv;
using namespace std;
const int XX=600, YY=600;

void loop(std::vector<widget*> & widgets){
    event ev;
    int index =-1;
       while(gin >> ev && ev.keycode != key_escape){
           if(ev.type==ev_mouse && ev.button == btn_left){
               for(size_t i=0; i<widgets.size(); i++){
                   if(widgets[i]->active(ev.pos_x, ev.pos_y)){
                       index =i;
                     //  cout << index;
                   }
               }
           }
           if(index!=-1){
               widgets[index]->event(ev);
           }
           for(widget* it: widgets){
               it->rajzol();
               gout << refresh;
           }
       }
}

int main(){
    gout.open(XX,YY);
    std::vector<widget*> widgets;
        amoba* a=new amoba(400, 400, 10,50, 3);
        widgets.push_back(a);
        a->rajzol();
        loop(widgets);
 /*
    szambeiro* a=new szambeiro(400, 200, 10,50,0);
        vector<string> szavak;
        szavak.push_back("alma");
        szavak.push_back("korte");
        szavak.push_back("szilva");
        szavak.push_back("banan");
        szavak.push_back("plusz");
        szavak.push_back("hehehehe");
    legordulo* b=new legordulo(400, 200, 10,300, szavak, 0, 1);
    button* c=new button(100,50, 450, 20, 1);
    widgets.push_back(a);
    a->rajzol();
    widgets.push_back(b);
    b->rajzol();
    widgets.push_back(c);
    c->rajzol();
    loop(widgets);
    //b.rajzol(10,300);
   // event ev;
    //int m_x= 0;
    //int m_y =0;
   // ofstream kifajl("Ertekek.txt");

  //  kifajl << "Kivalasztott szam: " << a->get_ertek() << endl;
   //     kifajl << "Kivalasztott string: " << b.get_ertek();
   //     kifajl.close();
*/
    return 0;
}
