struct gene_t {
    int step;
    int direction;
};

struct genotype_t {
    gene_t genes[GENOTYPE_SIZE];
    double fitness;
};

struct map_object_t {
    int x;
    int y;
    int radius;
    int type;
};

struct map_t {
    int width;
    int height;
    map_object_t blocks[MAX_BLOCKS_NBR];
    int nb_blocks;
    map_object_t goals[MAX_GOALS_NBR];
    int nb_goals;
    map_object_t start_pos;
    int min_step;
    int max_step;
    int min_radius;
    int max_radius;
    
    int mutation_prob;
    int nb_children;
    int migration_freq;
};

struct server_address_t {
    char hostname[64];
    int id;
};

struct server_list_t {
    server_address_t addr[SERVER_LIST_MAX];
    int size;
};

struct migrants_t {
    genotype_t pop[MIGRATION_SIZE];
};
