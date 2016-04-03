//
// Created by damo on 1/26/16.
//

#ifndef EMPATHY_UNIQUENESS_H
#define EMPATHY_UNIQUENESS_H

#include <vector>

/* The class to give everyone a unique identification.
 *
 * Just extend this class to remain unique!
 * */
class UniqueObject {
private:
    long id;

    /* List of all unique objects.
     *
     */
    static std::vector<UniqueObject *> objects;
public:
    static long lastId;

    /* Constructor. */
    UniqueObject();

    /* Return this instance's unique ID. */
    long getId() const{return id;}

    /* Get a subscriber by it's id.
     *
     * @static
     * */
    static UniqueObject *getById(int id) {
        for (int i = 0; i < objects.size(); i++) {
            if (objects[i]->getId() == id) {
                return objects[i];
            }
        }

        return nullptr;
    }
};


#endif //EMPATHY_UNIQUENESS_H
