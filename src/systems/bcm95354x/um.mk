# 
# This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenUM/master/Legal/LICENSE file.
# 
# Copyright 2007-2020 Broadcom Inc. All rights reserved.

#
# UM's version number
#

CHIP = bcm5354x


include ${TOP}/systems/${SYSTEM}/um_version.mk

#
# Default values for certain parameters
#

CFG_MLONG64 ?= 0
CFG_RELOC ?= 0
CFG_UNCACHED ?= 0
CFG_BOOTRAM ?= 0
CFG_PCI ?= 0
CFG_LDT ?= 0
CFG_LDT_REV_017 ?= 0
CFG_PCIDEVICE ?= 0
CFG_DOWNLOAD ?= 0
CFG_USB ?= 0
CFG_MSYS ?= 0
CFG_ZLIB ?= 0
CFG_VGACONSOLE ?= 0
CFG_BIENDIAN ?= 0
CFG_RAMAPP ?= 0
CFG_USB ?= 0
CFG_ZIPSTART ?= 0
CFG_ZIPPED_CFE ?= 0
CFG_RELEASE_STAGE ?= 0
CFG_COMPRESSED_IMAGE ?= 0

SDK_VERSION = xgs-robo-6.5.11
SDK_PATCH_DIR = $(TOP)/sdk/sdk-6.5.11-overwrite
SDK_RELEASE_DIR = $(TOP)/sdk/release/

ifeq ($(SDK_SRC_DIR),)
SDK_DIR = $(TOP)/sdk/sdk-$(SDK_VERSION)
SDK_INSTALL += $(SDK_DIR)/.install.sdk.$(SDK_VERSION)
else
SDK_DIR = $(SDK_SRC_DIR)
SDK_INSTALL = 
endif 

#
# Override some settings based on the value of CFG_RELOC.
#
# 'STATIC' relocation means no biendian, no bootram, ZIPstart
# '1' is SVR4 Relocation,  no RAMAPP, no BOOTRAM
# '0' (no relocation) : no changes
#

ifeq ($(strip ${CFG_RELOC}),1)
  CFG_RAMAPP = 0
  CFG_BOOTRAM = 0
endif

ifeq ($(strip ${CFG_RELOC}),STATIC)
  CFG_RAMAPP = 0
  CFG_BIENDIAN = 0
  CFG_BOOTRAM = 0
  CFG_ZIPSTART = 1
  CFE_CFLAGS += -DCFG_ZIPSTART=1
endif

#
# Default goal.
#

all : ALL

#
# Paths to other parts of the firmware.  Everything's relative to ${TOP}
# so that you can actually do a build anywhere you want.
#

BSP_SRC    = ${TOP}/systems/${SYSTEM}/src
BSP_INC    = ${TOP}/systems/${SYSTEM}/include
LIB_PATH   = ${BUILD_DIR}/lib
MAIN_SRC   = ${TOP}/src/kernel
MAIN_INC   = ${TOP}/include
SOC_SRC    = ${TOP}/src/driver/soc/${CHIP}
UIP_SRC    = ${TOP}/src/net
FLASH_SRC  = ${TOP}/src/driver/flash
XCMD_INC   = ${TOP}/src/appl/xcommands
SAL_CONFIG_H = ${TOP}/include/arm/sal_config.h
#
# Preprocessor defines for CFE's version number
#

VDEF = -DCFE_VER_MAJOR=${CFE_VER_MAJ} -DCFE_VER_MINOR=${CFE_VER_MIN} -DCFE_VER_BUILD=${CFE_VER_ECO}
VDEF += -DCFE_VER_SDK=${CFE_VER_SDK}

#ifneq ("$(strip ${CFE_VER_SDK})","")
#  VDEF += -DCFE_VER_SDK=${CFE_VER_SDK}
#endif

ifdef CFG_SERIAL_BAUD_RATE_OVERRIDE
  CFE_CFLAGS += -DCFG_SERIAL_BAUD_RATE=${CFG_SERIAL_BAUD_RATE_OVERRIDE}
endif

#
# Construct the list of paths that will eventually become the include
# paths and VPATH.
#

SRCDIRS = ${BSP_SRC} ${MAIN_SRC} ${TOP}/include

# ${TOP}/net ${TOP}/dev ${TOP}/ui ${TOP}/lib ${TOP}/httpd ${TOP}/httpd/callbacks

CFE_INC = ${TOP}/include ${TOP}/include/${ARCH} ${TOP}/src/net ${TOP}/src/appl/web/content ${XCMD_INC}  
CFE_INC += $(SDK_PATCH_DIR)/include $(SDK_PATCH_DIR)/libs/phymod/include $(SDK_DIR)/include $(SDK_DIR)/libs/phymod/include ${TOP}/include/pcm/soc
 
#
# Configure tools and basic tools flags.  This include sets up
# macros for calling the C compiler, basic flags,
# and linker scripts.
#

include ${BUILD_DIR}/src/tools.mk

#
# Add some common flags that are used on any architecture.
#
CFLAGS += -DVENDOR_BROADCOM
CFLAGS += -I. $(INCDIRS)
CFLAGS += -D_CFE_ ${VDEF} -DCFG_BOARDNAME=\"${CFG_BOARDNAME}\" -DCFG_CPU_ARM_CORTEX_A9_ENABLE

ifeq ($(strip ${CFG_QT}), 1)
CFLAGS += -D__EMULATION__
endif
#
# Gross - allow more options to be supplied from command line
#

ifdef CFG_OPTIONS
OPTFLAGS = $(patsubst %,-D%,$(subst :, ,$(CFG_OPTIONS)))
CFLAGS += ${OPTFLAGS}
endif

CFLAGS += -DPHYMOD_SUPPORT
CFLAGS += -DPHYMOD_TIER1_SUPPORT
CFLAGS += -DPHYMOD_INCLUDE_CUSTOM_CONFIG

#
# Include the makefiles for the architecture-common, cpu-specific,
# and board-specific directories.  Each of these will supply
# some files to "ALLOBJS".  The BOARD and CHIPSET directories are optional
# as some ports are so simple they don't need boad-specific stuff.
#

# include ${ARCH_SRC}/Makefile
# include ${CPU_SRC}/Makefile

# ifneq ("$(strip ${BOARD})","")
# include ${BOARD_SRC}/Makefile
# endif

include ${TOP}/systems/${SYSTEM}/src/Makefile

#
# Pull in the common directories
#

# include ${MAIN_SRC}/Makefile
# include ${TOP}/lib/Makefile

KERNELOBJS = background.o link.o main.o rx.o timer.o tx.o

SALOBJS = sal_alloc.o sal_chksum.o sal_console.o sal_init.o sal_libc.o\
          sal_printf.o sal_timer.o sal_config.o

SRCDIRS += ${TOP}/src/sal/${ARCH}

UIPOBJS = uip.o uip6.o uip_arp.o uip-ds6.o uip-nd6.o uip-icmp6.o uip_arch.o\
          uip_task.o

SRCDIRS += ${TOP}/src/net

APPLOBJS = app_init.o dhcpc.o igmpsnoop.o igmpsnoop_cbk.o mdns.o mdns_utils.o
ifndef CFG_SOC_SNAKE_TEST
APPLOBJS += snaketest.o
endif
SRCDIRS += ${TOP}/src/appl ${TOP}/src/appl/dhcpc ${TOP}/src/appl/snaketest
SRCDIRS += ${TOP}/src/appl/igmpsnoop ${TOP}/src/appl/net 
SRCDIRS += ${TOP}/src/appl/mdns


#
# XCOMANND core file include  
#

XCMDOBJS = xc_input_buffer.o xc_input_cli.o xc_output_buf.o xcmd_cli.o xcmd_core.o xcmd_auth.o xcmd_display_page.o
SRCDIRS += ${TOP}/src/appl/xcmd

#
# XCOMANND XML Tables generator : please use make xcommand to generate callback function  
#

XCOMMANDS_XMLDIR = ${TOP}/src/appl/xcommands
XCOMMANDS_PARSER = ${TOP}/tools/xcommands/parse_context.pl
XCOMMAND_XML_TABLES := \
    $(XCOMMANDS_XMLDIR)/global.xml
    
XCOMMAND_DEF_TABLES := $(XCOMMANDS_XMLDIR)/defines.xml    
    
XCOMMANDSDIRS = ${TOP}/src/appl/xcommands/callback ${TOP}/src/appl/xcommands/generated

SRCDIRS += ${XCOMMANDSDIRS}
XCOMMANDSOBJS = $(patsubst %.c,%.o,$(notdir $(foreach dir, $(XCOMMANDSDIRS), $(wildcard $(dir)/*.c))))

ifeq ($(strip ${CFG_WEB}), 1) 
HTTPDOBJS = httpd.o httpd_arch.o ssp.o ssp_fs_root.o ssp_fstab.o
SRCDIRS += ${TOP}/src/appl/httpd ${TOP}/src/appl/web
GUIDIRS = ${TOP}/src/appl/web/callback ${TOP}/src/appl/web/content
SRCDIRS += ${GUIDIRS}
GUIOBJS = $(patsubst %.c,%.o,$(notdir $(foreach dir, $(GUIDIRS), $(wildcard $(dir)/*.c))))
endif

UIOBJS = cli.o ui_switch.o ui_system.o ui_flash.o ui_igmpsnoop.o ui_rx.o ui_tx.o ui_pcm.o


SRCDIRS += ${TOP}/src/appl/cli

PERSISOBJS = persistence.o serialize.o flash_medium.o ramtxt_medium.o mcast.o\
             mirror.o network.o qos.o serializers.o vlan.o lag.o loopdetect.o\
             system.o
SRCDIRS += ${TOP}/src/appl/persistence ${TOP}/src/appl/persistence/media/flash\
           ${TOP}/src/appl/persistence/media/ramtxt\
           ${TOP}/src/appl/persistence/serialize ${TOP}/src/serializers\

BRDIMPLOBJ = brd_misc.o brd_rxtx.o brd_vlan.o 
SRCDIRS += ${TOP}/src/board

FLASHOBJ = iproc_qspi.o flash.o
SWITCHOBJ = wh2switch.o wh2rxtx.o wh2vlan.o wh2port.o wh2loop.o \
            wh2mdns.o wh2blocks.o unimac.o wh2led.o wh2portconf.o \
            wh2linkscan.o wh2lag.o wh2access.o wh2pcm.o wh2mmu.o

SRCDIRS += ${TOP}/src/driver/pcm
SWITCHOBJ += pcm_phyctrl_hounds.o pcm_common.o 

CFE_INC += $(SDK_PATCH_DIR)/include $(SDK_PATCH_DIR)/libs/phymod/include $(SDK_DIR)/include $(SDK_DIR)/libs/phymod/include 
SWITCHOBJ += sdk_phy.o bsl_debug.o 

ifeq ($(strip ${CFG_SOC_SNAKE_TEST}), 1)
SWITCHOBJ += wh2snaketest.o
endif
ifeq ($(strip ${CFG_QT}), 1)
SWITCHOBJ += wh2qt.o
endif

SRCDIRS += ${TOP}/src/driver/flash
SRCDIRS += ${TOP}/src/driver/soc/${CHIP} 

UTILSOBJS = ui_utils.o net_utils.o ports_utils.o ui_utils.o factory_utils.o pbmp.o  nvram_utils.o system_utils.o field.o

SRCDIRS += ${TOP}/src/utils/net ${TOP}/src/utils/ports ${TOP}/src/utils/ui\
           ${TOP}/src/utils/nvram ${TOP}/src/utils/system ${TOP}/src/utils/share


#
# Add the common object files here.
#
ALLOBJS += $(KERNELOBJS) $(SALOBJS) $(UIPOBJS) $(APPLOBJS) $(UTILSOBJS)\
           $(UIOBJS) $(BRDIMPLOBJ) $(PERSISOBJS) $(FLASHOBJ) $(SWITCHOBJ)\
           $(HTTPDOBJS) $(GUIOBJS) $(XCMDOBJS) $(XCOMMANDSOBJS) $(LINUX_OBJS)

#
# Add optional code.  Each option will add to ALLOBJS with its Makefile,
# and some append to SRCDIRS and/or CFE_INC.
#

ifeq ($(strip ${CFG_INTERRUPTS}),1)
CFLAGS += -DCFG_INTERRUPTS=1
endif

# Add phy support list
#SDK_PHY_LIST = EGPHY28 542XX
#MDK_PHY_LIST = 56160 54282 QTCE
#CFLAGS += $(foreach phy,$(MDK_PHY_LIST), -DINCLUDE_PHY_$(phy))

# specify endian of system and setup the flag 

ifeq ($(strip ${CFG_LITTLE}),1) 
CFLAGS += -DCFG_LITTLE_ENDIAN=1 -DCFG_BIG_ENDIAN=0
else
CFLAGS += -DCFG_LITTLE_ENDIAN=0 -DCFG_BIG_ENDIAN=1 
endif
 
#
# Make the paths
#

INCDIRS = $(patsubst %,-I%,$(subst :, ,$(BSP_INC) $(CFE_INC)))

VPATH = $(SRCDIRS)

#
# This is the makefile's main target.  Note that we actually
# do most of the work in 'ALL' (from the build Makefile) not 'all'.
#

#all : build_date.c makereg pcidevs_data2.h ALL
all : build_date.c ALL

.PHONY : all 
.PHONY : ALL
.PHONY : build_date.c

#
# Build the local tools that we use to construct other source files
#

HOST_CC = gcc
HOST_CFLAGS = -g -Wall -Werror -Wstrict-prototypes -Wmissing-prototypes

bin2codefile : ${TOP}/tools/bin2codefile.c
	$(HOST_CC) $(HOST_CFLAGS) -o bin2codefile ${TOP}/tools/bin2codefile.c

build_date.c :
	@echo "const char *builddate = \"`date`\";" > build_date.c
	@echo "const char *builduser = \"`whoami`@`hostname`\";" >> build_date.c

preparation: $(SDK_INSTALL)
	rm -f $(BUILD_DIR)/lib/libpcmphyctrl_physelect.a 
	rm -f $(TOP)/sdk/make/src/soc/phy/phyident.o

$(SDK_DIR)/.install.sdk.$(SDK_VERSION):
	mkdir -p $(SDK_DIR)
	tar -C $(SDK_DIR) -xvf $(TOP)/sdk/sdk-$(SDK_VERSION).tar
	touch $@


	
#
# Make a define for the board name
#

CFLAGS += -D_$(patsubst "%",%,${CFG_BOARDNAME})_


#
# Rules for building normal CFE files
#

LIBCFE = $(LIB_PATH)/libcfe.a


xcommands : $(patsubst %, %_cbkgen, ${XCOMMAND_XML_TABLES}) 
%.xml_cbkgen:
	@echo Convert $(patsubst %_cbkgen, %, $@) 
	@perl $(XCOMMANDS_PARSER) $(patsubst %_cbkgen, %, $@) $(XCOMMAND_DEF_TABLES) 


#
# Dependcy Rule 
#

-include $(wildcard $(patsubst %.o, %.d, $(CRT0OBJS) $(BSPOBJS) $(ALLOBJS)))

#
# Generic Complile 
#

%.o : %.c
	@echo ""
	$(GCC) $(CFE_CFLAGS) $(CFLAGS) -include $(BUILD_DIR)/conf.h -MP -MD -o $@ $< -c
ifeq ($(RELEASE_BUILD),1)
	$(QUIET)$(TOP)/tools/release_tool.py --target=release_sdklibs --input_file=$(patsubst %.o,%.d, $@) --source_directory=$(SDK_DIR) --destination_directory=$(SDK_RELEASE_DIR)
endif

%.o : %.S
	@echo ""
	$(GCCAS) -D__ASSEMBLER__ $(CFE_CFLAGS) $(CFLAGS) -include $(BUILD_DIR)/conf.h -MP -MD -o $@ $< -c

#
# Rules for building ZIPSTART
#

LIBZIPSTART = libzipstart.a

ZS_%.o : %.c
	$(CC) $(ENDIAN) $(ZIPSTART_CFLAGS) -D_ZIPSTART_ $(CFLAGS) -o $@ $<

ZS_%.o : %.S
	$(CC) $(ENDIAN) $(ZIPSTART_CFLAGS) -D_ZIPSTART_ $(CFLAGS) -o $@ $<

$(LIBPHYECD) : $(LIBPHYECDOBJ)
ifneq (,$(LIBPHYECDOBJ))
	rm -f ${LIB_PATH}/$(LIBPHYECD)
	$(GAR) cr ${LIB_PATH}/$(LIBPHYECD) $(LIBPHYECDOBJ)
	$(GRANLIB) ${LIB_PATH}/$(LIBPHYECD)
endif

#
# This rule constructs "libcfe.a" which contains most of the object
# files.
#

$(LIBCFE) : $(ALLOBJS) header_link pcmphyctrl_physelect pcmphyctrl_release_build
	rm -f $(LIBCFE)
	$(GAR) cr $(LIBCFE) $(ALLOBJS)
	$(GRANLIB) $(LIBCFE)