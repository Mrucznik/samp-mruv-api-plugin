#define RUN_TESTS

#include <a_samp>
#include <YSI_Core\y_testing>

#include "../../samp-mruv-api-plugin.inc"

main() {
    //
}

Test:mruv_itemsService_status_test() {
    new status[256];
    new ret = mvcs_GetServiceStatus(status);
    printf("ret: %s [%d]", status, ret);
    ASSERT(ret == 1);
}