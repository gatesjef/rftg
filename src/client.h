/*
 * Reasons to restart main loop.
 */
#define RESTART_NEW        1
#define RESTART_RESTORE    2
#define RESTART_LOAD       3
#define RESTART_UNDO       4
#define RESTART_NONE       5
#define RESTART_UNDO_ROUND 6
#define RESTART_UNDO_GAME  7
#define RESTART_REDO       8
#define RESTART_REDO_ROUND 9
#define RESTART_REDO_GAME  10
#define RESTART_REPLAY     11
#define RESTART_CURRENT    12

/*
 * User options.
 */
typedef struct options
{
	/* Number of players */
	int num_players;

	/* Expansion level */
	int expanded;

	/* Player name */
	char *player_name;

	/* Two-player advanced game */
	int advanced;

	/* Disable goals */
	int disable_goal;

	/* Disable takeovers */
	int disable_takeover;

	/* Customize seed */
	int customize_seed;

	/* Seed value */
	unsigned int seed;

	/* Hide/show card preview (For legacy reasons: 0: Show, 2: Hide) */
	int hide_card;

	/* Shrink opponent areas to fit without scrolling */
	int shrink_opponent;

	/* Display the settle discount icon */
	int settle_discount;

	/* Display the VP value for cards in hand */
	int vp_in_hand;

	/* Server name to connect to */
	char *server_name;

	/* Server port */
	int server_port;

	/* Username to connect as */
	char *username;

	/* Password */
	char *password;

	/* Game description when creating */
	char *game_desc;

	/* Game password when creating */
	char *game_pass;

	/* Number of players in multiplayer */
	int multi_min;
	int multi_max;

	/* Card size */
	int card_size;

	/* Log width */
	int log_width;

	/* Autosave */
	int auto_save;

	/* Save log at end of game */
	int save_log;

	/* Colored log */
	int colored_log;

	/* Verbose log */
	int verbose;

	/* Discard log */
	int discard_log;

	/* Last save location */
	char *last_save;

	/* Data folder location */
	char *data_folder;
} options;

extern options opt;
extern GtkListStore *user_list;
extern GtkTreeStore *game_list;
extern GtkWidget *entry_label, *chat_view, *password_entry;
extern GtkWidget *games_view;
extern GtkWidget *create_button, *join_button, *leave_button;
extern GtkWidget *kick_button, *addai_button, *start_button;
extern GtkWidget *action_prompt, *action_button;
extern GtkWidget *message_view;
extern GtkTextMark *message_end;
extern char *exp_names[];
extern game real_game;
extern int player_us;
extern int restart_loop;

extern int client_state;
extern int waiting_player[MAX_PLAYER];

extern void save_prefs(void);
extern void reset_cards(game *g, int color_hand, int color_table);
extern void redraw_hand(void);
extern void redraw_table(void);
extern void redraw_status(void);
extern void redraw_goal(void);
extern void redraw_phase(void);
extern void redraw_everything(void);
extern void modify_gui(void);
extern void reset_gui(void);
extern void switch_view(int lobby, int chat);
extern void gui_client_state_changed(int playing_game);

extern void game_view_changed(GtkTreeView *view, gpointer data);
extern void send_chat(GtkEntry *entry, gpointer data);
extern void connect_dialog(GtkMenuItem *menu_item, gpointer data);
extern void disconnect_server(GtkMenuItem *menu_item, gpointer data);
extern void resign_game(GtkMenuItem *menu_item, gpointer data);
extern void create_dialog(GtkButton *button, gpointer data);
extern void join_game(GtkButton *button, gpointer data);
extern void leave_game(GtkButton *button, gpointer data);
extern void start_game(GtkButton *button, gpointer data);
extern void kick_player(GtkButton *button, gpointer data);
extern void add_ai_player(GtkButton *button, gpointer data);
