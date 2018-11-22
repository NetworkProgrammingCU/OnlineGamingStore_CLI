// Guards
#ifndef _GAMEDATASTRUCT_H_
#define _GAMEDATASTRUCT_H_


typedef struct GameData
{
    char* title;            // Title of the game
    char* description;      // Description of the game
    char* publisher;        // Publisher of the game
    char* developers;       // Developers (or company) that created the game
    char* genre;            // Genre of the game
    char* notes;            // Specialized notes regarding the game
    
    // Linked List Functionality
    struct GameData *next;
} GameData;


// Concluding Guard
#endif
