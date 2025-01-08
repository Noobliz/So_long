t_map *create_node(int value) {
	t_map *node = malloc(sizeof(t_map));
	node->value = value;
	node->x = NULL;
	node->y = NULL;
	return node;
}

int main() {
	t_map *map = create_node(1);
	map->x = create_node(1);
	map->x->x = create_node(1);
	map->y = create_node(1);
	map->y->x = create_node(0); 
	map->y->x->x = create_node(1);
	map->y->y = create_node(1);
	map->y->y->x = create_node(1);
	map->y->y->x->x = create_node(1);

	if (surrounded_by_walls(map))
		printf("map valid.\n");
	else
		printf("Map not valid\n");

	return 0;
}
