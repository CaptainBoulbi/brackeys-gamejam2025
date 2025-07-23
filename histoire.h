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
    [VIOLA]   = { .name = "Viola" },
    [ARCHIE]  = { .name = "Archie" },
    [MINUIT]  = { .name = "Minuit" },
    [PHILLIP] = { .name = "Phillip" },
    [ED]      = { .name = "Ed" },
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

#define NB_BRANCHE 18
typedef struct Histoire {
    int nb_branche;
    Branche branches[NB_BRANCHE];
} Histoire;

typedef struct Historique {
    int idx_branche;
    int branche[NB_BRANCHE];
    int idx_conv;
    int conversation[NB_CONVERSATION_MAX];
} Historique;

Historique historique = {0};

Histoire histoire = {
    .nb_branche = 3,
    .branches = {

                [0] = {
            .personne = VIOLA,
            .nb_conversation = 9,
            .conversations = {
                // transition : 2870, you arrive at New Mountain, in the bar 'L'Atout' and meet Viola Fowler, drinking a glass.
                {
                    1.0f, 2.0f, "Do we know each other?", 2, {
                        "We met at L'Atout earlier",
                        "We shared a drink",
                    },
                },
                {
                    2.0f, 1.0f, "Oh yes, I remember", 0, {},
                },
                {
                    2.0f, 1.0f, "The guy with the whiskey, right?", 2, {
                        "That's right!",
                        "Exactly",
                    },
                },

                {
                    2.0f, 1.0f, "Perfect", 1, {
                        "We started talking after your friend fell off his chair"
                    },
                },

                {
                    2.0f, 1.0f, "That's Ed, he doesn't handle alcohol very well", 0, {}
                },

                {
                    2.0f, 1.0f, "It was quite funny to watch", 0, {}
                },

                {
                    2.0f, 1.0f, "Well, he's a great person", 2, {
                        "I'm sure of it",
                        "Just like you",
                    },
                },

                {
                    2.0f, 1.0f, "See! Even you noticed!", 0, {}
                },

                {
                    2.0f, 1.0f, "Well, sorry to cut this short, but I have to go meet some friends. You can message me around 10 PM, I'll be back", 2, {
                        "No problem",
                        "Alright, see you later",
                    },
                },

                {
                    2.0f, 1.0f, "See you tonight", 2, {
                        // set time to 10 PM
                        "(Say nothing)",
                        "I'm here!"
                    },
                },
            },
            .next = {1, 2}
        },

        [1] = {
            .personne = VIOLA,
            .nb_conversation = 4,
            .conversations = {
                // set time to 10:17 PM
                {
                    2.0f, 1.0f, "Are you there?", 2, {
                        "I had work",
                        "I was busy"
                    },
                },

                {
                    2.0f, 1.0f, "So you're a serious person?", 0, {}
                },

                {
                    2.0f, 1.0f, "What do you do for work?", 3, {
                        "I'm in tech",
                        "I'm in sales",
                        "I'm still a student",
                    },
                },

                {
                    2.0f, 1.0f, "Oh, that's great!", 0, {}
                },
            },
            .next = {3}
        },

        [2] = {
            .personne = VIOLA,
            .nb_conversation = 4,
            .conversations = {
                {
                    2.0f, 1.0f, "You're very punctual!", 1, {
                        "You have to be",
                    },
                },
                {
                    2.0f, 1.0f, "Sometimes you have to take your time", 0, {}
                },
                {
                    2.0f, 1.0f, "Did you have a good evening?", 2, {
                        "Awful",
                        "Meh, and you?",
                    },
                },
                {
                    2.0f, 1.0f, "Let's hope we cheer up by talking then", 0, {}
                },
            },
            .next = {3}
        },

        [3] = {
            .personne = VIOLA,
            .nb_conversation = 4,
            .conversations = {
                {
                    2.0f, 1.0f, "My evening was quite eventful, we went to mess with the police", 0, {}
                },
                {
                    2.0f, 1.0f, "I'm part of the Purple Sky", 2, {
                        "The terrorists?",
                        "The revolutionary group?",
                    },
                },
                {
                    2.0f, 1.0f, "I prefer to say 'activist group' but yes, that's us", 0, {}
                },
                {
                    2.0f, 1.0f, "We fight for freedom", 0, {}
                },
            },
            .next = {4}
        },

        [4] = {
            .personne = VIOLA,
            .nb_conversation = 3,
            .conversations = {
                // transition : One week later, you continued talking with Viola.
                // set time to 4:00 PM
                {
                    2.0f, 1.0f, "Midnight wants to meet you, if you're okay with that", 2, {
                        "Midnight? Who is that?",
                        "Is he a friend of yours?",
                    },
                },
                {
                    2.0f, 1.0f, "He's the leader of the Purple Sky", 1, {
                        "Why does he want to see me?",
                    },
                },
                {
                    2.0f, 1.0f, "He's been interested in you since the night at L'Atout", 2, {
                        "Alright, when does he want to meet?",
                        "No, I refuse to meet him",
                    },
                },
            },
            .next = {5,6}
        },

        [5] = {
            .personne = VIOLA,
            .nb_conversation = 1,
            .conversations = {
                {
                    2.0f, 1.0f, "Meet me behind the bar L'Atout at 11pm tonight", 2, {
                        "I'll be there",
                        "OK, see you tonight",
                    },
                },
            },
            .next = {7}
        },

        [6] = {
            .personne = VIOLA,
            .nb_conversation = 3,
            .conversations = {
                {
                    2.0f, 1.0f, "Okay, it's your choice", 0, {},
                },
                {
                    2.0f, 1.0f, "I'll have to delete this discussion then", 0, {},
                },
                {
                    2.0f, 1.0f, "Farewell", 0, {}
                },
            },
            .next = {0}
        },

        [7] = {
            .personne = MINUIT,
            .nb_conversation = 4,
            .conversations = {
                {
                    // transition: You are behind the Atout bar
                    // set time to 11pm
                    2.0f, 1.0f, "Are you the new guy?", 2, {
                        "I'm Viola's friend",
                        "Yes, I am."

                    },
                },
                {
                    2.0f, 1.0f, "I'm Midnight, I'm the leader of the Purple Sky", 0, {},
                },
                {
                    2.0f, 1.0f, "And Viola's ex too", 2, {
                        "Right."
                        "Speaking of Viola, she's running late"
                    },
                },
                {
                    2.0f, 1.0f, "I hear police sirens, what's going on?", 0, {},
                },
                {
                    2.0f, 1.0f, "Shit! It's too close, follow me", 2, {
                        "Let's go, it could be Viola",
                        "Uh ... are you sure we should go?"
                    },
                },
        },
        .next = {8, 9}
    },

    [8] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "That's her, I recognize her", 2, {
                        "No, not that",
                        "We've got to get her out of there",

                    },
                },
                {
                    2.0f, 1.0f, "Don't move, I'll try to go and see", 2, {
                        "No, it's too dangerous. The Purple Sky can't lose their leader",
                        "Okay, be careful",
                    },
                },
        },
        .next = {10, 11}
    },

    [9] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "And what else do you want to do? If it's Viola I won't forgive you, I'm going alone", 0, {},
                },
                {
                    2.0f, 1.0f, "Act like a coward if you want, but I'm going", 0, {},
                },
        },
        .next = {11}
    },

    [10] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "You may be right, but I can't lose Viola", 0, {},
                },
                {
                    2.0f, 1.0f, "Act like a coward if you want, but I'm going", 0, {},
                },
        },
        .next = {11}
    },

    [11] = {
            .personne = ARCHIE,
            .nb_conversation = 3,
            .conversations = {
                {
                    2.0f, 1.0f, "Don't be too upset with him, he really cares about her", 0, {},
                },
                {
                    2.0f, 1.0f, "By the way, I'm Archie", 0, {},
                },
                {
                    2.0f, 1.0f, "I'm Midnight's friend, and therefore a member of Purple Sky", 2, {
                        "Er... Nice to meet you, I guess."
                        "Where'd you come from? You scared me."
                    },
                },
        },
        .next = {12, 13}
    },

    [12] = {
            .personne = ARCHIE,
            .nb_conversation = 1,
            .conversations = {
                {
                    2.0f, 1.0f, "Nice to meet you", 0, {},
                },
        },
        .next = {14}
    },

    [13] = {
            .personne = ARCHIE,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "I'm Midnight's bodyguard", 0, {},
                },
                {
                    2.0f, 1.0f, "So I follow him wherever he goes", 0, {},
                },
        },
        .next = {14}
    },

    [14] = {
            .personne = ARCHIE,
            .nb_conversation = 3,
            .conversations = {
                {
                    2.0f, 1.0f, "By the way, it looks like the sirens have calmed down", 0, {},
                },
                {
                    2.0f, 1.0f, "Here comes Midnight again", 0, {},
                },
                {
                    2.0f, 1.0f, "I'm off, good luck, he looks angry", 0, {},
                },
        },
        .next = {15}
    },

    [15] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "C'ETAIT VIOLA !!!", 0, {},
                },
                {
                    2.0f, 1.0f, "THIS IS ALL YOUR FAULT! YOU CALLED THEM!", 2, {
                        "WHAT?! Of course not",
                        "Calm down, it's just bad luck"
                    },
                },
        },
        .next = {16, 17}
    },

    [16] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "IF! I didn't trust you and I was right", 0, {},
                },
                {
                    2.0f, 1.0f, "If you're here to cause trouble, get the hell out", 0, {},
                },

                // transition: You leave, leaving Midnight and Archie to decide how to free Viola. Thanks for playing this demo
        },
        .next = {0}
    },
    [17] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "BAD LUCK, HUH?! SHE CALLS THE COPS 'BAD LUCK'??", 0, {},
                },
                {
                    2.0f, 1.0f, "*pulls out a laser gun* YOU'RE GOING TO JOIN HER IN HELL, SCUM", 0, {},
                },

                // transition: Midnight shoots, killing you instantly. Thank you for playing this demo.
        },
        .next = {0}
        }
    }

};