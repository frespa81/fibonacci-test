#include <stdio.h>
#include "minunit.h"

#include "fibonacci.h"


int tests_run = 0;

static char * test_firstCall() {
    mu_assert("error, number != 1", getNextValueInFibonacciSequence() == 1);
    return 0;
}

static char * test_secondCall() {
    mu_assert("error, second call != 2", getNextValueInFibonacciSequence() == 2);
    return 0;
}

static char * test_thirdCall() {
    mu_assert("error, third call != 3", getNextValueInFibonacciSequence() == 3);
    return 0;
}

static char * test_fourthCall() {
    mu_assert("error, fourth call != 5", getNextValueInFibonacciSequence() == 5);
    return 0;
}

static char * test_twentiethCall() {
    int n = 20 - 5 - 1;
    while(n--) {
        getNextValueInFibonacciSequence();
    }

    mu_assert("error, 20th call != 6765", getNextValueInFibonacciSequence() == 6765);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_firstCall);
    mu_run_test(test_secondCall);
    mu_run_test(test_thirdCall);
    mu_run_test(test_fourthCall);
    mu_run_test(test_twentiethCall);
    return 0;
}

int main(int argc, char **argv) {

    (void)argc;
    (void)argv;

    char *result = all_tests();

    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
