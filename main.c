#include <stdio.h>
#include <string.h>

#include "raylib.h"

Vector2 window = {1920, 1080};

int horloge_heure = 6;
int horloge_min = 9;

#include "histoire.h"

float timer = 0.0f;

#define CHOIX_PAD 2
#define CHOIX_COLOR WHITE
#define CHOIX_COLOR_HOVER LIGHTGRAY

int draw_1_choix(Rectangle box, const char* choix)
{
    int pad = ((float)CHOIX_PAD/100)*box.width;
    Rectangle box1 = {
        box.x + pad,
        box.y + pad,
        box.width - pad*2,
        box.height - pad*2,
    };
    if (CheckCollisionPointRec(GetMousePosition(), box1))
        DrawRectangleRec(box1, CHOIX_COLOR_HOVER);
    else
        DrawRectangleRec(box1, CHOIX_COLOR);
    DrawText(choix, box1.x + pad, box1.y + box1.height/2 - pad*3/2, pad*3, BLACK);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), box1))
        return 1;
    return 0;
}

int draw_2_choix(Rectangle box, const char* choix1, const char* choix2)
{
    int pad = ((float)CHOIX_PAD/100)*box.width;
    Rectangle box1 = {
        box.x + pad,
        box.y + pad,
        box.width - pad*2,
        box.height/2 - pad*1.5,
    };
    if (CheckCollisionPointRec(GetMousePosition(), box1))
        DrawRectangleRec(box1, CHOIX_COLOR_HOVER);
    else
        DrawRectangleRec(box1, CHOIX_COLOR);
    DrawText(choix1, box1.x + pad, box1.y + box1.height/2 - pad*3/2, pad*3, BLACK);

    Rectangle box2 = {
        box.x + pad,
            box.y + pad/2 + box.height/2,
            box.width - pad*2,
            box.height/2 - pad*1.5,
    };
    if (CheckCollisionPointRec(GetMousePosition(), box2))
        DrawRectangleRec(box2, CHOIX_COLOR_HOVER);
    else
        DrawRectangleRec(box2, CHOIX_COLOR);
    DrawText(choix2, box2.x + pad, box2.y + box2.height/2 - pad*3/2, pad*3, BLACK);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), box1))
        return 1;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), box2))
        return 2;
    return 0;
}

int draw_3_choix(Rectangle box, const char* choix1, const char* choix2, const char* choix3)
{
    int pad = ((float)CHOIX_PAD/100)*box.width;
    Rectangle box1 = {
        box.x + pad,
        box.y + pad,
        box.width/2 - pad*1.5,
        box.height/2 - pad*1.5,
    };
    if (CheckCollisionPointRec(GetMousePosition(), box1))
        DrawRectangleRec(box1, CHOIX_COLOR_HOVER);
    else
        DrawRectangleRec(box1, CHOIX_COLOR);
    DrawText(choix1, box1.x + pad, box1.y + box1.height/2 - pad*3/2, pad*3, BLACK);

    Rectangle box2 = {
        box.x + pad/2 + box.width/2,
        box.y + pad,
        box.width/2 - pad*1.5,
        box.height/2 - pad*1.5,
    };
    if (CheckCollisionPointRec(GetMousePosition(), box2))
        DrawRectangleRec(box2, CHOIX_COLOR_HOVER);
    else
        DrawRectangleRec(box2, CHOIX_COLOR);
    DrawText(choix2, box2.x + pad, box2.y + box2.height/2 - pad*3/2, pad*3, BLACK);

    Rectangle box3 = {
        box.x + pad,
        box.y + pad/2 + box.height/2,
        box.width - pad*2,
        box.height/2 - pad*1.5,
    };
    if (CheckCollisionPointRec(GetMousePosition(), box3))
        DrawRectangleRec(box3, CHOIX_COLOR_HOVER);
    else
        DrawRectangleRec(box3, CHOIX_COLOR);
    DrawText(choix3, box3.x + pad, box3.y + box3.height/2 - pad*3/2, pad*3, BLACK);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), box1))
        return 1;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), box2))
        return 2;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), box3))
        return 3;
    return 0;
}

int draw_4_choix(Rectangle box, const char* choix1, const char* choix2, const char* choix3, const char* choix4)
{
    int pad = ((float)CHOIX_PAD/100)*box.width;
    Rectangle box1 = {
        box.x + pad,
        box.y + pad,
        box.width/2 - pad*1.5,
        box.height/2 - pad*1.5,
    };
    if (CheckCollisionPointRec(GetMousePosition(), box1))
        DrawRectangleRec(box1, CHOIX_COLOR_HOVER);
    else
        DrawRectangleRec(box1, CHOIX_COLOR);
    DrawText(choix1, box1.x + pad, box1.y + box1.height/2 - pad*3/2, pad*3, BLACK);

    Rectangle box2 = {
        box.x + pad/2 + box.width/2,
        box.y + pad,
        box.width/2 - pad*1.5,
        box.height/2 - pad*1.5,
    };
    if (CheckCollisionPointRec(GetMousePosition(), box2))
        DrawRectangleRec(box2, CHOIX_COLOR_HOVER);
    else
        DrawRectangleRec(box2, CHOIX_COLOR);
    DrawText(choix2, box2.x + pad, box2.y + box2.height/2 - pad*3/2, pad*3, BLACK);

    Rectangle box3 = {
        box.x + pad,
        box.y + pad/2 + box.height/2,
        box.width/2 - pad*1.5,
        box.height/2 - pad*1.5,
    };
    if (CheckCollisionPointRec(GetMousePosition(), box3))
        DrawRectangleRec(box3, CHOIX_COLOR_HOVER);
    else
        DrawRectangleRec(box3, CHOIX_COLOR);
    DrawText(choix3, box3.x + pad, box3.y + box3.height/2 - pad*3/2, pad*3, BLACK);

    Rectangle box4 = {
        box.x + pad/2 + box.width/2,
        box.y + pad/2 + box.height/2,
        box.width/2 - pad*1.5,
        box.height/2 - pad*1.5,
    };
    if (CheckCollisionPointRec(GetMousePosition(), box4))
        DrawRectangleRec(box4, CHOIX_COLOR_HOVER);
    else
        DrawRectangleRec(box4, CHOIX_COLOR);
    DrawText(choix4, box4.x + pad, box4.y + box4.height/2 - pad*3/2, pad*3, BLACK);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), box1))
        return 1;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), box2))
        return 2;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), box3))
        return 3;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), box4))
        return 4;
    return 0;
}

int main()
{
    InitWindow(window.x, window.y, "2025 brackey's game jam");
    SetWindowState(FLAG_FULLSCREEN_MODE);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    Texture phone_battery_tex = LoadTexture("data/phone-battery.png");
    Texture left_arrow_tex = LoadTexture("data/left-arrow.png");
    init_personnes();

    historique.idx_branche = 1;
    historique.branche[0] = 0;
    historique.conversation[0] = 0;

    while (!WindowShouldClose()) {
        if (IsWindowResized()) {
            window.x = GetScreenWidth();
            window.y = GetScreenHeight();
        }

        timer += GetFrameTime();

        Rectangle phone_box = {
            window.x/2-window.y/3, 0,
            window.y/3*2, window.y,
        };

        BeginDrawing();
        {
            ClearBackground(BEIGE);

            DrawRectangleRec(phone_box, RAYWHITE);

            Rectangle header_box = phone_box;
            header_box.height *= (float)15/100;
            DrawRectangleRec(header_box, BLUE);

            Rectangle notif_box = phone_box;
            notif_box.height *= (float)3/100;
            DrawRectangleRec(notif_box, DARKBLUE);

            DrawText(TextFormat("%02d:%02d", horloge_heure, horloge_min), notif_box.x+4, notif_box.y+2, notif_box.height-2, WHITE);

            float phone_battery_scale = notif_box.height/phone_battery_tex.height;
            DrawTextureEx(
                phone_battery_tex,
                (Vector2){
                    notif_box.x+notif_box.width-phone_battery_tex.width*phone_battery_scale,
                    notif_box.y
                }, 0, phone_battery_scale, WHITE
            );

            Branche branche = histoire.branches[historique.branche[historique.idx_branche-1]];
            Conversation conv = branche.conversations[historique.conversation[historique.idx_conv-1]];

            personnes[branche.personne].message = conv.question;

            if (!personnes[branche.personne].active && timer > conv.read_time) {
                personnes[branche.personne].active = 1;
            }

            if (IsKeyPressed(KEY_SPACE)) {
                printf("idx branche = %d\n", historique.idx_branche);
                printf("idx conv = %d\n", historique.idx_conv);
                historique.idx_conv++;
                historique.conversation[historique.idx_conv] = 0; // idx de la reponse
                if (historique.idx_conv >= branche.nb_conversation) {
                    historique.idx_conv = 0;
                    historique.idx_branche++;
                    historique.branche[historique.idx_branche] = 
                        historique.branche[historique.idx_branche-1]+1;
                    if (historique.idx_branche > histoire.nb_branche) {
                        printf("fin du monde\n");
                    }
                }
            }

            static int choix_active = 0;
            if (!choix_active) {
                float size = header_box.height*0.42;
                DrawText("Chat", header_box.x + header_box.width/2 - MeasureText("Chat", size)/2, header_box.y + size, size, WHITE);

                int active_personne = 0;
                for (int i = 0; i < MAX_PERSONNE; i++) {
                    if (!personnes[i].active) continue;
                    Rectangle conv_box = {
                        phone_box.x,
                        header_box.y+header_box.height + active_personne*phone_box.height*0.1,
                        phone_box.width,
                        phone_box.height*0.1,
                    };
                    float conv_scale = conv_box.height/personnes[i].pp.height;
                    active_personne++;

                    if (CheckCollisionPointRec(GetMousePosition(), conv_box))
                        DrawRectangleRec(conv_box, LIGHTGRAY);
                    else
                        DrawRectangleRec(conv_box, GRAY);

                    DrawTextureEx(personnes[i].pp, (Vector2){conv_box.x, conv_box.y}, 0, conv_scale, WHITE);

                    float name_size = 0.27*conv_box.height;
                    DrawText(personnes[i].name, conv_box.x+personnes[i].pp.width*conv_scale+name_size, conv_box.y+name_size/2, name_size, GOLD);
                    unsigned int max_char = 33;
                    if (personnes[i].message && strlen(personnes[i].message) >= max_char)
                        DrawText(TextFormat("%.*s...", max_char-3, personnes[i].message), conv_box.x+personnes[i].pp.width*conv_scale+name_size, conv_box.y+conv_box.height-name_size*1.5, name_size, WHITE);
                    else
                        DrawText(personnes[i].message, conv_box.x+personnes[i].pp.width*conv_scale+name_size, conv_box.y+conv_box.height-name_size*1.5, name_size, WHITE);

                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), conv_box)) {
                        choix_active = !choix_active;
                        personne_idx = i;
                    }
                }
            }

            if (choix_active) {
                float left_arrow_scale = (header_box.height-notif_box.height-header_box.height*0.12)/left_arrow_tex.height;
                Rectangle left_arrow_box = {
                    header_box.x+header_box.height*0.12/2,
                    header_box.y+notif_box.height+header_box.height*0.12/2,
                    left_arrow_tex.width*left_arrow_scale,
                    left_arrow_tex.height*left_arrow_scale,
                };
                DrawTextureEx(left_arrow_tex, (Vector2){left_arrow_box.x, left_arrow_box.y}, 0, left_arrow_scale, WHITE);
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), left_arrow_box))
                    choix_active = !choix_active;

                float pp_scale = (header_box.height-notif_box.height-header_box.height*0.12)/personnes[personne_idx].pp.height;
                Rectangle pp_box = left_arrow_box;
                pp_box.x += pp_box.width*1.42;
                DrawTextureEx(personnes[personne_idx].pp, (Vector2){pp_box.x, pp_box.y}, 0, pp_scale, WHITE);

                float name_size = 0.42*pp_box.height;
                DrawText(
                    personnes[personne_idx].name,
                    pp_box.x+personnes[personne_idx].pp.width*pp_scale+name_size,
                    pp_box.y+pp_box.height/2-name_size/2,
                    name_size, GOLD
                );

                Rectangle choix_box = phone_box;
                choix_box.height *= (float)35/100;
                choix_box.y = (phone_box.y+phone_box.height) - choix_box.height;
                DrawRectangleRec(choix_box, GRAY);

                Rectangle choix_titre_box = choix_box;
                choix_titre_box.height *= (float)15/100;
                DrawRectangleRec(choix_titre_box, BLACK);

                DrawText(
                    "Que voulez vous répondre ?",
                    choix_titre_box.x + 12,
                    choix_titre_box.y + choix_titre_box.height*(1-0.69)/2,
                    choix_titre_box.height * 0.69,
                    RAYWHITE
                );

                choix_box.y += choix_titre_box.height;
                choix_box.height -= choix_titre_box.height;

                static int s = 0;
                if (IsKeyPressed(KEY_SPACE)) s = (s+1)%4;

                int r = 0;
                switch (s) {
                    case 0: r = draw_1_choix(choix_box, "choix 1"); break;
                    case 1: r = draw_2_choix(choix_box, "choix 1", "choix 2"); break;
                    case 2: r = draw_3_choix(choix_box, "choix 1", "choix 2", "choix 3"); break;
                    case 3: r = draw_4_choix(choix_box, "choix 1", "choix 2", "choix 3", "choix 4"); break;
                }
                if (r) printf("%d\n", r);

                if (timer > conv.read_time) {
                    DrawText(conv.question, 500, 500, 50, ORANGE);
                }
            }

            DrawFPS(window.x - 100, 10);
            DrawText(TextFormat("timer = %.01f", timer), 5, 25, 25, WHITE);
        }
        EndDrawing();
    }
}
