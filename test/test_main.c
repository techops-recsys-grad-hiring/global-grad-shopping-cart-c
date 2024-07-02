#include <unity.h>
#include "./shopping_cart_test.h"

void setUp() {}

void tearDown() {}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(should_test_double);
  RUN_TEST(shopping_cart_test_should_calculate_price_with_no_discount);
  RUN_TEST(shopping_cart_test_should_calculate_loyalty_points_with_no_discount);
  RUN_TEST(shopping_cart_test_should_calculate_price_for_10_percent_discount);
  RUN_TEST(shopping_cart_test_should_calculate_loyalty_points_for_10_percent_discount);
  RUN_TEST(shopping_cart_test_should_calculate_price_for_15_percent_discount);
  RUN_TEST(shopping_cart_test_should_calculate_loyalty_points_for_15_percent_discount);

  return UNITY_END();
}
