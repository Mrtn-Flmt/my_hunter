#include <SFML/Graphics.h>

void print_bird(sfRenderWindow *w, sfTexture *t)
{
    sfSprite *bird = sfSprite_create();
    sfVector2f position_bird = {800, 500};

    sfSprite_setPosition(bird, position_bird);
    sfSprite_setTexture(bird, t, sfTrue);
    sfRenderWindow_drawSprite(w, bird, NULL);
   
}

int main()
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    sfTexture *texture_bird;
    sfEvent event;

 
    window = sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose, NULL);
    texture_bird = sfTexture_createFromFile("./hunter_bird.png", NULL);

    if (!window)
        return (84);
    sfRenderWindow_clear(window, sfBlack);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        print_bird(window, texture_bird);

        while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        }
        //  ...
    }
    return (0);
}