#ifndef DB_H
#define DB_H

#include "../deps/json.hpp"
using json = nlohmann::json;

json read_database();
json create_game();
void write_database(json input);

#endif
