#include "stdio.h"
#include "header.h"
#include "folderHeader/fHeader.h"
#include "fHeaderPio.h"
// #include "../.pio/libdeps/native/folderHeaderPio/fHeaderPio.h"
// #include "headerPio.h"

int main(int argc, char **argv)
{
    printf("Hello, World!\n");
    sayHallo();
    sayHalloFolder();
    sayHalloFolderPio();
}