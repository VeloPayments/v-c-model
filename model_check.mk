#override this variable with the location of this model checking library
MODEL_CHECK_DIR?=$(PWD)
MODEL_CHECK_INCLUDES=-I $(MODEL_CHECK_DIR)/include

CBMC_STANDARD_OPTS= \
    $(MODEL_CHECK_INCLUDES) -DCBMC --trace --bounds-check \
    --pointer-check --div-by-zero-check --memory-leak-check --stop-on-fail
CBMC_LOOP_REDUCING_OPTS= \
    --unwind 60 --unwinding-assertions
CBMC_OPTS=$(CBMC_STANDARD_OPTS) $(CBMC_LOOP_REDUCING_OPTS)
MODEL_CHECK_SOURCES=$(wildcard $(MODEL_CHECK_DIR)/src/*.c)
