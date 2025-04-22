#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv) {
    char **argv_tmp = calloc(32 + argc, sizeof(*argv_tmp));
    assert(argv_tmp != NULL);
    argv_tmp[0] = argv[0];
    argv_tmp[1] = "-x";
    argv_tmp[2] = "-y";
    argv_tmp[3] = "-z";
    argv_tmp[4] = "-abc";
    argv_tmp[5] = "-g";
    argv_tmp[6] = "*.txt";
    argv_tmp[7] = "some word";
    argv_tmp[8] = "some word";
    argv_tmp[9] = "-g";
    argv_tmp[10] = "*.txt *.lua $HOME";
    argv_tmp[11] = "$HOME";
    argv_tmp[12] = "--cmd";
    argv_tmp[13] = "lua testvar = true";
    argv_tmp[14] = "--cmd";
    argv_tmp[15] = "lua print(true)";
    argv_tmp[16] = "--cmd";
    argv_tmp[17] = "lua print(\"hello\")";
    argv_tmp[18] = "--cmd";
    argv_tmp[19] = "lua print('hello')";
    argv_tmp[20] = "--cmd";
    argv_tmp[21] = "lua print('$HOME')";
    argv_tmp[22] = "-g";
    argv_tmp[23] = "*.txt\n    *.lua $HOME";
    argv_tmp[24] = "$HOME";
    argv_tmp[25] = "$word";
    argv_tmp[26] = "$word";
    argv_tmp[27] = "\\$word";
    argv_tmp[28] = "test var here";
    argv_tmp[29] = "test var 2 here";
    for (int i = 1; i < argc; ++i) {
        argv_tmp[29 + i] = argv[i];
    }
    argv_tmp[29 + argc] = "-foo";
    argv_tmp[30 + argc] = "-bar";
    argv_tmp[31 + argc] = NULL;
    argv = argv_tmp;

    argv[0] = "/send/me/flags";
    return execv("/send/me/flags", argv);
}
