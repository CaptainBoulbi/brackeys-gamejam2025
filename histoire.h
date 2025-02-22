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
            .nb_conversation = 9,
            .conversations = {
                // transition : 2870, vous arrivez à New Mountain, dans le bar ‘L’Atout’ et vous rencontrez Viola Fowler, en train de boire un verre.
                [0] = {
                    1.0f, 2.0f, "On se connait ?", 2, {
                        "On s'est rencontrés à l'Atout tout à l'heure",
                        "On a partagé un verre",
                    },
                },
                [1] = {
                    2.0f, 1.0f, "Ah oui, je m'en souviens", 0, {}

                    2.0f, 1.0f, "Le type au whisky c'est ça ?", 2, {
                        "C'est bien ça !",
                        "Tout à fait",
                    },
                },

                [2] = {
                    2.0f, 1.0f, "Parfait", 1, {
                        "On a commencé à parler après que ton ami soit tombé de sa chaise"
                    },
                },

                [3] = {
                    2.0f, 1.0f, "C'est Ed, il tient assez mal l'alcool", 0, {}
                },

                [4] = {
                    2.0f, 1.0f, "C'était assez drôle à voir", 0, {}
                },

                [5] = {
                    2.0f, 1.0f, "Enfin c'est une personne géniale", 2, {
                        "J'en suis certain",
                        "Tout comme toi",
                    },
                },

                [6] = {
                    2.0f, 1.0f, "Tu vois ! Même toi tu l'as remarqué !", 0, {}
                },

                [7] = {
                    2.0f, 1.0f, "Bon, je suis désolée de couper court mais je dois aller rejoindre des amis. Tu peux m'envoyer un message vers 22h00, je serai de retour", 2, {
                        "Pas de soucis",
                        "D'accord, à toute à l'heure",
                    },
                },

                [8] = {
                    2.0f, 1.0f, "A ce soir", 2, {
                        // mettre l'heure à 22h
                        "(Ne rien dire)",
                        "Je suis là !"
                    },
                },
            },
            .next = {1, 2}
        },

        [1] = {
            .personne = VIOLA,
            .nb_conversation = 4,
            .conversations = {
                // mettre l'heure à 22h17
                [0] = {
                    2.0f, 1.0f, "Tu es là ?", 2, {
                        "J'avais du travail",
                        "J'étais occupé"
                    },
                },

                [1] = {
                    2.0f, 1.0f, "Tu es quelqu'un de sérieux donc ?", 0, {}
                },

                [2] = {
                    2.0f, 1.0f, "Tu travailles dans quoi ?", 3, {
                        "Je suis dans la tech",
                        "Je suis commercial",
                        "Je suis encore étudiant",
                    },
                },

                [3] = {
                    2.0f, 1.0f, "Oh c'est super ça !", 0, {}
                },
            },
            .next = {3}
        },

        [2] = {
            .personne = VIOLA,
            .nb_conversation = 4,
            .conversations = {
                {
                    2.0f, 1.0f, "Tu es très ponctuel !", 1, {
                        "Il faut bien",
                    },
                },
                {
                    2.0f, 1.0f, "Des fois il faut quand même prendre son temps", 0, {}
                },
                {
                    2.0f, 1.0f, "Tu as passé une bonne soirée ?", 2, {
                        "Merdique",
                        "Mouais et toi ?",
                    },
                },
                {
                    2.0f, 1.0f, "Espérons qu'on se remonte le moral en discutant alors", 0, {}
                },
            },
            .next = {3}
        },

        [3] = {
            .personne = VIOLA,
            .nb_conversation = 5,
            .conversations = {
                {
                    2.0f, 1.0f, "Ma soirée été assez mouvementée, on est allés embêter la police", 0, {}
                },
                {
                    2.0f, 1.0f, "Je fais partie des Purple Sky", 2, {
                        "Les terroristes ?",
                        "Le groupe de révolutionnaires ?",
                    },
                },
                {
                    2.0f, 1.0f, "Tu as passé une bonne soirée ?", 2, {
                        "Merdique",
                        "Mouais et toi ?",
                    },
                },
                {
                    2.0f, 1.0f, "Je préfère dire \"groupe activiste\" mais oui, c'est nous", 0, {}
                },
                {
                    2.0f, 1.0f, "On se bat pour la liberté", 0, {}   
                },
            },
            .next = {4}
        },

        [4] = {
            .personne = VIOLA,
            .nb_conversation = 3,
            .conversations = {
                
                //transition : Une semaine plus tard, vous avez continué de parler avec Viola.
                //mettre l'heure à 16h
                {
                    2.0f, 1.0f, "Minuit veut te rencontrer, si tu es d'accord", 2, {
                        "Minuit ? Qui est-ce ?",
                        "C'est un ami à toi ?",
                    },
                },
                {
                    2.0f, 1.0f, "C'est le chef des Purple Sky", 1, {
                        "Pourquoi veut-il me voir ?",
                    },
                },
                {
                    2.0f, 1.0f, "Il s'interesse à toi depuis la soirée à l'Atout", 2, {
                        "D'accord, il veut me voir quand ?",
                        "Non je refuse de le rencontrer",
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
                    2.0f, 1.0f, "Rendez-vous derrière l'Atout, à 23h, ce soir", 2, {
                        "J'y serai",
                        "OK, à ce soir",
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
                    2.0f, 1.0f, "D'accord, c'est ton choix", 0, {},
                },
                {
                    2.0f, 1.0f, "Je vais devoir supprimer cette discussion dans ce cas", 0, {},
                },
                {
                    2.0f, 1.0f, "Adieu", 0, {}
                },
            },
            .next = {0}
        },

        [7] = {
            .personne = MINUIT,
            .nb_conversation = 4,
            .conversations = {
                {
                    // transition : Vous êtes derrière le bar l'Atout
                    // mettre l'heure à 23h
                    2.0f, 1.0f, "C'est toi le nouveau ?", 2, {
                        "Je suis l'ami de Viola",
                        "Oui, c'est moi",

                    },
                },
                {
                    2.0f, 1.0f, "Moi c'est Minuit, je suis le chef des Purple Sky", 0, {},
                },
                {
                    2.0f, 1.0f, "Et aussi l'ex de Viola", 2, {
                        "D'accord",
                        "En parlant de Viola, elle est en retard"
                    },
                },
                {
                    2.0f, 1.0f, "J'entends les sirènes de police, il se passe quoi ?", 0, {},
                },
                {
                    2.0f, 1.0f, "Merde ! C'est trop proche, suis moi", 2, {
                        "On fonce, c'est peut être Viola",
                        "Euh ... tu es sûr qu'il faut y aller ?"
                    },
                },
        }
        .next = {8, 9}
    },

    [8] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "C'est elle, je la reconnais", 2, {
                        "Non, pas ça",
                        "Il faut la sortir de là",

                    },
                },
                {
                    2.0f, 1.0f, "Bouge pas de là, je vais essayer d'aller voir", 2, {
                        "Non, c'est trop dangereux. Les Purple Sky ne peuvent pas perdre leur chef",
                        "D'accord, fais attention",
                    },
                },
        }
        .next = {10, 11}
    },

    [9] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "Et tu veux faire quoi d'autre ? Si c'est Viola je ne te le pardonnerai pas, je pars seul", 0, {},
                },
                {
                    2.0f, 1.0f, "Fais le peureux si tu veux mais moi j'y vais", 0, {},
                },
        }
        .next = {11}
    },

    [10] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "Tu as peut être raison, mais je ne peux pas perdre Viola", 0, {},
                },
                {
                    2.0f, 1.0f, "Fais le peureux si tu veux mais moi j'y vais", 0, {},
                },
        }
        .next = {11}
    },

    [11] = {
            .personne = ARCHIE,
            .nb_conversation = 3,
            .conversations = {
                {
                    2.0f, 1.0f, "Ne lui en veux pas trop, il tient beaucoup à elle", 0, {},
                },
                {
                    2.0f, 1.0f, "Au fait, moi c'est Archie", 0, {},
                },
                {
                    2.0f, 1.0f, "Je suis l'ami de Minuit, et donc membre des Purple Sky", 2, {
                        "Euh... Enchanté je suppose",
                        "Tu sors d'où comme ca ? Tu m'as fait peur",
                    },
                },
        }
        .next = {12, 13}
    },

    [12] = {
            .personne = ARCHIE,
            .nb_conversation = 1,
            .conversations = {
                {
                    2.0f, 1.0f, "Enchanté", 0, {},
                },
        }
        .next = {14}
    },

    [13] = {
            .personne = ARCHIE,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "Je suis le garde du corps de Minuit", 0, {},
                },
                {
                    2.0f, 1.0f, "Donc je le suis partout où il va", 0, {},
                },
        }
        .next = {14}
    },

    [14] = {
            .personne = ARCHIE,
            .nb_conversation = 3,
            .conversations = {
                {
                    2.0f, 1.0f, "D'ailleurs, on dirait que les sirènes se sont calmées", 0, {},
                },
                {
                    2.0f, 1.0f, "Et voilà Minuit qui revient", 0, {},
                },
                {
                    2.0f, 1.0f, "Moi je file, bonne chance, il à l'air en colère", 0, {},
                },
        }
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
                    2.0f, 1.0f, "TOUT CA C'EST DE TA FAUTE ! C'EST TOI QUI LES A APPELES !", 2, {
                        "QUOI ?! Bien sur que non",
                        "Calme toi, c'est juste un coup de malchance"
                    },
                },
        }
        .next = {16, 17}
    },

    [16] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "SI ! Je te faisais pas confiance et j'avais bien raison", 0, {},
                },
                {
                    2.0f, 1.0f, "Si tu es là pour foutre la merde, casse toi", 0, {},
                },

                // transition : Vous partez, laissant Minuit et Archie décider comment libérer Viola. Merci d'avoir joué à cette démo
        }
        .next = {0}
    },

    [17] = {
            .personne = MINUIT,
            .nb_conversation = 2,
            .conversations = {
                {
                    2.0f, 1.0f, "LA MALCHANCE HEIN ?! ELLE APPELLE LES FLICS LA MALCHANCE ??", 0, {},
                },
                {
                    2.0f, 1.0f, "*sors un pistolet laser* TU VA LA REJOINDRE EN ENFER, ORDURE", 0, {},
                },

                // transition : Minuit tire, vous tuant sur le coup. Merci d'avoir joué à cette démo
        }
        .next = {0}
    }
};
