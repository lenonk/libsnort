## $Id$
AUTOMAKE_OPTIONS=foreign no-dependencies

noinst_LIBRARIES = libsnort.a

if BUILD_SNPRINTF
SNPRINTF_SOURCES = snprintf.c snprintf.h
endif

libsnort_a_SOURCES = cdefs.h \
event.h \
generators.h \
sf_protocols.h \
plugin_enum.h \
rules.h \
treenodes.h \
checksum.h \
debug.c snort_debug.h \
decode.c decode.h \
encode.c encode.h \
active.c active.h \
log.c log.h \
mstring.c mstring.h \
parser.c parser.h \
profiler.c profiler.h \
plugbase.c plugbase.h \
preprocids.h \
snort.c snort.h \
build.h \
$(SNPRINTF_SOURCES) \
strlcatu.c strlcatu.h \
strlcpyu.c strlcpyu.h \
tag.c tag.h \
util.c util.h \
detect.c detect.h \
signature.c signature.h \
mempool.c mempool.h \
sf_sdlist.c sf_sdlist.h sf_sdlist_types.h \
fpcreate.c fpcreate.h \
fpdetect.c fpdetect.h \
pcrm.c pcrm.h \
snort_bounds.h \
byte_extract.c \
byte_extract.h \
timersub.h \
spo_plugbase.h \
sfthreshold.c sfthreshold.h \
packet_time.c packet_time.h \
event_wrapper.c event_wrapper.h \
event_queue.c event_queue.h \
ipv6_port.h \
ppm.c ppm.h \
pcap_pkthdr32.h \
cpuclock.h \
sf_types.h \
log_text.c log_text.h \
detection_filter.c detection_filter.h \
detection_util.c detection_util.h \
rate_filter.c rate_filter.h \
obfuscation.c obfuscation.h \
rule_option_types.h \
sfdaq.c sfdaq.h \
idle_processing.c idle_processing.h idle_processing_funcs.h

snort_SOURCES = main.c

if BUILD_CONTROL_SOCKET
snort_SOURCES += dump.c dump.h
endif

if BUILD_DYNAMIC_EXAMPLES
EXAMPLES_DIR = dynamic-examples
endif


SUBDIRS = sfutil win32 output-plugins detection-plugins dynamic-plugins preprocessors parser dynamic-preprocessors dynamic-output target-based control file-process $(EXAMPLES_DIR)

INCLUDES = @INCLUDES@

libsnort_a_LIBADD = $(wildcard output-plugins/*.o) \
$(wildcard detection-plugins/*.o)            \
$(wildcard dynamic-plugins/*.o)            \
$(wildcard dynamic-output/plugins/*.o)      \
$(wildcard dynamic-output/*/*.o)      \
$(wildcard preprocessors/*.o)                \
$(wildcard parser/*.o) \
$(wildcard target-based/*.o) \
$(wildcard preprocessors/HttpInspect/*/*.o) \
$(wildcard preprocessors/Stream5/*.o) \
$(wildcard sfutil/*.o) \
$(wildcard control/*.o) \
$(wildcard file-process/*.o) \
$(wildcard file-process/libs/*.o)


if BUILD_SIDE_CHANNEL
libsnort_a_LIBADD += \
$(wildcard side-channel/*.o) \
$(wildcard side-channel/plugins/*.o)
SUBDIRS += side-channel
endif

#lib_LTLIBRARIES = libsnort.la
#libsnort_la_SOURCES = $(libsnort_a_SOURCES)
#libsnort_la_CFLAGS = -fPIC
#libsnort_la_LDFLAGS = -fPIC
#libsnort_la_LDFLAGS = -shared

bin_PROGRAMS = snort
snort_LDADD = libsnort.a
