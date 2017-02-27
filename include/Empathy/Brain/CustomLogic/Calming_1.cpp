#include "Calming_1.h"
#include "../../LifeEvent/TextInput/TextInput.h"
#include "../../LifeEvent/Text/Text.h"

using namespace std;

void empathy::brain::Calming_1::runLineNumber(std::string lineID, std::string callerID, cJSON *overrideData) {
    JSONBrain::runLineNumber(lineID, callerID, overrideData);
    if (lineID == CALMING_COLLECT_NAME){
        life_event::TextInput * textInput = new life_event::TextInput();
        textInput->setColor(0.8, 0.5, 0.5);
        textInput->setText("");
        textInput->setIdentifier("calming_1_text_input");
        textInput->setCenterY(-0.065f);
        textInput->setDuration(1000);
        textInput->setFadeInDuration(0.f);
        textInput->setFadeOutDuration(0.5);
        textInput->addAction(this, EMPATHY_TEXT_INPUT_ENTERED, CALMING_COLLECT_NAME);
        textInput->addAction("user_name_input_label", EMPATHY_TEXT_INPUT_ENTERED, EMPATHY_LIFE_EVENT_FINISH);
        textInput->addAction(textInput, EMPATHY_TEXT_INPUT_ENTERED, EMPATHY_LIFE_EVENT_FINISH);
        addLifeEvent(textInput);



    }
    else if (lineID == CALMING_ACCESS_NAME){

        life_event::Text * showtext = new life_event::Text();
        showtext->setText("Hi, " + getName() + " !");
        showtext->setDuration(3);
        showtext->setFadeOutDuration(0.7);
        showtext->setCenterY(0.065);

        addLifeEvent(showtext);



    }
    else if (lineID == CALMING_HAPPINESS_CHECK){
        string emotion = "sad";

        if(true){

            life_event::Text * showtext = new life_event::Text();
            showtext->setText("You seem " + emotion + ".");

            showtext->setCenterY(0.065f);
            addLifeEvent(showtext);

            life_event::Text * showtext2 = new life_event::Text();

            showtext2->setText("");
            showtext2->setCenterY(-0.065f);
            showtext2->setDuration(3);
            showtext2->setFadeInDuration(0.2);

            addLifeEvent(showtext2);


            activateTimeoutForNextLine("s5", 6.0);

        }
    } else if(lineID == CALMING_SHOW_SMILE_MESSAGE){
        if(true){ //user is smiling
            life_event::Text * textInput = new life_event::Text();
            textInput->setColor(0.8, 0.5, 0.5);
            textInput->setText("Yes, Yes, That’s the big smile!");
            textInput->setCenterX(0);
            textInput->setCenterY(0);
            textInput->setDuration(3);
            textInput->setFadeOutDuration(0.5);
            textInput->setFadeInDuration(0.3);

            addLifeEvent(textInput);

            activateTimeoutForNextLine("p2.2", 4.0);
        }else{
            activateTimeoutForNextLine("p2.2", 0.0);
        }
    } else if(lineID == CALMING_YOU_KNOW_YOURSELF_MESSAGE){
        life_event::Text * textInput = new life_event::Text();
        textInput->setColor(0.8, 0.5, 0.5);
        textInput->setText(getName() + ", you already know everything");
        textInput->setDuration(3);
        textInput->setCenterY(0.065f);
        textInput->setFadeOutDuration(0.5);
        textInput->setFadeInDuration(1.5);
        addLifeEvent(textInput);

        life_event::Text * textInput2 = new life_event::Text();
        textInput2->setColor(0.8, 0.5, 0.5);
        textInput2->setText("to make yourself happy. You're awesome.");
        textInput2->setDuration(3);
        textInput2->setCenterY(-0.065f);
        textInput2->setFadeOutDuration(0.5);
        textInput2->setFadeInDuration(1.5);
        addLifeEvent(textInput2);


        activateTimeoutForNextLine("p2.3", 4.8);

    } else if(lineID == CALMING_SHOW_THANK_YOu){
        life_event::Text * textInput = new life_event::Text();
        textInput->setColor(0.8, 0.5, 0.5);
        textInput->setText("Thanks for trying Empathy, "+getName() + "!");
        textInput->setDuration(30000);
        textInput->setCenterY(0.065f);
        textInput->setFadeOutDuration(0.5);
        textInput->setFadeInDuration(0.3);

        addLifeEvent(textInput);

        life_event::Text * textInput2 = new life_event::Text();
        textInput2->setColor(0.8, 0.5, 0.5);
        textInput2->setText("I hope you enjoyed the experience");
        textInput2->setCenterY(-0.13f);
        textInput2->setDuration(30000);
        textInput2->setCenterY(-0.065f);
        textInput2->setFadeOutDuration(0.5);
        textInput2->setFadeInDuration(0.3);
        addLifeEvent(textInput2);

    }
}

empathy::brain::Calming_1::Calming_1() :
        empathy::brain::JSONBrain("brains/Calming_1.json"),
        name("Human") {

}

void empathy::brain::Calming_1::onReceiveEvent(empathy::radio::Event &event) {
    Brain::onReceiveEvent(event);

    if(event.action == CALMING_COLLECT_NAME){
        string name = event.getString(EMPATHY_TEXT_INPUT_TEXT);
        Calming_1::setName(name);

        runLineNumber("bg_trans_1", CALMING_COLLECT_NAME, nullptr);

        activateTimeoutForNextLine(CALMING_ACCESS_NAME, 0.3);
        activateTimeoutForNextLine("s4", 0.3);


    }
}

const string &empathy::brain::Calming_1::getName() const {
    return name;
}

void empathy::brain::Calming_1::setName(const string &name) {
    Calming_1::name = name;
}
