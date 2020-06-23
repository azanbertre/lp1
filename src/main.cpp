#include "app.h"

int main(int argc, char* argv[]) {
    app app("messages.md");
    return app.run(argc, argv);
}
