//
// Created by damo on 2/14/16.
//

#include "MusicalBrain.h"
#include "../../../Utils/string_utils.h"
using namespace std;

void MusicalBrain::runLineNumber(int number, int caller) {
    long item=number % sequence.size();

    for(int i=0;i<sequence[item].size();i++){
        playKeyboardAudio(sequence[item][i]);
    }
    activateTimeoutForNextLine(number +1,1.0f/getFrequency(),number);
}

MusicalBrain::MusicalBrain() :
        Brain(),
        frequency(1.0f),
        sequence()
{

}

void MusicalBrain::setMusic(std::string string) {
    std::vector<std::string> notes=str_split(string,',');

    cout<<"End result"<<endl;
    for(int x=0;x< notes.size();x++){
        cout<< notes[x]<<x<<endl;
    }cout<<endl;

    for(int i=0;i<notes.size();i++){
        std::string note=notes[i];
        cout<<"note was "<<note<<endl;
        note=str_trim(note);
        cout<<"note is "<<note<<endl;
        std::vector<std::string> part=str_split(note,' ');

        cout<<"My result result"<<endl;
        for(int x=0;x< part.size();x++){
            cout<< part[x]<<x<<endl;
        }cout<<endl;

        for(int partIndex=0;partIndex<part.size();partIndex++){
//            part[partIndex]=str_trim(part[partIndex]);
        }

        sequence.push_back(part);
    }
}
