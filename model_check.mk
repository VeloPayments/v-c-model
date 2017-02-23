#override this variable with the location of this model checking library
MODEL_CHECK_DIR?=$(PWD)
MODEL_CHECK_INCLUDES=-I $(MODEL_CHECK_DIR)/include

CBMC_OPTS=$(MODEL_CHECK_INCLUDES) -DCBMC --trace --beautify --bounds-check \
          --pointer-check --div-by-zero-check --memory-leak-check
MODEL_CHECK_SOURCES=$(wildcard $(MODEL_CHECK_DIR)/src/*.c)
