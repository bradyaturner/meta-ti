require recipes-ti/includes/ti-paths.inc
require recipes-ti/includes/ti-staging.inc

TI_IPC_EXAMPLES_GIT_URI = "git://git.ti.com/ipc/ipc-examples.git"
TI_IPC_EXAMPLES_DEST_SUFFIX = "git/ipc-examples"
TI_IPC_EXAMPLES_GIT_PROTOCOL = "git"
TI_IPC_EXAMPLES_GIT_BRANCH = "master"
TI_IPC_EXAMPLES_NAME = "ipc-examples"

SRC_URI += "${TI_IPC_EXAMPLES_GIT_URI};\
destsuffix=${TI_IPC_EXAMPLES_DEST_SUFFIX};\
protocol=${TI_IPC_EXAMPLES_GIT_PROTOCOL};\
branch=${TI_IPC_EXAMPLES_GIT_BRANCH};\
name=${TI_IPC_EXAMPLES_NAME}"

TI_IPC_METADATA_GIT_URI = "git://git.ti.com/ipc/ipc-metadata.git"
TI_IPC_METADATA_DEST_SUFFIX = "git/ipc-metadata"
TI_IPC_METADATA_GIT_PROTOCOL = "git"
TI_IPC_METADATA_GIT_BRANCH = "master"
TI_IPC_METADATA_NAME = "ipc-metadata"

SRC_URI += "${TI_IPC_METADATA_GIT_URI};\
destsuffix=${TI_IPC_METADATA_DEST_SUFFIX};\
protocol=${TI_IPC_METADATA_GIT_PROTOCOL};\
branch=${TI_IPC_METADATA_GIT_BRANCH};\
name=${TI_IPC_METADATA_NAME}"

# Corresponds to tag: 3.44.00.00C
SRCREV_ipc-examples = "1b73bc32c5bdd869b5121f86859afb122d286acc"

# Corresponds to tag: 3.44.00.00
SRCREV_ipc-metadata = "07a745d47ecd7b4b64860e7c5d0fbe4e89524f2e"

S_ipc-examples = "${WORKDIR}/git/ipc-examples"
S_ipc-metadata = "${WORKDIR}/git/ipc-metadata"

PR = "${INC_PR}.4"

DEPENDS_append_keystone = " ti-cgt6x-native \
                            gcc-arm-none-eabi-native \
"
DEPENDS_append_omap-a15 = " ti-cgt6x-native \
                            ti-ccsv6-native \
                            gcc-arm-none-eabi-native \
"
IPC_TARGETS = ""
IPC_TARGETS_omap-a15 = "\
    gnu.targets.arm.A15F="${GCC_ARM_NONE_TOOLCHAIN}" \
    ti.targets.elf.C66="${STAGING_DIR_NATIVE}/usr/share/ti/cgt-c6x" \
    ti.targets.elf.C66_big_endian="${STAGING_DIR_NATIVE}/usr/share/ti/cgt-c6x" \
    ti.targets.arm.elf.M4="${M4_TOOLCHAIN_INSTALL_DIR}" \
"

IPC_TARGETS_keystone = " \
    gnu.targets.arm.A15F="${GCC_ARM_NONE_TOOLCHAIN}" \
    ti.targets.elf.C66="${STAGING_DIR_NATIVE}/usr/share/ti/cgt-c6x" \
    ti.targets.elf.C66_big_endian="${STAGING_DIR_NATIVE}/usr/share/ti/cgt-c6x" \
"

EXTRA_OEMAKE = "\
    PLATFORM=${PLATFORM} \
    XDC_INSTALL_DIR="${XDC_INSTALL_DIR}" \
    BIOS_INSTALL_DIR="${SYSBIOS_INSTALL_DIR}" \
    ${IPC_TARGETS} \
"