typedef struct Personne {
    int active;
    Texture pp;
    const char* name;
    const char* message;
} Personne;

typedef enum PersonneId {
    VIOLA,
    ARCHIE,
    MINUIT,
    PHILLIP,
    ED,
} PersonneId;

#define MAX_PERSONNE 5
int personne_idx = 0;
Personne personnes[MAX_PERSONNE] = {
    [0] = { .name = "Viola" },
    [1] = { .name = "Archie" },
    [2] = { .name = "Minuit" },
    [3] = { .name = "Phillip" },
    [4] = { .name = "Ed" },
};

void init_personnes(void)
{
    personnes[0].pp = LoadTexture("data/viola.png");
    personnes[1].pp = LoadTexture("data/archie.png");
    personnes[2].pp = LoadTexture("data/minuit.png");
    personnes[3].pp = LoadTexture("data/phillip.png");
    personnes[4].pp = LoadTexture("data/ed.png");
}

#define NB_REPONSE_MAX 4
typedef struct Conversation {
    float read_time, write_time;
    const char* question;
    int nb_reponse;
    const char* reponses[NB_REPONSE_MAX];
} Conversation;

#define NB_CONVERSATION_MAX 10
typedef struct Branche {
    PersonneId personne;
    int nb_conversation;
    Conversation conversations[NB_CONVERSATION_MAX];
    int next[NB_REPONSE_MAX];
} Branche;

#define NB_BRANCHE 10
typedef struct Histoire {
    int nb_branche;
    Branche branches[NB_BRANCHE];
} Histoire;

Histoire histoire = {
    .nb_branche = 3,
    .branches = {

        [0] = {
            .personne = VIOLA,
            .nb_conversation = 2,
            .conversations = {
                [0] = {
                    1.0f, 2.0f, "Salut bg!", 2, {
                        "Salut, tu est qui ?",
                        "Salut, on ce connait ?",
                    }
                },
                [1] = {
                    2.0f, 1.0f, "Bah c'est moi, Viola", 2, {
                        "Aaah, Viola. connait pas",
                        "Mais oui viola, comment ça va ?",
                    }
                },
            },
            .next = {1, 2}
        },

        [1] = {
            .personne = VIOLA,
            .nb_conversation = 1,
            .conversations = {
                {
                    3.0f, 0.5f, "Ration + banane", 0, {},
                }
            },
            .next = {0}
        },

        [2] = {
            .personne = ARCHIE,
            .nb_conversation = 4,
            .conversations = {
                {
                    0.0f, 1.0f, "Eh, toi, parle pas a ma meuf!", 3, {
                        "PTDR T KI ?",
                        "on se connait ?",
                        "jparle a qui je veut en faite",
                    }
                },
                {
                    2.0f, 0.5f, "SI TU PARLE ENCORE UNE FOIS A ELLE JE TE RETOURNE ET...", 3, {
                        "C'est vrai ça ?",
                        "Ptit coquin",
                        "Grrrr...",
                    }
                },
                {
                    1.5f, 1.0f, "Euuuh, comment ça mon reuf ?", 2, {
                        "Bah quoi tu veut pas ?",
                        "Désabille toi grabuge",
                    }
                },
                {
                    1.0f, 1.5f, "vasi on bz", 2, {
                        "OUI!",
                        "OUI! je ramène la sauce piquante",
                    }
                },
            },
            .next = {0}
        },

    },
};
