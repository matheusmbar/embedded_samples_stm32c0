#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup){};

TEST(FirstTestGroup, FirstTest) {
  CHECK(0 == 0);
  CHECK_EQUAL(1, 1);
}

TEST(FirstTestGroup, Sizeof32) {
  CHECK_EQUAL(sizeof(uint32_t), sizeof(uint32_t *));
}
