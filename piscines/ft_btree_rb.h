#ifndef FR_BTREE_RB_H_
#define FR_BTREE_RB_H_

enum e_rb_color {
	RB_BLACK,
	RB_RED
};

typedef struct s_rb_node {
	struct s_rb_node *parent;
	struct s_rb_node *left;
	struct s_rb_node *right;
	void *data;
	enum e_rb_color color;
} t_rb_node;

#endif
