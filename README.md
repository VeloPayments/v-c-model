Velo C Model Checking
=====================

This project includes C headers and GNU Makefile includes for adding model
checking via the [C Bounded Model Checker][cbmc-url] to C code.  Model checking
is an essential operation for writing robust code that is resistant to security
vulnerabilities.

[cbmc-url]: http://www.cprover.org/cbmc/

In order to use model checking, it is necessary to set up a build target that
pulls in all C source code that is to be checked.  CBMC transforms the
expressions in code into SMT equations and attempts to find counter-examples
that fail the selected properties.

Model Assertions
----------------

The model assertion is the most useful interaction with the model checker.
Assertions can be used to enforce function contracts and to check invariants in
data structures.  If the model checker can find a counter-example that causes
one of these assertions to fail, then it will display this counter-example.

The `MODEL_ASSERT` macro wraps the `assert()` method in a conditional macro that
optimizes away assertions at compile time.  Running the model checker with the
`CBMC` macro defined on the command-line will enable model assertions and other
model checking-specific macros and overrides.

malloc and free
---------------

By default, CBMC treats `malloc()` as if it always succeeds.  However, this
method can fail.  Furthermore, CBMC assumes the standard semantics for `free()`,
which treats `free(NULL)` as a no-op.  However, freeing a null pointer is often
indicative of an error in code.

The CBMC header redefines both `malloc()` and `free()` as `cbmc_malloc()` and
`cbmc_free()`.  The former is defined to return an ambiguous value which may be
NULL, and the latter performs a model assertion that the pointer argument is not
NULL.
