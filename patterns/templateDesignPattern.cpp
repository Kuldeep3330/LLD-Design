#include <iostream>
using namespace std;

// class Character
// {
// public:
//     void createCharacter()
//     {
//         selectRace();
//         chooseWeapon();
//         learnSkill();
//     }

// protected:
//     virtual void selectRace() = 0;
//     virtual void chooseWeapon() = 0;
//     virtual void learnSkill()
//     {
//         cout << "learning basic combat skills.\n";
//     }
//     virtual ~Character() = default;
// };
// class Warrior : public Character
// {
// protected:
//     void selectRace() override
//     {
//         cout << "selected race: Orc.\n";
//     }
//     void chooseWeapon() override
//     {
//         cout << "Choose weapon Axe.\n";
//     }
//     void learnSkill() override
//     {
//         cout << "learning Advanced melee combat skills.\n";
//     }
// };
// // concrete subclass 2
// class Mage : public Character
// {
// protected:
//     void selectRace() override
//     {
//         cout << "Selected race: Elf.\n";
//     }
//     void chooseWeapon() override
//     {
//         cout << "Chose weapon: Staff.\n";
//     }
//     void learnSkill() override
//     {
//         cout << "Learning advanced magical skills.\n";
//     }
// };

// another example:  File Processing
class FileProcessor
{
public:
    void processFile()
    {
        openFile();
        readFile();
        closeFile();
    }

protected:
    virtual void openFile() = 0;
    virtual void readFile() = 0;
    void closeFile()
    {
        cout << "file closed\n";
    }
    virtual ~FileProcessor() = default;
};
class TextFileProcessor : public FileProcessor
{
protected:
    void openFile() override
    {
        cout << "file open in Text format.\n";
    }
    void readFile() override
    {
        cout << "reading data from the text file.\n";
    }
};

// Concrete Subclass 2
class BinaryFileProcessor : public FileProcessor
{
protected:
    void openFile() override
    {
        cout << "Opening a binary file.\n";
    }

    void readFile() override
    {
        cout << "Reading data from the binary file.\n";
    }
};
int main()
{
    cout << "Processing Text File:\n";
    TextFileProcessor textProcessor;
    textProcessor.processFile();

    cout << "\n processing Text file:\n";
    TextFileProcessor BinaryFileProcessor;
    BinaryFileProcessor.processFile();
    // cout << "creating warrior\n";
    // Warrior warrior;
    // warrior.createCharacter();
    // cout << "creating Mage.\n";
    // Mage mage;
    // mage.createCharacter();
    return 0;
}