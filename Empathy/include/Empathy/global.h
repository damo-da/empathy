#include <iostream>

#ifndef EMPATHY_GLOBAL_H
#define EMPATHY_GLOBAL_H
namespace empathy{
    static std::string __base="Empathy/assets/";

    std::string join_path(std::string path1,std::string path2);

    void setBase(std::string path);
    std::string getBase();

    std::string getAssetPath(std::string);
}

#endif //EMPATHY_GLOBAL_H