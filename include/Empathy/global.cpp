#include "global.h"

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
#include <direct.h>
    #define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

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
    char cCurrentPath[FILENAME_MAX];

    if(__base==""){

        if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
        {
            __base= "";

            std::cout<<"Error setting base Directory!"<<std::endl;
        }else{
            cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

            __base=join_path(std::string(cCurrentPath),"empathy");

            std::cout<<"Base changed to "<<__base<<std::endl;
        }




    }


    return __base;
}

std::string empathy::getAssetPath(std::string dir)
{
    return join_path(getBase(),join_path("assets",dir));
}