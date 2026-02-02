//******************************************************************************
//Author : Evelyn Zuniga
// Assignment: GameStat Console App (Part 1)
//Description: This program is a game console that allows the user to create a  
//             character as well as input base stats. The user is able to select 
//             what they want to do in the console such as viewing the stats.
//*******************************************************************************

#include <iostream>
#include <string>

using namespace std;

 
int main() {
    // these are the variables used in the program
    int choice;
    bool keepRunning = true;
    string characterName;
    string characterClass;
    int classChoice;
    bool completedCharacter = false;
    
    double strength;
    double intelligence;
    double dexterity;
    double constitution; 
    int level = 0;
    
    int hp = 0;
    int mp = 0;
    double attackPower = 0;
    double defense = 0;
    
    const int MAX_LEVEL = 10;
    const int MAX_STAT = 20;
    
    // Main menu loop
    do {
        // Display menu
        cout << "\n=== GAMESTAT CHARACTER MANAGER ===" << endl;
        cout << "1. Create New Character" << endl;
        cout << "2. View Character Stats" << endl;
        cout << "3. Calculate Combat Ratings" << endl;
        cout << "4. Level Up Character" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        // Process menu choice
        switch (choice) {
            case 1:
                cout << "\n[Create Character]" << endl;
                
                cout << "Enter the name of your character: "; // allows user to enter name
                cin >> characterName;
                cout << endl; 
                
               
                cout << "Choose a Character Class: " << endl;
                cout << "1. Warrior" << endl;
                cout << "2. Mage" << endl;
                cout << "3. Rogue" << endl;
                cout << "4. Cleric" << endl;
                cout << "Enter your choice (1-4) : "; // allows user to enter a number to select a class
                cin >> classChoice;
                cout << endl;
                
                // while loop to ensure user enters a number between 1-4
                // numbers were used to be able to use switch
                while (classChoice < 1 || classChoice > 4) 
                    {
                        cout << "Invalid Character Choice, please choose again." << endl;
                        
                        // getting new input
                        
                        cout << "Choose a Character Class: " << endl;
                        cout << "1. Warrior" << endl;
                        cout << "2. Mage" << endl;
                        cout << "3. Rogue" << endl;
                        cout << "4. Cleric" << endl;
                        cout << "Please enter a valid choice (1-4) : " << endl;
                        cin >> classChoice;
                        cout << endl;
                    }
                // corresponds the class choice number with a character class
                if (classChoice == 1)
                    characterClass = "Warrior";
                else if (classChoice == 2)
                    characterClass = "Mage";
                else if (classChoice == 3)
                    characterClass = "Rogue";
                else
                    characterClass = "Cleric";
                
                // getting the base stats
               
               cout << "Enter your character's Base Stats(1-20)" << endl;
               
               cout << "Enter Character Strength (1-20): " ;
               cin >> strength; 
               cout << endl;
               
               //ensures stats are between 1-20
               if (strength < 1 || strength > 20 ) 
               {
                   cout << "Invalid Strength"; 
                   cout << endl;
               } else 
               
               {
                   cout << "Valid Strength";
                   cout << endl;
               }
                
                while (strength < 1 || strength >20)
                {
                   cout << "Please enter a valid character Strength (1-20): " ;
                   cin >> strength; 
                   cout << endl;
               
               }
               
               cout << "Enter Character Intelligence (1-20): " ;
               cin >> intelligence; 
               
               if (intelligence < 1 || intelligence > 20 ) 
               {
                   cout << "Invalid Intelligence"; 
                   cout << endl;
               } else 
               
               {
                   cout << "Valid Intelligence";
                   cout << endl;
               }
                
                while (intelligence < 1 || intelligence >20)
                {
                   cout << "Please enter a valid character intelligence (1-20): " ;
                   cin >> intelligence; 
                   cout << endl;
               
               }
               cout << endl;
               
               cout << "Enter Character Dexterity (1-20): " ;
               cin >> dexterity; 
               
               if (dexterity < 1 || dexterity > 20 ) 
               {
                   cout << "Invalid Dexterity"; 
                   cout << endl;
               } else 
               
               {
                   cout << "Valid Dexterity";
                   cout << endl;
               }
                
                while (dexterity < 1 || dexterity >20)
                {
                   cout << "Please enter a valid character Dexterity (1-20): " ;
                   cin >> dexterity; 
                   cout << endl;
               
               }
               
               cout << "Enter Character Constitution (1-20): " ;
               cin >> constitution; 
               
               if (constitution < 1 || constitution > 20 ) 
               {
                   cout << "Invalid Constitution"; 
                   cout << endl;
               } else 
               
               {
                   cout << "Valid Constitution";
                   cout << endl;
               }
                
                while (constitution < 1 || constitution > 20)
                {
                   cout << "Please enter a valid character Constitution (1-20): " ;
                   cin >> constitution; 
                   cout << endl;
               
               }
               
               // Class Bonuses Calculations
               
               switch (classChoice) {
                   case 1: 
                    strength += 3; // warrior bonus
                    break;
                   
                   case 2:
                    intelligence += 3; // mage bonus
                    break;
                   
                   case 3: 
                    dexterity += 3; // rogue bonus
                    break;
                   
                   case 4:
                    constitution += 3; // cleric bonus
                    break; 
               }
                level = 1;
                completedCharacter = true;
                   
                cout << "Congrats!! You have created a character." << endl;
                break;
               
                
            case 2:
            // ensures that user chooses choice 1 before anything else
            if (!completedCharacter) {
                cout << "Please create a character first!" << endl;
                break;
            }

            // calculations so combat stats can be displayed
                hp = (constitution * 10) + (level * 5);
                mp = (intelligence * 10) + (level * 3);
                defense = (constitution + dexterity) / 2;
                
                switch (classChoice) {
                    
                    // warrior
                    case 1: 
                        hp += 20;
                        attackPower = strength * 1.5;
                        break;
                    
                    // mage
                    case 2:
                        mp += 30;
                        attackPower = intelligence * 1.3;
                        break;
                    
                    // rogue
                    case 3:
                        attackPower = dexterity * 1.4;
                        break;
                    
                    // cleric 
                    case 4:
                    attackPower = (strength + intelligence) * 0.8;
                    break;
                }
                
                cout << "\n[View Stats]" << endl;
                
                cout << "\n=== CHARACTER PROFILE ===" << endl;
                cout << "Name: " << characterName << endl;
                cout << "Class: " << characterClass << endl;
                cout << "Level: " << level << endl;
                
                cout << "\n=== Base Stats=== " << endl;
                cout << "Strength: " << strength << endl;
                cout << "Intelligence: " << intelligence << endl;
                cout << "Dexterity: " << dexterity << endl;
                cout << "Constitution: " << constitution << endl;
                
                cout << "\n=== COMBAT STATS ===" << endl;
                cout << "Health Points: " << hp << endl;
                cout << "Mana Points: " << mp << endl;
                cout << "Attack Power: " << attackPower << endl;
                cout << "Defense: " << defense << endl;
                break;
                
                break;
                
            case 3:
            
            if (!completedCharacter) {
                cout << "Please create a character first!" << endl;
                break;
            }
            //calculations for combat ratings
                cout << "\n[Calculate Ratings]" << endl;
                
                hp = (constitution * 10) + (level * 5);
                mp = (intelligence * 10) + (level * 3);
                defense = (constitution + dexterity) / 2;
                
                switch (classChoice) {
                    
                    // warrior
                    case 1: 
                        hp += 20;
                        attackPower = strength * 1.5;
                        break;
                    
                    // mage
                    case 2:
                        mp += 30;
                        attackPower = intelligence * 1.3;
                        break;
                    
                    // rogue
                    case 3:
                        attackPower = dexterity * 1.4;
                        break;
                    
                    // cleric 
                    case 4:
                    attackPower = (strength + intelligence) * 0.8;
                    break;
                }
                
                cout << "\n=== COMBAT STATS ===" << endl;
                cout << "Health Points: " << hp << endl;
                cout << "Mana Points: " << mp << endl;
                cout << "Attack Power: " << attackPower << endl;
                cout << "Defense: " << defense << endl;
                break;
                
            case 4:
             
            if (!completedCharacter) {
                cout << "Please create a character first!" << endl;
                break;
            }
                cout << "\n[Level Up - Coming Soon]" << endl;
                
                if (level >= MAX_LEVEL) {
                    cout << "Congrats!!, you have reached the maximum level" << endl;
                } 
                
                cout << "\n=== Before Stats ===" << endl;
                cout << "Level: " << level << endl;
                cout << "Strength: " << strength << endl;
                cout << "Intelligence: " << intelligence << endl;
                cout << "Dexterity: " << dexterity << endl;
                cout << "Constitution: " << constitution << endl;
                
                // each base stat goes up by on each time user levels up
                if (strength < MAX_STAT) {
                    strength++;
                }
                if (intelligence < MAX_STAT) {
                    intelligence++;
                }
                if (dexterity < MAX_STAT) {
                    dexterity++;
                }
                if (constitution < MAX_STAT) {
                    constitution++;
                }
                if (level < MAX_LEVEL) { 
                    level++;
                }
                
                // recalculating the Stats
                hp = (constitution * 10) + (level * 5);
                mp = (intelligence * 10) + (level * 3);
                defense = (constitution + dexterity) / 2;
                
                
                switch (classChoice) {
                    
                    // warrior
                    case 1: 
                        hp += 20;
                        attackPower = strength * 1.5;
                        break;
                    
                    // mage
                    case 2:
                        mp += 30;
                        attackPower = intelligence * 1.3;
                        break;
                    
                    // rogue
                    case 3:
                        attackPower = dexterity * 1.4;
                        break;
                    
                    // cleric 
                    case 4:
                    attackPower = (strength + intelligence) * 0.8;
                    break;
                }
                cout << "\n=== After Stats === " << endl;
                cout << "Level: " << level << endl;
                cout << "Strength: " << strength << endl;
                cout << "Intelligence: " << intelligence << endl;
                cout << "Dexterity: " << dexterity << endl;
                cout << "Constitution: " << constitution << endl;
                
                cout << "\n=== New Combat Stats === " << endl;
                cout << "Health Points: " << hp << endl;
                cout << "Mana Points: " << mp << endl;
                cout << "Attack Power: " << attackPower << endl;
                cout << "Defense: " << defense << endl;
                break;
            
                
                break;
                
            case 5:
                cout << "\nThanks for using GameStat! Goodbye!" << endl;
                keepRunning = false;
                break;
                
            default:
                cout << "\nInvalid choice! Please enter 1-5." << endl;
                break;
        }
        
    } while (keepRunning);
    
    return 0;
}