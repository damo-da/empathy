//
// Created by damo on 2/14/16.
//

#include "MusicalBrain.h"
#include "../../../Utils/string_utils.h"
using namespace std;

void MusicalBrain::runLineNumber(std::string lineID, std::string callerID) {
    int number;
    if(lineID=="begin"){
        number=1;
    }else{
        number=str_to_int(lineID);
    }


    while(number>sequence.size())number -= sequence.size();
    int item=number-1;

    cout<<"playing "<<number<<": ";
    for(int i=0;i<sequence[item].size();i++){
        playKeyboardAudio(sequence[item][i]);
        cout<<sequence[item][i]<<" ";
    }
    cout<<endl;

    activateTimeoutForNextLine(int_to_str(number +1),1.0f,int_to_str(number));
}

MusicalBrain::MusicalBrain() :
        Brain(),
        frequency(1.0f),
        sequence()
{

}

void MusicalBrain::setMusic(std::string string) {
    std::vector<std::string> notes=str_split(string,',');

    for(int i=0;i<notes.size();i++){
        std::string note=notes[i];

        note=str_trim(note);

        std::vector<std::string> part=str_split(note,' ');

        sequence.push_back(part);
    }
}
