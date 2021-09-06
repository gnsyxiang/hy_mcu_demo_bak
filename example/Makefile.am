# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    05/03 2021 10:38
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        05/03 2021      create the file
# 
#     last modified: 05/03 2021 10:38
# ===============================================================

# ------------------
# defining variables
# ------------------
_no_error_com   =
_include_com    =
_sources_com    =
_cppflags_com   =
_cflags_com     =
_cxxflags_com   =
_ldflags_com    =
_ldadd_com      =
_elf_file       =
bin_PROGRAMS    =

# ---------------------
# add necessary content
# ---------------------
_no_error_com   +=

_include_com    +=

_sources_com    +=

_cppflags_com   += \
                   $(CPPFLAGS_COM) \
                   $(_no_error_com) \
                   $(_include_com)

_cflags_com     += $(CFLAGS_COM)

_cxxflags_com   += $(CXXFLAGS_COM)

_ldflags_com    += $(BIN_LDFLAGS_COM)

_ldadd_com      +=

if COMPILE_LIBHY_HAL
_ldadd_com      += $(HY_HAL_LIBS)
endif

if COMPILE_LIBHY_UTILS
_ldadd_com      += $(HY_UTILS_LIBS)
endif

if COMPILE_SELECT_MCU_AT32F4XX
_ldflags_com    += -T$(top_srcdir)/res/at/at32f4xx/AT32F407xG_FLASH.ld
endif

_elf_file                   += hy_main_demo
bin_PROGRAMS                += hy_main_demo.elf
hy_main_demo_elf_SOURCES    = $(_sources_com) main.c
hy_main_demo_elf_CPPFLAGS   = $(_cppflags_com)
hy_main_demo_elf_CFLAGS     = $(_cflags_com)
hy_main_demo_elf_CXXFLAGS   = $(_cxxflags_com)
hy_main_demo_elf_LDFLAGS    = $(_ldflags_com) -Wl,--gc-sections,-Map=hy_main_demo.map,-cref,-u,Reset_Handler
hy_main_demo_elf_LDADD      = $(_ldadd_com)

_elf_file                   += hy_led_demo
bin_PROGRAMS                += hy_led_demo.elf
hy_led_demo_elf_SOURCES     = $(_sources_com) led.c
hy_led_demo_elf_CPPFLAGS    = $(_cppflags_com)
hy_led_demo_elf_CFLAGS      = $(_cflags_com)
hy_led_demo_elf_CXXFLAGS    = $(_cxxflags_com)
hy_led_demo_elf_LDFLAGS     = $(_ldflags_com) -Wl,--gc-sections,-Map=hy_led_demo.map,-cref,-u,Reset_Handler
hy_led_demo_elf_LDADD       = $(_ldadd_com)

install-exec-hook:
	for file in $(_elf_file); do \
		@gcc_prefix@objcopy -O binary $$file.elf $$file.bin; \
	done
	$(INSTALL_PROGRAM_ENV) $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL_PROGRAM) *.bin "$(DESTDIR)$(bindir)$$dir"

