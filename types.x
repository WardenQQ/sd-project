
struct map_object_t {
    int x;
    int y;
    int radius;
    int type;
};

struct map_t {
    map_object_t blocks[MAX_BLOCKS_NBR];
    int nb_blocks;
    map_object_t goals[MAX_GOALS_NBR];
    int nb_goals;
    map_object_t start_pos;
};

struct server_info_t {
    int id[SERVER_LIST_MAX];
    int size;
    map_t map;
};

struct migrants_t {
    genotype_t pop[MIGRATION_SIZE];
};

struct genotype_t {
    gene_t genes[GENOTYPE_SIZE];
    double fitness;
};

struct gene_t {
    int step;
    int direction;
};