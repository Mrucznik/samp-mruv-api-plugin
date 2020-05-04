#define RUN_TESTS

#include <a_samp>
#include <YSI_Core\y_testing>

#include "../../samp-mruv-api-plugin.inc"

main() {
    //
    printf("Done :)");
}

Test:mruv_itemsService_status_test() {
    new ret = mruv_itemsService_status();
    printf("ret: %d", ret);
    ASSERT(ret == 1);
}