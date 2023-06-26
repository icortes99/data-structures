#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Canton.h"
#include "CantonTxt.h"
using namespace std;

class LeerTxt{
private:
    vector<CantonTxt> cantonList;

public:
    LeerTxt();
    CantonTxt* obtener_canton_id(int);
};