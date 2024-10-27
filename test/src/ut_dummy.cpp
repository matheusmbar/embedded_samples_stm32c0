#include "CppUTest/TestHarness.h"

#include "dummy.h"

TEST_GROUP(DummyGroup){};

TEST(DummyGroup, DummyFunctionReturnsParam) {
  CHECK_EQUAL(1, DummyFunction(1));
  CHECK_EQUAL(-11, DummyFunction(-11));
}
