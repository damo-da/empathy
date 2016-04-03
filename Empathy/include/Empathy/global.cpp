#include "global.h"



std::string empathy::join_path(std::string path1,std::string path2)
{
    if(path1[path1.size()-1]=='\\' || path1[path1.size()-1]=='/'){
        return path1+path2;
    }else{
        return path1+"/"+path2;
    }
}

void empathy::setBase(std::string path)
{
    __base=path;
}

std::string empathy::getBase()
{
    return __base;
}

std::string empathy::getAssetPath(std::string dir)
{
    return join_path(__base,dir);
}