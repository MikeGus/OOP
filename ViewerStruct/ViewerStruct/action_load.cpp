#include "action_load.h"

Errors open_file(FILE*& file, char* file_name)
{
    Errors error = OK;

    file = fopen(file_name, "r");
    if (!file) {
        error = MISSING_FILE;
    }

    return error;
}

Errors apply_load(Model& model, char* file_name)
{
    Errors error = OK;
    FILE* file = NULL;

    error = open_file(file, file_name);
    if (error != OK) {
        return error;
    }

    error = read_model(model, file);
    fclose(file);

    return error;
}
