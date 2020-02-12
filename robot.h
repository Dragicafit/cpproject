#define SIZE_X 10
#define SIZE_Y 10
#define VITESSE_MAX 10
#define MISSILES_MAX 2
#define COLLISION 0.02

typedef struct
{
    float position;
    float vitesse;
    float degat;
    int nb_missiles;
    char mort; /*Boolean*/
    char* script;
} robot;

typedef struct
{
    float vitesse;
    float direction;
} engine;

typedef struct
{
    float direction;
    int distance;
} shoot;

union
{
    engine engine;
    shoot shoot;
} action;

void nextInstruction(); // int si erreur
void miseAJour();
void degats();
int[] posToInt();
void init();
void destruction();
