#include <magisk.hpp>
#include <selinux.hpp>

constexpr char magiskrc[] =
"\n"

"on post-fs-data\n"
"    start logd\n"
"    rm " UNBLOCKFILE "\n"
"    start %2$s\n"
"    wait " UNBLOCKFILE " 10\n"
"    rm " UNBLOCKFILE "\n"
"\n"

"service %2$s %1$s/magisk --post-fs-data\n"
"    user root\n"
"    seclabel u:r:" SEPOL_PROC_DOMAIN ":s0\n"
"    oneshot\n"
"\n"

"service %3$s %1$s/magisk --service\n"
"    class late_start\n"
"    user root\n"
"    seclabel u:r:" SEPOL_PROC_DOMAIN ":s0\n"
"    oneshot\n"
"\n"

"on property:sys.boot_completed=1\n"
"    start %4$s\n"
"\n"

"service %4$s %1$s/magisk --boot-complete\n"
"    user root\n"
"    seclabel u:r:" SEPOL_PROC_DOMAIN ":s0\n"
"    oneshot\n"
"\n"
;
