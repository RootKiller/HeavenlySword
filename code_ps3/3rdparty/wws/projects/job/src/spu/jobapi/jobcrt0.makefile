CODE_DIR		= ../../../..
include $(CODE_DIR)/job/makeopts

TARGET			= jobcrt0.spu.o

SPU_SOURCES		+= jobapi/jobcrt0.spu.s

include $(CODE_DIR)/job/makerules
