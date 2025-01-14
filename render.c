#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define KEY_ESC 53 // Code de la touche Échap sur macOS (X11/Linux utilise d'autres codes)
#define KEY_UP 13  // Z ou Haut
#define KEY_DOWN 1 // S ou Bas
#define KEY_LEFT 0 // Q ou Gauche
#define KEY_RIGHT 2 // D ou Droite

typedef struct s_game {
    void *mlx;
    void *win;
    char **map; 
    int player_x;
    int player_y;
} t_game;

int key_hook(int keycode, t_game *game)
{
    if (keycode == KEY_ESC) {
        mlx_destroy_window(game->mlx, game->win); // Ferme la fenêtre
        exit(0);
    }
if (keycode == KEY_UP && game->map[game->player_y - 1][game->player_x] != '1')
    game->player_y--;
if (keycode == KEY_DOWN && game->map[game->player_y + 1][game->player_x] != '1')
    game->player_y++;
if (keycode == KEY_LEFT && game->map[game->player_y][game->player_x - 1] != '1')
    game->player_x--;
if (keycode == KEY_RIGHT && game->map[game->player_y][game->player_x + 1] != '1')
    game->player_x++;
if (keycode == KEY_UP && game->map[game->player_y - 1][game->player_x] == 'C') {
    game->map[game->player_y - 1][game->player_x] = '0';
    game->player_y--;
    game->collectibles--;
}


  // ajouter fction pr redessiner map
    return (0);
}

void render_map(t_game *game)
{
    int y, x;

    mlx_clear_window(game->mlx, game->win);
    y = 0;
    while (game->map[y]) {
        x = 0;
        while (game->map[y][x]) {
            if (game->map[y][x] == '1') 
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * 32, y * 32);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * 32, y * 32);
            else if (game->player_x == x && game->player_y == y)
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * 32, y * 32);
            x++;
        }
        y++;
    }
}


int main()
{
    t_game game;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 800, 600, "so_long");
    game.player_x = 5;
    game.player_y = 5;

    mlx_hook(game.win, 2, 1L<<0, key_hook, &game); // 2 = KeyPress
    mlx_loop(game.mlx);
    return (0);
}
