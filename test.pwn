#define RUN_TESTS

#include <a_samp>
#include <YSI_Core\y_testing>

#include "../../samp-mruv-api-plugin.inc"

main() {
    //
}

Test:mruv_connect_failure_test() {
    new ret = mruv_connect("");
    printf("ret: %d", ret);
    ASSERT(ret == 0);
}