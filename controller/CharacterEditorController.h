#pragma once

#include "../entity/Character.h"
#include "../view/CharacterView.h"


class CharacterEditorController {
    public:

        static const size_t BACKPACK_INIT_SIZE;

        static void selectAction();
		//static Character* selectCharacter();
        static void initializeBackpack(Character* character);
		static void saveCharacter(Character* character);
    private:
        static void createCharacter();
        static void editExistingcharacter();
        

};
