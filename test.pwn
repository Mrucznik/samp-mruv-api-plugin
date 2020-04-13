#define RUN_TESTS

#include <a_samp>
#include <YSI_Core\y_testing>

#include "../../samp-mruv-api-plugin.inc"

main() {
    //
}

Test:RunTest() {
    new ret = MyFunction();
    printf("ret: %d", ret);
    ASSERT(ret == 0);
}
