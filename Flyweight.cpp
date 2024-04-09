#include <iostream>
#include <unordered_map>

class Character {
public:
    Character(char intrinsicState) : intrinsicState(intrinsicState) {}
    void draw(int extrinsicState) {
        std::cout << "Drawing character " << intrinsicState << " at position " << extrinsicState << std::endl;
    }
private:
    char intrinsicState;
};

class CharacterFactory {
public:
    Character *getCharacter(char key) {
        if(characters.find(key) == characters.end()) {
            characters[key] = new  Character(key);
        }
        return characters[key];
    }
private:
    std::unordered_map<char, Character*> characters;
};

int main() {
    CharacterFactory characterFactory;
    int position = 0;

    characterFactory.getCharacter('A')->draw(position++);
    characterFactory.getCharacter('B')->draw(position++);
    characterFactory.getCharacter('C')->draw(position++);

    return 0;
}