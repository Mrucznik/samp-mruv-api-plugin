#define RUN_TESTS

#include <a_samp>
#include <YSI_Core\y_testing>

#include "../../samp-mruv-api-plugin.inc"


forward OnGetServiceStatus(status[]);

main() {
    //
}

Test:mruv_itemsService_status_test() {
    new status[256];
    new ret = mvcs_GetServiceStatus(status);
    printf("ret: %s [%d]", status, ret);
    ASSERT(ret == 1);
}

Test:mvis_AsyncGetServiceStatus_Test() {
    new ret = mvis_AsyncGetServiceStatus("OnGetServiceStatus", "s", "null");
    printf("ret: [%d]", ret);
    ASSERT(ret == 1);
}

public OnGetServiceStatus(status[])
{
    printf("Service status: %s", status);
    return 1;
}
