#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <sstream>
#include <fstream>
#include "widget.h"
#include "amoba.h"
#include "MainWindow.h"
using namespace genv;
using namespace std;


int main(){
    MainWindow *window = new MainWindow(1300, 600);
    amoba* a=new amoba(550,550, 10,50, 15);
    window->hozzaad(a);
    amoba* b=new amoba(550,550, 600,50, 30);
    window->hozzaad(b);
    window->loop();
    delete window;

    return 0;
}
