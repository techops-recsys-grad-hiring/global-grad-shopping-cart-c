#include <unity.h>
#include "./shopping_cart_test.h"
#include "../include/shopping_cart.h"

static int kPrice = 100;
static char *kProduct = "Product";

void shopping_cart_test_should_calculate_price_with_no_discount(void) {
    Product products[] = {
            {kPrice, "", kProduct}
    };

    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    TEST_ASSERT_EQUAL_DOUBLE(order.total_price, 100);
}

void shopping_cart_test_should_calculate_loyalty_points_with_no_discount(void) {
    Product products[] = {
            {kPrice, "", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    TEST_ASSERT_EQUAL_DOUBLE(order.loyalty_points, 20);
}

void shopping_cart_test_should_calculate_price_for_10_percent_discount(void) {
    Product products[] = {
            {kPrice, "DIS_10_ABCD", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    TEST_ASSERT_EQUAL_DOUBLE(order.total_price, 90.0);
}

void shopping_cart_test_should_calculate_loyalty_points_for_10_percent_discount(void) {
    Product products[] = {
            {kPrice, "DIS_10_ABCD", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    TEST_ASSERT_EQUAL_DOUBLE(order.loyalty_points, 10);
}

void shopping_cart_test_should_calculate_price_for_15_percent_discount(void) {
    Product products[] = {
            {kPrice, "DIS_15_ABCD", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    TEST_ASSERT_EQUAL_DOUBLE(order.total_price, 85.0);
}

void shopping_cart_test_should_calculate_loyalty_points_for_15_percent_discount(void) {
    Product products[] = {
            {kPrice, "DIS_15_ABCD", kProduct}
    };
    Customer customer = {"test"};
    ShoppingCart shoppingCart = shopping_cart_init(products, sizeof(products) / sizeof(Product), customer);
    Order order = shopping_cart_checkout(&shoppingCart);

    TEST_ASSERT_EQUAL(order.loyalty_points, 6);
}
